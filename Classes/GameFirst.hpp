//
//  GameFirst.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef GameFirst_hpp
#define GameFirst_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"

#include"Enemy.h"
#include"Friend.h"

USING_NS_CC;

#endif /* GameFirst_hpp */


class GameFirst:public Layer{
    
   
public:
    CREATE_FUNC(GameFirst);
    virtual bool init();
    
    void menuCallBack(Ref * pSender);
    void pause(Ref* pSender);
    void  menuShopCallBack(Ref * pSender);
    void updateCustom(float f);
   
    void onEnter();
    void onExit();
    void addEnemy(const Vec2& position);
    void enemiesmove(float dt);
    void enemiesattack(float dt);
    void friendmove(float dt);
    void timer();
    
public:
    Zcontrol * tsm;
     Menu* menu;
    Sprite * sprites;
    std::vector<std::string> spritePaths;
     int count;
};
