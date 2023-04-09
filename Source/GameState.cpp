#include "GameState.h"
#include <iostream>

GameState::GameState()
{}

void GameState::RegisterBaseActor(BaseActor* ba)
{
    BaseActors.push_back(ba);
}

void GameState::SortBaseActorsByYPos()
{
    for (unsigned int i = 1; i < BaseActors.size(); i++)
    {
        if (BaseActors[i]->GetWorldPos().y + (BaseActors[i]->GetHeight() * BaseActors[i]->GetScale()) < BaseActors[i-1]->GetWorldPos().y + (BaseActors[i-1]->GetHeight() * BaseActors[i-1]->GetScale()))
        {
            BaseActor* ba = BaseActors[i-1];
            BaseActors[i-1] = BaseActors[i];
            BaseActors[i] = ba;
        }
    }
}