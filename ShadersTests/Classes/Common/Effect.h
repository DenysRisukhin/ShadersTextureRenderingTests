//
//  Effect.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#ifndef Effect_h
#define Effect_h

#include "cocos2d.h"

class EffectSprite;

class Effect : public cocos2d::Ref
{
public:
    cocos2d::GLProgramState* getGLProgramState() const { return m_glprogramstate; }
    virtual void setTarget(EffectSprite *sprite);

protected:
    Effect();
    virtual ~Effect();
    
    bool initGLProgramState(const std::string& fragmentFilename);
    
protected:
    cocos2d::GLProgramState* m_glprogramstate;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    cocos2d::EventListenerCustom* m_backgroundListener;
    std::string m_fragSource;
#endif
};

#endif /* Effect_hpp */
