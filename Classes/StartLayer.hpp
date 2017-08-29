//
//  StartLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef StartLayer_hpp
#define StartLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"

USING_NS_CC;
#endif /* StartLayer_hpp */
class StartLayer:public Layer{
public:
    CREATE_FUNC(StartLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    void onEnter();
    
public:
    Zcontrol * tsm;
    
};
