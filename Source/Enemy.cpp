#include "Enemy.h"
#include "../raymath.h"

Enemy::Enemy(Vector2 spawnPos)
{
    worldPos=spawnPos;
}

void Enemy::SetPatrolPoints(Vector2 _origin, Vector2 _destination)
{
    patrolPoints[0]=_origin;
    patrolPoints[1]=_destination;
}

Vector2 Enemy::GetScreenPos()
{
    return Vector2Subtract(worldPos, target->GetWorldPos());
}

void Enemy::Tick(float deltaTime)
{
    if(!GetAlive()) return;
    Character::Tick(deltaTime);

    velocity = Vector2Subtract(target->GetScreenPos(), GetScreenPos());
    if (Vector2Length(velocity) < radius)
        velocity = {};
    

    if (CheckCollisionRecs(target->GetCollisionRect(), GetCollisionRect()))
        target->TakeDamage(damagePerSec);
}

void Enemy::SetTarget(Character* _target)
{
    target=_target;
}