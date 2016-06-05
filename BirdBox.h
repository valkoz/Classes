#ifndef __BIRDBOX_H__
#define __BIRDBOX_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "Box2D/Box2D.h"


class Bird2 : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite *bird;
	b2Body *birdbody;
public:
    	Bird2(cocos2d::Layer *layer, b2World * world);
	void Fly();
};

#endif // __BIRDBOX_H__
