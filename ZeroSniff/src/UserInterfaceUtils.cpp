#include "../include/UserInterfaceUtils.h"

int PrintAllDevices() {
	pcap_if* pDev; 
	pcap_if* d;  // for looping through the pcap_if linked list
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_addr* a; // for looping through the pcap_if linked list
	sockaddr_in* ipv4;
	sockaddr_in6 ipv6; 
	char ipstr[INET_ADDRSTRLEN];
	//obtain the device list 
	if (pcap_findalldevs(&pDev, errbuf) == -1) {
		std::cout << "failed to obtain device list . errbuff :" << std::endl << errbuf << std::endl; 
		return -1;
	}
	//loop through the list
	for (d = pDev; d != NULL; d = d->next) {
		std::cout << "[+] " << d->description << std::endl; 
		for (a = d->addresses; a != NULL; a = a->next) {
			switch (a->addr->sa_family) {
			case AF_INET:
				ipv4 = (sockaddr_in*)a->addr; 
				//convert the data to human readable version
				inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, INET_ADDRSTRLEN);
				std::cout << "    [*] " << ipstr << std::endl; 

			}
			
		}
		std::cout << std::endl;
	}
	pcap_freealldevs(pDev);
	return 0;
}


void HandleMenu() {
	//print the menu itself
	bool running = 1; 
	char userOpt; 
	while (running) {
		system("cls");
		std::cout << " _______                      ______       _    ___    ___ \n";
		std::cout << "(_______)                    / _____)     (_)  / __)  / __)\n";
		std::cout << "   __    _____  ____ ___    ( (____  ____  _ _| |__ _| |__ \n";
		std::cout << "  / /   | ___ |/ ___) _ \\    \____ \\ |  _ \\| (_   __|_   __)\n";
		std::cout << " / /____| ____| |  | |_| |   _____) ) | | | | | |    | |   \n";
		std::cout << "(_______)_____)_|   \\___/   (______/|_| |_|_| |_|    |_|   \n";
		std::cout << "                                                           \n" << std::endl << std::endl;
		std::cout << "[1] List of Devices" << std::endl;
		std::cout << "[2] Exit" << std::endl;
		userOpt = _getch();
		switch (userOpt) {
		case '1':
			system("cls");
			PrintAllDevices();
			std::cout << "----------------------------------------------\n" << "Enter anything to back to main menu\n" << "----------------------------------------------\n";
			_getch();
			break;
		case '2' : 
			system("cls");
			exit(0);
		}
	}
}
