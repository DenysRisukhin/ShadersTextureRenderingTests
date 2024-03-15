//
//  EffectBluer.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#include "EffectBluer.h"
#include "EffectSprite.h"

USING_NS_CC;

void EffectBlur::setTarget(EffectSprite *sprite)
{
    if (_glprogramstate == nullptr)
        return;
    
    Size size = sprite->getTexture()->getContentSizeInPixels();
    _glprogramstate->setUniformVec2("resolution", size);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    _glprogramstate->setUniformFloat("blurRadius", _blurRadius);
    _glprogramstate->setUniformFloat("sampleNum", _blurSampleNum);
#endif
}

bool EffectBlur::init(float blurRadius, float sampleNum)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    initGLProgramState("Shaders/example_Blur.fsh");
#else
    initGLProgramState("Shaders/example_Blur_winrt.fsh");
#endif
    _blurRadius = blurRadius;
    _blurSampleNum = sampleNum;
    
    return true;
}

void EffectBlur::setBlurRadius(float radius)
{
    _blurRadius = radius;
}

void EffectBlur::setBlurSampleNum(float num)
{
    _blurSampleNum = num;
}
