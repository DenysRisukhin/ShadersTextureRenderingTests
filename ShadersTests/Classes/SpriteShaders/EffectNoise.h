//
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectNoise_h
#define EffectNoise_h

#include "Effect.h"

class EffectNoise : public Effect
{
public:
    CREATE_FUNC(EffectNoise);

protected:
    bool init();

    virtual void setTarget(EffectSprite* sprite) override;
};

#endif /* EffectNoise_h */
