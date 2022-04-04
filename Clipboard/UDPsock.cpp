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

UDPsock::UDPsock(const wchar_t* adr_char, unsigned short Port)
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

void UDPsock::receive(int BufLen, char* RecvBuf)
{
	int err = recvfrom(RecvSocket
		, RecvBuf
		, BufLen
		, 0
		, reinterpret_cast<SOCKADDR*>(&SenderAddr)
		, &SenderAddrSize);
	if (err == SOCKET_ERROR)
	{
		std::cout << WSAGetLastError() << std::endl;
	}

}

void UDPsock::send(int BufLen, char* RecvBuf, const wchar_t* adr_char, unsigned short Port)
{
	struct sockaddr_in target_addr;

	target_addr.sin_family = AF_INET;
	target_addr.sin_port = htons(Port);
	//RecvAddr.sin_addr.s_addr = inet_addr(adr_char);
	InetPton(AF_INET, adr_char, &target_addr.sin_addr);


	int err = sendto(RecvSocket
		, RecvBuf
		, BufLen
		, 0
		, reinterpret_cast<SOCKADDR*>(&target_addr)
		, sizeof(target_addr));
	if (err == SOCKET_ERROR)
	{
		std::cout << WSAGetLastError() << std::endl;
	}
	
}
