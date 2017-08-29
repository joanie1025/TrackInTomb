//
//  JShopLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//




#ifndef ShopLayer_hpp
#define ShopLayer_hpp

#include "Zcontrol.hpp"
USING_NS_CC;

#endif /* ShopLayer_hpp */

class JShopLayer: public Layer{
public:
    CREATE_FUNC(JShopLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
    
};
