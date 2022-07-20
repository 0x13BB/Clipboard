#include "pch.h"
#include "udp_socket.h"
#include "Clipboard.h"
#include "PODstruct.h"
#include "Converter.h"
#include <random>
#include "Pocket_builder.h"

int sock_init();

void async_sender_function();

uint64_t get_unique_number();

int main(int argc, char* argv[])
{
	using std::cout;
	using std::cin;

	sock_init();
	
	

	std::string str = Clipboard::GetData();

	auto vec = Converter::string_to_char_arrays(str);

	auto pck = Pocket_builder::create_single_pocket(0, 1, 1, 1, vec[0]);

	for (size_t i = 0; i < 512; i++)
	{
		cout << pck[0][i];
	}


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

//void key_press_event_block_listener()
//{
//	if (RegisterHotKey(NULL, 1, MOD_CONTROL, 0x43))
//	{
//		std::cout << "registered\n";
//	}
//	else
//	{
//		std::cout << "Error code " << GetLastError();
//	}
//
//	udp_socket soc1(5051);
//	char bf[512] = "abcdef\n";
//	//bf = "abcdef\n";
//	const wchar_t* adr = L"192.168.0.255";
//
//
//	MSG msg = { 0 };
//	while (GetMessage(&msg, NULL, 0, 0) != 0)
//	{
//		std::cout << "\nMessage:" << msg.message;
//		if (msg.message == WM_HOTKEY)
//		{
//			//std::cout << " pressed";
//			//break;
//			soc1.send(512, bf, adr,5051);
//		}
//	}
//}

void async_sender_function()
{

	udp_socket soc1(5051);
	char bf[512] = "abcdef\n";
	const wchar_t* adr = L"192.168.0.255";




	if (RegisterHotKey(NULL, 1, MOD_CONTROL, 0x43))
	{
		std::cout << "registered\n";
	}
	else
	{
		std::cout << "Error code " << GetLastError();
	}

	


	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		std::cout << "\nMessage:" << msg.message;
		if (msg.message == WM_HOTKEY)
		{
			//std::cout << " pressed";
			//break;
			soc1.send(512, bf, adr, 5051);
		}
	}
}

uint64_t get_unique_number()
{
	static uint64_t old_unix_time;
	static uint64_t counter = 0;

	uint64_t unix_time = std::time(nullptr) * 10000;

	if (unix_time + counter > old_unix_time + counter)
	{
		old_unix_time = unix_time;
		counter = 0;
		return old_unix_time;
	}
	else
	{
		++counter;
		old_unix_time = unix_time + counter;
		return old_unix_time;
	}
}



