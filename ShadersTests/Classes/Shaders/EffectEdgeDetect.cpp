//
//  EffectEdgeDetect.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectEdgeDetect.h"
#include "EffectSprite.h"

bool EffectEdgeDetect::init() {
    initGLProgramState("Shaders/example_EdgeDetection.fsh");
    return true;
}

void EffectEdgeDetect::setTarget(EffectSprite* sprite)
{
    auto s = sprite->getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", Vec2(s.width, s.height));
}
