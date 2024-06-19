#include "test_engine_overheat.h"

namespace eng {
    void OverheatTest::runTest(EngineBase& engine)
    {
        const double maxSimulationTime = 5000; // Maximum simulation time in seconds
        const double dt = 0.01;

        while (!engine.isOverheated() && engine.getTime() < maxSimulationTime)
            engine.Update(dt);

        if (engine.isOverheated())
            std::cout << "����� ���������: " << engine.getTime() << " ������" << std::endl;
        else
            std::cout << "��������� �� ���������� � ������� ������������� ������� ������������� " << maxSimulationTime << " ������." << std::endl;
    }
}