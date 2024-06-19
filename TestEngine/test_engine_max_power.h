#ifndef TEST_ENGINE_MAX_POWER_H_
#define TEST_ENGINE_MAX_POWER_H_

#include <iostream>

#include "../TestEngineBase/test_engine_base.h"

namespace eng {
    class MaxPowerTest : public EngineTestBase {
    public:
        void runTest(EngineBase& engine) override;
    };
}
#endif