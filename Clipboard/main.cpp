#include "pch.h"
#include "UDPsock.h"
#include "Clipboard.h"



int sock_init();

int main(int argc, char* argv[])
{
	using namespace std;

	sock_init();


	unsigned short port = 5051;



	//char send_buff[10] = {'0','1','2','3','4','5','6','7','8','\0'};
	string ss = Clipboard::GetData();

	char* send_buff = &ss[0];


	//strcpy(send_buff, ss.c_str());

	cout << send_buff << endl;



	int buff_len = 512;
	int a;
	{
		a = 0;
		PerfTimer<std::chrono::milliseconds> v1("first");
	}
	{
		PerfTimer<std::chrono::milliseconds> v2("second");
		UDPsock test(L"192.168.0.101", port);
		test.send(buff_len, send_buff, L"192.168.0.255", port);
	}
	
	
	cout << a << endl;
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