#ifndef PROP_FACTORY_H
#define PROP_FACTORY_H

#include "raylib.h"
#include "Prop.h"
#include "PropData.h"

class PropFactory
{
public:
    PropFactory();
    Prop CreateProp(const PropData& pd, float scale, Vector2 worldPos);    
};

#endif