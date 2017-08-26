//
//  GameThird.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#include "GameThird.hpp"
bool GameThird::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/beijing1.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    
    // Label *label=Label::createWithSystemFont("剧情介绍","", 20);
    //label->setPosition(Vec2(winSize.width/2, winSize.height*0.9));
    //label->setColor(Color3B(255, 0, 0));
    //this->addChild(label);
    
   MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameThird::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(size.width*0.9, size.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithSystemFont("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameThird::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width*0.9, size.height*0.15));
    
    auto menu=Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
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
