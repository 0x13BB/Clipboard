#include "pch.h"
#include "UDPsock.h"
#include "Clipboard.h"
#include <charconv>

int sock_init();

int main(int argc, char* argv[])
{
	using namespace std;

	sock_init();

	
	unsigned short port = 5051;

	

	char send_buff[10] = {'0','1','2','3','4','5','6','7','8','\0'};
	
	
	cout << send_buff << endl;

	//std::memset(send_buff, '9', strlen(send_buff));

	int buff_len = strlen(send_buff)+1;
	

	UDPsock test(L"192.168.0.101", port);
	test.send(buff_len, send_buff, L"192.168.0.127", port);
	

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