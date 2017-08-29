//
//  GameThird.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

//#include "SimpleAudioEngine.h"
#include "GameThird.hpp"
//using namespace CocosDenshion;
USING_NS_CC;
extern Leader* leader;
extern Friend* myFriend;
extern int frienddeter;
extern bool whetherfriend;
extern int gamenumber;

bool GameThird::init(){
    
    
    Vec2 before = leader->getPosition();
    int time=leader->getTime();
    delete leader;
    leader = new Leader;
    leader->setTime(time);
    leader->setPosition(before);
    if (whetherfriend == true) {
        before = myFriend->getPosition();
        delete myFriend;
        myFriend = new Friend;
        myFriend->setPosition(before);
    }
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    count=leader->getTime();
    spritePaths.push_back("res/shalou/1.png");
    spritePaths.push_back("res/shalou/2.png");
    spritePaths.push_back("res/shalou/3.png");
    spritePaths.push_back("res/shalou/4.png");
    spritePaths.push_back("res/shalou/5.png");
    spritePaths.push_back("res/shalou/6.png");
    spritePaths.push_back("res/shalou/7.png");
    spritePaths.push_back("res/shalou/8.png");
    
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
    
    sprites->setPosition(Vec2(size.width*0.03, size.height*0.2));
    this->addChild(sprites,9);
    
   
    float interval = 5.0f;
    schedule(schedule_selector(GameThird::updateCustom), interval, kRepeatForever, 0);
     sprites->setTexture(spritePaths[count]);
    
    auto sprite = Sprite::create("res/beijing3.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    addChild(leader->mySprite, 3);
    if (whetherfriend == true) {
        addChild(myFriend->mySprite, 2);
        //this->schedule(schedule_selector(GameFirst::friendmove), 1.4f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
    }


    MenuItemImage* openBox=MenuItemImage::create(
                                         "res/closedcase.png",
                                         "res/gold.png"
                                         );
    MenuItemImage* emptyBox=MenuItemImage::create(
                                          "res/emptycase.png",
                                          "res/emptycase.png");
    //组合按钮
    MenuItemToggle * boxMenuToggle=MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameThird::menuCaseCallBack,this),openBox,emptyBox,NULL);
    boxMenuToggle->setPosition(Vec2(size.width*0.75,size.height*0.84));
    boxMenuToggle->setScale(0.5);
    
    auto sprite2 = Sprite::create("res/emptycase.png");
    sprite2->setPosition(Vec2(size.width*0.755,size.height*0.846));
    
    sprite2->setScale(0.5);
    
    this->addChild(sprite2, 0);
    auto sprite3 = Sprite::create("res/head.png");
    sprite3->setPosition(Vec2(size.width*0.03, size.height*0.95));
    
   sprite3->setScale(0.75);
    
    this->addChild(sprite3, 0);
    
    
    MenuItemImage* bItemImage = MenuItemImage::create("res/bagua.png","res/bagua.png",CC_CALLBACK_1(GameThird::menuBaCallBack,this));
    bItemImage->setPosition(Vec2(size.width*0.65, size.height*0.45));
    bItemImage->setScale(0.5);
    
    MenuItemImage* dItemImage = MenuItemImage::create("res/pause.png","res/pause.png",CC_CALLBACK_1(GameThird::pause,this));
    dItemImage->setPosition(Vec2(size.width*0.95, size.height*0.95));
    dItemImage->setScale(0.5);
    
    
    
    
    
    
    
    MenuItemImage* pItemImage = MenuItemImage::create("res/shop.png","res/shop.png",CC_CALLBACK_1(GameThird::menuShopCallBack,this));
    pItemImage->setPosition(Vec2(size.width*0.03, size.height*0.1));
    pItemImage->setScale(0.3);
    
   MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameThird::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(size.width*0.9, size.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithSystemFont("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameThird::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width*0.9, size.height*0.15));
    
  menu=Menu::create(boxMenuToggle,menuItem,menuItem_2,pItemImage,bItemImage, dItemImage,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,1);
    
    return true ;
}
void GameThird::updateCustom(float dt)
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

void GameThird::menuCallBack(Ref * pSender){
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
void  GameThird::menuShopCallBack(Ref * pSender){
    tsm->goShopScene();
}

void  GameThird::menuCaseCallBack(Ref * pSender){
menu->removeChild((MenuItemImage*)pSender, true);
  }
void  GameThird::menuBaCallBack(Ref * pSender){
    tsm->goQuaScene();
}

void  GameThird::pause(Ref * pSender){
    tsm->goPausedScene();

}
