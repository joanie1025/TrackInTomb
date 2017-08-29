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
extern Leader* leader;
extern Friend* myFriend;
int frienddeter=0;
bool whetherfriend=false;
extern int gamenumber;

// on "init" you need to initialize your instance
bool GameFirst::init(){

Vec2 origin = Director::getInstance()->getVisibleOrigin();
Size winSize=Director::getInstance()->getVisibleSize();

    
    if (leader != nullptr) {
        Vec2 before = leader->getPosition();
        int time=leader->getTime();
        delete leader;
        leader = new Leader;
        leader->setTime(time);
        leader->setPosition(before);
    }
    else
        leader = new Leader;
    
    if (whetherfriend == true) {
        if (myFriend != nullptr) {
            Vec2 before = myFriend->getPosition();
            delete myFriend;
            myFriend = new Friend;
            myFriend->setPosition(before);
        }
        else
            myFriend = new Friend;
    }
    
    spritePaths.push_back("res/shalou/1.png");
    spritePaths.push_back("res/shalou/2.png");
    spritePaths.push_back("res/shalou/3.png");
    spritePaths.push_back("res/shalou/4.png");
    spritePaths.push_back("res/shalou/5.png");
    spritePaths.push_back("res/shalou/6.png");
    spritePaths.push_back("res/shalou/7.png");
    spritePaths.push_back("res/shalou/8.png");
    count=leader->getTime();
    if(count<1)
        sprites=Sprite::create("res/shalou/1.png");
    else if(count<2)
        sprites=Sprite::create("res/shalou/2.png");
    else if(count<3)
        sprites=Sprite::create("res/shalou/3.png");
    else if(count<4)
        sprites=Sprite::create("res/shalou/4.png");
    else if(count<5)
        sprites=Sprite::create("res/shalou/5.png");
    else if(count<6)
        sprites=Sprite::create("res/shalou/6.png");
    else if(count<7)
        sprites=Sprite::create("res/shalou/7.png");
    else if(count<8)
        sprites=Sprite::create("res/shalou/8.png");
    else
        Director::getInstance()->end();
    
    sprites->setPosition(Vec2(winSize.width*0.03, winSize.height*0.2));
    this->addChild(sprites,9);
    
    float interval = 5.0f;
    schedule(schedule_selector(GameFirst::updateCustom), interval, kRepeatForever, 0);
    sprites->setTexture(spritePaths[count]);

    auto sprite = Sprite::create("res/beijing1.png");
    sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    auto sprite3 = Sprite::create("res/head.png");
    sprite3->setPosition(Vec2(winSize.width*0.03, winSize.height*0.95));
    
    sprite3->setScale(0.75);
    
    this->addChild(sprite3, 0);
    
    
    
    addChild(leader->mySprite, 3);
    if (whetherfriend == true) {
        addChild(myFriend->mySprite, 2);
        this->schedule(schedule_selector(GameFirst::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
    }
    
    
    
    MenuItemImage* pItemImage = MenuItemImage::create("res/shop.png","res/shop.png",CC_CALLBACK_1(GameFirst::menuShopCallBack,this));
    pItemImage->setPosition(Vec2(winSize.width*0.03, winSize.height*0.1));
    pItemImage->setScale(0.3);
    
    
    
    MenuItemImage* dItemImage = MenuItemImage::create("res/pause.png","res/pause.png",CC_CALLBACK_1(GameFirst::pause,this));
    dItemImage->setPosition(Vec2(winSize.width*0.95, winSize.height*0.95));
    dItemImage->setScale(0.5);
    
    
    /*MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameFirst::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(winSize.width*0.9, winSize.height*0.2));*/
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithTTF("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameFirst::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(winSize.width*0.9, winSize.height*0.15));
    
    menu=Menu::create(menuItem_2,dItemImage,pItemImage,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
  

  
  
    return true;
}

void GameFirst::updateCustom(float dt)
{
    if (spritePaths.size()>0)
    {
        
        sprites->setTexture(spritePaths[count]);
        count++;
        leader->setTime(count);
        if(count>8){
            tsm->goLoseScene();
        }
    }
}
void GameFirst::menuCallBack(Ref * pSender) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            //tsm->goGameSecond();
            //************************************************ÃÌº”Ω© ¨º∞∆‰Œª÷√************************
            addEnemy(Vec2(origin.x + visibleSize.width/2+60,
                          origin.y + visibleSize.height/2-100));
            addEnemy(Vec2(origin.x + visibleSize.width / 2+90,
                          origin.y + visibleSize.height / 2-100));
            addEnemy(Vec2(origin.x + visibleSize.width / 2+120,
                          origin.y + visibleSize.height / 2-100));
            //************************************************ÃÌº”Ω© ¨º∞∆‰Œª÷√************************
            tsm->whetheropen = true;
            menu->removeChild((MenuItemLabel*)pSender,true);
            break;
        case 102://µ⁄»˝∏ˆ∞¥≈•
            Director::getInstance()->end();
            exit(0);
            
            break;
        case 103:
            tsm->goGameSecond();
        default:
            break;
    }
}
void GameFirst::onEnter() {
    log("onEnter");
    Layer::onEnter();
    gamenumber = 1;
    //*************************************…Ë÷√÷˜Ω«≈Û”—≥ı ºŒª÷√****************************************
    leader->setPosition(tsm->leaderPosition1);
    if(whetherfriend==true){
        myFriend->setPosition(tsm->friendPosition1);}
    
        MenuItemImage *menuItem;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getVisibleSize();
    
    if (tsm->gamefirstgoto == false) {
        menuItem = MenuItemImage::create("res/door.png", "res/door.png", CC_CALLBACK_1(GameFirst::menuCallBack, this));
        menuItem->setTag(101);
        menuItem->setPosition(Vec2(origin.x + winSize.width*0.64, origin.y + winSize.height*0.5));
        menuItem->setScale(0.765f);
        menu->addChild(menuItem);
    }

        
    
    
    if (tsm->gamefirstgonext == true) {
        MenuItemLabel *menuItem5 = MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24), CC_CALLBACK_1(GameFirst::menuCallBack, this));
        menuItem5->setTag(103);
        menuItem5->setPosition(Vec2(origin.x + winSize.width*0.9, origin.y + winSize.height*0.2));
        menu->addChild(menuItem5);
    }
    //********************************************************************************
    tsm->gamefirstgoto = true;
   }




void GameFirst::onExit() {
    tsm->leaderPosition1 = leader->getPosition();
    if (whetherfriend == true)
        tsm->friendPosition1 = myFriend->getPosition();
    Layer::onExit();
}
//**********************************************************************
void GameFirst::enemiesmove(float dt) {
    for (int i = 0; i < 10; i++) {
        if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getblood() > 0)
            tsm->enemies[i]->move();
        else if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getblood() <= 0) {
            removeChild(tsm->enemies[i]->mySprite);
            delete tsm->enemies[i];
            tsm->enemies[i] = nullptr;
            tsm->num--;
        }
        //log("1");
    }
    if (tsm->num == 0&&tsm->whetheropen == true) {
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size winSize = Director::getInstance()->getVisibleSize();
        //*************************************µ⁄∂˛∏ˆ∞¥≈•…Ë÷√******************************************
        MenuItemLabel *menuItem = MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24), CC_CALLBACK_1(GameFirst::menuCallBack, this));
        menuItem->setTag(103);
        menuItem->setPosition(Vec2(origin.x + winSize.width*0.9, origin.y + winSize.height*0.2));
        menu->addChild(menuItem);
        tsm->gamefirstgonext = true;
        //*************************************µ⁄∂˛∏ˆ∞¥≈•…Ë÷√******************************************
    }
}
void GameFirst::enemiesattack(float dt) {//µ–»Àºı÷˜Ω«—™
    for (int i = 0; i <10; i++) {
        if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getDistance() <
            tsm->enemies[i]->getAttackDistance()) {
            leader->getAttacked(tsm->enemies[i]->getAttackValue());
        }
    }
    leader->whethergoon = true;
    //log("1");
}
void GameFirst::addEnemy(const Vec2& position) {
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (tsm->num == 0) {
        this->schedule(schedule_selector(GameFirst::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
        this->schedule(schedule_selector(GameFirst::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
    }
    for (int i = 0; i < 10; i++) {
        if (tsm->enemies[i] == nullptr) {
            tsm->enemies[i] = new Enemy;
            tsm->enemies[i]->setPosition(position);
            addChild(tsm->enemies[i]->mySprite, 0);
            tsm->num++;
            break;
        }
    }
}
void GameFirst::friendmove(float dt) {
    myFriend->move();
}


void  GameFirst::menuShopCallBack(Ref * pSender){
    tsm->goShopScene();
}




void  GameFirst::pause(Ref * pSender){
    tsm->goPausedScene();
    
}
