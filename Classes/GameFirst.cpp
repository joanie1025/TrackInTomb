//
//  GameFirst.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "GameFirst.hpp"
#include "SimpleAudioEngine.h"
#include"Leader.h"
#include"Friend.h"
USING_NS_CC;
Leader*leader = new Leader;

// on "init" you need to initialize your instance
bool GameFirst::init()
{
   
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/beijing1.png");
    sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    
    
    
    
    
    
    //Label *label=Label::createWithTTF("CLOCK","fonts/Marker Felt.ttf", 48);
    //label->setPosition(Vec2(winSize.width/2, winSize.height*3/4));
    //label->setColor(Color3B(255, 0, 0));
    //this->addChild(label);
    
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameFirst::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(winSize.width*0.9, winSize.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithTTF("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameFirst::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(winSize.width*0.9, winSize.height*0.15));
    
    auto menu=Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
  

    for (int i = 0; i < 10; i++) {
        enemies[i] = nullptr;
    }
    
    leader->setTexture("res/leader.png");
    leader->setPosition(Vec2(origin.x+this->getContentSize().width/2,origin.y+this->getContentSize().height/2));
    addChild(leader,2);//ÃÌº”÷˜Ω«
    myFriend = new Friend;
    myFriend->setTexture("res/friend2.png");
    addChild(myFriend,1);//ÃÌº”≈Û”—
    //*************µ–»ÀÃÌº”***************
    addEnemy(Vec2(origin.x + winSize.width,
                  origin.y + winSize.height ));
    addEnemy(Vec2(origin.x,
                  origin.y+ winSize.height));
    addEnemy(Vec2(origin.x ,
                  origin.y ));
    //*************µ–»ÀÃÌº”***************
    this->schedule(schedule_selector(GameFirst::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
    this->schedule(schedule_selector(GameFirst::enemiesattack),0.5f , kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
    this->schedule(schedule_selector(GameFirst::friendmove), 0.2f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
    return true;
}
void GameFirst::enemiesmove(float dt) {
    for (int i = 0; i <10; i++) {
        if (enemies[i] != nullptr&&enemies[i]->getblood() > 0)
            enemies[i]->move();
        else if (enemies[i] != nullptr&&enemies[i]->getblood() <= 0) {
            removeChild(enemies[i]);
            // delete enemies[i];
        }
    }
    //log("1");
}
void GameFirst::enemiesattack(float dt) {//µ–»Àºı÷˜Ω«—™
    for (int i = 0; i <10; i++) {
        if (enemies[i] != nullptr&&enemies[i]->getDistance() <
            enemies[i]->getAttackDistance()) {
            leader->getAttacked(enemies[i]->getAttackValue());
        }
    }
    //log("1");
}
void GameFirst::onExit() {
    Layer::onExit();
    unscheduleAllCallbacks();
    unscheduleAllSelectors();
}
GameFirst::~GameFirst() {
    for (int i = 0; i < 10;i++) {
        if (enemies[i] != nullptr)
            delete enemies[i];
    }
}
void GameFirst::addEnemy(const Vec2& position) {
    auto winSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    for (int i = 0; i < 10; i++) {
        if (enemies[i] == nullptr) {
            enemies[i] = new Enemy;
            enemies[i]->setTexture("res/Up/1.png");
            enemies[i]->setPosition(position);
            addChild(enemies[i],0);
            break;
        }
    }
}
void GameFirst::friendmove(float dt) {
    myFriend->move();
}
void GameFirst::onExitTransitionDidStart() {
   Layer::onExitTransitionDidStart();
}

void GameFirst::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            tsm->goGameSecond();
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
           
            break;
        default:
            break;
    }
}

