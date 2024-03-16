////
////  TestCaseScene.hpp
////  ShadersTests
////
////  Created by Risukhin Denys on 3/15/24.
////
//
//#ifndef TestCaseScene_h
//#define TestCaseScene_h
//
//#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//#include "VisibleRect.h"
//
//class TestCase : public cocos2d::Scene
//{
//public:
//    /** TestCase test type.*/
//    enum class Type
//    {
//        /** For testing whether test case not crash.*/
//        ROBUSTNESS,
//        /**
//         * For check the correctness of regular test cases.
//         * A test case passes only if the actual output equal to the expected output.
//         */
//        UNIT,
//        /** @warning The test type is not achieved.*/
//        GRAPHICAL_STATIC,
//        /** @note It's mean the test case need test manually.*/
//        MANUAL
//    };
//    TestCase();
//    ~TestCase();
//
//    virtual std::string title() const { return ""; }
//    virtual std::string subtitle() const { return ""; }
//
//    /** Returns the test type, the default type is Type::ROBUSTNESS.*/
//    virtual Type getTestType() const;
//    /** Returns the time the test case needs.*/
//    virtual float getDuration() const;
//
//
//    /** Returns the expected output.*/
//    virtual std::string getExpectedOutput() const { return ""; }
//    /** Returns the actual output.*/
//    virtual std::string getActualOutput() const { return ""; }
//
//    /** Callback functions.*/
//    virtual void restartTestCallback(cocos2d::Ref* sender);
//    virtual void nextTestCallback(cocos2d::Ref* sender);
//    virtual void priorTestCallback(cocos2d::Ref* sender);
//    virtual void onBackCallback(cocos2d::Ref* sender);
//
//    /**
//     * You should NEVER call this method, unless you know what you are doing.
//     */
//    void setTestSuite(TestSuite* testSuite);
//    TestSuite* getTestSuite() const { return _testSuite; }
//
//    /** Returns the run time of test case.*/
//    float getRunTime() const { return _runTime; }
//
//    /**
//     * You should NEVER call this method, unless you know what you are doing.
//     */
//    void setTestCaseName(const std::string& name) { _testCaseName = name; }
//    std::string getTestCaseName() const { return _testCaseName; }
//
//    virtual void onEnter() override;
//CC_CONSTRUCTOR_ACCESS:
//    virtual bool init() override;
////
//protected:
//    cocos2d::MenuItemImage* _priorTestItem;
//    cocos2d::MenuItemImage* _restartTestItem;
//    cocos2d::MenuItemImage* _nextTestItem;
//
//    cocos2d::Label* _titleLabel;
//    cocos2d::Label* _subtitleLabel;
//
//private:
//    TestSuite* _testSuite;
//    float _runTime;
//    std::string _testCaseName;
//};
//
//#endif /* TestCaseScene_h */
