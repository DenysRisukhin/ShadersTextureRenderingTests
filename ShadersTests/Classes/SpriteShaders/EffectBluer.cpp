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
    if (m_glprogramstate == nullptr)
        return;
    
    Size size = sprite->getTexture()->getContentSizeInPixels();
    m_glprogramstate->setUniformVec2("resolution", size);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    m_glprogramstate->setUniformFloat("blurRadius", _blurRadius);
    m_glprogramstate->setUniformFloat("sampleNum", _blurSampleNum);
#endif
}

bool EffectBlur::init(float blurRadius, float sampleNum)
{
    initGLProgramState("Shaders/Blur.fsh");

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
