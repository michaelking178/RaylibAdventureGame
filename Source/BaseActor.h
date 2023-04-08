#ifndef BASE_ACTOR_H
#define BASE_ACTOR_H

#include "raylib.h"

class BaseActor
{
public:
    BaseActor();
    virtual void Tick(float deltaTime) {};
    void DrawCollisionRect(Rectangle rect); // Debug
};

#endif