#include "PropFactory.h"
#include "raymath.h"

PropFactory::PropFactory()
{}

Prop PropFactory::CreateProp(const PropData& pd, float scale, Vector2 worldPos)
{
    return Prop{
        LoadTexture(pd.spriteFilePath),
        pd.spritePos,
        pd.spriteSize,
        scale,
        worldPos
    };
}