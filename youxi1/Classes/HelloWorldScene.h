#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"

#include "Box2D/Box2D.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	void addTarget();
	void spriteMoveFinished(CCNode *sender);
	void gameLogic(float dt);
	void update(float dt); //Åö×²¼ì²â
	//´¥Ãþ¼ø¶¨
	void ccTouchesEnded(CCSet *touches, CCEvent *event);

	CCArray *arrayTarget;
	CCArray *arrayProjectile;
	int projectilesDestroyed;
};


#endif  // __HELLOWORLD_SCENE_H__