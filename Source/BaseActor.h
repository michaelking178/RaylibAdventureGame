#ifndef BASE_ACTOR_H
#define BASE_ACTOR_H

#include "raylib.h"

class BaseActor
{
public:
    BaseActor();

protected:
    float spriteWidth{0.f};
    float spriteHeight{0.f};
    Vector2 worldPos{};
    const char* name{};
    float scale{4.f};

public:
    virtual void Tick(float deltaTime) {};
    virtual void Draw(Vector2 playerPos);
    const char* GetName() { return name; }

    // Returns the unscaled height of the BaseActor's sprite
    float GetHeight() { return spriteHeight; }

    // Returns the world scale factor applied to the BaseActor's sprite
    float GetScale() { return scale; }

    // Returns the world position of the BaseActor
    Vector2 GetWorldPos();

    // Draw Collision Rect for debugging
    void DrawCollisionRect(Rectangle rect);
};

#endif