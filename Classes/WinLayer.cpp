//
//  WinLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#include "WinLayer.hpp"
#include"Leader.h"
#include"Friend.h"
extern Leader* leader;
extern Friend* myFriend;
bool WinLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
   
    Label *label=Label::createWithSystemFont("YOU WIN","", 60);
   label->setPosition(Vec2(size.width/2, size.height*0.6));
    label->setColor(Color3B(255, 0, 0));
this->addChild(label);
    
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("restart", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(WinLayer::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(size.width/2, size.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithSystemFont("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(WinLayer::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width/2, size.height*0.15));
    
    auto menu=Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void WinLayer::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            tsm->goStartScene();
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
            break;
        default:
            break;
    }
}
