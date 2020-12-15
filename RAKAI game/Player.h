#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Collision.h"
#include "star.h"
#include "Buff.h"

#pragma once
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	sf::Sound Soundss;
	sf::SoundBuffer soundstar;
	void update(float deltaTime, std::vector<star*>& stars, std::vector<Buff>& X2Vector);
	void updateNumstar(float deltaTime, std::vector<star*>& stars, std::vector<Buff>& X2Vector);
	int EndGameover() { return int(body.getPosition().x - 200); }
	bool getBuffStatus() { return this->buffX10; }
	bool soundStatus() { return this->sound; }
	void Draw(sf::RenderWindow& window);
	void ResetNumstar();
	void OnCollision(sf::Vector2f direction);
	int  getcheck() { return this->check; }
	void HPbar(float deltaTime, Player player, sf::Vector2f pos);
	void SetPosition(float x, float y);
	void RESET();



	sf::Vector2f GetPosition() { return body.getPosition(); }//view
	Collision GetCollider() { return Collision(body); }

private:

	int numStar;
	int checkjump;
	float speed;
	float damage;
	bool sound;
	bool faceRight;
	bool bullet;
	bool buffX10;
	int check = 0;
	unsigned int row;

	sf::RectangleShape body;
	Animation animation;

	float buffTimer = 0;
	sf::Clock clock;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};