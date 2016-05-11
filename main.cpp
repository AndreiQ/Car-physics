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
	//set up visual for vehicle
	sf::View view(sf::FloatRect(100, 100, 200, 100));
    view.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
    view.setCenter(sf::Vector2f(view.getSize().x,view.getSize().y));
    window.setView(view);
    Car car;
    sf::Texture backTexture;
    if (!backTexture.loadFromFile("background2.jpg"))
        return EXIT_FAILURE;
    sf::Sprite background(backTexture);
    background.setScale(3,3);


	//-----------------------------------//

	while(window.isOpen())
	{
		//poll input
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed
				|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
        }
		//------------------------
		float dt = deltaClock.restart().asSeconds();

        car.updateMovement(dt);

		frameClock.restart();

		window.clear();
		window.draw(background);
		window.draw(car.carShape);
		view.setCenter(car.carShape.getPosition());
		window.setView(view);
		window.display();



		//----------------------
		const float time = 1.f / frameClock.getElapsedTime().asSeconds();
		std::stringstream stream;
		stream << "Current fps: " << time << std::endl;
		window.setTitle(stream.str());
	}

	return 0;
}
