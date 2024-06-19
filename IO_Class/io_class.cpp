#include "io_class.h"

namespace eng {
    void eng::IO::run()
    {
        double T_ambient;
        std::cout << "¬ведите температуру окружающей среды (по ÷ельсию): ";
        std::cin >> T_ambient;

        std::vector<double> M{ 20, 75, 100, 105, 75, 0 };
        std::vector<double> V{ 0, 75, 150, 200, 250, 300 };

        Engine engine(10, M, V, 110, 0.01, 0.0001, 0.1, T_ambient);

        OverheatTest overheatTest;
        MaxPowerTest maxPowerTest;

        overheatTest.runTest(engine);
        maxPowerTest.runTest(engine);
    }
}
