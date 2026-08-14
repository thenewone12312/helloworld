#include "Player.h"

Player::Player(Texture* texture)
: Object(texture)
{   
   this->maxHealth = 5;
   this->health = this->maxHealth;
}

Player::Player(Sprite* sprite)
: Object(sprite)
{   
    this->maxHealth = 5;
    this->health = this->maxHealth;
}

float Player::getHealthPercent()
{
    return this->health/this->maxHealth;
}

void Player::setHealth(float health)
{
    this->health = health;
}

void Player::setMaxHealth(float health)
{
    this->maxHealth= health;
}

void Player::addHealth(float change)
{
    if (change == 0) return;
    this->maxHealth += change;
}

float Player::getDMG()
{
    return this->dmg;
}

void Player::setDMG(float dmg)
{
    this->dmg = dmg;
}
