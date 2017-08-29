//
//  QuaLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#include "QuaLayer.hpp"

bool QuaLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/qua.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
    sprite->setScale(0.8);
    
    this->addChild(sprite, 0);
    
    MenuItemImage* pItemImage = MenuItemImage::create("res/A.png","res/A.png",CC_CALLBACK_1(QuaLayer::menuCallBack,this));
    pItemImage->setPosition(Vec2(size.width*0.3, size.height*0.525));
    pItemImage->setTag(201);
    pItemImage->setScale(0.8);
    MenuItemImage* pItemImage2 = MenuItemImage::create("res/B.png","res/B.png",CC_CALLBACK_1(QuaLayer::menuCallBack,this));
    pItemImage2->setPosition(Vec2(size.width*0.4, size.height*0.525));
    pItemImage2->setTag(202);
    pItemImage2->setScale(0.8);
    MenuItemImage* pItemImage3 = MenuItemImage::create("res/C.png","res/C.png",CC_CALLBACK_1(QuaLayer::menuCallBack,this));
    pItemImage3->setPosition(Vec2(size.width*0.5, size.height*0.525));
    pItemImage3->setTag(203);
    pItemImage3->setScale(0.8);
    MenuItemImage* pItemImage4 = MenuItemImage::create("res/D.png","res/D.png",CC_CALLBACK_1(QuaLayer::menuCallBack,this));
    pItemImage4->setPosition(Vec2(size.width*0.6, size.height*0.525));
    pItemImage4->setTag(204);
    pItemImage4->setScale(0.8);
   
    
    
    MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithSystemFont("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(QuaLayer::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(size.width/2, size.height*0.15));
    
    auto menu=Menu::create(pItemImage,pItemImage2,pItemImage3,pItemImage4,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void QuaLayer::menuCallBack(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 202:
            tsm->goLoseScene();
            break;
        case 203:
            tsm->goLoseScene();
            break;
        case 204:
            tsm->goLoseScene();
            break;
        case 201:
            tsm->goWinScene();
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
            break;
        default:
            break;
    }
}



