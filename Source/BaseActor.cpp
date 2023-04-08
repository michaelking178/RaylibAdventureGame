#include "BaseActor.h"

BaseActor::BaseActor()
{}

void BaseActor::DrawCollisionRect(Rectangle rect)
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, RED);
}