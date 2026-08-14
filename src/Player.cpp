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
    return std::clamp(this->health/this->maxHealth, 0.0f, 1.0f);
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
    this->health += change;
}

void Player::setLeniency(float cooldown)
{
    this->leniency = cooldown;
}

void Player::processLeniency(float deltaTime)
{
    this->leniency = std::max(0.0f, leniency - deltaTime); //
    //i have no idea how long this'll last. we'll figure that out later
}

float Player::getDMG()
{
    return this->dmg;
}

void Player::setDMG(float dmg)
{
    this->dmg = dmg;
}


void Player::takeDMG(float dmg, float leniency, float knockback, Object* attacker)
{
    if (leniency!=0) return;
    
    this->addHealth(-dmg);
    this->setLeniency(leniency);
    vec2 tempPosition = (this->getPosition() - attacker->getPosition());
    tempPosition.normalize();
    this->addVelocity(tempPosition*knockback);
}