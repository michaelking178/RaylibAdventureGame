#include "Character.h"
#include "raymath.h"

Character::Character()
{}

void Character::Tick(float deltaTime)
{
    if(isAttacking)
        maxFrames = 4;
    else
        maxFrames = 3;
    width = static_cast<float>(anim_textures[ANIM_STATE].width/maxFrames);
    height = static_cast<float>(anim_textures[ANIM_STATE].height);

    worldPosLastFrame = worldPos;
    if (Vector2Length(velocity) != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));

        if (velocity.y > 0.f && std::abs(velocity.y) >= std::abs(velocity.x)*.5f)
            ANIM_STATE=WALK_DOWN;
        else if (velocity.y < 0.f && std::abs(velocity.y) >= std::abs(velocity.x)*.5f)
            ANIM_STATE=WALK_UP;
        else if (velocity.x < 0.f)
            ANIM_STATE=WALK_LEFT;
        else if (velocity.x > 0.f)
            ANIM_STATE=WALK_RIGHT;
    }
    // else
    //     ANIM_STATE=IDLE;

    // Update Anim
    texture=anim_textures[ANIM_STATE];
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        if (velocity.x==0.f && velocity.y==0.f && !isAttacking)
            frame=1;
        else
            frame++;
        runningTime = 0.0f;
        if (frame > maxFrames)
        {
            frame=0;
            if(isAttacking) FinishAttack();
        }
    }
    velocity = {};

    // Draw Character
    Rectangle source{
        .x = frame * width,
        .y = 0.f,
        .width = width,
        .height = height};
    Rectangle dest{
        .x = GetScreenPos().x,
        .y = GetScreenPos().y,
        .width = scale * width,
        .height = scale * height};
        DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

Vector2 Character::GetWorldPos()
{
    return worldPos;
}

void Character::UndoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::GetCollisionRect()
{
    return {
        GetScreenPos().x + 15,
        GetScreenPos().y + 80,
        width * scale * 0.7f,
        height * scale * 0.4f
    };
}

void Character::TakeDamage(int _damage)
{
    hitpoints -= _damage;
    if (hitpoints <= 0.0f)
        SetAlive(false);
}

void Character::Attack()
{
    isAttacking=true;
    switch (ANIM_STATE) {
        case WALK_DOWN:
            ANIM_STATE = ATTACK_DOWN;
            break;
        case WALK_UP:
            ANIM_STATE = ATTACK_UP;
            break;
        case WALK_LEFT:
            ANIM_STATE = ATTACK_LEFT;
            break;
        case WALK_RIGHT:
            ANIM_STATE = ATTACK_RIGHT;
            break;
        default:
            break;
    }
}

void Character::FinishAttack()
{
    isAttacking=false;
    switch (ANIM_STATE) {
        case ATTACK_DOWN:
            ANIM_STATE = WALK_DOWN;
            break;
        case ATTACK_UP:
            ANIM_STATE = WALK_UP;
            break;
        case ATTACK_LEFT:
            ANIM_STATE = WALK_LEFT;
            break;
        case ATTACK_RIGHT:
            ANIM_STATE = WALK_RIGHT;
            break;
        default:
            break;
    }
}