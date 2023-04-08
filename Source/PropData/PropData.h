#ifndef PROP_DATA_H
#define PROP_DATA_H

#include <string>
#include "raymath.h"

struct PropData
{
    PropData(std::string _spriteFilePath, Vector2 _spritePos, int _width, int _height);
    const std::string spriteFilePath;
    const Vector2 spritePos;
    const int width;
    const int height;
};

#endif