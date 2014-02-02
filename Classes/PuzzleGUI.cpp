//
//  PuzzleGUI.cpp
//  HamstersTime
//
//  Created by Evgeny on 2/2/14.
//
//

#include "PuzzleGUI.h"
#include "PuzzleScene.h"

USING_NS_CC;

bool PuzzleGUI::init()
{
    //super
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(PuzzleGUI::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    
    auto vikingButton = MenuItemImage::create("Hmstbig_V_d.png", "Hmstbig_V_d.png",
                                              CC_CALLBACK_1(PuzzleGUI::vikingTouchEndedCallback, this));
    auto rastamanButton = MenuItemImage::create("Hmstbig_R_d.png", "Hmstbig_R_d.png",
                                              CC_CALLBACK_1(PuzzleGUI::rastamanTouchEndedCallback, this));
    auto geekButton = MenuItemImage::create("Hmstbig_G_d.png", "Hmstbig_G_d.png",
                                              CC_CALLBACK_1(PuzzleGUI::geekTouchEndedCallback, this));
    
    Size buttonSize = vikingButton->getContentSize();
    vikingButton->setPosition(Point(visibleSize.width / 3 - buttonSize.width*0.5, buttonSize.height*0.5));
    rastamanButton->setPosition(Point(2*visibleSize.width / 3 - buttonSize.width*0.5, buttonSize.height*0.5));
    geekButton->setPosition(Point(visibleSize.width - buttonSize.width*0.5, buttonSize.height*0.5));
    
    menu->addChild(vikingButton);
    menu->addChild(rastamanButton);
    menu->addChild(geekButton);
    
    this->addChild(menu, 1);
    
    return true;

}

void PuzzleGUI::vikingTouchEndedCallback(Object* pSender)
{
    m_pPuzzle->setActiveViking();
}

void PuzzleGUI::rastamanTouchEndedCallback(Object* pSender)
{
    m_pPuzzle->setActiveRastaman();
}

void PuzzleGUI::geekTouchEndedCallback(Object* pSender)
{
    m_pPuzzle->setActiveGeek();
}

void PuzzleGUI::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void PuzzleGUI::setPuzzle(Puzzle* pPuzzle)
{
    m_pPuzzle = pPuzzle;
}
