//
//  EffectSpriteLampScene.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectSpriteLampScene.h"
#include "EffectNormalMapped.h"

USING_NS_CC;

Scene* EffectSpriteLampScene::createScene()
{
    return EffectSpriteLampScene::create();
}

bool EffectSpriteLampScene::init()
{
    if (Scene::init())
    {
        auto s = Director::getInstance()->getWinSize();
        _sprite = EffectSprite::create("Images/elephant1_Diffuse.png");
        //auto contentSize = _sprite->getContentSize();
        _sprite->setPosition(Vec2(s.width/2, s.height/2));
        addChild(_sprite);
        
        auto lampEffect = EffectNormalMapped::create("Images/elephant1_Normal.png");
        
        Vec3 pos(150,150, 50);
        _lightSprite = Sprite::create("Images/ball.png");
        this->addChild(_lightSprite);
        _lightSprite->setPosition(Vec2(pos.x, s.height- pos.y));
        Mat4 mat = _sprite->getNodeToWorldTransform();
        Point lightPosInLocalSpace = PointApplyAffineTransform(Vec2(pos.x, pos.y), _sprite->getWorldToNodeAffineTransform());
        lampEffect->setLightColor(Color4F(1,1,1,1));
        lampEffect->setLightPos(Vec3(lightPosInLocalSpace.x, lightPosInLocalSpace.y, 50));
        lampEffect->setKBump(2);
        _sprite->setEffect(lampEffect);
        _effect = lampEffect;
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(EffectSpriteLampScene::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(EffectSpriteLampScene::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(EffectSpriteLampScene::onTouchesEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        return true;
    }

    return false;
}


void EffectSpriteLampScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    for ( auto &item: touches )
    {
        auto touch = item;
        auto s = Director::getInstance()->getWinSize();
        Point loc_winSpace = touch->getLocationInView();
        _lightSprite->setPosition(Vec2( loc_winSpace.x,  s.height - loc_winSpace.y));
        Vec3 pos(loc_winSpace.x,loc_winSpace.y, 50);
        Mat4 mat = _sprite->getNodeToWorldTransform();
        Point lightPosInLocalSpace = PointApplyAffineTransform(Vec2(pos.x, pos.y), _sprite->getWorldToNodeAffineTransform());
        ((EffectNormalMapped*)_effect)->setLightPos(Vec3(lightPosInLocalSpace.x, lightPosInLocalSpace.y, 50));
    }
}

void EffectSpriteLampScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
    for ( auto &item: touches )
    {
        auto touch = item;
        auto s = Director::getInstance()->getWinSize();
        Point loc_winSpace = touch->getLocationInView();
        _lightSprite->setPosition(Vec2( loc_winSpace.x, s.height - loc_winSpace.y));
        Vec3 pos(loc_winSpace.x,loc_winSpace.y, 50);
        Mat4 mat = _sprite->getNodeToWorldTransform();
        Point lightPosInLocalSpace = PointApplyAffineTransform(Vec2(pos.x, pos.y), _sprite->getWorldToNodeAffineTransform());
        ((EffectNormalMapped*)_effect)->setLightPos(Vec3(lightPosInLocalSpace.x, lightPosInLocalSpace.y, 50));
    }
}

void EffectSpriteLampScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    for ( auto &item: touches )
    {
        auto touch = item;
        auto s = Director::getInstance()->getWinSize();
        Point loc_winSpace = touch->getLocationInView();
        _lightSprite->setPosition(Vec2( loc_winSpace.x, s.height - loc_winSpace.y));
        Vec3 pos(loc_winSpace.x,loc_winSpace.y, 50);
        Mat4 mat = _sprite->getNodeToWorldTransform();
        Point lightPosInLocalSpace = PointApplyAffineTransform(Vec2(pos.x, pos.y), _sprite->getWorldToNodeAffineTransform());
        ((EffectNormalMapped*)_effect)->setLightPos(Vec3(lightPosInLocalSpace.x, lightPosInLocalSpace.y, 50));
    }
}
