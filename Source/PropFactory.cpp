#include "PropFactory.h"
#include "raymath.h"

PropFactory::PropFactory()
{}

Prop PropFactory::CreateProp(Texture2D _texture, Vector2 _spritePos, Vector2 _spriteSize, float _scale, Vector2 _worldPos)
{
    return Prop{_texture, _spritePos, _spriteSize, _scale, _worldPos};
}