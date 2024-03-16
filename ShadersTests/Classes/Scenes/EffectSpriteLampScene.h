//
//  EffectSpriteLampScene.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectSpriteLampScene_h
#define EffectSpriteLampScene_h

#include "cocos2d.h"
#include "Effect.h"
#include "EffectSprite.h"
#include <vector>

class EffectSpriteLampScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(EffectSpriteLampScene);

    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual std::string subtitle() const {return "Sprite Lamp effects";}

    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event);
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event);
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event);
    
protected:
    EffectSprite *_sprite;
    Effect* _effect;
    cocos2d::Sprite* _lightSprite;
};

#endif /* EffectSpriteLampScene_h */
