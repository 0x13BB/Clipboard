#pragma once
class UDPsock
{
public:
	UDPsock(unsigned short Port);
	UDPsock(unsigned short Port, const wchar_t* adr_char);
	~UDPsock();

	void receive(int BufLen, char* RecvBuf);
	void send(int BufLen, char* RecvBuf, unsigned short Port, const wchar_t* adr_char);

private:

	SOCKET RecvSocket;


	struct sockaddr_in RecvAddr;
	struct sockaddr_in SenderAddr;

	int SenderAddrSize = sizeof(SenderAddr);

	char RecvBuf[1024];
	int BufLen = 1024;

	
};

