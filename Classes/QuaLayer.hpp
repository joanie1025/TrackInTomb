//
//  QuaLayer.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/26.
//
//

#ifndef QuaLayer_hpp
#define QuaLayer_hpp

#include "Zcontrol.hpp"
USING_NS_CC;

#endif /* QuaLayer_hpp */
class QuaLayer:public Layer{
public:
    CREATE_FUNC(QuaLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
    
    
public:
    Zcontrol * tsm;
    
};
