//
//  StartLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "StartLayer.hpp"
bool StartLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/background.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
    sprite->setScale(0.3);
    
    this->addChild(sprite, 0);
    
    
    //Label *label=Label::createWithTTF("CLOCK","fonts/Marker Felt.ttf", 48);
    //label->setPosition(Vec2(size.width/2, size.height*3/4));
    //label->setColor(Color3B(255, 0, 0));
    //this->addChild(label);
    
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
            tsm->goInfoScene();
            break;
        default:
            break;
    }
}
