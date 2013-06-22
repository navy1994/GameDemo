#include "GameOverScene.h"
#include "GameOverLayer.h"
#include "GameScene.h"
#include "MenuScene.h"

GameOverScene::GameOverScene(void)
{
}


GameOverScene::~GameOverScene(void)
{
}

bool GameOverScene::init()
{
	if(CCScene::init())
	{
	    CCSize size = CCDirector::sharedDirector()->getWinSize();
		gameOverlayer = GameOverLayer::create();
		this->addChild(gameOverlayer);

	    CCMenuItemImage *myItems = CCMenuItemImage::create(
            "back.png",
            "back.png",
            this,
            menu_selector(GameOverScene::mainMenuCallback));
            myItems->setPosition(ccp(size.width/2, size.height/2 + 50)); 
            CCMenu* myMenu = CCMenu::menuWithItems(myItems, NULL); 
			myMenu->setScale(0.7);
            myMenu->setPosition(CCPointZero); 
            this->addChild(myMenu, 1);

		CCMenuItemImage *bItems = CCMenuItemImage::create(
            "backA.png",
            "backB.png",
            this,
            menu_selector(GameOverScene::gameCallback));
            bItems->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 30, 30)); 
            CCMenu* bMenu = CCMenu::menuWithItems(bItems, NULL); 
            bMenu->setPosition(CCPointZero); 
            this->addChild(bMenu, 1); 

		return true;
	}
	else
	{
		return false;
	}
}

GameOverLayer *GameOverScene::getLayer()
{
	return gameOverlayer;
}

void GameOverScene::mainMenuCallback(CCObject* pSender)
{
     CCScene* scene = CCScene::node(); 
	 MenuScene *scene1 = MenuScene::create();
	 scene->addChild(scene1);
     CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::transitionWithDuration(0.3, scene));
}

void GameOverScene::gameCallback(CCObject* pSender)
{
     CCScene* scene = CCScene::node(); 
	 GameScene *scene1 = GameScene::create();
	 scene->addChild(scene1);
     CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.3, scene));
}