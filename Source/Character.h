#ifndef CHARACTER_H
#define CHARACTER_H

#include "BaseActor.h"
#include <map>

class Character : public BaseActor
{
public:
    Character();

private:
    bool isAlive{true};
    bool isAttacking{false};

protected:
    enum ANIM_STATES {
        IDLE, 
        WALK_DOWN, WALK_UP, WALK_LEFT, WALK_RIGHT,
        ATTACK_DOWN, ATTACK_UP, ATTACK_LEFT, ATTACK_RIGHT
    };
    ANIM_STATES ANIM_STATE{IDLE};
    Texture2D anim_textures[9];
    Texture2D texture{};
    Vector2 worldPosLastFrame{};
    Vector2 velocity{};
    Vector2 toolSocket{};
    int frame{};
    int maxFrames{2};
    int hitpoints{1000};
    int maxHitpoints{1000};
    float runningTime{0.f};
    float updateTime{1.f / 12.f};
    float speed{1.f};

public:
    void Tick(float deltaTime) override;
    void Draw(Vector2 playerPos) override;
    Vector2 GetWorldPos();
    virtual Vector2 GetScreenPos() = 0;
    void UndoMovement();
    Rectangle GetCollisionRect();
    bool GetAlive() {return isAlive;}
    void SetAlive(bool _alive) {isAlive=_alive;}
    void TakeDamage(int _damage);
    void Attack();
    void FinishAttack();
};

#endif