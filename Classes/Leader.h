#ifndef __LEADER_H__
#define __LEADER_H__
#include"Character.h"
#include"cocos2d.h"
using namespace cocos2d;
class Leader :public Character {
	int time;
	int timelimit;
	int money;
	Animation*left;//向左走的动画
	Animation*right;//向右走的动画
	Animation*ahead;//向前走的动画
	Animation*back;//向后走的动画
				   /*************************
				   *
				   *
				   *
				   *此处可构建动画
				   *
				   *
				   *
				   **************************/
public:
	Leader();
	~Leader();
	void addtime(int);
	void addMoney(int);
	void goLeft();
	void goRight();
	void goAhead();
	void goBack();
	void determine(EventKeyboard::KeyCode, Event*event);
};
#endif
