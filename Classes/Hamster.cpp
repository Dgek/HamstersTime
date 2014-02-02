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
    m_velocity = cocos2d::Vect(1,0);
    
    this->scheduleUpdate();
    
    return true;
}

void Hamster::update(float delta)
{
    Sprite::update(delta);
    this->setPosition(this->getPosition() + m_velocity);
}