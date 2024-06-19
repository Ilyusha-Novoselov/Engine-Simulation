#ifndef ENGINE_BASE_H_
#define ENGINE_BASE_H_

namespace eng {
    // Abstract base class for engines
    class EngineBase {
    public:
        virtual ~EngineBase() = default;

        // Obtaining the current speed
        virtual double getCurrentSpeed() const = 0;

        // Getting the current temperature
        virtual double getCurrentTemp() const = 0;

        // Getting the current time
        virtual double getTime() const = 0;

        virtual void setCurrentSpeed(double speed) = 0;

        virtual void setCurrentTemp() = 0;

        virtual void setTime(double time) = 0;

        // Generating torque
        virtual double getTorque(double speed) const = 0;

        // Updating the engine status
        virtual void Update(double dt) = 0;

        // Overheating test
        virtual bool isOverheated() const = 0;

        // Getting power
        virtual double getPower() const = 0;
    };
}
#endif