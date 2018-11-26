#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int do_HTON(int *ivar) {
	char *p = (char *)ivar;
	int i = 0;
	printf("\n Before htonl : ");
	for (i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));

	printf("    Value of i : %d", *ivar);
	printf("\n\n After htonl : ");
	*ivar = htonl(*ivar);
	
	for (i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));
	printf("    Value of i : %d", *ivar);
	printf("\n");
}

int do_NTOH(int *ivar) {
	char *p = (char *)ivar;
	int i = 0;
	printf("\n Before ntohl : ");
	for (i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));

	printf("    Value of i : %d", *ivar);
	printf("\n\n After ntohl : ");
	*ivar = ntohl(*ivar);

	for (i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));
	printf("    Value of i : %d", *ivar);
	printf("\n");
}

int main() {
	int ivar = 3;
	do_HTON(&ivar);
	do_NTOH(&ivar);
}