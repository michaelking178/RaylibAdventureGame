#include "Enemy_Cacto.h"
#include "../raymath.h"

Enemy_Cacto::Enemy_Cacto(Vector2 spawnPos) :
    Enemy(spawnPos)
{
    anim_textures[IDLE]=LoadTexture("Textures\\Characters\\Enemies\\Cacto\\Cacto_Idle.png");
    anim_textures[WALK_DOWN]=LoadTexture("Textures\\Characters\\Enemies\\Cacto\\Cacto_Walk_Down.png");
    anim_textures[WALK_UP]=LoadTexture("Textures\\Characters\\Enemies\\Cacto\\Cacto_Walk_Up.png");
    anim_textures[WALK_LEFT]=LoadTexture("Textures\\Characters\\Enemies\\Cacto\\Cacto_Walk_Left.png");
    anim_textures[WALK_RIGHT]=LoadTexture("Textures\\Characters\\Enemies\\Cacto\\Cacto_Walk_Right.png");
    //anim_textures[ATTACK]=

    ANIM_STATE=IDLE;
    texture=anim_textures[ANIM_STATE];

    width = static_cast<float>(anim_textures[IDLE].width/3);
    height = static_cast<float>(anim_textures[IDLE].height);

    speed = 2.f;
    maxHitpoints = 20;
    damagePerSec = 5;
    scale=3.f;
    hitpoints = maxHitpoints;
}
