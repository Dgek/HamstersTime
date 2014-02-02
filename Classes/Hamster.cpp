//
//  Hamster.cpp
//  HamstersTime
//
//  Created by Evgeny on 2/2/14.
//
//

#include "Hamster.h"

bool Hamster::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    m_direction = DIRECTION_UP;
    
    return true;
}