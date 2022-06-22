#include "pch.h"
#include "udp_socket.h"
#include "Clipboard.h"
#include "PODstruct.h"
#include "Converter.h"

int sock_init();

void async_sender_function();

int main(int argc, char* argv[])
{
	using std::cout;
	using std::cin;

	sock_init();
	
	cout << "press ctrl + c\n";

	sizeof(PODstruct);
	cout << std::is_pod_v<PODstruct> << '\n';

	auto test_arr = Converter::string_to_char_arrays(Clipboard::GetData());

	//std::cout << test_arr[0][0];


	auto str1 = Converter::char_arrays_to_string(test_arr);

	cout << str1.find("OD") << '\n';

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
