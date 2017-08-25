#include"cocos2d.h"
#include"Leader.h"
#include"base\CCEventKeyboard.h"
#include"proj.win32\Character.h"
//方向1为上，2为下，3为左，4为右
static bool deter = false;
USING_NS_CC;
Leader::Leader()
{
	left=nullptr;//向左走的动画
	right = nullptr;//向右走的动画
	ahead = nullptr;//向前走的动画
	back = nullptr;//向后走的动画
	int time = 10;
	int timelimit = 10;
	int money = 0;
	EventListenerKeyboard* listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event*event) {
		log("2");
		extern Leader* leader;
		leader->determine(keyCode,event);
	};
	listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event*event) {
		deter = true;
	};
	EventDispatcher*eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void Leader::addtime(int num) {
	if (time + num > timelimit)
		time = timelimit;
	else
		time += num;
}
void Leader::addMoney(int num) {
	money += num;
}
/*KEY_DPAD_RIGHT,
KEY_DPAD_UP,
KEY_DPAD_DOWN,
KEY_DPAD_CENTER*/
void Leader::determine(EventKeyboard::KeyCode keyCode, Event*event) {
	deter = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
	    schedule(CC_CALLBACK_0(Leader::goLeft, this), 0.2f, "123");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		schedule(CC_CALLBACK_0(Leader::goRight, this), 0.2f, "123");
		goRight();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		schedule(CC_CALLBACK_0(Leader::goAhead, this), 0.2f, "123");
		goAhead();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		schedule(CC_CALLBACK_0(Leader::goBack, this), 0.4f, "123");
		goBack();
	}
}
void Leader::goLeft() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, Vec2(-10, 0));
	if (deter == true)
		unschedule("123");
	else if(getPosition().x - getContentSize().width / 2>origin.x){
		if (left != nullptr) {
			FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)left, 1));
			this->runAction(Spawn::create(ac1, move, NULL));
		}
		else
			this->runAction(ac1);
	}
}
void Leader::goRight() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, Vec2(10, 0));
	if (deter == true)
		unschedule("123");
	else if(getPosition().x+getContentSize().width/2<origin.x+visibleSize.width){
		if (right != nullptr) {
			FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)right, 1));
			this->runAction(Spawn::create(ac1, move, NULL));
		}
		else
			this->runAction(ac1);
	}
}
void Leader::goAhead() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, Vec2(0, 10));//面朝观众
	if (deter == true)
		unschedule("123");
	else if(getPosition().y + getContentSize().height / 2<origin.y + visibleSize.height){
		if (left!= nullptr) {
			FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)ahead, 1));
			this->runAction(Spawn::create(ac1, move, NULL));
		}
		else
			this->runAction(ac1);
	}
}
void Leader::goBack() {//面朝观众
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, Vec2(0, -10));
	if (deter == true)
		unschedule("123");
	else if(getPosition().y - getContentSize().height / 2>origin.y){
		if (left != nullptr) {
			FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)back, 1));
			this->runAction(Spawn::create(ac1, move, NULL));
		}
		else
			this->runAction(ac1);
	}
}
Leader::~Leader() {
	delete left;
	delete right;
	delete ahead;
	delete back;
}