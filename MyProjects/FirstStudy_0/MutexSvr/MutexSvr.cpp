// MutexSvr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <list>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

struct KUser
{
	bool			bConnect;
	SOCKET			client;
	SOCKADDR_IN		clientAddr;
};

HANDLE				g_hMutex = NULL;

list<KUser*> g_UserList;

DWORD WINAPI ClientThread(LPVOID data)
{

	KUser* user = (KUser*)data;
	//SOCKET sock = (SOCKET)data;
	char szBuffer[MAX_PATH] = { 0, };
	while (1)
	{
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		int iRecvByte = recv(user->client, szBuffer, MAX_PATH, 0);		//recv
		if (iRecvByte == 0 || iRecvByte == SOCKET_ERROR)
		{
			printf("\nClient Exit!");
			break;
		}
		szBuffer[iRecvByte] = 0;

		printf("\nSendMessage = %s[%s]", szBuffer, inet_ntoa(user->clientAddr.sin_addr));
		DWORD dwRet = WaitForSingleObject(g_hMutex, INFINITE);
		while (dwRet != WAIT_TIMEOUT)
		{
			list<KUser*>::iterator KHead = g_UserList.begin();
			list<KUser*>::iterator KTail = g_UserList.end();
			for (;KHead != KTail;++KHead)
			{
				if ((*KHead) != 0)
				{
					int iSendByte = send((*KHead)->client, szBuffer, iRecvByte, 0);		//send
				}
			}
		}
		ReleaseMutex(g_hMutex);
	}

	WaitForSingleObject(g_hMutex, INFINITE);
	list<KUser*>::iterator KHead = g_UserList.begin();
	list<KUser*>::iterator KTail = g_UserList.end();
	for (;KHead != KTail;++KHead)
	{
		if (user == (*KHead))
		{
			closesocket((*KHead)->client);
			delete(*KHead);
			*KHead = 0;
		}
	}
	ReleaseMutex(g_hMutex);

	return 0;
}
void main()
{
	HANDLE hMutex = CreateMutex(NULL, FALSE, L"KGCA_Mutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hMutex);
		return;
	}
	//���� �ʱ�ȭ
	WSADATA wsa;
	int iRet;
	HANDLE hThread;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return;
	}

	g_hMutex = CreateMutex(NULL, FALSE, L"MAIN_Mutex");
	//		socket(�ּ�ü��,����Ÿ�� , �������� ����)
	//sock = socket(AF_INET, SOCK_STREAM/SOCK_DGRAM, 0);
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, 0);	//�����׼��� ����
	SOCKADDR_IN sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(10000);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	/*iRet = bind(listenSock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR) return;
	iRet = listen(listenSock, SOMAXCONN);
	if (iRet == SOCKET_ERROR) return;*/
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

	while (1)
	{
		KUser* user = new KUser;

		int addlength = sizeof(user->clientAddr);
		//accept�� ���ӵǾ�߸� ��ȯ�Ѵ�.
		//����� �Լ�
		user->client = accept(listenSock, (SOCKADDR*)&(user->clientAddr), &addlength);		//accept
		printf("\nClient Connect! ip = %s, port = %d",
			inet_ntoa(user->clientAddr.sin_addr),
			ntohs(user->clientAddr.sin_port));

		g_UserList.push_back(user);

		DWORD dwRecvThreadID;
		char szBuffer[MAX_PATH] = { 0, };
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		hThread = CreateThread(												//thread ������
			0,
			0,
			ClientThread,
			(LPVOID)user,
			0,
			&dwRecvThreadID);

		WaitForSingleObject(g_hMutex, INFINITE);
		list<KUser*>::iterator KHead = g_UserList.begin();
		while (KHead != g_UserList.end())
		{
			if (*KHead == 0)
			{
				KHead = g_UserList.erase(KHead);
			}
			else
			{
				KHead++;
			}
		}
		ReleaseMutex(g_hMutex);
	}
	closesocket(listenSock);													//������ ���� ����
	CloseHandle(g_hMutex);		
	CloseHandle(hMutex);
	//���� ����
	WSACleanup();
}
