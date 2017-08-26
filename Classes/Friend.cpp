#include"Friend.h"
extern Leader* leader;
Friend::Friend() :Character(2){
	left = nullptr;
	right = nullptr;
	ahead = nullptr;
	back= nullptr;
}
	double Friend::getDistance() {
		double distance = 0;
		distance = sqrt((leader->getPosition().x - this->getPosition().x)*(leader->getPosition().x - this->getPosition().x) +
			(leader->getPosition().y - this->getPosition().y)*(leader->getPosition().y - this->getPosition().y)) - leader->getContentSize().width / 2 + getContentSize().width / 2;
		return distance;
	}
	void Friend::move() {
		double distance = getDistance();
		if (distance>50) {
			Vec2 direction = Vec2((leader->getPosition().x - this->getPosition().x) / distance * 5,
				(leader->getPosition().y - this->getPosition().y) / distance * 5);
			float y = atan2(leader->getPosition().x - this->getPosition().x, leader->getPosition().y - this->getPosition().y);
			Animation*action = nullptr;
			if (y > 45 && y < 135) {
				if (left != nullptr)
					action = ahead;
				this->changeDirection(1);
			}
			else if ((y >= 0 && y <= 45) || (y <= 360 && y > 315)) {
				if (left != nullptr)
					action = right;
				this->changeDirection(4);
			}
			else if (y > 225 && y <= 315) {
				if (left != nullptr)
					action = back;
				this->changeDirection(2);
			}
			else {
				if (left != nullptr)
					action = left;
				this->changeDirection(3);
			}
			FiniteTimeAction*ac1 = MoveBy::create(0.2f, direction);//四张图片 每两帧一张
			if (action != nullptr) {
				FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)action, 0));
				this->runAction(Spawn::create(ac1, move, NULL));
			}
			else
				this->runAction(ac1);
		}
	}