#ifndef CAR_H
#define CAR_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Car
{
    public:
        Car();
        sf::RectangleShape carShape;
    float currentSpeed = 0.f;
	//consts are units per second as each value is multiplied by frame time
	const float acceleration = 360.f;
	const float deceleration = 280.f;
	const float maxSpeed = 800.f;
	const float rotateAmount = 220.f;
	//some movement values
	sf::Vector2f movementVec; //normal vector based on current direction
	sf::Vector2f forwardVec; //normal vec pointing forward
    void updateMovement(float dt);
        virtual ~Car();
    private:
};

#endif // CAR_H
