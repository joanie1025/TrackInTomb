//
//  JShopLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#include "JShopLayer.hpp"
bool JShopLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size size=Director::getInstance()->getVisibleSize();
    auto sprite = Sprite::create("res/gameshop.png");
    sprite->setPosition(Vec2(size.width/2, size.height/2));
    
   
    
    this->addChild(sprite, 0);
    MenuItemImage* pItemImage = MenuItemImage::create("res/100.png","res/100.png",CC_CALLBACK_1(JShopLayer::menuCallBack,this));
    pItemImage->setPosition(Vec2(size.width*0.16, size.height*0.3));
    pItemImage->setTag(201);
    pItemImage->setScale(0.1);
    MenuItemImage* pItemImage2 = MenuItemImage::create("res/200.png","res/200.png",CC_CALLBACK_1(JShopLayer::menuCallBack,this));
    pItemImage2->setPosition(Vec2(size.width*0.4, size.height*0.3));
    pItemImage2->setTag(202);
    pItemImage2->setScale(0.1);
    MenuItemImage* pItemImage3 = MenuItemImage::create("res/200.png","res/200.png",CC_CALLBACK_1(JShopLayer::menuCallBack,this));
    pItemImage3->setPosition(Vec2(size.width*0.6, size.height*0.3));
    pItemImage3->setTag(203);
    pItemImage3->setScale(0.1);
    MenuItemImage* pItemImage4 = MenuItemImage::create("res/100.png","res/100.png",CC_CALLBACK_1(JShopLayer::menuCallBack,this));
    pItemImage4->setPosition(Vec2(size.width*0.8, size.height*0.3));
    pItemImage4->setTag(204);
    pItemImage4->setScale(0.1);

    MenuItemImage* menuItem = MenuItemImage::create("res/out.png","res/out.png",CC_CALLBACK_1(JShopLayer::menuCallBack,this));
    menuItem->setPosition(Vec2(size.width*0.94, size.height*0.8));
    menuItem->setTag(101);
    menuItem->setScale(0.01);
    
       
   
    
    auto menu=Menu::create(pItemImage,pItemImage2,pItemImage3,pItemImage4,menuItem,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
void JShopLayer::menuCallBack(Ref * pSender){
    
    switch (((MenuItem *)pSender)->getTag()) {
        case 202:
            
            break;
        case 203:
            
            break;
        case 204:
            
            break;
        case 201:
           
            break;
        case 101:
           Director::getInstance()->popScene();
            break;
        default:
            break;
    }

    
    
}



