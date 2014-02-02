//
//  PuzzleGUI.h
//  HamstersTime
//
//  Created by Evgeny on 2/2/14.
//
//

#ifndef __HamstersTime__PuzzleGUI__
#define __HamstersTime__PuzzleGUI__

#include "cocos2d.h"

class PuzzleGUI  : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PuzzleGUI);
    
};

#endif /* defined(__HamstersTime__PuzzleGUI__) */
