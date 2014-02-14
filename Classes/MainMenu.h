//
//  MainMenu.h
//  HamstersTime
//
//  Created by Evgeny on 2/10/14.
//
//

#ifndef __HamstersTime__MainMenu__
#define __HamstersTime__MainMenu__

#include "cocos2d.h"

class MainMenuBG : public cocos2d::Layer
{
public:
    virtual bool init();
    
    CREATE_FUNC(MainMenuBG);
};

class MainMenuGUI : public cocos2d::Layer
{
public:
    virtual bool init();
    
    //callbacks
    void mapButtonCallback(Object* pSender);
    void multButtonCallback(Object* pSender);
    void soundButtonCallback(Object* pSender);
    void optionButtonCallback(Object* pSender);
    
    CREATE_FUNC(MainMenuGUI);
};

class OptionsMenu : public cocos2d::Layer
{
public:
    virtual bool init();
    
    //callbacks
    void backButtonCallback(Object* pSender);
    
    CREATE_FUNC(OptionsMenu);
};

#endif /* defined(__HamstersTime__MainMenu__) */
