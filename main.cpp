#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Network.hpp>

using namespace std;

template <typename T>

std::string toString(T arg) {
	std::stringstream ss;
	ss << arg;
	return ss.str();

}


bool playM = false;
bool tutorial = false;
bool bruceP = false;
bool bruceI = false;
bool bruceK = false;
bool bruceB = false;

bool tutorialFP = false;
bool tutorialT = true;
bool tutorialF = true;
bool tutorialS = true;
bool tutorialFF = true;
bool gamemodes = false;
bool levels = false;
bool onePlayer = false;
bool twoPlayer = false;
bool oneSurvival = false;
bool twoSurvival = false;
bool onePvp = false;
bool twoPvp = false;

int bruceHealth = 200;

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


	sf::Text Health;
	Health.setFont(font);
	Health.setCharacterSize(35);
	Health.setFillColor(sf::Color::Red);
	Health.setString("HEALTH: 200");
	Health.setPosition(1, 1);
	//std::string Health = toString<int>(bruceHealth);
	//Health.setString("Health: " + bruceHealth);

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


	sf::Text MapPVPT;
	MapPVPT.setFont(font);
	MapPVPT.setString("-->");
	MapPVPT.setCharacterSize(75);
	MapPVPT.setFillColor(sf::Color::White);
	MapPVPT.setPosition(510, 345);


	sf::Text GamemodeBackBT;
	GamemodeBackBT.setFont(font);
	GamemodeBackBT.setCharacterSize(75);
	GamemodeBackBT.setFillColor(sf::Color::Black);
	GamemodeBackBT.setPosition(510, 345);


	sf::Text TutorialF;
	TutorialF.setFont(font);
	TutorialF.setString("NOW PRESS A AND D TO MOVE AROUND");
	TutorialF.setCharacterSize(35);
	TutorialF.setFillColor(sf::Color::White);
	TutorialF.setPosition(100, 100);


	sf::Text TutorialS;
	TutorialS.setFont(font);
	TutorialS.setString("NOW PRESS E TO PUNCH");
	TutorialS.setCharacterSize(35);
	TutorialS.setFillColor(sf::Color::White);
	TutorialS.setPosition(100, 100);

	sf::Text TutorialT;
	TutorialT.setFont(font);
	TutorialT.setString("NOW PRESS F TO KICK");
	TutorialT.setCharacterSize(35);
	TutorialT.setFillColor(sf::Color::White);
	TutorialT.setPosition(100, 100);


	sf::Text TutorialFF;
	TutorialFF.setFont(font);
	TutorialFF.setString("NOW PRESS Q TO BLOCK");
	TutorialFF.setCharacterSize(35);
	TutorialFF.setFillColor(sf::Color::White);
	TutorialFF.setPosition(100, 100);


	sf::Text TutorialTF;
	TutorialTF.setString("CONGRADULATIONS YOU FINISHED");
	TutorialTF.setCharacterSize(35);
	TutorialTF.setFillColor(sf::Color::White);
	TutorialTF.setFont(font);
	TutorialTF.setPosition(100, 100);


	sf::Text TutorialTFT;
	TutorialTFT.setString("THE TUTORIAL");
	TutorialTFT.setCharacterSize(35);
	TutorialTFT.setFillColor(sf::Color::White);
	TutorialTFT.setFont(font);
	TutorialTFT.setPosition(100, 175);


	sf::Text PlayLevels;
	PlayLevels.setString("LEVELS");
	PlayLevels.setCharacterSize(35);
	PlayLevels.setFillColor(sf::Color::White);
	PlayLevels.setFont(font);
	PlayLevels.setPosition(575, 275);

	sf::Text Gamemodes;
	Gamemodes.setString("GAMEMODES");
	Gamemodes.setCharacterSize(35);
	Gamemodes.setFillColor(sf::Color::White);
	Gamemodes.setFont(font);
	Gamemodes.setPosition(525, 375);


	sf::Texture BruceIT;
	BruceIT.loadFromFile("BruceI.png");
	sf::Sprite BruceI;
	BruceI.setTexture(BruceIT);
	BruceI.setScale(sf::Vector2f(0.3, 0.3));
	BruceI.setPosition(25, 235);
	

	sf::Texture BruceKT;
	BruceKT.loadFromFile("BruceKick.png");
	sf::Sprite BruceK;
	BruceK.setTexture(BruceKT);
	BruceK.setScale(sf::Vector2f(3.6, 3.6));
	BruceK.setPosition(25, 235);


	sf::Texture BrucePT;
	BrucePT.loadFromFile("BruceP.png");
	sf::Sprite BruceP;
	BruceP.setTexture(BrucePT);
	BruceP.setScale(sf::Vector2f(0.3, 0.3));
	BruceP.setPosition(25, 235);


	sf::Texture BruceBT;
	BruceBT.loadFromFile("BruceBlock.png");
	sf::Sprite BruceB;
	BruceB.setTexture(BruceBT);
	BruceB.setScale(sf::Vector2f(3.6, 3.6));
	BruceB.setPosition(25, 235);


	sf::RectangleShape TutorialFP;
	TutorialFP.setSize(sf::Vector2f(1280, 720));
	TutorialFP.setFillColor(sf::Color::Black);
	TutorialFP.setPosition(1, 1);


	sf::RectangleShape Menu;
	Menu.setSize(sf::Vector2f(1280, 720));
	Menu.setFillColor(sf::Color::Black);
	Menu.setPosition(1, 1);

	sf::RectangleShape TutorialM;
	TutorialM.setSize(sf::Vector2f(1280, 720));
	TutorialM.setFillColor(sf::Color::Black);
	TutorialM.setPosition(1, 1);


	sf::RectangleShape PlayB;
	PlayB.setSize(sf::Vector2f(140, 75));
	PlayB.setFillColor(sf::Color::Black);
	PlayB.setPosition(570, 260);

	sf::RectangleShape PlayLevelsB;
	PlayLevelsB.setSize(sf::Vector2f(200, 75));
	PlayLevelsB.setFillColor(sf::Color::Black);
	PlayLevelsB.setPosition(570, 260);

	sf::RectangleShape PlayGamemodesB;
	PlayGamemodesB.setSize(sf::Vector2f(315, 75));
	PlayGamemodesB.setFillColor(sf::Color::Black);
	PlayGamemodesB.setPosition(520, 360);


	sf::RectangleShape MapPVP;
	MapPVP.setSize(sf::Vector2f(200, 100));
	MapPVP.setFillColor(sf::Color::Black);
	MapPVP.setPosition(500, 350);


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

		if (event.type == sf::Event::MouseButtonPressed && MapPVP.getGlobalBounds().contains(mousePosF)) {

			tutorialFP = true;
			tutorial = false;

		}


		if (playM == true) {
			PlayB.setPosition(1000, 1000);
			Menu.setPosition(1000, 1000);
		}

		if (playM == false) {
			PlayB.setPosition(570, 260);
			Menu.setPosition(1, 1);
		}

		if (tutorial == true) {
			TutorialB.setPosition(1000, 1000);
			TutorialP.setPosition(1000, 1000);
			TutorialPT.setPosition(1000, 1000);
			TutorialM.setPosition(1000, 1000);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			bruceI = false;
			bruceK = false;
			bruceB = false;
			bruceP = true;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			bruceI = false;
			bruceP = false;
			bruceB = false;
			bruceK = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

			bruceI = false;
			bruceP = false;
			bruceK = false;
			bruceB = true;
		}

		else {
			bruceP = false;
			bruceK = false;
			bruceB = false;
			bruceI = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			BruceI.move(2, 0);
			BruceP.move(2, 0);
			BruceK.move(2, 0);
			BruceB.move(2, 0);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			BruceI.move(-2, 0);
			BruceP.move(-2, 0);
			BruceK.move(-2, 0);
			BruceB.move(-2, 0);
		}

		//updates

		window.setFramerateLimit(60);
		window.clear(sf::Color(51, 153, 255, 0));

		//draw objects

		if (playM == false) {
			window.draw(Menu);
			window.draw(Tittle);
			window.draw(PlayB);
			window.draw(PlayM);
		}

		if (playM == true) {
			window.draw(TutorialM);
			window.draw(TutorialB);
			window.draw(PlayT);
			window.draw(TutorialP);
			window.draw(TutorialPT);
		}

		if (tutorial == true) {
			window.draw(Floor);

			window.draw(TutorialF);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				TutorialF.setPosition(1000, 1000);
				tutorialF = false;
			}

			if (tutorialF == false) {

				window.draw(TutorialS);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					TutorialF.setPosition(1000, 1000);
					tutorialS = false;
				}

			}

			if (tutorialS == false) {
				window.draw(TutorialT);
				TutorialS.setPosition(1000, 1000);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					TutorialT.setPosition(1000, 1000);
					tutorialT = false;

				}

				if (tutorialT == false) {
					window.draw(TutorialFF);
					TutorialT.setPosition(1000, 1000);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
						TutorialFF.setPosition(1000, 1000);
						tutorialFF = false;
					}
				}

				if (tutorialFF == false) {
					window.draw(TutorialTF);
					window.draw(TutorialTFT);
					window.draw(MapPVP);
					window.draw(MapPVPT);
				}

			}

			if (bruceI == true) {
				window.draw(BruceI);
			}

			if (bruceP == true) {
				window.draw(BruceP);
			}

			if (bruceK == true) {
				window.draw(BruceK);
			}

			if (bruceB == true) {
				window.draw(BruceB);
			}
		}

		if (tutorialFP == true) {
			window.draw(TutorialFP);
			window.draw(Tittle);
			window.draw(PlayGamemodesB);
			window.draw(PlayLevelsB);
			window.draw(PlayLevels);
			window.draw(Gamemodes);
		}

		window.display();
	}
}
