#ifndef PROP_FACTORY_H
#define PROP_FACTORY_H

#include "raylib.h"
#include "Prop.h"

class PropFactory
{
public:
    PropFactory();
    Prop CreateProps();
    Prop CreateProp(Texture2D _texture, Vector2 _spritePos, Vector2 _spriteSize, float _scale, Vector2 _worldPos);

private:
    
};

#endif