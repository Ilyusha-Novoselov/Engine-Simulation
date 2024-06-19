#ifndef TEST_ENGINE_BASE_H_
#define TEST_ENGINE_BASE_H_

#include "../EngineBase/engine_base.h"

namespace eng {
    // Abstract base class for engine tests
    class EngineTestBase {
    public:
        virtual ~EngineTestBase() = default;

        virtual void runTest(EngineBase& engine) = 0;
    };
}

#endif