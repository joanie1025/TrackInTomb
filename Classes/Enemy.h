#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Enemy :public Character {
	int attacktimes;
public:
	Animation*left;//�����ߵĶ���
	Animation*right;//�����ߵĶ���
	Animation*ahead;//��ǰ�ߵĶ���
	Animation*back;//����ߵĶ���
	Enemy();
	double getDistance();
	void move();
};
#endif

