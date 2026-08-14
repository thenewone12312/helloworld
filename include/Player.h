#pragma once
#include "Object.h"
#include <iostream>
#include <algorithm>

class Player : public Object
{
    private:
        float health;
        float maxHealth;
        float dmg;
        float leniency; //for taking dmg - how much time you have before you can take dmg again

    public:
        Player(Texture* texture);
        Player(Sprite* sprite);
        float getHealthPercent(); //for displaying a healthbar
        void setHealth(float health); //this value is not clamped to maxHealth due to potential overhealing
        void setMaxHealth(float health);
        void addHealth(float change);

        void takeDMG(float dmg = 0.0f, float leniency = 0.0f, float knockback = 1.0f, Object* attacker = nullptr);//default enemy configs ; this could be potentially used to deal KNOCKBACK only, with some tweaking

        void setLeniency(float cooldown);
        void processLeniency(float deltaTime);


        float getDMG();
        void setDMG(float dmg);//too lazy to make a add function lah

};