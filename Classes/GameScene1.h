#ifndef __GAMESCENE1_H__
#define __GAMESCENE1_H__
#include "cocos2d.h"
#include"Enemy.h"
using namespace cocos2d;
class GameScene1 : public cocos2d::Scene
{
	Enemy*enemies;
	int num;
public:
	~GameScene1();
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void onExit();
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene1);
	void enemiesmove(float);
};
#endif // __HELLOWORLD_SCENE_H__


