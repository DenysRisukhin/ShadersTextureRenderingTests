//
//  EffectSprite.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#ifndef EffectSprite_h
#define EffectSprite_h

#include "cocos2d.h"
#include "Effect.h"
#include <vector>
#include <tuple>
#include "Common.h"

USING_NS_CC;

class Effect;

class EffectSprite : public Sprite
{
public:
    static EffectSprite* create(const std::string& filename);

    void setEffect(Effect* effect);
    void addEffect(Effect* effect, ssize_t order);
    void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) override;
    
protected:
    EffectSprite();
    ~EffectSprite();
    
protected:
    std::vector<std::tuple<ssize_t,Effect*,QuadCommand>> m_effects;
    Effect* m_defaultEffect;
};

#endif /* EffectSprite_hpp */
