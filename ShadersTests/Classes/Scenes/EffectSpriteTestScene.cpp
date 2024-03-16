/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "EffectSpriteTestScene.h"

#include "EffectBluer.h"
#include "EffectOutline.h"
#include "EffectNoise.h"
#include "EffectEdgeDetect.h"
#include "EffectGreyScale.h"
#include "EffectLensFlare.h"
#include "EffectBloom.h"
#include "EffectCelShading.h"
#include "EffectSepia.h"

USING_NS_CC;

Scene* EffectSpriteTestScene::createScene()
{
    return EffectSpriteTestScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool EffectSpriteTestScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto layer = LayerColor::create(Color4B::BLUE);
    addChild(layer);

    auto label = Label::createWithTTF("Shaders Portfolio \n TESTED BY DENYS RISUKHIN", "fonts/Marker Felt.ttf", 24, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        addChild(label, 1);
    }

    _sprite = EffectSprite::create("monster.png");
    if (_sprite == nullptr)
    {
        problemLoading("'monster.png'");
    }
    else
    {
        _sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        addChild(_sprite, 0);
    }

    auto s = Director::getInstance()->getWinSize();

    auto itemPrev = MenuItemImage::create("arrow_left.png", "arrow_left.png",
                                      [&](Ref *sender) {
                                          _vectorIndex--;
                                          if(_vectorIndex<0)
                                              _vectorIndex = _effects.size()-1;
                                          _sprite->setEffect(_effects.at(_vectorIndex));
                                      });

    auto itemNext = MenuItemImage::create("arrow_right.png", "arrow_right.png",
                                      [&](Ref *sender) {
                                          _vectorIndex++;
                                          if(_vectorIndex>=_effects.size())
                                              _vectorIndex = 0;
                                          _sprite->setEffect(_effects.at(_vectorIndex));
                                      });

    auto menu = Menu::create(itemPrev, itemNext, nullptr);
    menu->alignItemsHorizontally();
    //menu->setScale(0.5);
    menu->setAnchorPoint(Vec2(0,0));
    menu->setPosition(Vec2(s.width/2,70));
    addChild(menu);

//    auto jump = JumpBy::create(4, Vec2(s.width / 2,0), 0, 4);
//    auto rot = RotateBy::create(4, 720);
//    auto spawn = Spawn::create(jump, rot, nullptr);
//    auto rev = spawn->reverse();
//    auto seq = Sequence::create(spawn, rev, nullptr);
//    auto repeat = RepeatForever::create(seq);
//    _sprite->runAction(repeat);

    
    spriteEffects();

    return true;
}

void EffectSpriteTestScene::spriteEffects()
{
    _effects.pushBack(EffectBlur::create());
    _effects.pushBack(EffectOutline::create());
    _effects.pushBack(EffectNoise::create());
    _effects.pushBack(EffectEdgeDetect::create());
    _effects.pushBack(EffectGreyScale::create());
    _effects.pushBack(EffectSepia::create());
    _effects.pushBack(EffectBloom::create());
    _effects.pushBack(EffectCelShading::create());
    _effects.pushBack(EffectLensFlare::create());

    _vectorIndex = 0;
    _sprite->setEffect( _effects.at(_vectorIndex) );
}
