#include "Car.h"

Car::Car()
{
    carShape.setSize((sf::Vector2f(30.f, 100.f)));
    carShape.setOrigin(15.f ,50.f);
    carShape.setPosition(400.f, 300.f);
    forwardVector = sf::Vector2f(0,1);
}
void Car::changeCarSpeed(float valueForChange)
{
    currentSpeed += valueForChange;
    if(currentSpeed<0.f)currentSpeed=0.f;
    if(currentSpeed>maxSpeed)currentSpeed=maxSpeed;
}
void Car::rotateCar(float angle)
{
    this->changeCarSpeed((-1)*currentSpeed/40.f);
    carShape.rotate(angle);
}
void Car::updateMovement(float rotation)
{
    sf::Transform newTransform;
    newTransform.rotate(rotation);
    movementVector = newTransform.transformPoint(forwardVector);
}
void Car::checkInputs(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			this->rotateCar(-rotateAmount *deltaTime);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			this->rotateCar(rotateAmount * deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->changeCarSpeed(acceleration*deltaTime);
            this->updateMovement(carShape.getRotation());
        }
    else
        this->changeCarSpeed((-1)*acceleration*deltaTime);
    carShape.move(movementVector * currentSpeed * deltaTime);
}
void Car::drawCarInWindow(sf::RenderWindow &window)
{
	sf::View view(sf::FloatRect(100, 100, 200, 100));
    view.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
    view.setCenter(sf::Vector2f(view.getSize().x,view.getSize().y));
    window.setView(view);
    view.setCenter(this->carShape.getPosition());
    window.setView(view);
    window.draw(carShape);
}
Car::~Car()
{

}

