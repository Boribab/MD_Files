#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAXBUF 1024
#define MAXLINE 1024
int main(int argc, char **argv) {
	WSADATA wsadata;
	int server_sockfd;
	int client_len;
	char buf[MAXBUF];
	struct sockaddr_in clientaddr, serveraddr;
	client_len = sizeof(clientaddr);

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		return 1;
	}
	if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket error : ");
		return 1;
	}
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(3000);
	client_len = sizeof(serveraddr);
	
	if (connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) == -1) {
		perror("connect error : ");
		return 1;
	}
	memset(buf, 0x00, MAXLINE);
	strcpy(buf, "Test");
	if (send(server_sockfd, buf, MAXLINE, 0) <= 0) {
		perror("write error : ");
		return 1;
	}
	getchar();
	closesocket(server_sockfd);
	WSACleanup();
	return 0;
}