/*********************************************************************
Example code to accompany article at:

http://trederia.blogspot.com/2014/02/space-racers-breakdown-part-3-vehicle.html

*********************************************************************/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//#include <Helpers.h>

#include <sstream>
#include "Car.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Vehicle Handling");
	sf::Clock deltaClock, frameClock;
	window.setFramerateLimit(60);
    Car car;
    sf::Texture backgroudTexture;
    backgroudTexture.loadFromFile("background2.jpg");
    sf::Sprite backgroundSprite(backgroudTexture);
    backgroundSprite.setScale(3,3);
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed
				|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
        }
		float deltaTime = deltaClock.restart().asSeconds();
		frameClock.restart();
		window.clear();
		window.draw(backgroundSprite);

		car.checkInputs(deltaTime);
		car.drawCarInWindow(window);

		window.display();
		const float time = 1.f / frameClock.getElapsedTime().asSeconds();
		window.setTitle("Titlu");
	}

	return 0;
}
