#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "Engine/Transform.h"

#pragma comment( lib, "ws2_32.lib")

const unsigned short SERVERPORT = 8888;

const unsigned int MESSAGELENGTH = 1024;

struct SendElement
{
	Transform playerPos;
	std::vector<Transform> bulletPos;
};

class Socket
{
	int sock;
public:
	bool Init();
	bool InitSocket(int sockType);
	bool Connect(std::string serverIpv4Address, unsigned short port);
	bool Send(SendElement _elem);
	bool Recv(SendElement *_elem);
	bool Exit();
};

