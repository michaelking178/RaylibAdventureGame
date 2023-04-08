#include "Prop.h"
#include "raymath.h"

Prop::Prop()
{}

Prop::Prop(Texture2D _texture, Vector2 _spritePos, Vector2 _spriteSize, float _scale, Vector2 _worldPos):
    texture(_texture),
    scale(_scale),
    worldPos(_worldPos)
{
    sourceRect = {
        .x = _spritePos.x,
        .y = _spritePos.y,
        .width = _spriteSize.x,
        .height = _spriteSize.y
    };
}

void Prop::Render(Vector2 playerPos)
{
    Vector2 screenPos = Vector2Subtract(worldPos, playerPos);
    destRect = {
        .x = screenPos.x,
        .y = screenPos.y,
        .width = sourceRect.width * scale,
        .height = sourceRect.height * scale
    };
    DrawTexturePro(texture, sourceRect, destRect, Vector2{}, 0.f, WHITE);
}

Rectangle Prop::GetCollisionRect(Vector2 playerPos)
{
    Vector2 screenPos = Vector2Subtract(worldPos, playerPos);
    Rectangle rect {
        screenPos.x,
        screenPos.y,
        sourceRect.width * scale * 0.85f,
        sourceRect.height * scale * 0.6f
    };
    return Rectangle {
        rect.x + (rect.width * 0.125f),
        rect.y + (rect.height * 0.35f),
        rect.width,
        rect.height
    };
}