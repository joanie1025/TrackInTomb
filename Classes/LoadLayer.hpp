//
//  LoadLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef LoadLayer_hpp
#define LoadLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"
USING_NS_CC;

#endif /* LoadLayer_hpp */
class LoadLayer:public Layer{
public:
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    void onScheduleOnce(float dt);
    
    
public:
    Zcontrol * tsm;
    
};
