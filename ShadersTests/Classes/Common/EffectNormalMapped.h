//
//  EffectNormalMapped.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef EffectNormalMapped_h
#define EffectNormalMapped_h

#include "Effect.h"

USING_NS_CC;

class EffectNormalMapped : public Effect
{
public:
    CREATE_FUNC(EffectNormalMapped);
    static EffectNormalMapped* create(const std::string& normalMapFileName);

    void setKBump(float value);
    void setLightPos(const Vec3& pos);
    void setLightColor(const Color4F& color);
    
    float getKBump() const { return m_kBump; }
    
protected:
    bool init();
    bool initNormalMap(const std::string&normalMapFileName);
    virtual void setTarget(EffectSprite* sprite) override;
    
protected:
    EffectSprite* _sprite;
    Vec3 m_lightPos;
    Color4F m_lightColor;
    float  m_kBump;
};

#endif /* EffectNormalMapped_h */
