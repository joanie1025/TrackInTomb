//
//  PausedScene.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/28.
//
//

#include "PausedScene.hpp"
bool PausedScene::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/background.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    sprite->setScale(0.3);
    
    this->addChild(sprite, 0);
    
    
    
    MenuItemImage* pItemImage = MenuItemImage::create("res/rego.png","res/rego.png",CC_CALLBACK_1(PausedScene::back,this));
    pItemImage->setPosition(Vec2(size.width*0.95, size.height*0.95));
    pItemImage->setScale(0.3);
    
    auto menu=Menu::create(pItemImage,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,1);
    
    return true ;
}
void PausedScene::back(Ref * pSender){
   
    Director::getInstance()->popScene();
    
}
