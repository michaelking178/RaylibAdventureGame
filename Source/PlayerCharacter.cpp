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
    anim_textures[ATTACK_DOWN]=LoadTexture("Textures\\Characters\\Player\\Player_Attack_Down.png");
    anim_textures[ATTACK_UP]=LoadTexture("Textures\\Characters\\Player\\Player_Attack_Up.png");
    anim_textures[ATTACK_LEFT]=LoadTexture("Textures\\Characters\\Player\\Player_Attack_Right.png");
    anim_textures[ATTACK_RIGHT]=LoadTexture("Textures\\Characters\\Player\\Player_Attack_Right.png");

    ANIM_STATE=WALK_DOWN;
    texture=anim_textures[ANIM_STATE];

    spriteWidth = static_cast<float>(anim_textures[ANIM_STATE].width/maxFrames);
    spriteHeight = static_cast<float>(anim_textures[ANIM_STATE].height);
    speed = 7.5f;
    toolSocket = Vector2{8.f, 26.f};
    name = "Player";
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
    
    if (IsKeyPressed(KEY_LEFT_CONTROL))
    {
        Attack();
    }
}

Vector2 PlayerCharacter::GetScreenPos()
{
    return {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * spriteWidth),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * spriteHeight)
    };
}