//
//  EffectBluer.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#ifndef EffectBluer_h
#define EffectBluer_h

#include <stdio.h>
#include "Effect.h"

class EffectSprite;

// Blur
class EffectBlur : public Effect
{
public:
    CREATE_FUNC(EffectBlur);
    
    virtual void setTarget(EffectSprite *sprite) override;
    
    void setBlurRadius(float radius);
    void setBlurSampleNum(float num);

protected:
    bool init(float blurRadius = 10.0f, float sampleNum = 5.0f);
    
    float _blurRadius;
    float _blurSampleNum;
};

#endif /* EffectBluer_h */
