#ifndef __LEADER_H__
#define __LEADER_H__
#include"Character.h"
#include"cocos2d.h"
USING_NS_CC;
using namespace cocos2d;

class Leader:public Character {
	int time;
	int timelimit;
	int money;
	Animation*left;
	Animation*right;
	Animation*ahead;
	Animation*back;
public:
	bool attackdeter;
	Leader();
	~Leader();
    CREATE_FUNC(Leader);
    virtual bool init();
	void addtime(int);
	void addMoney(int);
	void goLeft();
	void goRight();
	void goAhead();
	void goBack();
	void determine(EventKeyboard::KeyCode, Event*event);
};
#endif
