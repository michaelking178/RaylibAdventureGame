#include "raymath.h"
#include "Source/PlayerCharacter.h"
#include "Source/Enemy_Cacto.h"
#include "Source/Prop.h"
#include "Source/PropFactory.h"
#include "Source/Minimap.h"
#include "Source/GameState.h"

int main()
{
    // Create Game State and prop factory
    GameState gameState{};
    PropFactory propFactory{};

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
    Prop props[4] {
        propFactory.CreateProp(
            gameState.logPropData,
            3.f,
            Vector2{100.f, 100.f}
        ),
        propFactory.CreateProp(
            gameState.logPropData,
            4.f,
            Vector2{250.f, 550.f}
        ),
        propFactory.CreateProp(
            gameState.treePropData,
            3.f,
            Vector2{500.f, 750.f}
        ),
        propFactory.CreateProp(
            gameState.treePropData,
            4.f,
            Vector2{280.f*mapScale, 217.f*mapScale} // this way I can use coordinates straight from the level texture, and plan out the level design in GIMP.
        )
    };

    // Populate GameState BaseActor vector just before starting Update
    gameState.RegisterBaseActor(&player);
    gameState.RegisterBaseActor(&cacto);
    for (auto prop : props)
    {
        gameState.RegisterBaseActor(&prop);
    }

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
        // for (auto prop : props) {
        //     // Debug draw prop collision rects
        //     //prop.DrawCollisionRect(prop.GetCollisionRect(player.GetWorldPos()));

        //     prop.Draw(player.GetWorldPos());
        // }
        
        // Debug draw player Collision Rect
        //player.DrawCollisionRect(player.GetCollisionRect());

        // Ticks
        player.Tick(GetFrameTime());
        cacto.Tick(GetFrameTime());

        // Draw the BaseActors
        gameState.SortBaseActorsByYPos();
        for (BaseActor* ba : gameState.GetBaseActors())
        {
            ba->Draw(player.GetWorldPos());
        }

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