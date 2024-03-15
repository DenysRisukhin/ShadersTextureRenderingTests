//
//  EffectBloom.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectBloom.h"
#include "EffectSprite.h"

bool EffectBloom::init()
{
    initGLProgramState("Shaders/Bloom.fsh");
    return true;
}

void EffectBloom::setTarget(EffectSprite* sprite)
{
    auto s = sprite->getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", Vec2(s.width, s.height));
}
