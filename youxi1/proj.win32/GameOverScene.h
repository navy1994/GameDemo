#pragma once
#include "f:\���\���������װ��\cocos2d-2.1beta3-x-2.1.0\cocos2d-2.1beta3-x-2.1.0\cocos2dx\layers_scenes_transitions_nodes\ccscene.h"
#include "cocos2d.h"
#include "GameOverLayer.h"

using namespace cocos2d;
class GameOverScene :
	public CCScene
{
public:
	GameOverScene(void);
	~GameOverScene(void);
	virtual bool init();
	CREATE_FUNC(GameOverScene);

	GameOverLayer *getLayer();
private:
	GameOverLayer *gameOverlayer;

	void mainMenuCallback(CCObject* pSender);
	void gameCallback(CCObject* pSender);
};

