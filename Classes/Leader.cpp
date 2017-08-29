#include"cocos2d.h"
#include"Leader.h"
#include "base/CCEventKeyboard.h"
#include"Character.h"
static bool deter1 = 0;
static bool deter2= 0;
static bool deter3 = 0;
static bool deter4 = 0;
USING_NS_CC;
int gamenumber = 0;//此时玩家处于场景几
Leader::Leader()
:  Character(0) {
    time = 0;
    timelimit = 140;
    money = 0;
    attackdeter = false;
    whethergoon = false;
    EventListenerKeyboard* listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event*event) {
        extern Leader* leader;
        if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
            keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW
            || keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
            leader->determine(keyCode, event);
        else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
            if (leader->getDirection() == 1)
                leader->setTexture("res/back_hf/1.png");
            else if(leader->getDirection() == 2)
                leader->setTexture("res/ahead_hf/1.png");
            else if (leader->getDirection() == 3)
                leader->setTexture("res/left_hf/1.png");
            else if (leader->getDirection() == 4)
                leader->setTexture("res/right_hf/1.png");
            leader->attackdeter = true;
            leader->whethergoon = true;
            leader->determine(keyCode, event);
        }
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
        else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
            leader->attackdeter = false;
            leader->whethergoon = false;
        }
    };
    EventDispatcher*eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener,mySprite);
}
int Leader::getTime(){
    return time;
}
void Leader::setTime(int& x){
    this->time=x;
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
void Leader::determine(EventKeyboard::KeyCode keyCode, Event*event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
        attackdeter = true;
        whethergoon = true;
        mySprite->schedule(CC_CALLBACK_0(Leader::doattackit, this), 0.5f, "565");
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
        deter1 = 1;
        mySprite->schedule(CC_CALLBACK_0(Leader::goLeft, this), 0.5f, "1");
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        deter2 = 1;
        mySprite->schedule(CC_CALLBACK_0(Leader::goRight, this), 0.5f, "2");
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
        deter3 = 1;
        mySprite->schedule(CC_CALLBACK_0(Leader::goAhead, this), 0.5f, "3");
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
        deter4 = 1;
        mySprite->schedule(CC_CALLBACK_0(Leader::goBack, this), 0.5f, "4");
    }
    /*else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
     attackdeter = true;
     whethergoon = true;
     mySprite->schedule(CC_CALLBACK_0(Leader::doattackit, this), 0.4f, "565");
     }*/
}
void Leader::goLeft() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (deter1 == false) {
        mySprite->unschedule("1");
        this->mySprite->stopAllActions();
        if (attackdeter == false)
            this->setTexture("res/left_h/1.png");//重新设置图像
        if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                 + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45 && gamenumber == 2)
            gameover();
    }
    else if(getPosition().x - getContentSize().width / 2 > origin.x) {
        bool whethercanmove = true;
        if (gamenumber == 2) {
            int x = getPosition().x;
            int y = getPosition().y - mySprite->getContentSize().height / 2;
            for (int i = 0; i < 7; i++) {
                if (y > rect[i].y - 45 && y<rect[i].y + 30 && x<rect[i].x +40 && x > rect[i].x) {
                    whethercanmove = false;
                }
            }
        }//*************************************************************************************
        else if (gamenumber == 3) {
            Vec2 cannotgo=Vec2(origin.x + visibleSize.width*0.45, origin.y + visibleSize.height*0.62 + mySprite->getContentSize().height / 2);
            /*if (abs(getPosition().y-mySprite->getContentSize().height/2-
             (origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))<50 &&
             getPosition().x<origin.x + visibleSize.width*0.45 + 80 && getPosition().x>origin.x + visibleSize.width*0.45) {*/
            if((abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x)) / sqrt(2)>30 ||
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x-20))>
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))
                ) && getPosition().x>origin.x + visibleSize.width*0.45 - 30 && getPosition().x<origin.x + visibleSize.width*0.45 + 30){
                int x = getPosition().x;
                int y = getPosition().y ;
                whethercanmove = false;
            }
        }
        if (whethercanmove == true) {
            if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                     + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45 && gamenumber == 2)
                gameover();
            FiniteTimeAction*ac1 = MoveBy::create(0.5f, Vec2(-20, 0));
            this->runAction(ac1);
            if (attackdeter == false&&getDirection()!=3)
                this->setTexture("res/left_h/1.png");//重新设置图像
            if (attackdeter == true && getDirection() != 3) {
                changeDirection(3);
                //setTexture("fight/Left/1.png");
            }
            else
                this->changeTheDirection(3);
        }
    }
}
void Leader::goRight() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (deter2 == false) {
        mySprite->unschedule("2");
        this->mySprite->stopAllActions();
        if(attackdeter==false)
            this->setTexture("res/right_h/1.png");//重新设置图像
        if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                 + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45 && gamenumber == 2)
            gameover();
    }
    else if (getPosition().x + getContentSize().width / 2 < origin.x + visibleSize.width) {
        
        bool whethercanmove = true;
        if (gamenumber == 2) {
            int x = getPosition().x;
            int y = getPosition().y - mySprite->getContentSize().height / 2;
            for (int i = 0; i < 7; i++) {
                if (y > rect[i].y - 45 && y < rect[i].y + 30 && x > rect[i].x -40 && x < rect[i].x ) {
                    whethercanmove = false;
                }
            }
        }
        //*************************************************************************************
        else if (gamenumber == 3) {
            Vec2 cannotgo = Vec2(origin.x + visibleSize.width*0.45, origin.y + visibleSize.height*0.62 + mySprite->getContentSize().height / 2);
            /*	if (abs(getPosition().y - mySprite->getContentSize().height / 2-(
             origin.y + visibleSize.height*0.62  - origin.x - visibleSize.width*0.45 + getPosition().x))<50&&
             getPosition().x>origin.x + visibleSize.width*0.45 - 80 && getPosition().x<origin.x + visibleSize.width*0.45) {*/
            if((abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))/sqrt(2)>20||
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x+20))>
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))
                )&& getPosition().x>origin.x + visibleSize.width*0.45 - 30 && getPosition().x<origin.x + visibleSize.width*0.45+30){
                whethercanmove = false;
            }
        }
        if (whethercanmove == true) {
            if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                     + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45&&gamenumber == 2)
                gameover();
            FiniteTimeAction*ac1 = MoveBy::create(0.5f, Vec2(20, 0));
            this->runAction(ac1);
            if (attackdeter == false && getDirection() != 4)
                this->setTexture("res/right_h/1.png");//重新设置图像
            if (attackdeter == true && getDirection() != 4) {
                changeDirection(4);
                //	setTexture("fight/Right/1.png");
            }
            else
                this->changeTheDirection(4);
            
            /*		Animation * animation2 = Animation::create();
             SpriteFrame * spriteFrame5 = SpriteFrame::create("Down/1.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("Down/2.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("Down/3.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("Down/4.png", Rect(0, 0, 50, 85));
             animation2->addSpriteFrame(spriteFrame5);
             animation2->addSpriteFrame(spriteFrame6);
             animation2->addSpriteFrame(spriteFrame7);
             animation2->addSpriteFrame(spriteFrame8);
             animation2->setDelayPerUnit(0.1f);
             animation2->setRestoreOriginalFrame(true);
             Animate* action2 = Animate::create(animation2);
             FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
             
             
             Animation * animation2 = Animation::create();
             SpriteFrame * spriteFrame5 = SpriteFrame::create("leader/1.png", Rect(0, 0, 50, 120));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("leader/2.png", Rect(0, 0, 50, 120));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("leader/3.png", Rect(0, 0, 50, 120));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("leader/4.png", Rect(0, 0, 50, 120));
             SpriteFrame * spriteFrame9 = SpriteFrame::create("leader/5.png", Rect(0, 0, 50, 120));
             SpriteFrame * spriteFrame10 = SpriteFrame::create("leader/6.png", Rect(0, 0, 50, 120));
             animation2->addSpriteFrame(spriteFrame5);
             animation2->addSpriteFrame(spriteFrame6);
             animation2->addSpriteFrame(spriteFrame7);
             animation2->addSpriteFrame(spriteFrame8);
             animation2->addSpriteFrame(spriteFrame9);
             animation2->addSpriteFrame(spriteFrame10);
             animation2->setDelayPerUnit(0.1f);
             animation2->setRestoreOriginalFrame(true);
             Animate* action2 = Animate::create(animation2);
             FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
             back->setTag(22);
             this->runAction(back);*/
        }
    }
}
void Leader::goAhead() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (deter3 == false) {
        mySprite->unschedule("3");
        if (attackdeter == false)
            this->setTexture("res/back_h/1.png");//重新设置图像
        this->mySprite->stopAllActions();
        if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                 + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45 && gamenumber == 2)
            gameover();
    }
    else if((gamenumber!=1||getPosition().y<origin.y + visibleSize.height*0.3)
            &&getPosition().y - getContentSize().height / 2<origin.y + visibleSize.height-30){//设置人物不同场景时向上走不可超过的范围
        bool whethercanmove = true;
        if (gamenumber == 2) {
            int x = getPosition().x;
            int y = getPosition().y - mySprite->getContentSize().height / 2;
            for (int i = 0; i < 7; i++) {
                //if (rect[i].containsPoint(getPosition())&&getPosition().y>(rect[i].getMaxY()+ rect[i].getMinY())/2 -((rect[i].getMaxY() + rect[i].getMinY()) / 2)+20)
                if (x > rect[i].x - 40 && x<rect[i].x + 40 && y>rect[i].y - 45 && y<rect[i].y) {
                    whethercanmove = false;
                }
            }
        }
        //*************************************************************************************
        else if (gamenumber == 3) {
            Vec2 cannotgo = Vec2(origin.x + visibleSize.width*0.45, origin.y + visibleSize.height*0.62 + mySprite->getContentSize().height / 2);
            /*if (getPosition().y -mySprite->getContentSize().height / 2 -
             (origin.y + visibleSize.height*0.62  - origin.x - visibleSize.width*0.45 + getPosition().x)>-50&&
             getPosition().x>origin.x + visibleSize.width*0.45 - 80 && getPosition().x<origin.x + visibleSize.width*0.45 + 80) {*/
            if((abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x)) / sqrt(2)>20 ||
                abs(getPosition().y+20 - mySprite->getContentSize().height / 2 - (
                                                                                  origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x ))>
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))
                ) && getPosition().x>origin.x + visibleSize.width*0.45 - 30 && getPosition().x<origin.x + visibleSize.width*0.45 + 30){
                whethercanmove = false;
            }
        }
        if (whethercanmove == true) {
            if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                     + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45&&gamenumber==2)
                gameover();
            FiniteTimeAction*ac1 = MoveBy::create(0.5f, Vec2(0, 20));//面朝观众
            this->runAction(ac1);
            if(attackdeter==false)
                this->setTexture("res/back_h/1.png");//重新设置图像
            if (attackdeter == true && getDirection() != 1) {
                changeDirection(1);
                //	setTexture("actor/Up/1.png");
            }
            else
                this->changeTheDirection(1);
            
        }
    }
}
void Leader::goBack() {//面朝观众
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (deter4 == false) {
        mySprite->unschedule("4");
        this->mySprite->stopAllActions();
        if (attackdeter == false)
            this->setTexture("res/ahead_h/1.png");//重新设置图像
        if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                 + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45&&gamenumber == 2)
            gameover();
    }
    else if(getPosition().y - getContentSize().height / 2>origin.y){
        bool whethercanmove = true;
        if (gamenumber == 2) {
            int x = getPosition().x;
            int y = getPosition().y - mySprite->getContentSize().height / 2;
            for (int i = 0; i < 7; i++) {
                if (x > rect[i].x - 30 && x < rect[i].x + 30 && y < rect[i].y + 30&&y>rect[i].y) {
                    whethercanmove = false;
                }
            }
        }
        //*************************************************************************************
        else if (gamenumber == 3) {
            Vec2 cannotgo = Vec2(origin.x + visibleSize.width*0.45, origin.y + visibleSize.height*0.62 + mySprite->getContentSize().height / 2);
            /*if (getPosition().y - mySprite->getContentSize().height / 2 -
             (origin.y + visibleSize.height*0.62  - origin.x - visibleSize.width*0.45 + getPosition().x)<50&&
             getPosition().x>origin.x + visibleSize.width*0.45-80&& getPosition().x<origin.x + visibleSize.width*0.45 + 80) {*/
            if((abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x)) / sqrt(2)>20 ||
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 -20- origin.x - visibleSize.width*0.45 + getPosition().x )) >
                abs(getPosition().y - mySprite->getContentSize().height / 2 - (
                                                                               origin.y + visibleSize.height*0.62 - origin.x - visibleSize.width*0.45 + getPosition().x))
                ) && getPosition().x>origin.x + visibleSize.width*0.45 - 30 && getPosition().x<origin.x + visibleSize.width*0.45 + 30){
                whethercanmove = false;
            }
        }
        if (whethercanmove == true) {
            if (sqrt((getPosition().x - origin.x - visibleSize.width + 40)*(getPosition().x - origin.x - visibleSize.width + 55)
                     + (getPosition().y - origin.y - visibleSize.height + 40)* (getPosition().y - origin.y - visibleSize.height + 35))<45&&gamenumber == 2)
                gameover();
            FiniteTimeAction*ac1 = MoveBy::create(0.5f, Vec2(0, -20));
            this->runAction(ac1);
            if (attackdeter == false)
                this->setTexture("res/ahead_h/1.png");//重新设置图像
            if (attackdeter == true && getDirection() != 2) {
                changeDirection(2);
                //setTexture("actor/Down/1.png");
            }
            else
                changeTheDirection(2);
            /*
             Animation * animation2 = Animation::create();
             SpriteFrame * spriteFrame5 = SpriteFrame::create("antor/Down/1.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("antor/Down/2.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("antor/Down/3.png", Rect(0, 0, 50, 85));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("antor/Down/4.png", Rect(0, 0, 50, 85));
             animation2->addSpriteFrame(spriteFrame5);
             animation2->addSpriteFrame(spriteFrame6);
             animation2->addSpriteFrame(spriteFrame7);
             animation2->addSpriteFrame(spriteFrame8);
             animation2->setDelayPerUnit(0.1f);
             animation2->setRestoreOriginalFrame(true);
             Animate* action2 = Animate::create(animation2);
             FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
             this->runAction(back);
             */
        }
    }
}
Leader::~Leader() {
    /*delete left;
     delete right;
     delete ahead;
     delete back;*/
}
void Leader::changeTheDirection(int direction) {
    if (direction == 2) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/ahead_h/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/ahead_h/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/ahead_h/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/ahead_h/4.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        Character::changeDirection(2);
        mySprite->stopAllActionsByTag(123);
        back->setTag(123);
        this->runAction(back);
        //this->setTexture("actor/Down/1.png");
    }
    else if (direction == 1) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/back_h/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/back_h/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/back_h/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/back_h/4.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        Character::changeDirection(1);
        mySprite->stopAllActionsByTag(123);
        back->setTag(123);
        this->runAction(back);
        Character::changeDirection(1);
        //this->setTexture("actor/Up/1.png");
    }
    else if (direction == 4) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/right_h/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/right_h/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/right_h/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/right_h/4.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        Character::changeDirection(4);
        mySprite->stopAllActionsByTag(123);
        back->setTag(123);
        this->runAction(back);
        Character::changeDirection(4);
        //this->setTexture("actor/Right/1.png");
    }
    else if (direction == 3) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/left_h/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/left_h/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/left_h/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/left_h/1.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        Character::changeDirection(3);
        mySprite->stopAllActionsByTag(123);
        back->setTag(123);
        this->runAction(back);
        //	this->setTexture("actor/Left/1.png");
    }
}
void Leader::gameover() {
    log("gameover");
}
void Leader::doattackit() {
    if (getDirection() == 1&&attackdeter==true) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/back_hf/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/back_hf/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/back_hf/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/back_hf/1.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        //Character::changeDirection(2);
        mySprite->stopAllActionsByTag(123);
        //this->setTexture("fight/Up/1.png");
        back->setTag(123);
        this->runAction(back);
        //
    }
    else if (getDirection() == 2 && attackdeter == true) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/ahead_hf/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/ahead_hf/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/ahead_hf/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/ahead_hf/1.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        //Character::changeDirection(2);
        mySprite->stopAllActionsByTag(123);
        //this->setTexture("fight/Down/1.png");
        back->setTag(123);
        this->runAction(back);
        //
    }
    else if (getDirection() == 3 && attackdeter == true) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/left_hf/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/left_hf/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/left_hf/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/left_hf/1.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        //Character::changeDirection(2);
        mySprite->stopAllActionsByTag(123);
        //this->setTexture("fight/Left/1.png");
        back->setTag(123);
        this->runAction(back);
        //
    }
    else if (getDirection() == 4 && attackdeter == true) {
        Animation * animation2 = Animation::create();
        SpriteFrame * spriteFrame5 = SpriteFrame::create("res/right_hf/1.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame6 = SpriteFrame::create("res/right_hf/2.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame7 = SpriteFrame::create("res/right_hf/3.png", Rect(0, 0, 82, 137));
        SpriteFrame * spriteFrame8 = SpriteFrame::create("res/right_hf/1.png", Rect(0, 0, 82, 137));
        animation2->addSpriteFrame(spriteFrame5);
        animation2->addSpriteFrame(spriteFrame6);
        animation2->addSpriteFrame(spriteFrame7);
        animation2->addSpriteFrame(spriteFrame8);
        animation2->setDelayPerUnit(0.1f);
        animation2->setRestoreOriginalFrame(true);
        Animate* action2 = Animate::create(animation2);
        FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
        //Character::changeDirection(2);
        mySprite->stopAllActionsByTag(123);
        //this->setTexture("fight/Right/1.png");
        back->setTag(123);
        this->runAction(back);
        //
    }
    else if (attackdeter == false) {
        mySprite->unschedule("565");
        mySprite->stopAllActionsByTag(123);
    }
}
