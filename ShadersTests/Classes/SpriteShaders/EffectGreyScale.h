//
//  EffectGreyScale.hpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectGreyScale_h
#define EffectGreyScale_h

#include "Effect.h"

class EffectGreyScale : public Effect
{
public:
    CREATE_FUNC(EffectGreyScale);

protected:
    bool init() {
        initGLProgramState("Shaders/GreyScale.fsh");
        return true;
    }
};

#endif /* EffectGreyScale_h */
