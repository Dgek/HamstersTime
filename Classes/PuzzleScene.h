#ifndef __PUZZLE_SCENE_H__
#define __PUZZLE_SCENE_H__

#include "cocos2d.h"
#include "Hamster.h"

class Puzzle : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //input hand
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Puzzle);
    
protected:
    cocos2d::Sprite* m_pVikingHamster;
    cocos2d::Sprite* m_pRastamanHamster;
    cocos2d::Sprite* m_pGeekHamster;
};

#endif // __PUZZLE_SCENE_H__
