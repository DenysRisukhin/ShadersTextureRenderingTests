//
//  EffectOutline.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/14/24.
//

#include "EffectOutline.h"

USING_NS_CC;

bool EffectOutline::init()
{
    initGLProgramState("Shaders/Outline.fsh");

    Vec3 color(1.0f, 0.2f, 0.3f);
    GLfloat radius = 0.01f;
    GLfloat threshold = 1.75;

    m_glprogramstate->setUniformVec3("u_outlineColor", color);
    m_glprogramstate->setUniformFloat("u_radius", radius);
    m_glprogramstate->setUniformFloat("u_threshold", threshold);
    return true;
}
