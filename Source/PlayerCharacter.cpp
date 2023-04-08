#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
{
    anim_textures[IDLE]=LoadTexture("Textures\\Characters\\Player\\Player_Idle.png");
    anim_textures[WALK_DOWN]=LoadTexture("Textures\\Characters\\Player\\Player_Walk_Down.png");
    anim_textures[WALK_UP]=LoadTexture("Textures\\Characters\\Player\\Player_Walk_Up.png");
    anim_textures[WALK_LEFT]=LoadTexture("Textures\\Characters\\Player\\Player_Walk_Left.png");
    anim_textures[WALK_RIGHT]=LoadTexture("Textures\\Characters\\Player\\Player_Walk_Right.png");
    //anim_textures[ATTACK]=

    ANIM_STATE=IDLE;
    texture=anim_textures[ANIM_STATE];

    width = static_cast<float>(anim_textures[IDLE].width/3);
    height = static_cast<float>(anim_textures[IDLE].height);
    speed = 7.5f;
}

void PlayerCharacter::Tick(float deltaTime)
{
    if (!GetAlive()) return;
    Character::Tick(deltaTime);

    // Player Controls
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        velocity.x -= speed;
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        velocity.x += speed;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        velocity.y -= speed;
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        velocity.y += speed;
}

Vector2 PlayerCharacter::GetScreenPos()
{
    return {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)
    };
}