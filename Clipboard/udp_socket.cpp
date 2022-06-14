#include "pch.h"
#include "udp_socket.h"

udp_socket::udp_socket(unsigned short port)
	: socket_(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))
{
	inner_address_.sin_family = AF_INET;
	inner_address_.sin_port = htons(port);
	inner_address_.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(socket_, reinterpret_cast<SOCKADDR*>(&inner_address_), sizeof(inner_address_));
}

udp_socket::udp_socket(const wchar_t* adr_char, unsigned short port)
	: socket_(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))
{
	inner_address_.sin_family = AF_INET;
	inner_address_.sin_port = htons(port);
	//inner_addr_.sin_addr.s_addr = inet_addr(adr_char);
	InetPton(AF_INET, adr_char, &inner_address_.sin_addr);

	bind(socket_, reinterpret_cast<SOCKADDR*>(&inner_address_), sizeof(inner_address_));
}

udp_socket::~udp_socket()
{
	closesocket(socket_);
}

void udp_socket::receive(int buffer_length, char* receive_buffer)
{
	const int error = recvfrom(socket_
	                           , receive_buffer
	                           , buffer_length
	                           , 0
	                           , reinterpret_cast<SOCKADDR*>(&outer_address_)
	                           , &sender_address_size_);

	if (error == SOCKET_ERROR)
	{
		std::cout << WSAGetLastError() << std::endl;
	}
}

void udp_socket::send(const int buffer_length, char* receive_buffer, const wchar_t* address_char,
                      const unsigned short port)
{
	struct sockaddr_in target_addr;

	target_addr.sin_family = AF_INET;
	target_addr.sin_port = htons(port);
	//inner_addr_.sin_addr.s_addr = inet_addr(address_char);
	InetPton(AF_INET, address_char, &target_addr.sin_addr);


	const int error = sendto(socket_
	                         , receive_buffer
	                         , buffer_length
	                         , 0
	                         , reinterpret_cast<SOCKADDR*>(&target_addr)
	                         , sizeof(target_addr));

	if (error == SOCKET_ERROR)
	{
		std::cout << WSAGetLastError() << std::endl;
	}
}
