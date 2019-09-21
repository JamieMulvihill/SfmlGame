
#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Animation
{
public:
	Animation();

	// Create animation
	void addFrame(sf::IntRect rect);
	void setFrameSpeed(float speed);
	int getSize();

	// update/reset animation
	void animate(float dt);
	void reset();

	// get current frame of animation
	sf::IntRect getCurrentFrame();

	// Animation controls
	float getFrameSpeed() { return animationSpeed; };
	void setGravFlip(bool gFlip) { gFlipped = gFlip; };
	bool getGravFlip() { return gFlipped; };
	void setFlipped(bool flip) { flipped = flip; };
	bool getFlipped() { return flipped; };
	void setLooping(bool loop) { isLooping = loop; };
	bool getLooping() { return isLooping; };
	void setPlaying(bool play) { isPlaying = play; };
	bool getPlaying() { return isPlaying; };
	int currentFrame;

protected:
	std::vector<sf::IntRect>frames;
	sf::IntRect frame;


	float animationSpeed;	// in FPS
	bool gFlipped; // bool for flipping sprite vertically
	bool flipped; // bool for flipping spriter horizontally
	bool isLooping;
	bool isPlaying;
	float elapsedTime;

};