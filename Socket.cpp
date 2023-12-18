#include "Socket.h"

bool Socket::Init()
{
	return WSAGetLastError();
}

bool Socket::InitSocket(int sockType)
{
	return WSAGetLastError();
}

bool Socket::Connect(std::string serverIpv4Address, unsigned short port)
{
	return WSAGetLastError();
}

bool Socket::Send(SendElement _elem)
{
	
	return WSAGetLastError();
}

bool Socket::Recv(SendElement* _elem)
{
	SendElement recvElem;
	int ret;

	// 受信
	ret = recv(sock, (char*)&recvElem, sizeof(recvElem), 0);
	// 失敗
	if (ret != sizeof(recvElem))
	{
		return false;
	}

	// 成功時は受信データをバイトオーダーに変換
	*_elem = ntohl(recvElem);
	return true;
	return WSAGetLastError();
}

bool Socket::Exit()
{
	return WSAGetLastError();
}
