#pragma once
#include "Object.h"

class Player : public Object
{
    private:
        float health;
        float maxHealth;
        float dmg;

    public:
        Player(Texture* texture);
        Player(Sprite* sprite);
        float getHealthPercent();
        void setHealth(float health);
        void setMaxHealth(float health);
        void addHealth(float change);

        float getDMG();
        void setDMG(float dmg);//too lazy to make a add function lah

};