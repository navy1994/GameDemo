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

		  CCSprite *bg = CCSprite::create("blue-shooting-stars.png");
		  bg->setAnchorPoint(CCPointZero);
		  bg->setPosition(CCPointZero);
		  this->addChild(bg);

           CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(MenuScene::menuCloseCallback));
		
            CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::create("Main Menu", "Arial", 30);
		
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));
		pLabel->setColor(ccc3(0,0,0));
        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

		CCMenuItemImage *myItems = CCMenuItemImage::create(
            "newgameA.png",
            "newgameB.png",
            this,
            menu_selector(MenuScene::menuNewGameCallback));
            CC_BREAK_IF(!myItems); 
            myItems->setPosition(ccp(size.width/2, size.height/2)); 
            CCMenu* myMenu = CCMenu::menuWithItems(myItems, NULL); 
			myMenu->setScale(0.5);
            myMenu->setPosition(CCPointZero); 
            CC_BREAK_IF(!myMenu); 
            this->addChild(myMenu, 1); 

			CCSprite *about = CCSprite::create("aboutA.png");
		   about->setAnchorPoint(CCPointZero);
		   about->setScale(0.5);
		   about->setPosition(ccp(size.width/2 - 55, size.height/2 - 50));
		   this->addChild(about);

		   CCSprite *cat = CCSprite::create("cat.png");
		   cat->setAnchorPoint(CCPointZero);
		   cat->setScale(0.5);
		   cat->setPosition(ccp(size.width/2 - 150, size.height/2 - 40));
		   this->addChild(cat);

		   CCSprite *enemy = CCSprite::create("enemy.png");
		  enemy->setAnchorPoint(CCPointZero);
		   enemy->setScale(0.5);
		   enemy->setPosition(ccp(size.width/2 + 75, size.height/2 - 40));
		   this->addChild(enemy);

			SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3",true);


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