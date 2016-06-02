#ifndef __GAME_SCENE_BOX_H__
#define __GAME_SCENE_BOX_H__

#include "cocos2d.h"

class GameSceneBox : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameSceneBox);
};

#endif // __GAME_SCENE_BOX_H__