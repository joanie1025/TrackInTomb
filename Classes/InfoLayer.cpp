//
//  InfoLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "InfoLayer.hpp"
bool InfoLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/info.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
  
    sprite->setScale(0.8);
    
    this->addChild(sprite, 0);
    
   
    
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Continue", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(InfoLayer::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(size.width/2, size.height*0.2));
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithSystemFont("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(InfoLayer::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width/2, size.height*0.15));
    
    auto menu=Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void InfoLayer::menuCallBack(Ref * pSender){
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
