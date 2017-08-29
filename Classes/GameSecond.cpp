//
//  GameSecond.cpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//
#include<ctime>
#include "GameSecond.hpp"
extern Leader* leader;
extern Friend* myFriend;
extern int frienddeter;
extern bool whetherfriend;
extern int gamenumber;
bool startenemies;
bool friendstart;
bool GameSecond::init(){
    friendstart=false;
    startenemies = false;
    //whetherfriend = true;
    Vec2 before=leader->getPosition();
    int time=leader->getTime();
    delete leader;
    leader = new Leader;
    leader->setTime(time);
    leader->setPosition(before);
    if (whetherfriend == true) {
        before = myFriend->getPosition();
        delete myFriend;
        myFriend = new Friend;
        myFriend->setPosition(before);
    }
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize=Director::getInstance()->getVisibleSize();
    
    
    if (whetherfriend == true) {
        if (myFriend != nullptr) {
            Vec2 before = myFriend->getPosition();
            delete myFriend;
            myFriend = new Friend;
            myFriend->setPosition(before);
        }
        else
            myFriend = new Friend;
    }
    
    spritePaths.push_back("res/shalou/1.png");
    spritePaths.push_back("res/shalou/2.png");
    spritePaths.push_back("res/shalou/3.png");
    spritePaths.push_back("res/shalou/4.png");
    spritePaths.push_back("res/shalou/5.png");
    spritePaths.push_back("res/shalou/6.png");
    spritePaths.push_back("res/shalou/7.png");
    spritePaths.push_back("res/shalou/8.png");
    count=leader->getTime();
    if(count<1)
        sprites=Sprite::create("res/shalou/1.png");
    else if(count<2)
        sprites=Sprite::create("res/shalou/2.png");
    else if(count<3)
        sprites=Sprite::create("res/shalou/3.png");
    else if(count<4)
        sprites=Sprite::create("res/shalou/4.png");
    else if(count<5)
        sprites=Sprite::create("res/shalou/5.png");
    else if(count<6)
        sprites=Sprite::create("res/shalou/6.png");
    else if(count<7)
        sprites=Sprite::create("res/shalou/7.png");
    else if(count<8)
        sprites=Sprite::create("res/shalou/8.png");
    else
        Director::getInstance()->end();
    
    sprites->setPosition(Vec2(winSize.width*0.03, winSize.height*0.2));
    this->addChild(sprites,9);
    
    float interval = 5.0f;
    schedule(schedule_selector(GameSecond::updateCustom), interval, kRepeatForever, 0);
    sprites->setTexture(spritePaths[count]);
    
   
    
    
    
    auto sprite = Sprite::create("res/beijing2.png");
    sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    
    sprite->setScale(0.75);
    
    this->addChild(sprite, 0);
    addChild(leader->mySprite, 3);//¥Ê“…£¨Œ™ ≤√¥…æ»•ª·”–Œ Ã‚
    if (whetherfriend == true) {
        addChild(myFriend->mySprite, 2);//¥Ê“…£¨Œ™ ≤√¥…æ»•ª·”–Œ Ã‚
        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
        friendstart = true;
    }
    MenuItemImage* dItemImage = MenuItemImage::create("res/pause.png","res/pause.png",CC_CALLBACK_1(GameSecond::pause,this));
    dItemImage->setPosition(Vec2(winSize.width*0.95, winSize.height*0.95));
    dItemImage->setScale(0.5);
    auto sprite3 = Sprite::create("res/head.png");
    sprite3->setPosition(Vec2(winSize.width*0.03, winSize.height*0.95));
    
    sprite3->setScale(0.75);
    
    this->addChild(sprite3, 1);
    
    
    
    
    MenuItemLabel *menuItem_3=MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameSecond::menuCallBack, this));
    menuItem_3->setTag(103);
    menuItem_3->setPosition(Vec2(winSize.width*0.9, winSize.height*0.2));
    
    
   MenuItemLabel *menuItem_2=MenuItemLabel::create(Label::createWithTTF("Quit", "fonts/Marker Felt.ttf", 24),CC_CALLBACK_1(GameSecond::menuCallBack, this));
    menuItem_2->setTag(102);
   menuItem_2->setPosition(Vec2(winSize.width*0.9, winSize.height*0.15));
    MenuItemImage* pItemImage = MenuItemImage::create("res/shop.png","res/shop.png",CC_CALLBACK_1(GameSecond::menuShopCallBack,this));
    pItemImage->setPosition(Vec2(winSize.width*0.03, winSize.height*0.1));
    pItemImage->setScale(0.3);
    
   menu=Menu::create(menuItem_2,menuItem_3,dItemImage,pItemImage,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true ;
}
    
void GameSecond::updateCustom(float dt)
{
    if (spritePaths.size()>0)
    {
        sprites->setTexture(spritePaths[count]);
        count++;
        leader->setTime(count);
        if(count>8){
            tsm->goLoseScene();
        }
    }
}


    
    
    
void GameSecond::menuCallBack(Ref * pSender) {
    

        bool addtrue = false;
        //Sprite* moneyget = Sprite::create("res/friend2.png");
        srand(time(0));
        if(frienddeter==0)
            frienddeter = rand()%7+1;
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size winSize = Director::getInstance()->getVisibleSize();
    
   
    
    
        MenuItemLabel *menuItem = MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24), CC_CALLBACK_1(GameSecond::menuCallBack, this));
        menuItem->setTag(101);
        menuItem->setPosition(Vec2(origin.x + winSize.width*0.9, origin.y + winSize.height*0.3));
        switch (((MenuItem *)pSender)->getTag()) {
            case 101:
                tsm->goGameThird();
                break;
            case 103:
                tsm->goGameFirst();
                break;
            case 102:
                Director::getInstance()->end();
                exit(0);
                break;
            case 201:
                tsm->gamesecondgoto1 = true;
                if (frienddeter == 1) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }
                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if(rand()%3==0){
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/1.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f,Vec2(0,0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite,this,moneyget));
                    moneyget->runAction(Sequence::create(ac1,ac2,NULL));
                    /*	clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                
                break;
            case 202:
                tsm->gamesecondgoto2 = true;
                if (frienddeter == 2) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }
                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/2.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    /*clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                
                break;
            case 203:
                tsm->gamesecondgoto3 = true;
                if (frienddeter == 3) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }
                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/3.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    /*clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                break;
            case 204:
                tsm->gamesecondgoto4 = true;
                if (frienddeter == 4) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }

                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/4.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    /*clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //	removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                break;
            case 205:
                tsm->gamesecondgoto5 = true;
                if (frienddeter == 5) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/5.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    /*clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //	removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                break;
            case 206:
                tsm->gamesecondgoto6 = true;
                if (frienddeter == 6) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/6.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    /*clock_t delay = 1 * CLOCKS_PER_SEC;
                     clock_t start = clock();
                     while (clock() - start<delay);*/
                    //	removeChild(moneyget, true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                break;
            case 207:
                tsm->gamesecondgoto7 = true;
                if (frienddeter == 7) {
                    whetherfriend = true;
                    myFriend = new Friend;
                    myFriend->setPosition(((MenuItemImage*)pSender)->getPosition());
                    addChild(myFriend->mySprite, 2);
                    menu->addChild(menuItem);
                    if (friendstart == false) {
                        this->schedule(schedule_selector(GameSecond::friendmove), 1.0f, kRepeatForever, 0);//≈Û”—µƒ“∆∂Ø
                        friendstart = true;
                    }
                    menu->removeChild((MenuItemImage*)pSender, true);
                }
                else if (rand() % 3 == 0) {
                    addtrue = true;
                    Sprite* moneyget = Sprite::create("res/money/7.png");
                    moneyget->setScale(0.755f);
                    moneyget->setPosition(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    addChild(moneyget, 1);
                    FiniteTimeAction*ac1 = MoveBy::create(1.0f, Vec2(0, 0));
                    FiniteTimeAction*ac2 = CallFuncN::create(CC_CALLBACK_0(GameSecond::deletesprite, this, moneyget));
                    moneyget->runAction(Sequence::create(ac1, ac2, NULL));
                    //removeChild(moneyget,true);
                }
                else {
                    addEnemy(((MenuItemImage*)pSender)->getPosition());
                    menu->removeChild((MenuItemImage*)pSender, true);
                    if (startenemies == false) {
                        this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
                        this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
                        startenemies = true;
                    }
                }
                break;
            default:
                break;
        }
    }
    void GameSecond::onEnter() {
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size winSize = Director::getInstance()->getVisibleSize();
                
        
        
        if ((tsm->num) > 0) {
            for (int i = 0; i < 10; i++) {
                if (tsm->enemies[i] != nullptr) {
                    delete tsm->enemies[i];
                    tsm->enemies[i] = nullptr;
                    tsm->num--;
                    addEnemy(Vec2(origin.x + winSize.width / (rand()%4+1), origin.y + winSize.height / (rand()%4+1) / 2));
                }
            }
            this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
            this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
            startenemies = true;
        }
        
        log("onEnter");
        Layer::onEnter();
        gamenumber = 1;
        //------------------------------…Ë÷√÷˜Ω«≈Û”—≥ı ºŒª÷√----------------------------------------
        leader->setPosition(tsm->leaderPosition2);
        if (whetherfriend == true)
            myFriend->setPosition(tsm->friendPosition2);
        //------------------------------…Ë÷√÷˜Ω«≈Û”—≥ı ºŒª÷√----------------------------------------
        //------------------------------------------------------------------------------------------
        //-------------------------------π◊≤ƒ∞¥≈•…Ë÷√-------------------------------------
        
        MenuItemImage *menuItem1;
        if (tsm->gamesecondgoto1 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/1.png", "res/guancai/1.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(201);
            menuItem1->setPosition(Vec2(110,300));
            menuItem1->setScale(0.9);
            menu->addChild(menuItem1);
        }
        
        if (tsm->gamesecondgoto2 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/2.png", "res/guancai/2.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(202);
            menuItem1->setPosition(Vec2(210, 480));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        
        if (tsm->gamesecondgoto3 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/3.png", "res/guancai/3.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(203);
            menuItem1->setPosition(Vec2(405, 450));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        if (tsm->gamesecondgoto4 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/4.png", "res/guancai/4.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(204);
            menuItem1->setPosition(Vec2(490,265));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        if (tsm->gamesecondgoto5 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/5.png", "res/guancai/5.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(205);
            menuItem1->setPosition(Vec2(735,210));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        if (tsm->gamesecondgoto6 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/6.png", "res/guancai/6.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(206);
            menuItem1->setPosition(Vec2(920, 350));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        ;
        if (tsm->gamesecondgoto7 == false) {
            menuItem1 = MenuItemImage::create("res/guancai/7.png", "res/guancai/7.png", CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem1->setTag(207);
            menuItem1->setPosition(Vec2(720, 500));
            menuItem1->setScale(0.75);
            menu->addChild(menuItem1);
        }
        //-------------------------------------µ⁄“ª∏ˆ∞¥≈•…Ë÷√---------------------------------------
        //-------------------------------------≈–∂œ «∑Òƒ‹»•µ⁄∂˛∏ˆ≥°æ∞-------------------------------
        if (whetherfriend == true) {
            MenuItemLabel *menuItem5 = MenuItemLabel::create(Label::createWithTTF("Next", "fonts/Marker Felt.ttf", 24), CC_CALLBACK_1(GameSecond::menuCallBack, this));
            menuItem5->setTag(101);
            menuItem5->setPosition(Vec2(origin.x + winSize.width*0.9, origin.y + winSize.height*0.3));
            menu->addChild(menuItem5);
        }
        //-------------------------------------≈–∂œ «∑Òƒ‹»•µ⁄∂˛∏ˆ≥°æ∞-------------------------------
        //	tsm->gamefirstgoto = true;
        
    }
    void GameSecond::onExit() {
        tsm->leaderPosition2 = leader->getPosition();
        if (whetherfriend == true)
            tsm->friendPosition2 = myFriend->getPosition();
        Layer::onExit();
    }
    void GameSecond::addEnemy(const Vec2& position) {
       
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        /*if (tsm->num == 0) {
         this->schedule(schedule_selector(GameSecond::enemiesmove), 0.4f, kRepeatForever, 0);//µ–»Àµƒ“∆∂Ø
         this->schedule(schedule_selector(GameSecond::enemiesattack), 0.5f, kRepeatForever, 0);//µ–»À∂‡…Ÿ√Îπ•ª˜÷˜Ω«“ª¥Œ
         }*/
        for (int i = 0; i < 10; i++) {
            if (tsm->enemies[i] == nullptr) {
                tsm->enemies[i] = new Enemy;
                tsm->enemies[i]->setPosition(position);
                addChild(tsm->enemies[i]->mySprite, 0);
                tsm->num++;
                break;
            }
        }
    }
    void GameSecond::enemiesmove(float dt) {
        for (int i = 0; i < 10; i++) {
            if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getblood() > 0)
                tsm->enemies[i]->move();
            else if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getblood() <= 0) {
                removeChild(tsm->enemies[i]->mySprite);
                delete tsm->enemies[i];
                tsm->enemies[i] = nullptr;
                tsm->num--;
            }
        }
    }
    void GameSecond::enemiesattack(float dt) {
        for (int i = 0; i <10; i++) {
            if (tsm->enemies[i] != nullptr&&tsm->enemies[i]->getDistance() <
                tsm->enemies[i]->getAttackDistance()) {
                leader->getAttacked(tsm->enemies[i]->getAttackValue());
            }
        }
        leader->whethergoon = true;
    }
    void GameSecond::friendmove(float dt) {
        myFriend->move();
    }
    void GameSecond::deletesprite(Sprite*sprite) {
        removeChild(sprite,true);
    }
    
    
void  GameSecond::menuShopCallBack(Ref * pSender){
    tsm->goShopScene();
}
    
    
    
void  GameSecond::pause(Ref * pSender){
    tsm->goPausedScene();
    
}
