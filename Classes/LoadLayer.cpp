//
//  LoadLayer.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "LoadLayer.hpp"
#include "SimpleAudioEngine.h"
USING_NS_CC;
bool LoadLayer::init(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Size size=Director::getInstance()->getVisibleSize();
    
    //auto texture=Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
    //Sprite::createWithTexture(texture);
    auto sprite = Sprite::create("res/title.png");
    sprite->setPosition(Vec2(size.width/2 + origin.x, size.height/2 + origin.y));
    sprite->setScale(0.75);
    
 
    this->addChild(sprite, 0);
    //auto listener=EventListenerTouchOneByOne::create();
  

    
    //图片
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce) , 1.0);
    
    return true ;
}
void LoadLayer::onScheduleOnce(float dt){
    tsm->goInfoScene();
}


