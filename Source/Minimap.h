#ifndef MINIMAP_H
#define MINIMAP_H

#include "PlayerCharacter.h"
#include "raylib.h"
#include <string>

class Minimap
{
public:
    Minimap();
    Minimap(const char* _texPath, const int (&_windowDimensions)[2]);
    void Draw(PlayerCharacter& player, const float& mapScale, const int (&windowDimensions)[2]);
    void Toggle();

private:
    Texture2D tex{};
    const float scale{0.333f};
    Vector2 pos{};
    Rectangle background{};
    bool isEnabled{false};
};

#endif