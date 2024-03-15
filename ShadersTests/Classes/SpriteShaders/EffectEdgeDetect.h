//
//  EffectEdgeDetect.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectEdgeDetect_h
#define EffectEdgeDetect_h

#include "Effect.h"

class EffectEdgeDetect : public Effect
{
public:
    CREATE_FUNC(EffectEdgeDetect);

protected:
    bool init();

    virtual void setTarget(EffectSprite* sprite) override;
};

#endif /* EffectEdgeDetect_h */
