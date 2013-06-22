#pragma once
#include "f:\软件\电脑软件安装包\cocos2d-2.1beta3-x-2.1.0\cocos2d-2.1beta3-x-2.1.0\cocos2dx\layers_scenes_transitions_nodes\ccscene.h"
#include "cocos2d.h"
using namespace cocos2d;
class MenuScene :
	public CCScene
{
public:
	MenuScene(void);
	~MenuScene(void);
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(MenuScene);
	void menuCloseCallback(CCObject* pSender);

	void menuNewGameCallback(CCObject* pSender);
};

