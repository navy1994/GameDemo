#include "MenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

MenuScene::MenuScene(void)
{
}

MenuScene::~MenuScene(void)
{
}

CCScene* MenuScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        MenuScene *layer = MenuScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

bool MenuScene::init()
{
	bool bRet = false;
    do 
    {
          CC_BREAK_IF(! CCScene::init());

		  CCSprite *bg = CCSprite::create("bj.png");
		  bg->setAnchorPoint(CCPointZero);
		  bg->setPosition(CCPointZero);
		  this->addChild(bg);

           CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(MenuScene::menuCloseCallback));
		
            CC_BREAK_IF(! pCloseItem);

        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        this->addChild(pMenu, 1);

		  CCSize size = CCDirector::sharedDirector()->getWinSize();
  

		CCMenuItemImage *myItems = CCMenuItemImage::create(
            "start1.png",
            "start2.png",
            this,
            menu_selector(MenuScene::menuNewGameCallback));
            CC_BREAK_IF(!myItems); 
            myItems->setPosition(ccp(size.width/2, size.height/2)); 
            CCMenu* myMenu = CCMenu::menuWithItems(myItems, NULL); 
            myMenu->setPosition(CCPointZero); 
            CC_BREAK_IF(!myMenu); 
            this->addChild(myMenu, 1); 

			CCSprite *about = CCSprite::create("about1.png");
		   about->setAnchorPoint(CCPointZero);
		   about->setPosition(ccp(size.width/2 - 55, size.height/2 - 50));
		   this->addChild(about);

			SimpleAudioEngine::sharedEngine()->playBackgroundMusic("back.wav",true);


        bRet = true;
    } while (0);

    return bRet;
}

void MenuScene::menuNewGameCallback(CCObject* pSender)
{
     CCScene* scene = CCScene::node(); 
	 GameScene *scene1 = GameScene::create();
	 scene->addChild(scene1);
     CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::transitionWithDuration(0.3, scene));
}

void MenuScene::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}