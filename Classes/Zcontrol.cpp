//
//  Zcontrol.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "Zcontrol.hpp"

#include"LoadLayer.hpp"
#include"InfoLayer.hpp"
#include"StartLayer.hpp"
#include"GameFirst.hpp"
void Zcontrol::createLoadScene(){
    loadScene=Scene::create();
    LoadLayer*layer=LoadLayer::create();
    layer->tsm=this;
    loadScene->addChild(layer);
    
    
}

void Zcontrol::goInfoScene(){
    infoScene=Scene::create();
    InfoLayer * layer=InfoLayer::create();
    layer->tsm=this;
    infoScene->addChild(layer);
    Director::getInstance()->replaceScene(infoScene);
    
    
}

void Zcontrol::goStartScene(){
    startScene=Scene::create();
    StartLayer * layer=StartLayer::create();
    layer->tsm=this;
    startScene->addChild(layer);
    
    Director::getInstance()->replaceScene(startScene);
    
    
}
void Zcontrol::goGameFirst(){
    gameFirst=Scene::create();
    GameFirst * layer=GameFirst::create();
    layer->tsm=this;
    gameFirst->addChild(layer);
    Director::getInstance()->replaceScene(gameFirst);
    
    
}
