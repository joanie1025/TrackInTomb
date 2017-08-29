//
//  GameSecond.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef GameSecond_hpp
#define GameSecond_hpp

#include <stdio.h>
#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"

USING_NS_CC;

#endif /* GameSecond_hpp */
class GameSecond :public Layer {
    
public:
    Menu* menu;
    CREATE_FUNC(GameSecond);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    void pause(Ref* pSender);
    void  menuShopCallBack(Ref * pSender);
    void updateCustom(float f);
    //**************************************
    void onEnter();
    void onExit();
    void addEnemy(const Vec2& position);
    void enemiesmove(float dt);
    void enemiesattack(float dt);
    void friendmove(float dt);
    //void getmoney(Ref* pSpender);
    void deletesprite(Sprite*sprite);
    //**************************************
public:
    Zcontrol * tsm;
    Sprite * sprites;
    std::vector<std::string> spritePaths;
    int count;
};
