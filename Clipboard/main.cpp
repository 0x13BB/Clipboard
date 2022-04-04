#include "pch.h"
#include "UDPsock.h"

int sock_init();

int main(int argc, char* argv[])
{
	using namespace std;

	sock_init();

	//const wchar_t* addr = L"192.168.0.255";
	unsigned short port = 5051;

	int buff_len = 1024;

	char send_buff[1024] = {"4"};

	memset(send_buff, 'A', buff_len);

	cout << send_buff << endl;

	UDPsock test(port, L"192.168.0.101");
	test.send(buff_len, send_buff, port, L"192.168.0.255");
	

	cin.get();
	WSACleanup();
	return 0;
}


int sock_init()
{
	static WSADATA wsa_data;

	// Initialize Winsock
	int const err_result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (err_result != 0) {
		std::cout << "WSAStartup failed: " << err_result;
		return 1;
	}



	
	
	return 0;
}