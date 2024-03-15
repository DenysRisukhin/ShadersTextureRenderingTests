//
//  EffectSepia.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectSepia_h
#define EffectSepia_h

#include "Effect.h"

class EffectSepia : public Effect
{
public:
    CREATE_FUNC(EffectSepia);

protected:
    bool init() {
        initGLProgramState("Shaders/example_Sepia.fsh");
        return true;
    }
};

#endif /* EffectSepia_h */
