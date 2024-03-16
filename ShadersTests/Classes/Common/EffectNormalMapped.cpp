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
    m_kBump = 2;
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
    getGLProgramState()->setUniformFloat("u_kBump", m_kBump);
    getGLProgramState()->setUniformVec2("u_contentSize", Vec2(sprite->getContentSize().width,sprite->getContentSize().height));
}

void EffectNormalMapped::setKBump(float value)
{
    m_kBump = value;
    auto glProgramState = getGLProgramState();
    
    if (glProgramState)
    {
        glProgramState->setUniformFloat("u_kBump", m_kBump);
    }
}

void EffectNormalMapped::setLightPos(const Vec3& pos)
{
    m_lightPos = pos;
    auto glProgramState = getGLProgramState();
    
    if (glProgramState)
    {
        glProgramState->setUniformVec4("u_lightPosInLocalSpace", Vec4(m_lightPos.x,m_lightPos.y,m_lightPos.z,1));
    }
    
}

void EffectNormalMapped::setLightColor(const Color4F& color)
{
    m_lightColor = color;
    auto glProgramState = getGLProgramState();
    
    if (glProgramState)
    {
        getGLProgramState()->setUniformVec3("u_diffuseL", Vec3(m_lightColor.r,m_lightColor.g,m_lightColor.b));
    }
}
