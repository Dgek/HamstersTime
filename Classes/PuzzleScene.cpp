#include "PuzzleScene.h"
#include "PuzzleGUI.h"

USING_NS_CC;

Scene* Puzzle::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Puzzle::create();
    
    auto gui = PuzzleGUI::create();
    //gui->init();
    
    // add layer as a child to scene
    scene->addChild(layer);
    scene->addChild(gui);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Puzzle::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("HamstersTime Demo", "Arial", 22);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("Field_G_d.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    m_pVikingHamster = Hamster::create("evil_forward_d.png");
    m_pVikingHamster->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 300));
    
    m_pRastamanHamster = Hamster::create("good_forward_d.png");
    m_pRastamanHamster->setPosition(m_pVikingHamster->getPosition() - Point(300, 0));
    
    m_pGeekHamster = Hamster::create("fat_forward_d.png");
    m_pGeekHamster->setPosition(m_pVikingHamster->getPosition() + Point(300, 0));
    
    this->addChild(m_pVikingHamster, 0);
    this->addChild(m_pRastamanHamster, 0);
    this->addChild(m_pGeekHamster, 0);
    
    return true;
}

bool Puzzle::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point location = touch->getLocation();
}

