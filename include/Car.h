#ifndef CAR_H
#define CAR_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Car
{
    public:
        sf::RectangleShape carShape;
        Car();
        void checkInputs(float deltaTime);
        void drawCarInWindow(sf::RenderWindow &window);
        virtual ~Car();
    private:
        float currentSpeed = 0.f;
        const float acceleration = 360.f;
        const float deceleration = 280.f;
        const float maxSpeed = 800.f;
        const float rotateAmount = 220.f;
        void changeCarSpeed(float valueForChange);
        void rotateCar(float angle);
        void updateMovement(float roatation);
        sf::Vector2f movementVector;
        sf::Vector2f forwardVector;
};

#endif // CAR_H
