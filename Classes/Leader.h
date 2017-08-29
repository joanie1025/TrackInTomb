#ifndef __LEADER_H__
#define __LEADER_H__
#include"Character.h"
#include"cocos2d.h"
#include"Enemy.h"
USING_NS_CC;
using namespace cocos2d;

class Leader :public Character{
    int time;
    int timelimit;
    int money;
    /*	Animation*left;//œÚ◊Û◊ﬂµƒ∂Øª≠
     Animation*right;//œÚ”“◊ﬂµƒ∂Øª≠
     Animation*ahead;//œÚ«∞◊ﬂµƒ∂Øª≠
     Animation*back;//œÚ∫Û◊ﬂµƒ∂Øª≠*/
    /*************************
     *
     *
     *
     *¥À¥¶ø…ππΩ®∂Øª≠
     *
     *
     *
     **************************/
public:
    int getTime();
    void setTime(int& x);
    Vec2 rect[7];
    Vec2 poolplace;
    bool whethergoon;//µ–»À «∑ÒºÃ–¯ ‹µΩ…À∫¶
    bool attackdeter;//ÕÊº“ «∑Ò‘⁄π•ª˜
    Leader();
    ~Leader();
    void addtime(int);
    void addMoney(int);
    void goLeft();
    void goRight();
    void goAhead();
    void goBack();
    void determine(EventKeyboard::KeyCode, Event*event);
    void changeTheDirection(int);
    void gameover();
    void doattackit();
};
#endif
