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

class Puzzle;
class PuzzleGUI  : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    void vikingTouchEndedCallback(Object* pSender);
    void rastamanTouchEndedCallback(Object* pSender);
    void geekTouchEndedCallback(Object* pSender);
    
    void setPuzzle(Puzzle* pPuzzle);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PuzzleGUI);
    
private:
    Puzzle* m_pPuzzle;
    //cocos2d::Sprite m_pVikingButton;
   // cocos2d::Sprite m_pRastamanButton;
   // cocos2d::Sprite m_pGeekButton;
    
};

#endif /* defined(__HamstersTime__PuzzleGUI__) */
