#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "Character.h"

class PlayerCharacter : public Character
{
public:
    PlayerCharacter(int winWidth, int winHeight);
    void Tick(float deltaTime) override;
    virtual Vector2 GetScreenPos() override;
    Rectangle GetWeaponCollisionRect() const {return weaponCollisionRec;};
    float GetHealth() const {return hitpoints;}
    float GetMaxHealth() const {return maxHitpoints;}

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon {};
    Rectangle weaponCollisionRec{};
};

#endif