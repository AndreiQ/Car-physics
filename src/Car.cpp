#include "Car.h"

Car::Car()
{

    carShape.setSize((sf::Vector2f(30.f, 100.f)));
    carShape.setOrigin(5.f ,15.f);
    carShape.setPosition(400.f, 300.f);
    forwardVec = sf::Vector2f(0,1);

}

Car::~Car()
{

}
void Car::updateMovement(float dt)
{

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			carShape.rotate(-rotateAmount *dt);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			carShape.rotate(rotateAmount * dt);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if(currentSpeed < maxSpeed)
			{
				currentSpeed += acceleration * dt;
			}
			//rotate direction vector
			sf::Vector2f oldVec = movementVec;
			sf::Transform t;
			t.rotate(carShape.getRotation());
			movementVec = t.transformPoint(forwardVec);
			//calc the dot product so any rotation reduces the
			//current speed - gives the impression of wheel spin
			//when accelerating after a tight turn
			//currentSpeed *= Helpers::Vectors::Dot(oldVec, movementVec);
		}
		else
		{
			currentSpeed -= deceleration * dt;
			if(currentSpeed < 0.f) currentSpeed = 0.f;
		}



		//finally, move car
		carShape.move(movementVec * currentSpeed * dt);

		//-------draw-------------

}
