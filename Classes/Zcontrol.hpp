//
//  Zcontrol.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef Zcontrol_hpp
#define Zcontrol_hpp
#include"Enemy.h"
#include"Leader.h"
#include"Friend.h"
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class Zcontrol{
public:
    bool gamefirstgoto;// «∑Ò»•π˝≥°æ∞“ª
    bool gamefirstgonext;// «∑Òø…“‘¥”µ⁄“ª∏ˆ≥°æ∞Ω¯»Îµ⁄∂˛∏ˆ≥°æ∞
    //bool gamesecondgonext;// «∑Òø…“‘¥”µ⁄∂˛∏ˆ≥°æ∞Ω¯»Îµ⁄»˝∏ˆ≥°æ∞
    bool gamesecondgoto1;// «∑Ò¥Úø™π˝π◊≤ƒ1
    bool gamesecondgoto2;// «∑Ò¥Úø™π˝π◊≤ƒ2
    bool gamesecondgoto3;// «∑Ò¥Úø™π˝π◊≤ƒ3
    bool gamesecondgoto4;// «∑Ò¥Úø™π˝π◊≤ƒ4
    bool gamesecondgoto5;// «∑Ò¥Úø™π˝π◊≤ƒ5
    bool gamesecondgoto6;// «∑Ò¥Úø™π˝π◊≤ƒ6
    bool gamesecondgoto7;// «∑Ò¥Úø™π˝π◊≤ƒ7
    int num;//œ÷‘⁄◊‹π≤”–∂‡…ŸΩ© ¨
    bool whetheropen;//“—∞¥π˝"open the door"∞¥≈•
    Vec2 leaderPosition1;//≥°æ∞“ª÷–ƒ–÷˜µƒŒª÷√
    Vec2 friendPosition1;//≥°æ∞“ª÷–≈Û”—µƒŒª÷√
    Vec2 leaderPosition2;//≥°æ∞∂˛÷–ƒ–÷˜µƒŒª÷√
    Vec2 friendPosition2;//≥°æ∞∂˛÷–≈Û”—µƒŒª÷√
    Vec2 leaderPosition3;//≥°æ∞»˝÷–ƒ–÷˜µƒŒª÷√
    Vec2 friendPosition3;//≥°æ∞»˝÷–≈Û”—µƒŒª÷√
    Zcontrol();
    Scene * loadScene;
    Scene * infoScene;
    Scene * startScene;
    Scene * gameFirst;
    Scene * gameSecond;
    Scene * gameThird;
    Scene * shopScene;
    Scene * quaScene;
    Scene * winScene;
    Scene * loseScene;
    Scene * pausedScene;
    
    
    Enemy * enemies[10];

    
    void createLoadScene();
    void goInfoScene();
    void goStartScene();
    void goGameFirst();
    void goGameSecond();
    void goGameThird();
    void goShopScene();
    void goQuaScene();
    void goWinScene();
    void goLoseScene();
    void goPausedScene();
    
    void enemiesmove( Layer* layer);
    void enemiesattack();
    void friendmove();

};


#endif /* Zcontrol_hpp */
