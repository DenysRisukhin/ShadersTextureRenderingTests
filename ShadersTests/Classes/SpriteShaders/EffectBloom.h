//
//  EffectBloom.hpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectBloom_h
#define EffectBloom_h

#include "Effect.h"

class EffectSprite;

class EffectBloom : public Effect
{
public:
    CREATE_FUNC(EffectBloom);

protected:
    bool init();

    virtual void setTarget(EffectSprite* sprite) override;
};

#endif /* EffectBloom_h */
