#include "Net.h"
#include <winsock2.h>
#include <iostream>

#define PORT1 28000
#define PORT2 28001

int __cdecl main(int argc, char **argv)
{
	char * ip = "127.0.0.1";

	char input[200];
	char message[200];

	Net net = Net();
	net.initialise();
	net.setupUDP(PORT1, ip);

	Net net2 = Net();
	net2.initialise();
	net2.setupUDP(PORT2, ip);

	std::cin >> input;
	net.sendData(ip, PORT2, input);
	std::cout << net2.receiveData(message) << std::endl;
	std::cout << message << std::endl;
	

	system("PAUSE");
	return 0;
}