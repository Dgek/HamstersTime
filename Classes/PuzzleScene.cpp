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
    gui->setPuzzle(layer);
    
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
    
    auto label = LabelTTF::create("HamstersTime Demo", "Arial", 18);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("texture_d.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    m_pRastamanHamster = Hamster::create("good_forward_d.png");
    m_pRastamanHamster->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    m_pVikingHamster = Hamster::create("evil_forward_d.png");
    m_pVikingHamster->setPosition(m_pRastamanHamster->getPosition() - Point(300, 0));
    
    m_pGeekHamster = Hamster::create("fat_forward_d.png");
    m_pGeekHamster->setPosition(m_pRastamanHamster->getPosition() + Point(300, 0));
    
    m_pActiveHamster = m_pVikingHamster;
    
    this->addChild(m_pVikingHamster, 0);
    this->addChild(m_pRastamanHamster, 0);
    this->addChild(m_pGeekHamster, 0);
    
    this->scheduleUpdate();
    this->setTouchEnabled(true);
    
    return true;
}

void Puzzle::update(float delta)
{
    Layer::update(delta);
    
    m_pVikingHamster->update(delta);
    m_pRastamanHamster->update(delta);
    m_pGeekHamster->update(delta);
}

void Puzzle::setActiveViking()
{
    m_pActiveHamster = m_pVikingHamster;
}

void Puzzle::setActiveRastaman()
{
    m_pActiveHamster = m_pRastamanHamster;
}

void Puzzle::setActiveGeek()
{
    m_pActiveHamster = m_pGeekHamster;
}

void Puzzle::onEnter()
{
    Layer::onEnter();
    
    //register touch event
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = CC_CALLBACK_2(Puzzle::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Puzzle::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Puzzle::onTouchEnded, this);
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Puzzle::onExit()
{
    Layer::onExit();
}

bool Puzzle::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point location = touch->getLocation();
    Point hamsterLoc = m_pActiveHamster->getPosition();
    
    float timeForAction = sqrt((hamsterLoc.x - location.x)*(hamsterLoc.x - location.x) +
                               (hamsterLoc.y - location.y)*(hamsterLoc.y - location.y));
    timeForAction /= 80;
    
    m_pActiveHamster->stopAllActions();
    m_pActiveHamster->runAction(cocos2d::Sequence::create(
                                                          MoveTo::create(timeForAction, location),
                                                          NULL));
}

void Puzzle::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    
}

void Puzzle::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    
}
