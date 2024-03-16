//
//  EffectNormalMapped.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "EffectNormalMapped.h"
#include "EffectSprite.h"

EffectNormalMapped* EffectNormalMapped::create(const std::string&normalMapFileName)
{
    EffectNormalMapped *normalMappedSprite = new (std::nothrow) EffectNormalMapped();
    if (normalMappedSprite && normalMappedSprite->init() && normalMappedSprite->initNormalMap(normalMapFileName))
    {
        normalMappedSprite->autorelease();
        return normalMappedSprite;
    }
    CC_SAFE_DELETE(normalMappedSprite);
    return nullptr;
}

bool EffectNormalMapped::init()
{
    initGLProgramState("Shaders3D/Normal.frag");
    _kBump = 2;
    return true;
}
bool EffectNormalMapped::initNormalMap(const std::string& normalMapFileName)
{
    auto normalMapTexture = Director::getInstance()->getTextureCache()->addImage(normalMapFileName);
    getGLProgramState()->setUniformTexture("u_normalMap", normalMapTexture);
    return true;
}
void EffectNormalMapped::setTarget(EffectSprite* sprite)
{
    _sprite = sprite;
    getGLProgramState()->setUniformFloat("u_kBump", _kBump);
    getGLProgramState()->setUniformVec2("u_contentSize", Vec2(sprite->getContentSize().width,sprite->getContentSize().height));
}

void EffectNormalMapped::setKBump(float value)
{
    _kBump = value;
    auto glProgramState = getGLProgramState();
    if(glProgramState) glProgramState->setUniformFloat("u_kBump", _kBump);
}

void EffectNormalMapped::setLightPos(const Vec3& pos)
{
    _lightPos = pos;
    auto glProgramState = getGLProgramState();
    if(glProgramState) glProgramState->setUniformVec4("u_lightPosInLocalSpace", Vec4(_lightPos.x,_lightPos.y,_lightPos.z,1));
    
}

void EffectNormalMapped::setLightColor(const Color4F& color)
{
    _lightColor = color;
    auto glProgramState = getGLProgramState();
    if(glProgramState) getGLProgramState()->setUniformVec3("u_diffuseL", Vec3(_lightColor.r,_lightColor.g,_lightColor.b));
    
}
