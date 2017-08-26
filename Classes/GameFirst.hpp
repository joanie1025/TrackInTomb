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
    Enemy* enemies[10];
    Friend* myFriend;
public:
    CREATE_FUNC(GameFirst);
    virtual bool init();
    //void touchCallBack(Ref * sender，Wiget::TouchEventType controlEvent);
    
   void menuCallBack(Ref * pSender);
    static cocos2d::Scene* createScene();
    
    ~GameFirst();
    void onExitTransitionDidStart();
    // a selector callback
    void onExit();
    void addEnemy(const Vec2& position);
    // implement the "static create()" method manually
    
    void enemiesmove(float);
    void enemiesattack(float dt);
    void friendmove(float dt);

    
public:
    Zcontrol * tsm;
    
};
