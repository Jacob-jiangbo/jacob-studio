#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	short s = 0x1234;
	long L = 0x23456789;
	printf("s=%x, L=%x\n", s, L);
	printf("first byte:%x, %x\n", *(char*)&s, *(unsigned char*)&L);
	s = htons(s);
	L = htonl(L);
	printf("s=%x, L=%x\n", s, L);
	printf("first byte:%x, %x\n", *(char*)&s, *(unsigned char*)&L);
	s = ntohs(s);
	L = ntohl(L);
	printf("s=%x, L=%x\n", s, L);
	printf("first byte:%x, %x\n", *(char*)&s, *(unsigned char*)&L);
	return 0;
}

