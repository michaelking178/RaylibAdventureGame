#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{
public:
    Enemy(Vector2 spawnPos);
    void Tick(float deltaTime) override;
    void SetPatrolPoints(Vector2 _origin, Vector2 _destination);
    virtual Vector2 GetScreenPos() override;
    void SetTarget(Character* _target);

protected:
    Vector2 patrolPoints[2];
    float detectionRange{5.f};
    Character* target;
    float radius {25.f};
    int damagePerSec{5};
};

#endif