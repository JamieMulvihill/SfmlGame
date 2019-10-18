#pragma once
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

// The IP address of the server
#define SERVERIP "127.0.0.1"

// The UDP port number on the server
#define SERVERPORT 4444

// The (fixed) size of message that we send between the two programs
#define MESSAGESIZE 40

class UdpClient {
public:
	UdpClient();
	~UdpClient();

	void SendFucntion(int x, int y);
	void RecieveFucntion();
	float Lerp(float a, float b, float f);

	sf::RectangleShape rec;
	
	Player* players[4];
private:
	char buffer[MESSAGESIZE];
	sf::UdpSocket socket;
	sf::Packet data;
	std::size_t received;
	std::string message;
	int id_;
};
