#pragma once
class udp_socket
{
public:
	explicit udp_socket(unsigned short port);
	udp_socket(const wchar_t* adr_char, unsigned short port);
	~udp_socket();

	void receive(int buffer_length, char* receive_buffer);
	void send(int buffer_length, char* receive_buffer, const wchar_t* address_char, unsigned short port);

private:
	SOCKET socket_;


	struct sockaddr_in inner_address_;
	struct sockaddr_in outer_address_;

	int sender_address_size_ = sizeof(outer_address_);
};

