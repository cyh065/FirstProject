// Client_0.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <windows.h>
#include "KProtocol.h"
#pragma comment(lib,"ws2_32.lib")

int SendMsg(SOCKET sock, char* msg, WORD type)
{
	UPACKET	sendmsg;
	ZeroMemory(&sendmsg, sizeof(UPACKET));
	sendmsg.ph.type = type;
	sendmsg.ph.len = PACKET_HEADER_SIZE + strlen(msg);
	memcpy(sendmsg.msg, msg, strlen(msg));
	int iSendbyte = 0;
	char* szSend = (char*)&sendmsg;
	while (1)
	{
		iSendbyte +=
			send(sock, szSend, sendmsg.ph.len - iSendbyte, 0);
		if (sendmsg.ph.len == iSendbyte)
		{
			break;
		}
		szSend += iSendbyte;
	}
	return iSendbyte;
}

void PacketProcess(UPACKET* pPacket)
{
	switch (pPacket->ph.type)
	{
		case PACKET_CHAR_MSG:
		{
			printf("RecvMessage=%s", pPacket->msg);
		}break;
		case PACKET_CHAR_JOIN:
		{
			printf("Names");
		}break;
		case PACKET_CHAR_DROP:
		{
			CHARACTER_INFO info;
			memcpy(&info, pPacket->msg, sizeof(CHARACTER_INFO));
			printf("%s Exit", info.szName);
		}break;
	}
}

DWORD WINAPI SendThread(LPVOID data)
{
	SOCKET	sock = (SOCKET)data;
	char	szBuffer[MAX_PATH] = { 0, };
	while (1)
	{
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		fgets(szBuffer, MAX_PATH, stdin);
		if (_stricmp(szBuffer,"exit") == 0) break;
		int iMessageSize = strlen(szBuffer);
		int iRet = SendMsg(sock, szBuffer, PACKET_CHAR_MSG);
		if (iRet == 0 || iRet == SOCKET_ERROR)break;
		Sleep(1);
	}
	closesocket(sock);
	return 0;
}

DWORD WINAPI RecvThread(LPVOID data)
{
	SOCKET	sock = (SOCKET)data;
	char	szBuffer[MAX_PATH] = { 0, };
	int		iRecvData = 0;
	bool	bConnect = true;
	while (bConnect)
	{
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		int iRet = recv(sock, &szBuffer[iRecvData], PACKET_HEADER_SIZE-iRecvData, 0);
		iRecvData += iRet;
		if (iRet == 0 || iRet == SOCKET_ERROR)
		{
			bConnect = false;
			break;
		}
		UPACKET* pPacket = (UPACKET*)&szBuffer;
		if (iRecvData == PACKET_HEADER_SIZE)
		{
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
			PacketProcess(pPacket);
			iRecvData = 0;
		}
		Sleep(1);
	}
	closesocket(sock);
	return 1;
}


void main()

{
	//윈속 초기화
	WSADATA wsa;
	int iRet;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return;
	}
	SOCKET sock;
	//		socket(주소체계,소켓타입 , 프로토콜 지정) 
	sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN sa;
	sa.sin_family = AF_INET;

	//inet_pton() or InetPton()
	sa.sin_port = htons(10000);
	sa.sin_addr.s_addr = inet_addr("192.168.0.26");
	iRet = connect(sock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	
	DWORD dwSendThreadID;
	HANDLE hSendThread = CreateThread(
		0,
		0,
		SendThread,
		(LPVOID)sock,
		0,
		&dwSendThreadID);

	DWORD dwRecvThreadID;
	HANDLE hRecvThread = CreateThread(
		0,
		0,
		RecvThread,
		(LPVOID)sock,
		0,
		&dwRecvThreadID);

	WaitForSingleObject(hRecvThread, INFINITE);
	//윈속 해제
	CloseHandle(hSendThread);
	CloseHandle(hRecvThread);
	WSACleanup();
}
