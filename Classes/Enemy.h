#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Enemy :public Character {
	int attacktimes;
public:
	/*FiniteTimeAction*left1;//�����ߵĶ���
	FiniteTimeAction*right1;//�����ߵĶ���
	FiniteTimeAction*ahead;//��ǰ�ߵĶ���
	FiniteTimeAction*back;//����ߵĶ���*/
	Enemy();
	double getDistance();
	void move();
	void changeDirection(int);
};
#endif

