//
//  GameSecond.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "GameSecond.hpp"
bool GameSecond::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize=Director::getInstance()->getVisibleSize();
  /* Node *node=CSLoader::createNode("res/studio/MenuScene.csb");
   this->addChild(node);*/
    auto sprite = Sprite::create("res/beijing3.png");
    sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameSecond::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(winSize.width*0.9, winSize.height*0.25));
    
    
    MenuItemLabel *menuItem_3=MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameSecond::menuCallBack, this));
    menuItem_3->setTag(103);
    menuItem_3->setPosition(Vec2(winSize.width*0.9, winSize.height*0.2));
    
    
   MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithTTF("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameSecond::menuCallBack, this));
    menuItem_2->setTag(102);
   menuItem_2->setPosition(Vec2(winSize.width*0.9, winSize.height*0.15));
    
   auto menu=Menu::create(menuItem,menuItem_2,menuItem_3,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void GameSecond::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
            tsm->goGameThird();
            break;
        case 103:
            tsm->goGameFirst();
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
            break;
        default:
            break;
    }
}
