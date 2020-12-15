#include "Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->numStar = 0;
    this->speed = 400.0f;
    this->jumpHeight = jumpHeight;
    this->buffX10 = false;
    this->sound = false;
    this->buffTimer = 0;
    this->checkjump = 0;

    row = 0;
    faceRight = true;
    bullet = false;

    body.setSize(sf::Vector2f(150.0f, 60.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(200.0f, 520.0f);
    body.setTexture(texture);

}

Player::~Player()
{
}

void Player::update(float deltaTime, std::vector<star*>& stars, std::vector<Buff>& X2Vector)
{
    velocity.y = 1.0f;
    velocity.x = 1.0f;

    int a = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
        a = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->body.getPosition().x <= 1080 - 60) {
        velocity.x = speed * a;
        faceRight = true;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.x = -speed * a;
        faceRight = false;
        //&& this->body.getPosition().x >= 60

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && this->body.getPosition().y >= 30) {

        velocity.y = -speed * a;

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && this->body.getPosition().y <= 720 - 25) {
        velocity.y = speed * a;


    }


    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);

}


void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f) {
        //left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f) {
        //right
        velocity.x = 0.0f;
    }

    else if (direction.y > 0.0f) {
        //top
        velocity.y = 0.0f;
    }
}
void Player::HPbar(float deltaTime, Player player, sf::Vector2f pos)
{
    body.setPosition(pos.x, pos.y - 50.0f);
    body.setTextureRect(animation.uvRect);
}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Player::SetPosition(float x, float y)
{
    body.setPosition(x, y);
}
void Player::RESET() {
    if (body.getPosition().y >= 600) {
        body.setPosition(200, 520);
    }
}
void Player::ResetNumstar() {
    this->numStar = 0;
    this->buffX10 = false;
}