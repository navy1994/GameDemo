#include "GameOverLayer.h"
#include "GameScene.h"

GameOverLayer::GameOverLayer(void)
{
}

GameOverLayer::~GameOverLayer(void)
{
}

bool GameOverLayer::init()
{
	if(CCLayerColor::initWithColor(ccc4(255,255,255,255)))
	{
		
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		bg = CCSprite::create("back_1.png");
		bg->setAnchorPoint(CCPointZero);
		bg->setPosition(ccp(0,0));
		this->addChild(bg);
		label = CCLabelTTF::create("","Artial",25);
		label->setColor(ccc3(0,0,0));
		label->setPosition(ccp(winSize.width/2,winSize.height/2-50));
		this->addChild(label);

		
		this->runAction(CCSequence::create(CCDelayTime::create(3),CCCallFunc::create(this,
			callfunc_selector(GameOverLayer::gameOverDone)),NULL));


		return true;
	}
	else
	{
		return false;
	}
}

void GameOverLayer::gameOverDone()
{
   	CCDirector::sharedDirector()->replaceScene(GameScene::scene());
}

CCSprite *GameOverLayer::getGameover()
{
	return bg;
}

CCLabelTTF *GameOverLayer::getLabel()
{
	return label;
}