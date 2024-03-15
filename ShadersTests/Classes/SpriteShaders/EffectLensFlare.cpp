//
//  EffectLensFlare.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectLensFlare.h"
#include "EffectSprite.h"

bool EffectLensFlare::init()
{
    initGLProgramState("Shaders/LensFlare.fsh");
    return true;
}

void EffectLensFlare::setTarget(EffectSprite* sprite)
{
    auto s = sprite->getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("textureResolution", Vec2(s.width, s.height));

    s = Director::getInstance()->getWinSize();
    getGLProgramState()->setUniformVec2("resolution", Vec2(s.width, s.height));

}
