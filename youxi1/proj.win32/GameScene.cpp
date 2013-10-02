
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "GameOverScene.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;
using namespace CocosDenshion;

GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
}

CCScene* GameScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        GameScene *layer = GameScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

void GameScene::gameLogic(float dt)
{
	this->addTarget();
}
// on "init" you need to initialize your instance
bool GameScene::init()
{
        if(CCLayerColor::initWithColor(ccc4(255,255,255,255)))
		{
			projectilesDestroyed = 0;
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			arrayProjectile = CCArray::create();
			arrayTarget = CCArray::create();

			bg1 = CCSprite::create("back1.jpg");
			bg1->setAnchorPoint(CCPointZero);
			bg1->setPosition(ccp(0,0));
			bg1->getTexture()->setAntiAliasTexParameters();
			this->addChild(bg1);
			
			bg2=CCSprite::create("back1.jpg");
			bg2->setAnchorPoint(CCPointZero);
			bg2->setPosition(ccp(0,bg2->getContentSize().height-2));
			bg1->getTexture()->setAntiAliasTexParameters();
			this->addChild(bg2);

			this->schedule(schedule_selector(GameScene::backgroundMove),0.01f);  

			player = CCSprite::create("fighter.png");
			player->setScale(0.5);
			player->setPosition(ccp(winSize.width/2,20));
			this->addChild(player);
			
			arrayProjectile->retain();
			arrayTarget->retain();

			SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("back.wav");
			SimpleAudioEngine::sharedEngine()->preloadEffect("zidan.wav");
			SimpleAudioEngine::sharedEngine()->preloadEffect("baozha.wav");

			this->schedule(schedule_selector(GameScene::gameLogic),1.0);
            this->schedule(schedule_selector(GameScene::update));
			this->setTouchEnabled(true);

			
		   return true;
		}
		else
		{
		   return false;
		}
}

void GameScene::backgroundMove(float dt)  
{  
	bg1->setPositionY(bg1->getPositionY()-2);  
	bg2->setPositionY(bg1->getPositionY()+bg1->getContentSize().height-2);  
	if (bg2->getPositionY()==0)//要注意因为背景图高度是842，所以每次减去2最后可以到达0，假如背景高度是841，那么这个条件永远达不到，滚动失败   
	{  
		bg1->setPositionY(0);  
	}  
}  


void GameScene::update(float dt)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	for(int i = 0; i < arrayTarget->count();i++)
	{
		CCSprite *target = (CCSprite*)arrayTarget->objectAtIndex(i);
		for(int j = 0; j < arrayProjectile->count();j++)
		{
			CCSprite *projectile = (CCSprite*)arrayProjectile->objectAtIndex(j);
			if(target->boundingBox().intersectsRect(projectile->boundingBox()))
			{
				arrayTarget->removeObject(target);
				arrayProjectile->removeObject(projectile);
				this->removeChild(target);
				this->removeChild(projectile);
				projectilesDestroyed++;
				if(projectilesDestroyed >= 10)
				{
					GameOverScene *scene = GameOverScene::create();
					scene->getLayer()->getLabel()->setString("You beat back 10 enemies");
					CCLabelTTF* pLabel = CCLabelTTF::create("YOU WIN", "Arial", 35);
                    CC_BREAK_IF(! pLabel);
					pLabel->setColor(ccc3(0,0,0));
                    pLabel->setPosition(ccp(winSize.width/2,winSize.height/2));
                    scene->addChild(pLabel);
					
					CCDirector::sharedDirector()->replaceScene(CCTransitionShrinkGrow::transitionWithDuration(0.5, scene));
				}
				break;
			}
		}
	}
}

void GameScene::ccTouchesEnded(cocos2d::CCSet *touches,cocos2d::CCEvent *event)
{
	CCTouch *touch =(CCTouch*)touches->anyObject();
	CCPoint location = touch->getLocationInView();
	location = this->convertTouchToNodeSpace(touch);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *projectile = CCSprite::create("bullet2.png");

	projectile->setScale(2);

	projectile->setPosition(ccp(winSize.width/2,20));
	
	float offX = location.x - projectile->getPositionX();
	float offY = location.y - projectile->getPositionY();

	if(offY <= 0)
	{
		return;
	}
	projectile->setTag(2);
	this->addChild(projectile);
	arrayProjectile->addObject(projectile);

	float angle = offX / offY;
	float realY = winSize.height + projectile->getContentSize().height/2 + 20;
	float realX = realY * angle +projectile->getPositionX();

	CCPoint finalPosition = ccp(realX, realY);

	float length = sqrtf(realX * realX + realY * realY);
	float velocity = 480;
	float realMoveDuration = length / velocity;

	projectile->runAction(CCSequence::create(CCMoveTo::create(realMoveDuration,finalPosition),
		CCCallFuncN::create(this, callfuncN_selector(GameScene::spriteMoveFinished)),NULL));
	SimpleAudioEngine::sharedEngine()->playEffect("zidan.wav", false);
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.2f);
}



void GameScene::spriteMoveFinished(CCNode *sender)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *sprite = (CCSprite*)sender;
	if(sprite->getTag() == 1)
	{
		arrayTarget->removeObject(sprite);

		GameOverScene *scene = GameOverScene::create();
		scene->getLayer()->getLabel()->setString("YOU LOSE");
		CCSprite *gameover = CCSprite::create("gameover.png");
		gameover->setScale(0.3);
		gameover->setPosition(ccp(winSize.width/2,winSize.height/2));
		scene->getLayer()->getGameover()->addChild(gameover);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::transitionWithDuration(0.5, scene));

	}
	else if(sprite->getTag() == 2)
	{
		arrayProjectile->removeObject(sprite);
	}
}

void GameScene::addTarget()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *target = CCSprite::create("diji.png");
	int minX = target->getContentSize().width/2;
	int maxX = winSize.width - target->getContentSize().width/2;
	int rangeX = maxX - minX;
	int actualX = rand()%rangeX + minX;
	target->setScale(0.5);
	target->setPosition(ccp(actualX,((winSize.height) + (target->getContentSize().height/2))));
	target->setTag(1);
	this->addChild(target);
	arrayTarget->addObject(target);

	//float actrualDuration = 3.0;//只有一个速度
	float minDuration = 2;
	float maxDuration = 4;
	int rangeDuration = maxDuration - minDuration; //随机速度
	float actrualDuration = rand()%rangeDuration + minDuration;

	CCFiniteTimeAction *actionMove = CCMoveTo::create(actrualDuration,ccp(actualX,0 - target->getContentSize().height/2 ));

	CCFiniteTimeAction *actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(GameScene::spriteMoveFinished));
	target->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));
}

void GameScene::finishShoot()
{
    this->addChild(projectile);
    arrayProjectile->addObject(projectile);
    SimpleAudioEngine::sharedEngine()->playEffect("zidan.wav", false);
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.2f);
    projectile->release();
    projectile = NULL;
}

