#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

void main()
{
	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return;
	}
	SOCKET sock;
	//		socket(주소체계,소켓타입 , 프로토콜 지정)
	//sock = socket(AF_INET, SOCK_STREAM, 0);
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	//SOCKADDR sa;
	SOCKADDR_IN sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	short iAddress = 10000;
	//inet_pton() or InetPton()
	sa.sin_port = htons(10000);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr("192.168.0.23");
	int iRet = bind(sock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	iRet = listen(sock, SOMAXCONN);
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	SOCKADDR_IN clientAddr;
	SOCKET client;
	while (1)
	{
		int addlength = sizeof(clientAddr);
		//accept는 접속되어야만 반환한다.
		//블록형 함수
		client = accept(sock, (SOCKADDR*)&clientAddr, &addlength);
		printf("\nClient Connect! ip = %s, port = %d",
			inet_ntoa(clientAddr.sin_addr),
			ntohs(clientAddr.sin_port));

		char szBuffer[MAX_PATH] = { 0, };
		while (1)
		{
			ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
			
			int iRecvByte = recv(client, szBuffer, sizeof(char)*MAX_PATH,0);
			if (iRecvByte == SOCKET_ERROR)
			{
				break;
			}
			printf("\nRecv Message = %s", szBuffer);
			int iSendByte = send(client, szBuffer, strlen(szBuffer), 0);
			if (iSendByte == SOCKET_ERROR)
			{
				break;
			}
			printf("\nSend Message = %s", szBuffer);
			if (iRecvByte == 0)
			{
				printf("\nClient DisConnect! ip = %s, port = %d",
					inet_ntoa(clientAddr.sin_addr),
					ntohs(clientAddr.sin_port));
				break;
			}
		}
	}
	//윈속 해제
	WSACleanup();
}