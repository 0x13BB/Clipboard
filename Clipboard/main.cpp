#include "pch.h"
#include "udp_socket.h"
#include "Clipboard.h"
#include "PODstruct.h"


int sock_init();

int main(int argc, char* argv[])
{
	using namespace std;

	sock_init();


	unsigned short port = 5051;

	cout << "enter port in range 1-65535, default 5051\n";
	
	//cin >> port;



	string ss = Clipboard::GetData();

	char* send_buff = &ss[0];


	PODstruct A = PODstruct();
	

	cout << is_pod_v<PODstruct> << '\n';
	cout << sizeof(A) << '\n';
	
	
	cin.ignore();
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


