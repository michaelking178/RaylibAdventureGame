#ifndef TOOL_H
#define TOOL_H

// This is going to be the base class for things like weapons and other Character-equipable/usable items.
// Shared traits will include RootPos (socketed to Character), anim basics and some kind of Use() function.

#include "raymath.h"

class Tool
{
public:
    Tool();

protected:
    Vector2 SocketPos;
    Texture2D texture;
};

#endif