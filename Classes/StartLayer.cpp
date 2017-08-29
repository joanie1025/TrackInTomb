//
//  StartLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//
#include"Leader.h"
#include"Friend.h"
#include "StartLayer.hpp"
extern Leader* leader;
extern Friend* myFriend;
extern int frienddeter;
extern bool whetherfriend;
bool StartLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/background.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
    sprite->setScale(0.3);
    
    this->addChild(sprite, 0);
    
    
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Start", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(StartLayer::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(size.width*0.9, size.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(StartLayer::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width*0.9, size.height*0.15));
    
    auto menu=Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void StartLayer::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            tsm->goGameFirst();
            break;
        case 102:
            Director::getInstance()->popScene();
            break;
        default:
            break;
    }
}
void StartLayer::onEnter(){

    tsm->gamefirstgonext=false;
    tsm->gamefirstgoto = false;// «∑Ò»•π˝≥°æ∞“ª
    //gamesecondgonext = false;
    tsm->gamesecondgoto1=false;// «∑Ò¥Úø™π˝π◊≤ƒ1
    tsm->gamesecondgoto2 = false;// «∑Ò¥Úø™π˝π◊≤ƒ2
    tsm->gamesecondgoto3 = false;// «∑Ò¥Úø™π˝π◊≤ƒ3
    tsm->gamesecondgoto4 = false;// «∑Ò¥Úø™π˝π◊≤ƒ4
    tsm->gamesecondgoto5 = false;// «∑Ò¥Úø™π˝π◊≤ƒ5
    tsm->gamesecondgoto6 = false;// «∑Ò¥Úø™π˝π◊≤ƒ6
    tsm->gamesecondgoto7 = false;// «∑Ò¥Úø™π˝π◊≤ƒ7
    tsm->num = 0;
    tsm->whetheropen = false;
    leader=nullptr;
    myFriend=nullptr;
    frienddeter=0;
    whetherfriend=false;
    Layer::onEnter();
}
