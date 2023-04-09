#include "BaseActor.h"

BaseActor::BaseActor()
{}

void BaseActor::DrawCollisionRect(Rectangle rect)
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, RED);
}

Vector2 BaseActor::GetWorldPos()
{
    return worldPos;
}

void BaseActor::Draw(Vector2 playerPos)
{
    DrawText("BASEACTOR DRAW", worldPos.x, worldPos.y, 50, BLACK);
}