//
//  EffectOutline.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#ifndef EffectOutline_h
#define EffectOutline_h

#include "Effect.h"

class EffectOutline : public Effect
{
public:
    CREATE_FUNC(EffectOutline);

    bool init();
};


#endif /* EffectOutline_h */
