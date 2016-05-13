// Server_0.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <list>
#include "KProtocol.h"
#pragma comment(lib,"ws2_32.lib")

using namespace std;

struct KUser
{
	bool			bConnect;
	SOCKET			client;
	SOCKADDR_IN		clientAddr;
};

CRITICAL_SECTION g_crit;

list<KUser*> g_UserList;

void BroadCastting(KUser* pSendUser, UPACKET* pPacket)
{
	EnterCriticalSection(&g_crit);
	
	int iUserCnt = 0;
	for (list<KUser*>::iterator itor = g_UserList.begin();
	itor != g_UserList.end();itor++)
	{
		KUser* user = *itor;
		if (user->bConnect == false)continue;
		int iSendbyte = send(user->client, (char*)pPacket, pPacket->ph.len, 0);
		if (iSendbyte == SOCKET_ERROR)
		{
			printf("\nClient Exit[%s]", inet_ntoa(user->clientAddr.sin_addr));
			break;
		}
	}
	LeaveCriticalSection(&g_crit);

}

void  PacketProcess(KUser* pUser, UPACKET* pPacket)
{
	// 1개의 패킷이 완성
	switch (pPacket->ph.type)
	{
	case PACKET_CHAR_MSG:
	{
		BroadCastting(pUser, pPacket);
		printf("\nRecvMessage=%s", pPacket->msg);
	}break;
	}
}

int SendMsg(SOCKET sock, char* msg, WORD type)
{
	UPACKET	sendmsg;
	ZeroMemory(&sendmsg, sizeof(UPACKET));
	sendmsg.ph.type = type;
	sendmsg.ph.len = PACKET_HEADER_SIZE + strlen(msg);
	memcpy(sendmsg.msg, msg, strlen(msg));

	int iSendbyte =	send(sock, (char*)&sendmsg, sendmsg.ph.len, 0);
	printf("\nSendMessage = %s[%d]", msg, strlen(msg));
	return iSendbyte;
}

void UserDel(KUser	*pUser)
{
	typedef std::list<KUser*>::iterator ITOR;
	ITOR itor;
	for (itor = g_UserList.begin();
		itor != g_UserList.end();
		itor++)
	{
		KUser* user = *itor;
		if (user->client == pUser->client)
			break;
	}
	KUser* user = *itor;
	closesocket(user->client);
	delete user;
	g_UserList.erase(itor);
}

DWORD WINAPI ClientThread(LPVOID data)
{

	KUser* user = (KUser*)data;
	SOCKET sock = user->client;
	//SOCKET sock = (SOCKET)data;
	char szBuffer[MAX_PATH] = { 0, };
	int iRecvData = 0;
	bool bConnect = true;
	while (bConnect)
	{
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		int iRet = recv(sock, &szBuffer[iRecvData], PACKET_HEADER_SIZE - iRecvData, 0);		//recv
		iRecvData += iRet;
		if (iRet == 0 || iRet == SOCKET_ERROR)
		{
			bConnect = false;
			break;
		}
		if (iRecvData == PACKET_HEADER_SIZE)
		{
			UPACKET* pPacket = (UPACKET*)&szBuffer;
			int iRecvSize = pPacket->ph.len - PACKET_HEADER_SIZE;
			int iRet = 0;
			while (iRecvData < pPacket->ph.len)
			{
				iRecvSize -= iRet;
				iRet = recv(sock, &szBuffer[iRecvData], iRecvSize, 0);
				iRecvData += iRet;
				if (iRet == 0 || iRet == SOCKET_ERROR)
				{
					bConnect = false;
					break;
				}
			}
			PacketProcess(user,pPacket);
			iRecvData = 0;

		}
		Sleep(1);
	}
	EnterCriticalSection(&g_crit);
	UPACKET pack;
	pack.ph.len = PACKET_HEADER_SIZE + sizeof(CHARACTER_INFO);
	pack.ph.type = PACKET_CHAR_DROP;

	CHARACTER_INFO info;
	info.iData[0] = 777;
	info.iIndex = 555;
	strcpy_s(info.szName, "Name");
	memcpy(pack.msg, &info, sizeof(info));

	BroadCastting(user, &pack);

	UserDel(user);
	LeaveCriticalSection(&g_crit);
	return 0;
}
void main()
{
	InitializeCriticalSection (&g_crit);

	//윈속 초기화
	WSADATA wsa;
	int iRet;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return;
	}
	
	//		socket(주소체계,소켓타입 , 프로토콜 지정)
	//sock = socket(AF_INET, SOCK_STREAM/SOCK_DGRAM, 0);
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, 0);	//리스닝소켓 생성
	SOCKADDR_IN sa;

	sa.sin_family = AF_INET;
	sa.sin_port = htons(10000);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	iRet = bind(listenSock, (SOCKADDR*)&sa, sizeof(sa));	//bind
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	iRet = listen(listenSock, SOMAXCONN);					//listen
	if (iRet == SOCKET_ERROR)
	{
		return;
	}

	SOCKADDR_IN clientAddr;
	SOCKET  client;
	while (1)
	{
		

		int addlength = sizeof(clientAddr);
		//accept는 접속되어야만 반환한다.
		//블록형 함수
		client = accept(listenSock, (SOCKADDR*)&clientAddr, &addlength);		//accept
		printf("\nClient Connect! ip = %s, port = %d",
			inet_ntoa(clientAddr.sin_addr), 
			ntohs(clientAddr.sin_port));

		KUser* user = new KUser;
		user->client = client;
		user->clientAddr = clientAddr;
		

		DWORD dwSendThreadID;
		UPACKET pack;
		pack.ph.len = PACKET_HEADER_SIZE;
		pack.ph.type = PACKET_CHAR_JOIN;

		int iSendbyte = send(client, (char*)&pack, pack.ph.len, 0);

		g_UserList.push_back(user);

		CloseHandle(CreateThread(0, 0, ClientThread, (LPVOID)user, 0, &dwSendThreadID));
	}
	closesocket(listenSock);													//리스닝 소켓 해제
	//윈속 해제
	WSACleanup();

	DeleteCriticalSection(&g_crit);
}