//
//  GameThird.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#ifndef GameThird_hpp
#define GameThird_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;


#endif /* InfoLayer_hpp */
class GameThird:public Layer{
public:
    Menu *menu;
    CREATE_FUNC(GameThird);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    void  menuShopCallBack(Ref * pSender);
    void  menuCaseCallBack(Ref * pSender);
    void  menuBaCallBack(Ref * pSender);
    void pause(Ref* pSender);
     void updateCustom(float f);
    
public:
    Zcontrol * tsm;
    Sprite * sprites;
    std::vector<std::string> spritePaths;
    int count;
};
