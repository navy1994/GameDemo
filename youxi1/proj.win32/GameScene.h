#pragma once
#include "f:\���\���������װ��\cocos2d-2.1beta3-x-2.1.0\cocos2d-2.1beta3-x-2.1.0\cocos2dx\layers_scenes_transitions_nodes\ccscene.h"
#include "cocos2d.h"

#include "Box2D/Box2D.h"

using namespace cocos2d;
class GameScene :
	public CCLayerColor
{
public:
	GameScene(void);
	~GameScene(void);
	virtual bool init();
	 static cocos2d::CCScene* scene();
	CREATE_FUNC(GameScene);
	void addTarget();
	void spriteMoveFinished(CCNode *sender);
	void gameLogic(float dt);
	void update(float dt); //��ײ���
	//��������
	void ccTouchesEnded(CCSet *touches, CCEvent *event);

	CCArray *arrayTarget;
	CCArray *arrayProjectile;
	int projectilesDestroyed;
	CCSprite *player;
    CCSprite *projectile;

	 void finishShoot();
};

