#ifndef PROP_DATA_H
#define PROP_DATA_H

#include <string>
#include "raymath.h"

struct PropData
{
    PropData(const char* _spriteFilePath, Vector2 _spritePos, Vector2 _spriteSize);
    const char* spriteFilePath;
    const Vector2 spritePos;
    const Vector2 spriteSize;
};

#endif