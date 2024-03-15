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
    cocos2d::GLProgramState* getGLProgramState() const { return _glprogramstate; }
    virtual void setTarget(EffectSprite *sprite);

protected:
    bool initGLProgramState(const std::string &fragmentFilename);
    Effect();
    virtual ~Effect();
    
protected:
    cocos2d::GLProgramState* _glprogramstate;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    std::string _fragSource;
    cocos2d::EventListenerCustom* _backgroundListener;
#endif
};

#endif /* Effect_hpp */
