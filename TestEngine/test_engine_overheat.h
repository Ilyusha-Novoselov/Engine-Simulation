#ifndef TEST_ENGINE_OVERHEAT_H_
#define TEST_ENGINE_OVERHEAT_H_

#include <iostream>

#include "../TestEngineBase/test_engine_base.h"

namespace eng {
    class OverheatTest : public EngineTestBase {
    public:
        void runTest(EngineBase& engine) override;
    };
}
#endif