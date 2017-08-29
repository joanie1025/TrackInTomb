//
//  Zcontrol.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#include "Zcontrol.hpp"
#include "JShopLayer.hpp"
#include"LoadLayer.hpp"
#include"InfoLayer.hpp"
#include"StartLayer.hpp"
#include"GameFirst.hpp"
#include"GameSecond.hpp"
#include"GameThird.hpp"
#include "QuaLayer.hpp"
#include "LoseLayer.hpp"
#include "WinLayer.hpp"
#include "PausedScene.hpp"
#include"Friend.h"
#include"Leader.h"

Friend* myFriend;
Leader* leader;
Zcontrol::Zcontrol() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    gamefirstgonext=false;
    gamefirstgoto = false;// «∑Ò»•π˝≥°æ∞“ª
    //gamesecondgonext = false;
    gamesecondgoto1=false;// «∑Ò¥Úø™π˝π◊≤ƒ1
    gamesecondgoto2 = false;// «∑Ò¥Úø™π˝π◊≤ƒ2
    gamesecondgoto3 = false;// «∑Ò¥Úø™π˝π◊≤ƒ3
    gamesecondgoto4 = false;// «∑Ò¥Úø™π˝π◊≤ƒ4
    gamesecondgoto5 = false;// «∑Ò¥Úø™π˝π◊≤ƒ5
    gamesecondgoto6 = false;// «∑Ò¥Úø™π˝π◊≤ƒ6
    gamesecondgoto7 = false;// «∑Ò¥Úø™π˝π◊≤ƒ7
    num = 0;
    whetheropen = false;
    leaderPosition1=Vec2(origin.x+visibleSize.width/2,origin.y + visibleSize.height / 2-100);
    friendPosition1= Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2-100);
    friendPosition2= Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2-100);
    leaderPosition2 = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 100);
    leaderPosition3= Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2-100);
    friendPosition3= Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2-100);
    for (int i = 0; i < 10; i++)
        enemies[i] = nullptr;
}

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
void Zcontrol::goGameSecond(){
    gameSecond=Scene::create();
    GameSecond * layer=GameSecond::create();
    layer->tsm=this;
    gameSecond->addChild(layer);
    Director::getInstance()->replaceScene(gameSecond);
    
}
void Zcontrol::goGameThird(){

    gameThird=Scene::create();
    GameThird * layer=GameThird::create();
    layer->tsm=this;
    gameThird->addChild(layer);
    Director::getInstance()->replaceScene(gameThird);



}
void Zcontrol::goShopScene(){
    shopScene=Scene::create();
    JShopLayer * layer=JShopLayer::create();
    layer->tsm=this;
    shopScene->addChild(layer);
    
    Director::getInstance()->pushScene(shopScene);
    
    
}
void Zcontrol::goQuaScene(){
    quaScene=Scene::create();
    QuaLayer * layer=QuaLayer::create();
    layer->tsm=this;
    quaScene->addChild(layer);
    
    Director::getInstance()->replaceScene(quaScene);
    
    
}
void Zcontrol::goPausedScene(){
    pausedScene=Scene::create();
    PausedScene * layer=PausedScene::create();
    layer->tsm=this;
    pausedScene->addChild(layer);
    
    Director::getInstance()->pushScene(pausedScene);
    
    
}
void Zcontrol::goWinScene(){
    winScene=Scene::create();
    WinLayer* layer=WinLayer::create();
    layer->tsm=this;
    winScene->addChild(layer);
    
    Director::getInstance()->replaceScene(winScene);
    
    
}
void Zcontrol::goLoseScene(){
    loseScene=Scene::create();
    LoseLayer * layer=LoseLayer::create();
    layer->tsm=this;
    loseScene->addChild(layer);
    
    Director::getInstance()->replaceScene(loseScene);
    
    
}
void Zcontrol::enemiesmove(Layer* layer) {
    for (int i = 0; i < 10; i++) {
        if (enemies[i] != nullptr&&enemies[i]->getblood() > 0)
            enemies[i]->move();
        else if (enemies[i] != nullptr&&enemies[i]->getblood() <= 0) {
            layer->removeChild(enemies[i]->mySprite);
            enemies[i]->mySprite = Sprite::create();
            delete enemies[i];
            enemies[i] = nullptr;
        }
        //log("1");
    }
}
void Zcontrol::enemiesattack() {//µ–»Àºı÷˜Ω«—™
    for (int i = 0; i <10; i++) {
        if (enemies[i] != nullptr&&enemies[i]->getDistance() <
            enemies[i]->getAttackDistance()) {
            leader->getAttacked(enemies[i]->getAttackValue());
        }
    }
    leader->whethergoon = true;
    //log("1");
}

void Zcontrol::friendmove() {
    myFriend->move();
}
