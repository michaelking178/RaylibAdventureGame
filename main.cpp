#include "raymath.h"
#include "Source/PlayerCharacter.h"
#include "Source/Enemy_Cacto.h"
#include "Source/Prop.h"
#include "Source/PropFactory.h"
#include "Source/Minimap.h"

int main()
{
    // Window Setup
    const int WindowDimensions[2]{1920,1080};
    InitWindow(WindowDimensions[0],WindowDimensions[1], "My Adventure Game");
    SetTargetFPS(60);

    // World Setup
    Texture2D map = LoadTexture("Textures/Levels/TestLevel/starting_map.png");
    const float mapScale{4.0f};
    Vector2 mapPos{};

    // Minimap Setup
    Minimap minimap{"Textures/Levels/TestLevel/starting_map.png", WindowDimensions};

    // Player Setup
    PlayerCharacter player{WindowDimensions[0], WindowDimensions[1]};

    // Cacto Setup (TEMP)
    Enemy_Cacto cacto{Vector2{1000.f, 1000.f}};
    cacto.SetTarget(&player);

    // Create several props with the factory
    PropFactory propFactory{};
    Prop props[2] {
        propFactory.CreateProp(
            LoadTexture("Textures/Props/outside.png"),
            Vector2{288.f, 16.f},
            Vector2{48.f, 32.f},
            3.f,
            Vector2{100.f, 100.f}
        ),
        propFactory.CreateProp(
            LoadTexture("Textures/Props/outside.png"),
            Vector2{288.f, 16.f},
            Vector2{48.f, 32.f},
            4.f,
            Vector2{250.f, 550.f}
        )
    };

    // Update
    while(!WindowShouldClose())
    {
        // Toggle Minimap (move to input manager later)
        if (IsKeyPressed(KEY_TAB))
            minimap.Toggle();

        //Draw Call
        BeginDrawing();
        ClearBackground(MAGENTA);

        //Draw Level
        mapPos=Vector2Scale(player.GetWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0, mapScale, WHITE);

        // Draw Props
        for (auto prop : props) {
            // Debug draw prop collision rects
            //prop.DrawCollisionRect(prop.GetCollisionRect(player.GetWorldPos()));

            prop.Render(player.GetWorldPos());
        }
        
        // Debug draw player Collision Rect
        //player.DrawCollisionRect(player.GetCollisionRect());

        // Ticks
        player.Tick(GetFrameTime());
        cacto.Tick(GetFrameTime());

        // Check for Prop Collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.GetCollisionRect(player.GetWorldPos()), player.GetCollisionRect()))
            {
                player.UndoMovement();
            }
            // Enemies aren't colliding :( 
        }

        // Draw Minimap
        minimap.Draw(player, mapScale, WindowDimensions);

        // End Frame
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}