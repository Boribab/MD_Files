#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAXBUF 1024
int main(int argc, char **argv) {
	WSADATA wsadata;
	int server_sockfd, client_sockfd;
	int client_len, n;
	char buf[MAXBUF];
	struct sockaddr_in clientaddr, serveraddr;
	client_len = sizeof(clientaddr);

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		return 1;
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

	memset(buf, 0x00, MAXBUF);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len);
	printf("New Client Connect : %s\n", inet_ntoa(clientaddr.sin_addr));
	while (1) {
		if ((n = recv(client_sockfd, buf, MAXBUF, 0)) <= 0) {
			getchar();
			closesocket(client_sockfd);
			break;
		}
	}
	closesocket(server_sockfd);
	WSACleanup();
	return 0;
}