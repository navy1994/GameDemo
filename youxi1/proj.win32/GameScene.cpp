
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
        // 'scene' is an autorelease object
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

			CCSprite *bg = CCSprite::create("bg.png");
			bg->setAnchorPoint(CCPointZero);
			bg->setPosition(CCPointZero);
			this->addChild(bg,0);

			CCSprite *player = CCSprite::create("cat.png");
			player->setScale(0.3);
			player->setPosition(ccp(player->getContentSize().width/2-40,winSize.height/2));
			this->addChild(player);
			
			arrayProjectile->retain();
			arrayTarget->retain();

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

	CCSprite *projectile = CCSprite::create("YuGuZD.png");
	projectile->setScale(0.5);
	projectile->setPosition(ccp(30,winSize.height/2));

	float offX = location.x - projectile->getPositionX();
	float offY = location.y - projectile->getPositionY();

	if(offX <= 0)
	{
		return;
	}
	projectile->setTag(2);
	this->addChild(projectile);
	arrayProjectile->addObject(projectile);

	float angle = offY / offX;
	float realX = winSize.width + projectile->getContentSize().width/2 + 20;
	float realY = realX * angle +projectile->getPositionY();

	CCPoint finalPosition = ccp(realX, realY);

	float length = sqrtf(realX * realX + realY * realY);
	float velocity = 480;
	float realMoveDuration = length / velocity;

	projectile->runAction(CCSequence::create(CCMoveTo::create(realMoveDuration,finalPosition),
		CCCallFuncN::create(this, callfuncN_selector(GameScene::spriteMoveFinished)),NULL));
}

void GameScene::spriteMoveFinished(CCNode *sender)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *sprite = (CCSprite*)sender;
	//this->removeChild(sprite,true);
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

	CCSprite *target = CCSprite::create("enemy.png");
	int minY = target->getContentSize().height/2;
	int maxY = winSize.height - target->getContentSize().height/2;
	int rangeY = maxY - minY;
	int actualY = rand()%rangeY + minY;
	target->setScale(0.3);
	target->setPosition(ccp(((winSize.width) + (target->getContentSize().width/2)),actualY));
	target->setTag(1);
	this->addChild(target);
	arrayTarget->addObject(target);

	//float actrualDuration = 3.0;//只有一个速度
	float minDuration = 2;
	float maxDuration = 4;
	int rangeDuration = maxDuration - minDuration; //随机速度
	float actrualDuration = rand()%rangeDuration + minDuration;

	CCFiniteTimeAction *actionMove = CCMoveTo::create(actrualDuration,ccp(0 - target->getContentSize().width/2, actualY));

	CCFiniteTimeAction *actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(GameScene::spriteMoveFinished));
	target->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));
}

void GameScene::finishShoot()

{
    this->addChild(projectile);
    arrayProjectile->addObject(projectile);
    SimpleAudioEngine::sharedEngine()->playEffect("pew-pew-lei.mp3", false);

    projectile->release();
    projectile = NULL;
}