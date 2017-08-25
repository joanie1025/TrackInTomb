#include "GameScene1.h"
#include "SimpleAudioEngine.h"
#include"Leader.h"
USING_NS_CC;
Leader*leader = new Leader;
Scene* GameScene1::createScene()
{
	return GameScene1::create();
}

// on "init" you need to initialize your instance
bool GameScene1::init()
{
	num = 0;
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	leader->setTexture("leader.png");
	addChild(leader);
	this->schedule(schedule_selector(GameScene1::enemiesmove), 0.4f, kRepeatForever, 0);
	return true;
}
void GameScene1::enemiesmove(float dt) {
	for (int i = 0; i < num; i++) {
		enemies[i].move();
	}
	//log("1");
}
void GameScene1::onExit() {
	unscheduleAllCallbacks();
	unscheduleAllSelectors();
}
GameScene1::~GameScene1() {
	delete[]enemies;
}
