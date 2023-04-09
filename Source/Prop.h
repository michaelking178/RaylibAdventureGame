#ifndef PROP_H
#define PROP_H

#include "BaseActor.h"
#include "raylib.h"

class Prop : public BaseActor
{
public:
    Prop();
    Prop(Texture2D _texture, Vector2 _spritePos, Vector2 _spriteSize, float _scale, Vector2 _worldPos);
    void Draw(Vector2 playerPos);
    Rectangle GetCollisionRect(Vector2 playerPos);

private:
    Texture2D texture{};
    Rectangle sourceRect{};
    Rectangle destRect{};
};

#endif