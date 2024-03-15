//
//  EffectCelShading.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectCelShading.h"
#include "EffectSprite.h"

bool EffectCelShading::init()
{
    initGLProgramState("Shaders/CelShading.fsh");
    return true;
}

void EffectCelShading::setTarget(EffectSprite* sprite)
{
    auto s = sprite->getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", Vec2(s.width, s.height));
}
