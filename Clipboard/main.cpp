#include "pch.h"

int sock_init();

int main(int argc, char* argv[])
{
	using namespace std;

	sock_init();
	

	cin.get();
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



	
	WSACleanup();
	return 0;
}