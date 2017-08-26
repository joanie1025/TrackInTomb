#include"cocos2d.h"
#include"Leader.h"
#include "base/CCEventKeyboard.h"
#include"Character.h"
 USING_NS_CC;

static bool deter1 = 0;
static bool deter2= 0;
static bool deter3 = 0;
static bool deter4 = 0;
USING_NS_CC;
bool Leader::init(){
    return true;
}

Leader::Leader():Character(0) {
	
	left=nullptr;
	right = nullptr;//向右走的动画
	ahead = nullptr;//向前走的动画
	back = nullptr;//向后走的动画
	int time = 10;
	int timelimit = 10;
	int money = 0;
	bool attackdeter = false;
	EventListenerKeyboard* listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event*event) {
		extern Leader* leader;
		if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
			keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW
			|| keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
			leader->determine(keyCode, event);
		else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
			leader->attackdeter=true;
	};
	listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event*event) {
		extern Leader*leader;
		if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
			deter1 = 0;
		else if(keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
			deter3 = 0;
		else if(keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
			deter2 = 0;
		else if(keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
			deter4 = 0;
		else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
			leader->attackdeter = false;
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
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		deter1 = 1;
	    schedule(CC_CALLBACK_0(Leader::goLeft, this), 0.3f, "1");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		deter2 = 1;
		schedule(CC_CALLBACK_0(Leader::goRight, this), 0.3f, "2");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		deter3 = 1;
		schedule(CC_CALLBACK_0(Leader::goAhead, this), 0.3f, "3");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		deter4 = 1;
		schedule(CC_CALLBACK_0(Leader::goBack, this), 0.3f, "4");
	}
}
void Leader::goLeft() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	FiniteTimeAction*ac1 = MoveBy::create(0.3f, Vec2(-12, 0));
	if (deter1 == false)
		unschedule("1");
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
	FiniteTimeAction*ac1 = MoveBy::create(0.3f, Vec2(12, 0));
	if (deter2 == false)
		unschedule("2");
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
	FiniteTimeAction*ac1 = MoveBy::create(0.3f, Vec2(0, 12));//面朝观众
	if (deter3 == false)
		unschedule("3");
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
	FiniteTimeAction*ac1 = MoveBy::create(0.3f, Vec2(0, -12));
	if (deter4 == false)
		unschedule("4");
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
