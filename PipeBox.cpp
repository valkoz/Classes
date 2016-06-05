#include "PipeBox.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#define SCALE_RATIO 32

USING_NS_CC;

Pipe2::Pipe2()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe2::SpawnPipe(cocos2d::Layer *layer, b2World *world)
{
	
	auto random = CCRANDOM_0_1();	
	auto topPipePosition = visibleSize.height- visibleSize.height*random/2;
	auto PipeWidth = visibleSize.width/20;
	auto topPipePositionWidth = visibleSize.width + PipeWidth;

	Rect a(topPipePositionWidth, topPipePosition, PipeWidth, visibleSize.height +origin.y - topPipePosition); 
	MakePipeBody(layer, world, a);
	Rect b(topPipePositionWidth, 0, PipeWidth, topPipePosition - visibleSize.height/3);
	MakePipeBody(layer, world, b);



}

void Pipe2::MakePipeBody(cocos2d::Layer *layer, b2World *world, cocos2d::Rect rect){
 
	auto Pipe = Sprite::create("pipe.png", rect);
	Pipe->setPosition(rect.getMidX(),rect.getMidY());
	layer->addChild(Pipe);
	//Pipe->setScale(0.5);
		
	
	b2BodyDef PipeBodyDef;

	PipeBodyDef.type = b2_kinematicBody;	//gravitity is not for pipes

	PipeBodyDef.position.Set(rect.getMidX()/SCALE_RATIO, rect.getMidY()/SCALE_RATIO);

	PipeBodyDef.userData = Pipe;

	auto PipeBody = world->CreateBody(&PipeBodyDef);

	
	float a = Pipe->getContentSize().width;//*0.7;
	float b = Pipe->getContentSize().height;//*0.9;
	float sizeX = a/(2*SCALE_RATIO);
	float sizeY = b/(2*SCALE_RATIO);

	b2PolygonShape polygon;
	polygon.SetAsBox(sizeX, sizeY); //a 4x2 rectangle !!может округлять в большую сторону; ORIGINY слишком большой OrigiinX маленький(

	//polygon.SetAsBox(1, sizeY);

	b2FixtureDef PipeShapeDef;

	PipeShapeDef.shape = &polygon;

	PipeShapeDef.density = 0;

	PipeShapeDef.friction = 0;

	PipeShapeDef.restitution = 0;

	PipeBody->CreateFixture(&PipeShapeDef);

	PipeBody->SetLinearVelocity( b2Vec2(-3,0));



}

