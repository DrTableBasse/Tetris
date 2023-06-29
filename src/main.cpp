/*

 Author: Yannis STEFANELLI

 Creation Date: 28-02-2023 22:12:29

 Description :
 Main project file
*/

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/tetromino.h"
#include <SFML/Audio.hpp>
#include <vector>
#include <IconsFontAwesome.h>
#include <imconfig.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include "ImGuiUtils.h" //general config header

using namespace sf;
using namespace ImGui;

int main(){
	//resolution and creation of window
	Vector2i res(720, 1080);
	RenderWindow window(VideoMode(res.x, res.y), "TetrESGI", Style::Titlebar | Style::Close);

	//loading icon
	auto image = sf::Image{};
	if(!image.loadFromFile("../sprites/logo.jpg"))
	{
		cout << "Icone n'a pas chargé\n";
	}
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	if(SFML::Init(window, true))
	{}



	//texture create and loading spritesheet
	Texture texture;
	if(!texture.loadFromFile("../sprites/spritesheet.png"))
	{
		cout << "Le spritesheet n'a pas load\n";
	}

	int volume = 0;
	bool windowOpen = true;
	Clock deltaClock;
	Clock clock;
	Clock fall;
	SoundBuffer buffer;
	sf::Sound sound;

	if(!buffer.loadFromFile("../src/musique/soundtrack.ogg"))
	{
		return -1;
	}
	sound.setBuffer(buffer);
	sound.play();

	//declaration of the board (default = 10x20)
	//you can access board.setsize() to change board's size
	Board board;

	//piece declaration
	std::vector<Sprite> listBlock;
	Tetromino piece(&texture, 2, Vector2i(board.x, board.y));

	//Frame loop
	while(window.isOpen())
	{
		//Event loop
		Event event{};
		while(window.pollEvent(event))
		{
			SFML::ProcessEvent(window, event);

			//Conditions to close the window
			if(event.type == Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyReleased)
			{
				if(event.key.code == sf::Keyboard::Escape)
				{
					windowOpen = !windowOpen;
					sound.play();
					break;
				}
			}

			//remplacer par le menu pause
			if(Keyboard::isKeyPressed(Keyboard::Left))
			{
				while(clock.getElapsedTime().asSeconds() > 0.05f)
				{
					if(piece.pos.x - 24 >= 0 && !Tetromino::verifyColision(piece, listBlock, board, 'L'))
					{
						piece.setpos(Vector2i(-24, 0), 0);
					}
					clock.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right))
			{
				while(clock.getElapsedTime().asSeconds() > 0.05f)
				{
					if(piece.pos.x + 24 <= board.x * 24 && !Tetromino::verifyColision(piece, listBlock, board, 'R'))
					{
						piece.setpos(Vector2i(24, 0), 0);
					}
					clock.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::A))
			{
				while(clock.getElapsedTime().asSeconds() > 0.1f)
				{
					piece.setpos(Vector2i(0, 0), -1);
					clock.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::E))
			{
				while(clock.getElapsedTime().asSeconds() > 0.1f)
				{
					piece.setpos(Vector2i(0, 0), 1);
					clock.restart();
				}
			}
		}

		//update la fenêtre
		SFML::Update(window, deltaClock.restart());
		//Clearing the window after each draw
		window.clear(Color(0, 0, 0));

		if(windowOpen)
		{

			Begin("window", NULL);
			sound.pause();
			if(ImGui::Button("Reprendre la partie"))
			{
				windowOpen = false;
				sound.play();

			}

			ImGui::SliderInt("Régler le volume", &volume, 0, 100);
			sound.setVolume(volume);


			if(ImGui::Button("Quitter le jeu"))
			{
				return EXIT_SUCCESS;
			}


			End();
		}


		//draw each piece blocks (max 4)
		for(const auto &block: piece.blocks)
		{
			window.draw(block);
		}
		for(const auto &block: listBlock)
		{
			window.draw(block);
		}

		if(fall.getElapsedTime().asSeconds() > 0.2 && !windowOpen)
		{
			piece.setpos(Vector2i(0, 24), 0);
			if(Tetromino::verifyColision(piece, listBlock, board, 'D'))
			{
				for(const auto &block: piece.blocks)
				{
					board.tab[static_cast<int>(block.getPosition().x)/24][static_cast<int>(block.getPosition().y)/24] = 1;
					listBlock.push_back(block);
				}

				piece.reset();
			}
			fall.restart();
		}
		SFML::Render(window);
		window.display();
	}
	SFML::Shutdown();
	return 0;
}
