//
//  EffectNoise.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectNoise.h"
#include "EffectSprite.h"

bool EffectNoise::init() {
    initGLProgramState("Shaders/example_Noisy.fsh");
    return true;
}

void EffectNoise::setTarget(EffectSprite* sprite)
{
    auto s = sprite->getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", Vec2(s.width, s.height));
}
