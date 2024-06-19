#include "test_engine_max_power.h"
#include "../Engine/engine.h"

namespace eng {
    void MaxPowerTest::runTest(EngineBase& engine)
    {
        double max_power = 0;
        double max_power_speed = 0;

        if (engine.getTime() >= 5000)
        {
            engine.setCurrentSpeed(0.0);
            engine.setCurrentTemp();
            engine.setTime(0.0);
        }

        while (true)
        {
            engine.Update(0.01);
            double power = engine.getPower();
            if (power > max_power)
            {
                max_power = power;
                max_power_speed = engine.getCurrentSpeed();
            }
            else
                break;
        }

        std::cout << "Максимальная мощность: " << max_power << " кВт при скорости " << max_power_speed << " рад/сек" << std::endl;
    }
}