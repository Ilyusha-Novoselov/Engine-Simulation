#ifndef ENGINE_H_
#define ENGINE_H_

#include <vector>

#include "../EngineBase/engine_base.h"

namespace eng {
    // Engine class for simulating engine operation
    class Engine : public EngineBase {
    public:
        Engine(double I, std::vector<double>& M, std::vector<double>& V, double T_overheat,
            double HM, double HV, double C, double T_ambient)
            : _I(I), _M(M), _V(V), _T_overheat(T_overheat), _HM(HM), _HV(HV), _C(C), _T_ambient(T_ambient),
            _current_speed(0), _current_temp(T_ambient), _time(0) {}

        double getCurrentSpeed() const override;

        double getCurrentTemp() const override;

        double getTime() const override;

        void setCurrentSpeed(double speed) override;

        void setCurrentTemp() override;

        void setTime(double time) override;

        // Obtaining torque through linear interpolation
        double getTorque(double speed) const override;

        void Update(double dt) override;

        bool isOverheated() const override;

        double getPower() const override;

    private:
        double _I;
        std::vector<double> _M;
        std::vector<double> _V;
        double _T_overheat;
        double _HM;
        double _HV;
        double _C;

        double _T_ambient;
        double _current_speed;
        double _current_temp;
        double _time;
    };
}

#endif