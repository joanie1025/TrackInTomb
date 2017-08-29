//
//  WinLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#ifndef WinLayer_hpp
#define WinLayer_hpp

#include <stdio.h>

#endif /* WinLayer_hpp */
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;


class WinLayer:public Layer{
public:
    CREATE_FUNC(WinLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
};
