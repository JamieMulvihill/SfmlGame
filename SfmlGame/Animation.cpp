#include "Animation.h"

// Constructor. Sets initial values.
Animation::Animation()
{
	currentFrame = 0;
	elapsedTime = 0.f;
	isPlaying = true;
	isLooping = true;

}

// Adds animation frame. Rect object represent a single sprite frame
void Animation::addFrame(sf::IntRect rect)
{
	frames.push_back(rect);
}

// Returns the size of the animation. The number of frames.
int Animation::getSize()
{
	return frames.size();
}

// Get current frame from the animation. Flip the returning frame if required.
sf::IntRect Animation::getCurrentFrame()
{
	frame = frames[currentFrame];

	// if flipped horizontally
	if (flipped)
	{
		frame = sf::IntRect(frame.left + frame.width, frame.top, -frame.width, frame.height);
	}
	// if flipped vertically
	if (gFlipped) {
		frame = sf::IntRect(frame.left, frame.top + frame.height, frame.width, -frame.height);
	}
	// if flipped both vertically and horizontally
	if (flipped && gFlipped) {
		frame = sf::IntRect(frame.left + frame.width, frame.top + frame.height, -frame.width, -frame.height);
	}
	return frame;
}

// Check if the animation should progress, if so move to next frame, or loop back to the start
void Animation::animate(float dt)
{
	if (isPlaying)
	{
		elapsedTime += dt;
		if (elapsedTime >= animationSpeed)
		{
			currentFrame++;
			if (currentFrame >= (int)frames.size())
			{
				if (isLooping)
				{
					currentFrame = 0;
				}
				else
				{
					currentFrame--;
				}
			}
			elapsedTime = 0;
		}
	}
}

// Reset animation.
void Animation::reset()
{
	currentFrame = 0;
	elapsedTime = 0;
}

// Set animation speed, in Frames per Second.
void Animation::setFrameSpeed(float speed)
{
	animationSpeed = speed;
}