#pragma once
#include "f:\软件\电脑软件安装包\cocos2d-2.1beta3-x-2.1.0\cocos2d-2.1beta3-x-2.1.0\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"
#include "cocos2d.h"
using namespace cocos2d;

class GameOverLayer :
	public CCLayerColor
{
public:
	GameOverLayer(void);
	~GameOverLayer(void);
	virtual bool init();
	CREATE_FUNC(GameOverLayer);

	void gameOverDone();

	CCLabelTTF *getLabel();

	CCSprite *getGameover();
private:
	CCLabelTTF *label;
	CCSprite *bg;
};

