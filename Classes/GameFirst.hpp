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
USING_NS_CC;

#endif /* GameFirst_hpp */


class GameFirst:public Layer{
public:
    CREATE_FUNC(GameFirst);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
};
