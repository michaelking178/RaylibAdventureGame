#ifndef CHARACTER_H
#define CHARACTER_H

#include "BaseActor.h"
#include "raylib.h"

class Character : public BaseActor
{
public:
    Character();
    void Tick(float deltaTime) override;
    Vector2 GetWorldPos();
    virtual Vector2 GetScreenPos() = 0;
    void UndoMovement();
    Rectangle GetCollisionRect();
    bool GetAlive() {return isAlive;}
    void SetAlive(bool _alive) {isAlive=_alive;}
    void TakeDamage(int _damage);

protected:
    enum ANIM_STATES {IDLE, WALK_DOWN, WALK_UP, WALK_LEFT, WALK_RIGHT, ATTACK};
    ANIM_STATES ANIM_STATE{IDLE};
    Texture2D anim_textures[6];
    Texture2D texture{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    Vector2 velocity{};
    int frame{};
    int maxFrames{2};
    float runningTime{0.f};
    float updateTime{1.f / 12.f};
    float width{};
    float height{};
    float scale{4.f};

    float speed{1.f};
    int hitpoints{1000};
    int maxHitpoints{1000};

private:
    bool isAlive{true};
};

#endif