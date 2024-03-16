//
//  ShaderHeartScene.cpp
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#include "ShaderHeartScene.h"
#include "ShaderNode.h"

Scene* ShaderHeart::createScene()
{
    return ShaderHeart::create();
}

bool ShaderHeart::init()
{
    if (Scene::init())
    {
        auto sn = ShaderNode::shaderNodeWithVertex("", "Shaders/Heart.fsh");

        auto s = Director::getInstance()->getWinSize();
        sn->setPosition(Vec2(s.width/2, s.height/2));

        addChild(sn);

        return true;
    }

    return false;
}

//std::string ShaderHeart::title() const
//{
//    return "Shader: Frag shader";
//}
//
//std::string ShaderHeart::subtitle() const
//{
//    return "Heart";
//}
