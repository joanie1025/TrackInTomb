//
//  InfoLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef InfoLayer_hpp
#define InfoLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;

#endif /* InfoLayer_hpp */
class InfoLayer:public Layer{
public:
    CREATE_FUNC(InfoLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
};
