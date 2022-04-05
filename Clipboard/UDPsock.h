#pragma once
class UDPsock
{
public:
	UDPsock(unsigned short Port);
	UDPsock(const wchar_t* adr_char, unsigned short Port);
	~UDPsock();

	void receive(int BufLen, char* RecvBuf);
	void send(int BufLen, char* RecvBuf, const wchar_t* adr_char, unsigned short Port);

private:

	SOCKET RecvSocket;


	struct sockaddr_in RecvAddr;
	struct sockaddr_in SenderAddr;

	int SenderAddrSize = sizeof(SenderAddr);

	

	
};

