//
//  EffectCelShading.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectCelShading_h
#define EffectCelShading_h

#include "Effect.h"

class EffectCelShading : public Effect
{
public:
    CREATE_FUNC(EffectCelShading);

protected:
    bool init();

    virtual void setTarget(EffectSprite* sprite) override;
};

#endif /* EffectCelShading_h */
