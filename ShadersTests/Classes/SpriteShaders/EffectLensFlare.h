//
//  EffectLensFlare.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectLensFlare_h
#define EffectLensFlare_h

#include "Effect.h"

class EffectLensFlare : public Effect
{
public:
    CREATE_FUNC(EffectLensFlare);

protected:
    bool init();

    virtual void setTarget(EffectSprite* sprite) override;
};

#endif /* EffectLensFlare_h */
