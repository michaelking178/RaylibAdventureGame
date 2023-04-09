#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "BaseActor.h"
#include "PropData.h"
#include <vector>

class GameState
{
public:
    GameState();

private:
    std::vector<BaseActor *> BaseActors;

public:
    void RegisterBaseActor(BaseActor* ba);
    void SortBaseActorsByYPos();
    std::vector<BaseActor *> GetBaseActors(){ return BaseActors; }

    const PropData logPropData {
        "Textures/Props/outside.png", // Spritesheet filepath
        Vector2{288.f, 16.f}, // sprite position in sheet
        Vector2{48.f, 32.f} // sprite size in sheet
    };
    const PropData treePropData {
        "Textures/Props/outside.png",
        Vector2{528.f, 16.f},
        Vector2{96.f, 96.f}
    };
};

#endif