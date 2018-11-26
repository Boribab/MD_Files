#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAXBUF 1024
#define MAXLINE 1024

WSADATA wsadata;
int server_sockfd, client_sockfd;
int n, chk = 1;
char buf[MAXBUF], id[MAXBUF], pw[MAXBUF];
struct sockaddr_in clientaddr, serveraddr;
int client_len = sizeof(clientaddr);

int s() {

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		exit(0);
	}

	if ((server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
		perror("socket error : ");
		exit(0);
	}

	memset(&serveraddr, 0, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(3000);

	bind(server_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	listen(server_sockfd, 5);
}

int IDPWcheck() {
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len);
	printf("New Client Connect : %s\n", inet_ntoa(clientaddr.sin_addr));
	memset(id, 0x00, MAXBUF);
	recv(client_sockfd, id, MAXBUF, 0);
	memset(pw, 0x00, MAXBUF);
	recv(client_sockfd, pw, MAXBUF, 0);
}

int s2(const char* iid, const char* ipw) {
	chk &= !strcmp(iid, id);
	chk &= !strcmp(ipw, pw);

	if (!chk) {
		return 0;
	}
	else {
		send(client_sockfd, "로그인 성공!", 14, 0);
		return 1;
	}
}

int closeSocket() {
	closesocket(client_sockfd);
}

int s3(){
	closesocket(server_sockfd);
	WSACleanup();
	return 0;
}