#include "engine.h"

namespace eng {
    double Engine::getCurrentSpeed() const
    {
        return _current_speed;
    }

    double Engine::getCurrentTemp() const
    {
        return _current_temp;
    }

    double Engine::getTime() const
    {
        return _time;
    }

    void Engine::setCurrentSpeed(double speed)
    {
        _current_speed = speed;
    }

    void Engine::setCurrentTemp()
    {
        _current_temp = _T_ambient;
    }

    void Engine::setTime(double time)
    {
        _time = time;
    }


    double Engine::getTorque(double speed) const
    {
        for (size_t i = 0; i < _V.size() - 1; ++i)
        {
            if (speed >= _V[i] && speed <= _V[i + 1])
                return _M[i] + (_M[i + 1] - _M[i]) * (speed - _V[i]) / (_V[i + 1] - _V[i]);
        }

        return 0.0;
    }

    void Engine::Update(double dt)
    {
        double torque = getTorque(_current_speed);
        double acceleration = torque / _I;
        _current_speed += acceleration * dt;

        double heating_rate = torque * _HM + _current_speed * _current_speed * _HV;
        double cooling_rate = _C * (_T_ambient - _current_temp);
        _current_temp += (heating_rate + cooling_rate) * dt;

        _time += dt;
    }

    bool Engine::isOverheated() const
    {
        return _current_temp >= _T_overheat;
    }

    double Engine::getPower() const
    {
        double torque = getTorque(_current_speed);
        return torque * _current_speed / 1000.0;
    }
}

