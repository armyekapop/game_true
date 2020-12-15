#pragma once
#include <SFML/Graphics.hpp>
#include<math.h>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, float deltaTime, bool faceRight);
	void updateBu(int row, float deltaTime);
	void updatestar(int row, float deltaTime);
	void updateItemBloodup(int row, float deltaTime);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};
