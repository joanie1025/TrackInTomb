//
//  PausedScene.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/28.
//
//

#ifndef PausedScene_hpp
#define PausedScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;

#endif /* PausedScene_hpp */
class PausedScene :public Layer{
public:
    CREATE_FUNC(PausedScene);
    virtual bool init();
    void back(Ref * pSender);
    
public:
    Zcontrol * tsm;
    
    
};
