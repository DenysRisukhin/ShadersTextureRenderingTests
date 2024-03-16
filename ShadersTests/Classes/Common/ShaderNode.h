//
//  ShaderNode.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/15/24.
//

#ifndef ShaderNode_h
#define ShaderNode_h

#include <stdio.h>
#include "cocos2d.h"
#include "Effect.h"
#include <vector>
#include <tuple>

USING_NS_CC;

class ShaderNode : public cocos2d::Node
{
public:
    CREATE_FUNC(ShaderNode);
    static ShaderNode* shaderNodeWithVertex(const std::string &vert, const std::string &frag);

    virtual void update(float dt) override;
    virtual void setPosition(const cocos2d::Vec2 &newPosition) override;
    virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

protected:
    ShaderNode();
    ~ShaderNode() {}

    bool initWithVertex(const std::string &vert, const std::string &frag);
    void loadShaderVertex(const std::string &vert, const std::string &frag);

    void onDraw(const cocos2d::Mat4& transform, uint32_t flags);

    cocos2d::Vec2 m_center;
    cocos2d::Vec2 m_resolution;
    float m_time;
    std::string m_vertFileName;
    std::string m_fragFileName;
    cocos2d::CustomCommand _customCommand;
};


#endif /* ShaderNode_h */
