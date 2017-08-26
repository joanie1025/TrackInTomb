//
//  GameSecond.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef GameSecond_hpp
#define GameSecond_hpp

#include <stdio.h>


#include <stdio.h>
#include "cocos2d.h"
#include "Zcontrol.hpp"
#include "ui/CocosGUI.h"
#include "cocostudio/cocoStudio.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;
#endif /* GameSecond_hpp */
class GameSecond:public Layer{

public:
    CREATE_FUNC(GameSecond);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;



};
