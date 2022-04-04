#include "pch.h"
#include "UDPsock.h"

UDPsock::UDPsock(unsigned short Port)
	: RecvSocket(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))
{
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(Port);
	RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(RecvSocket, reinterpret_cast<SOCKADDR*>(&RecvAddr), sizeof(RecvAddr));
}

UDPsock::UDPsock(unsigned short Port, const wchar_t* adr_char)
	: RecvSocket(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))
{
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(Port);
	//RecvAddr.sin_addr.s_addr = inet_addr(adr_char);
	InetPton(AF_INET, adr_char, &RecvAddr.sin_addr);

	bind(RecvSocket, reinterpret_cast<SOCKADDR*>(&RecvAddr), sizeof(RecvAddr));
}

UDPsock::~UDPsock()
{
	closesocket(RecvSocket);
}

char* UDPsock::receive(int BufLen, char* RecvBuf)
{
	recvfrom(RecvSocket
		, RecvBuf
		, BufLen
		, 0
		, reinterpret_cast<SOCKADDR*>(&SenderAddr)
		, &SenderAddrSize);

	return this->RecvBuf;
}
