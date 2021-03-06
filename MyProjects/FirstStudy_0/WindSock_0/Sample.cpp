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
	sa.sin_family = AF_INET;
	short iAddress = 10000;
	//inet_pton() or InetPton()
	sa.sin_port = htons(10000);
	sa.sin_addr.s_addr = inet_addr("192.168.0.100");
	int iRet = connect(sock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	char szBuffer[MAX_PATH] = { 0, };
	while (1)
	{
		ZeroMemory(szBuffer, sizeof(char)* MAX_PATH);
		fgets(szBuffer, MAX_PATH, stdin);
		int iMessageSize = strlen(szBuffer);
		int iSendByte = send(sock, szBuffer, iMessageSize, 0);
		printf("\nSendMessage = %s[%d]", szBuffer, iMessageSize);
		int iRecvByte = recv(sock, szBuffer, sizeof(char)*MAX_PATH, 0);
		if (iRecvByte == 0)
		{
			printf("\nServer DisConnect!");
			break;
		}
		printf("\nRecvMessage = %s[%d]", szBuffer, strlen(szBuffer));
	}
	//윈속 해제
	WSACleanup();
}