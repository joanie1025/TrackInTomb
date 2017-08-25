//
//  GameFirst.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "GameFirst.hpp"
bool GameFirst::init(){
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
    
    return true ;
}
void GameFirst::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
            break;
        default:
            break;
    }
}

