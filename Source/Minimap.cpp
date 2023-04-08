#include "Minimap.h"

Minimap::Minimap(const char* _texPath, const int (&_windowDimensions)[2])
{
    tex = LoadTexture(_texPath);
    pos.x = _windowDimensions[0] * 0.85f;
    pos.y = _windowDimensions[1] * 0.73f;
    background.y = pos.y - (pos.y * 0.015f);
    background.x = pos.x - (pos.x * 0.008f);
    background.width = tex.width * scale * 1.1f;
    background.height = tex.height * scale * 1.1f;
}

void Minimap::Draw(PlayerCharacter& player, const float& mapScale, const int (&windowDimensions)[2])
{
    if (isEnabled)
    {
        // Draw Minimap
        DrawRectangle(background.x, background.y, background.width, background.height, BLACK);
        DrawTextureEx(tex, pos, 0, scale, WHITE);

        // Draw the miniCam rect
        Rectangle miniCam {
            player.GetWorldPos().x * (scale / mapScale) + pos.x,
            player.GetWorldPos().y * (scale / mapScale) + pos.y,
            windowDimensions[0] * (scale / mapScale),
            windowDimensions[1] * (scale / mapScale),
        };
        DrawRectangleLines(miniCam.x, miniCam.y, miniCam.width, miniCam.height, WHITE);
        
        // Draw the miniPlayer
        DrawRectangle(
            miniCam.x + (miniCam.width * 0.5f),
            miniCam.y + (miniCam.height * 0.5f),
            10.f,
            10.f,
            RED
        );
    }
}

void Minimap::Toggle()
{
    isEnabled = !isEnabled;
}