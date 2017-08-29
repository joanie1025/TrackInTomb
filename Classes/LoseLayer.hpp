//
//  LoseLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#ifndef LoseLayer_hpp
#define LoseLayer_hpp

#include <stdio.h>

#endif /* LoseLayer_hpp */
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;


class LoseLayer:public Layer{
public:
    CREATE_FUNC(LoseLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
};
