#include "UdpClient.h"
#include <cmath>

UdpClient::UdpClient()
{
	rec.setPosition(400, 300);
	rec.setSize(sf::Vector2f(64, 64));
	rec.setFillColor(sf::Color::Red);
	std::cout << "I am a client" << std::endl;
	socket.setBlocking(false);
}

UdpClient::~UdpClient()
{
}

void UdpClient::SendFucntion(int x, int y) {

	message.append(std::to_string(x));
	message += "#";
	message.append(std::to_string(y));

	sf::IpAddress recipient = SERVERIP;
	unsigned short port = SERVERPORT;
	if (socket.send(message.c_str(), message.length(), recipient, port) != sf::Socket::Done)
	{
		// error...
		printf("Fuck my life...sned");
	}
	else {
		message.clear();
	}

}

void UdpClient::RecieveFucntion() {

	// UDP socket:
	sf::IpAddress sender = SERVERIP;
	unsigned short port;
	if (socket.receive(buffer, MESSAGESIZE, received, sender, port) != sf::Socket::Done)
	{
		// error...
		printf("Fuck my life...Reviex");
	}
	else {
		printf("Got Message from server\n");
		printf(buffer);
		std::string positionX, positionY;

		bool stillX = true;
		for (int i = 0; i < received; i++) {
			if (stillX && buffer[i] != '#') {
				positionX += buffer[i];
			}
			else if (!stillX && buffer[i] != '#') {
				positionY += buffer[i];
			}
			else {
				stillX = false;
			}
		}

		rec.setPosition(std::stoi(positionX), std::stoi(positionY));
		printf("\n");
	}
}

float UdpClient::Lerp(float a, float b, float t)
{
	return (a * (1.0 - t)) + (b * t);
}
