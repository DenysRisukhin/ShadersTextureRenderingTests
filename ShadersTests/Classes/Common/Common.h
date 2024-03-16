//
//  Common.h
//  ShadersTests
//
//  Created by Risukhin Denys on 3/16/24.
//

#ifndef Common_h
#define Common_h

#include "cocos2d.h"
#include "Effect.h"
#include <tuple>
#include "Common.h"

USING_NS_CC;


static int tuple_sort( const std::tuple<ssize_t,Effect*,QuadCommand> &tuple1, const std::tuple<ssize_t,Effect*,QuadCommand> &tuple2 )
{
    return std::get<0>(tuple1) < std::get<0>(tuple2);
}

#endif /* Common_h */
