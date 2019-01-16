#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Network.hpp>

using namespace std;

bool playM = false;
bool tutorial = false;

int main() { 

	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text Tittle;
	Tittle.setFont(font);
	Tittle.setString("BROKEN BONES");
	Tittle.setCharacterSize(45);
	Tittle.setFillColor(sf::Color::Red);
	Tittle.setPosition(400, 100);

	sf::Text TutorialP;
	TutorialP.setFont(font);
	TutorialP.setString("NOW YOU WILL HAVE TO GO");
	TutorialP.setCharacterSize(45);
	TutorialP.setFillColor(sf::Color::White);
	TutorialP.setPosition(155, 300);


	sf::Text TutorialPT;
	TutorialPT.setFont(font);
	TutorialPT.setString("THROUGH A QUICK TUTORIAL");
	TutorialPT.setCharacterSize(40);
	TutorialPT.setFillColor(sf::Color::White);
	TutorialPT.setPosition(200, 375);


	sf::Text PlayM;
	PlayM.setFont(font);
	PlayM.setString("PLAY");
	PlayM.setCharacterSize(35);
	PlayM.setFillColor(sf::Color::White);
	PlayM.setPosition(575, 275);

	sf::Text PlayT;
	PlayT.setFont(font);
	PlayT.setString("-->");
	PlayT.setCharacterSize(75);
	PlayT.setFillColor(sf::Color::Black);
	PlayT.setPosition(510, 505);


	sf::RectangleShape Menu;
	Menu.setSize(sf::Vector2f(1280, 720));
	Menu.setFillColor(sf::Color::Black);
	Menu.setPosition(1, 1);

	sf::RectangleShape PlayB;
	PlayB.setSize(sf::Vector2f(140, 75));
	PlayB.setFillColor(sf::Color::Black);
	PlayB.setPosition(570, 260);
	
	sf::RectangleShape PlayerOne;
	PlayerOne.setSize(sf::Vector2f(100, 200));
	PlayerOne.setFillColor(sf::Color::Blue);
	PlayerOne.setPosition(150, 350);

	sf::RectangleShape Floor;
	Floor.setSize(sf::Vector2f(1280, 200));
	Floor.setFillColor(sf::Color::Green);
	Floor.setPosition(0, 520);

	sf::RectangleShape TutorialB;
	TutorialB.setSize(sf::Vector2f(200, 100));
	TutorialB.setFillColor(sf::Color::White);
	TutorialB.setPosition(500, 500);


	sf::RenderWindow window(sf::VideoMode(1280, 720), "Broken Bones");

	while (window.isOpen()) {

		//handle events
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (event.type == sf::Event::MouseButtonPressed && PlayB.getGlobalBounds().contains(mousePosF)) {

			playM = true;

		}

		if (event.type == sf::Event::MouseButtonPressed && TutorialB.getGlobalBounds().contains(mousePosF)) {

			tutorial = true;

		}

		if (playM == true) {
			PlayB.setPosition(1000, 1000);
			Menu.setPosition(1000, 1000);
		}

		if (playM == false){
			PlayB.setPosition(570, 260);
			Menu.setPosition(1, 1);
		}

		if (tutorial == true) {
			TutorialB.setPosition(1000, 1000);
			TutorialP.setPosition(1000, 1000);
			TutorialPT.setPosition(1000, 1000);
		}
		//updates

		window.clear();
		//draw objects
		if (playM == false) {
			window.draw(Menu);
			window.draw(Tittle);
			window.draw(PlayB);
			window.draw(PlayM);
		}

		if (playM == true) {
			window.draw(TutorialB);
			window.draw(PlayT);
			window.draw(TutorialP);
			window.draw(TutorialPT);
		}
		if (tutorial == true) {
			window.draw(Floor);
			window.draw(PlayerOne);
		}
		window.display();
	}
}

