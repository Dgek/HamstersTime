//
//  Hamster.h
//  HamstersTime
//
//  Created by Evgeny on 2/2/14.
//
//

#ifndef __HamstersTime__Hamster__
#define __HamstersTime__Hamster__

#include "cocos2d.h"
#include "Game.h"

class Hamster : public cocos2d::Sprite
{
private:
    Direction m_direction;
    cocos2d::Vect m_velocity;
    
public:
    
    virtual bool init();
    virtual void update(float delta);
};

#endif /* defined(__HamstersTime__Hamster__) */
