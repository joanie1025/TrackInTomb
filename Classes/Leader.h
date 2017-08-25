#ifndef __LEADER_H__
#define __LEADER_H__
#include"Character.h"
#include"cocos2d.h"
using namespace cocos2d;
class Leader :public Character {
	int time;
	int timelimit;
	int money;
	Animation*left;//�����ߵĶ���
	Animation*right;//�����ߵĶ���
	Animation*ahead;//��ǰ�ߵĶ���
	Animation*back;//����ߵĶ���
				   /*************************
				   *
				   *
				   *
				   *�˴��ɹ�������
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
