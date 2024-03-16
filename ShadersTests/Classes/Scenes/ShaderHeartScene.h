//
//  ShaderHeartScene.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef ShaderHeartScene_h
#define ShaderHeartScene_h

#include "cocos2d.h"
#include "Effect.h"
#include "EffectSprite.h"
#include <vector>

class ShaderHeart : public cocos2d::Scene
{
public:
    CREATE_FUNC(ShaderHeart);
    static cocos2d::Scene* createScene();

    virtual bool init() override;
};


#endif /* ShaderHeartScene_h */
