#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "stdlib.h"
#include "Player.h"
#include "Bloodup.h"
#include "Buff.h"
#include "star.h"
#include "enemy.h"
using namespace std;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Toommo", sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1080.0f, 720.0f));//view

	//BGMENU1
	sf::RectangleShape bg(sf::Vector2f(1080.0f, 720.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture s;
	s.loadFromFile("a/main.png");
	bg.setTexture(&s);

	//BGBGMENU2
	sf::RectangleShape bg1(sf::Vector2f(1080.0f, 720.0f));
	bg1.setPosition(0.0f, 0.0f);
	sf::Texture s1;
	s1.loadFromFile("a/state1.png");
	bg1.setTexture(&s1);

	//BGMENU3
	sf::RectangleShape bg2(sf::Vector2f(1080.0f, 720.0f));
	bg2.setPosition(0.0f, 0.0f);
	sf::Texture s2;
	s2.loadFromFile("a/state2.png");
	bg2.setTexture(&s2);

	//BGMENU3
	sf::RectangleShape bg3(sf::Vector2f(1080.0f, 720.0f));
	bg3.setPosition(0.0f, 0.0f);
	sf::Texture s3;
	s3.loadFromFile("a/state3.png");
	bg3.setTexture(&s3);

	//BGMENU4
	sf::RectangleShape bg4(sf::Vector2f(1080.0f, 720.0f));
	bg4.setPosition(0.0f, 0.0f);
	sf::Texture s4;
	s4.loadFromFile("a/state4.png");
	bg4.setTexture(&s4);

	//BG1
	sf::RectangleShape background(sf::Vector2f(1080.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("a/map1.png");
	background.setTexture(&space);

	//Endgame
	sf::RectangleShape mission(sf::Vector2f(1080.0f, 720.0f));
	mission.setPosition(0.0f, 0.0f);
	sf::Texture complete;
	complete.loadFromFile("a/endgame.png");
	mission.setTexture(&complete);



	//keyname
	sf::RectangleShape key(sf::Vector2f(1080.0f, 720.0f));
	key.setPosition(0.0f, 0.0f);
	sf::Texture kk;
	kk.loadFromFile("a/keyname2.png");
	key.setTexture(&kk);

	//------------------------------------------------------------- Music & Sound ------------------------------------------------------------//
	sf::SoundBuffer sound2;
	if (!sound2.loadFromFile("a/laser5.ogg"))
		return -1;

	sf::Sound Sound1;
	Sound1.setBuffer(sound2);

	//soundclick
	sf::SoundBuffer soundc;
	soundc.loadFromFile("a/click.WAV");
	sf::Sound Soundch;
	Soundch.setBuffer(soundc);

	//sounditemup
	sf::SoundBuffer soundup;
	soundup.loadFromFile("a/bloodup.WAV");
	sf::Sound SoundUp;
	SoundUp.setBuffer(soundup);

	//sounditemdown
	sf::SoundBuffer sounddown;
	sounddown.loadFromFile("a/blooddw.WAV");
	sf::Sound Sounddown;
	Sounddown.setBuffer(sounddown);

	//soundjump
	sf::SoundBuffer soundwrap;
	soundwrap.loadFromFile("a/powerUp10.ogg");
	sf::Sound Sound3;
	Sound3.setBuffer(soundwrap);

	//soundmenu
	sf::Music music;
	music.openFromFile("a/menu1.wav");
	music.setLoop(true);
	music.setVolume(20.f);

	//soundmap
	sf::Music music1;
	music1.openFromFile("a/ogb.wav");
	music1.setLoop(true);
	music1.setVolume(20.f);

	//soundover
	sf::Music musicend;
	musicend.openFromFile("a/over.wav");
	musicend.setLoop(true);
	musicend.setVolume(20.f);



	//----------------------------------------------------------- Font -------------------------------------------------------------//
	sf::Font font;
	font.loadFromFile("a/ARLRDBD.TTF");
	std::ostringstream score;
	sf::Text Score;
	Score.setCharacterSize(30);
	Score.setString(score.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::Black);

	//scoregame
	int countscore = 0;
	sf::Font SCORE;
	SCORE.loadFromFile("a/ARLRDBD.TTF");
	std::ostringstream score1;
	sf::Text scoregame;
	scoregame.setCharacterSize(50);
	scoregame.setString(score1.str());
	scoregame.setFont(SCORE);
	scoregame.setFillColor(sf::Color::Black);

	//hp font
	sf::Font Hppush;
	Hppush.loadFromFile("a/ARLRDBD.TTF");
	std::ostringstream hppush;
	sf::Text Hpblood;
	Hpblood.setCharacterSize(30);
	Hpblood.setString(hppush.str());
	Hpblood.setFont(font);
	Hpblood.setFillColor(sf::Color::Red);
	sf::Text Hpblood2;
	Hpblood2.setCharacterSize(30);
	Hpblood2.setString(hppush.str());
	Hpblood2.setFont(font);
	Hpblood2.setFillColor(sf::Color::Red);
	sf::Text bulA;
	bulA.setCharacterSize(30);
	bulA.setString(hppush.str());
	bulA.setFont(font);
	bulA.setFillColor(sf::Color::Red);
	sf::Text bulA1;
	bulA1.setCharacterSize(30);
	bulA1.setString(hppush.str());
	bulA1.setFont(font);
	bulA1.setFillColor(sf::Color::Red);
	sf::Text bulA2;
	bulA2.setCharacterSize(30);
	bulA2.setString(hppush.str());
	bulA2.setFont(font);
	bulA2.setFillColor(sf::Color::Red);
	sf::Text HighScore;
	HighScore.setCharacterSize(30);
	HighScore.setString(hppush.str());
	HighScore.setFont(font);
	HighScore.setFillColor(sf::Color::Yellow);

	//Player
	sf::Texture playertexture;
	playertexture.loadFromFile("a/swim.png");
	Player player(&playertexture, sf::Vector2u(4, 3), 0.15f, 600.0f, 200.0f);

	//enemy


	sf::Texture STAR;
	STAR.loadFromFile("a/star4.png");
	std::vector <star*> starVector;

	//ITEM
	//Bloodup
	sf::Texture BLOODUP;
	BLOODUP.loadFromFile("a/module.png");
	std::vector <Bloodup> BloodupVector;
	//Blooddown
	sf::Texture BLOODDOWN;
	BLOODDOWN.loadFromFile("a/module.png");
	std::vector <Bloodup> BlooddownVector;
	//X10
	sf::Texture POINTX2;
	POINTX2.loadFromFile("a/module.png");
	std::vector <Buff> X2Vector;
	sf::Texture stateX10;
	stateX10.loadFromFile("a/module.png");
	sf::RectangleShape x10(sf::Vector2f(180, 180));
	x10.setTexture(&stateX10);

	//key
	sf::Texture keyW;
	keyW.loadFromFile("a/module.png");
	sf::RectangleShape ww(sf::Vector2f(32, 32));
	ww.setPosition(sf::Vector2f(850, 30));
	ww.setTexture(&keyW);
	sf::Texture keyS;
	keyS.loadFromFile("a/module.png");
	sf::RectangleShape ss(sf::Vector2f(32, 32));
	ss.setPosition(sf::Vector2f(850, 67));
	ss.setTexture(&keyS);
	sf::Texture keyD;
	keyD.loadFromFile("a/module.png");
	sf::RectangleShape dd(sf::Vector2f(32, 32));
	dd.setPosition(sf::Vector2f(850, 106));
	dd.setTexture(&keyD);
	sf::Texture keySP;
	keySP.loadFromFile("a/module.png");
	sf::RectangleShape sp(sf::Vector2f(32, 32));
	sp.setPosition(sf::Vector2f(850, 146));
	sp.setTexture(&keySP);

	//endscore
	int realscore = 0;
	int EndScore = 0;
	sf::Text Send;
	Send.setCharacterSize(40);
	Send.setFont(font);
	Send.setFillColor(sf::Color::White);

	//endscorestar
	int EndNumStar = 0;
	sf::Text CSTER;
	sf::Font gameover;
	gameover.loadFromFile("a/ARLRDBD.TTF");
	CSTER.setCharacterSize(40);
	CSTER.setString(hppush.str());
	CSTER.setFont(gameover);
	CSTER.setFillColor(sf::Color::White);

	//newscore
	sf::Text NewScore;
	NewScore.setCharacterSize(60);
	NewScore.setString(hppush.str());
	NewScore.setFont(font);
	NewScore.setFillColor(sf::Color::White);


	sf::Texture load;
	load.loadFromFile("a/keynameload.png");
	sf::RectangleShape ll(sf::Vector2f(1080, 720));
	ll.setPosition(sf::Vector2f(0, 0));
	ll.setTexture(&load);

	float MyHP = 78000;
	sf::RectangleShape HP(sf::Vector2f(MyHP / 200.0f, 30));
	HP.setPosition(sf::Vector2f(100, 50));
	HP.setFillColor(sf::Color::Red);
	HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));

	float Downlaod = 0;
	sf::RectangleShape DL(sf::Vector2f(Downlaod / 50.0f, 20));
	DL.setPosition(sf::Vector2f(285, 647.5f));
	DL.setFillColor(sf::Color::White);
	DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));

	sf::Texture LOAD;
	LOAD.loadFromFile("a/load.png");
	sf::RectangleShape LL(sf::Vector2f(1080, 720));
	LL.setPosition(sf::Vector2f(0, 0));
	LL.setTexture(&LOAD);

	//pause
	sf::Texture pause;
	pause.loadFromFile("a/pause.png");
	sf::RectangleShape pp(sf::Vector2f(1080, 720));
	pp.setTexture(&pause);

	//pauseresume
	sf::Texture pauseresume;
	pauseresume.loadFromFile("a/pauseback.png");
	sf::RectangleShape pr(sf::Vector2f(1080, 720));
	pr.setTexture(&pauseresume);

	//pausemenu
	sf::Texture pausemenu;
	pausemenu.loadFromFile("a/pm.png");
	sf::RectangleShape pm(sf::Vector2f(1080, 720));
	pm.setTexture(&pausemenu);

	//pauseexit
	sf::Texture pauseexit;
	pauseexit.loadFromFile("a/pauseexit.png");
	sf::RectangleShape pe(sf::Vector2f(1080, 720));
	pe.setTexture(&pauseexit);

	//End
	sf::Texture end;
	end.loadFromFile("a/endgame.png");
	sf::RectangleShape ee(sf::Vector2f(1080, 720));
	ee.setTexture(&end);

	sf::Texture High;
	High.loadFromFile("a/highscoree.png");
	sf::RectangleShape hh(sf::Vector2f(1080, 720));
	hh.setTexture(&High);

	sf::String playerInput;
	std::ofstream fileWriter;
	std::ostringstream keyname;
	sf::Text Keyname;
	Keyname.setCharacterSize(40);
	Keyname.setString(" ");
	Keyname.setFont(font);
	Keyname.setFillColor(sf::Color::Black);


	sf::Texture alien;
	alien.loadFromFile("a/shark2.png");
	std::vector <Enemy> alienVector;

	sf::Texture alien1;
	alien1.loadFromFile("a/shark.png");
	std::vector <Enemy> alien1Vector;

	sf::Texture fish1;
	fish1.loadFromFile("a/fish1f.png");
	std::vector <Enemy> fish1Vector;

	sf::Texture fish2;
	fish2.loadFromFile("a/fish2.png");
	std::vector <Enemy> fish2Vector;



	int i = 0;
	int q = 0;
	int Bul = 0;
	int count = 0;
	int state = 0;
	int countloop = 0;
	int soundcount = 0;

	float deltaTime = 0.0f;
	float countTimeAdd = 0;
	float countTimeSub = 0;
	float countTimeBul = 0;
	float countTimeBul1 = 0;
	float countTimeBul2 = 0;
	float countTimex2 = 0;
	

	float aww = 0;

	sf::Clock clock;
	sf::Clock timerpausemenu;
	sf::Clock timer;
	sf::Clock timercoli;

	bool slide;
	bool checkdraw = false;
	bool checkmap1 = false;
	bool checkmap2 = false;
	bool checkcoli = false;
	bool checkBul1 = false;
	bool checkBul2 = false;
	bool checkAdd = false;
	bool checkSub = false;
	bool checkBul = false;
	bool checkx2 = false;
	bool Cload = false;
	bool START = true;
	bool MENU = true;
	bool Rank = false;
	bool SCORE1 = true;
	bool endGame = false;
	bool MemScore = false;
	bool sound_over = false;
	bool checkpause = false;
	bool cheakhighscore = false;

	float spawnTimerMax = 100.f;
	float spawnTimer = spawnTimerMax;
	float spawnTimer1 = spawnTimerMax;
	float spawnTimer2 = spawnTimerMax;
	float spawnTimer3 = spawnTimerMax;

	std::map<int, std::string> keepscore;
	std::ifstream fileReader;
	std::string word;

	/*Modify textbox*/
	char last_char = ' ';
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5.0f, 30.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 15.0f));
	cursor.setFillColor(sf::Color::Black);
	sf::Text text("", font);
	Keyname.setPosition(300, 500);
	text.setFillColor(sf::Color::Black);
	text.setPosition(545, 535);
	cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
	float totalTime_cursor = 0;
	sf::Clock clock_cursor;
	bool state_cursor = false;

	std::string user_name = "";
	fstream myFile;

	while (window.isOpen())
	{
		music.play();
		while (MENU == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;

			deltaTime = clock.restart().asSeconds();
			if (cheakhighscore == false) {
				window.draw(bg);
				window.draw(bg1);
			}
			if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 275 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 348)
			{
				window.draw(bg2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					MENU = false;
					START = false;
					MemScore = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 395 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 466)
			{
				window.draw(bg3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (timerpausemenu.getElapsedTime().asSeconds() >= 0.3))
				{
					Soundch.play();
					MENU = false;
					START = false;
					Rank = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 515 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 584)
			{
				window.draw(bg4);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					window.close();
					break;
				}
			}
			window.display();
		}
		while (Rank == true) {
			
			if(countloop == 0){
				view.setCenter(540, 360);
			}
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;

			window.clear();
			window.draw(hh);
			sf::Text text1("", font);
			text1.setCharacterSize(30);
			text1.setFillColor(sf::Color::White);
			fileReader.open("database/keephighscore.txt");
			do {
				fileReader >> word;
				std::string first_token = word.substr(0, word.find(','));
				int second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				keepscore[second_token] = first_token;
			} while (fileReader.good());
			fileReader.close();
			std::map<int, std::string>::iterator end = keepscore.end();
			std::map<int, std::string>::iterator beg = keepscore.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
				text1.setString(it->second);
				text1.setPosition(view.getCenter().x - 170, 210 + 80 * currentDisplay);
				window.draw(text1);
				text1.setString(std::to_string(it->first));
				text1.setPosition(view.getCenter().x + 95, 210 + 80 * currentDisplay);
				window.draw(text1);
				currentDisplay++;
				if (currentDisplay == 5)
				{
					break;
				}
			}
			if (sf::Mouse::getPosition(window).x >= 416 &&
				sf::Mouse::getPosition(window).y >= 636 &&
				sf::Mouse::getPosition(window).x <= 665 &&
				sf::Mouse::getPosition(window).y <= 685)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Soundch.play();
					Rank = false;
					MENU = true;
				}
			}
			window.display();
		}

		while (MemScore == true) {

			countTimeAdd += deltaTime;
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			if (event.type == sf::Event::TextEntered && last_char != event.text.unicode)
			{
				if (event.text.unicode == 13) { //enter
					user_name = playerInput;
					playerInput.clear();
					MENU = true;
				}
				else if (event.text.unicode == 8 && playerInput.getSize() > 0) { // backspace delete
					playerInput = playerInput.substring(0, playerInput.getSize() - 1);
				}
				else {
					if (playerInput.getSize() < 10) {
						if (countTimeAdd > 0.2) {
							playerInput += event.text.unicode;
							countTimeAdd = 0;
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					MENU = false;
					Rank = false;
					Cload = true;
					soundcount = 0;
				}
				last_char = event.text.unicode;
				text.setString(playerInput);
				cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
			}
			else if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ') {
				last_char = ' ';
			}
			window.clear();
			window.draw(key);
			window.draw(Keyname);

			totalTime_cursor += clock_cursor.restart().asSeconds();
			if (totalTime_cursor >= 0.5) {
				totalTime_cursor = 0;
				state_cursor = !state_cursor;
			}
			if (state_cursor == true) {
				window.draw(cursor);
			}
			window.draw(text);
			if (Cload == true) {
				window.draw(ll);
				window.draw(LL);
				Downlaod += 95;
				DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));
				window.draw(DL);
				if (Downlaod > 80000) {
					Downlaod = 80000;
					MemScore = false;
					START = true;
					music1.play();
					Cload = false;
				}
			}
			window.display();
		}

		deltaTime = 0;
		clock.restart();
		cout << user_name << endl;

		Downlaod = 0;
		MyHP = 78000;
		state = 0;
		EndNumStar = 0;
		
		

		while (START == true) {
			
			//std::cout << "player pos :" << player.GetPosition().y << std::endl;
			music.pause();
			slide = false;
			count = 10;
			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//std::cout << mouesPosition.x << ' ' << mouesPosition.y << '\n';

			if ((checkpause == false && endGame == false) && state != 3) {
				player.update(deltaTime, starVector, X2Vector);
			}
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			spawnTimer += 0.05f;
			if (spawnTimer >= spawnTimerMax && endGame == false && checkpause == false)
			{
				alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 3), 0.3f,130.0f, 85.33f, 1100.0f, rand() % 680 + 150.0f));
				spawnTimer = 0.f;
			}
			spawnTimer1 += 0.045f;
			if (spawnTimer1 >= spawnTimerMax && endGame == false && checkpause == false)
			{
				alien1Vector.push_back(Enemy(&alien1, sf::Vector2u(2, 3), 0.3f, 130.0f, 85.33f, 70.0f, rand() % 680 + 150.0f));
				spawnTimer1 = 0.f;
			}
			spawnTimer2 += 0.05f;
			if (spawnTimer2 >= spawnTimerMax && endGame == false && checkpause == false)
			{
				fish1Vector.push_back(Enemy(&fish1, sf::Vector2u(4, 3), 0.3f, 105.0f, 65.33f, 70.0f, rand() % 680 + 150.0f));
				spawnTimer2 = 0.f;
			}
			spawnTimer3 += 0.04f;
			if (spawnTimer3 >= spawnTimerMax && endGame == false && checkpause == false)
			{
				fish2Vector.push_back(Enemy(&fish2, sf::Vector2u(4, 3), 0.3f, 105.0f, 65.33f, 1100.0f, rand() % 680 + 150.0f));
				spawnTimer3 = 0.f;
			}

			
			//Star
			for (int i = 0; i < starVector.size(); i++) {
				starVector[i]->update(deltaTime);
			}
			//Bloodup
			for (int i = 0; i < BloodupVector.size(); i++) {
				BloodupVector[i].update(deltaTime, player);
			}
			//Blooddown
			for (int i = 0; i < BlooddownVector.size(); i++) {
				BlooddownVector[i].update(deltaTime, player);
			}
			//X10
			for (int i = 0; i < X2Vector.size(); i++) {
				X2Vector[i].update(deltaTime);
			}

			//Alien
			for (int i = 0; i < alienVector.size(); i++) {
				alienVector[i].update1(deltaTime, checkpause, endGame);
				if (checkpause == false) {
					alienVector[i].update2(deltaTime, player, checkpause,endGame);
				}
			}

			for (int i = 0; i < alien1Vector.size(); i++) {
				alien1Vector[i].update1(deltaTime, checkpause, endGame);
				if (checkpause == false) {
					alien1Vector[i].update3(deltaTime, player, checkpause, endGame);
				}
			}

			for (int i = 0; i < fish1Vector.size(); i++) {
				fish1Vector[i].update1(deltaTime, checkpause, endGame);
				if (checkpause == false) {
					fish1Vector[i].update3(deltaTime, player, checkpause, endGame);
				}
			}
			for (int i = 0; i < fish2Vector.size(); i++) {
				fish2Vector[i].update1(deltaTime, checkpause, endGame);
				if (checkpause == false) {
					fish2Vector[i].update2(deltaTime, player, checkpause, endGame);
				}
			}
			

			score1.str(" ");
			score1 << "SCORE :  " << realscore;
			EndScore = realscore;
			scoregame.setPosition({ 40,30 });
			scoregame.setString(score1.str());


			hppush.str(" ");
			hppush << "JUMP";

			HP.setPosition(view.getCenter().x + 100, 45);
			Score.setPosition(view.getCenter().x - 485, 95);
			scoregame.setPosition(view.getCenter().x - 510, 30);


			ww.setPosition({ view.getCenter().x + 330 , 30 });
			ss.setPosition({ view.getCenter().x + 330 , 67 });
			dd.setPosition({ view.getCenter().x + 330 , 106 });
			sp.setPosition({ view.getCenter().x + 330 , 146 });

			view.setCenter(540.0f, 360.0f);
			if (view.getCenter().x - 540.0f <= 0.0f) {
				view.setCenter(540.0f, 360.0f);
			}
			if (view.getCenter().x + 540.0f >= 30000.0f) {
				view.setCenter(29460.0f, 360.0f);
			}

			//
			hppush.str(" ");
			hppush << "  " << EndScore;
			Send.setString(hppush.str());

			hppush.str(" ");
			hppush << "  " << EndNumStar;
			CSTER.setString(hppush.str());

			hppush.str(" ");
			hppush << "  " << EndScore + EndNumStar;
			NewScore.setString(hppush.str());

			for (i = 0; i < alienVector.size(); i++) {
				if (alienVector[i].colAlien() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					checkcoli = true;
					q = 0;
				}
			}

			for (i = 0; i < alien1Vector.size(); i++) {
				if (alien1Vector[i].colAlien() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					checkcoli = true;
					q = 0;
				}
			}

			for (i = 0; i < fish1Vector.size(); i++) {
				if (fish1Vector[i].colAlien() == 2) {
					MyHP += 10000;
					if (MyHP >= 78000)
					{
						MyHP = 78000;
					}
					realscore += 500;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < fish2Vector.size(); i++) {
				if (fish2Vector[i].colAlien() == 2) {
					MyHP += 10000;
					if (MyHP >= 78000)
					{
						MyHP = 78000;
					}
					realscore += 500;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					checkcoli = true;
					q = 0;
				}
			}
			

			//Bloodup
			for (i = 0; i < BloodupVector.size(); i++) {
				if (BloodupVector[i].colBloodup() == 1) {
					MyHP += 1000;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					if (MyHP > 78000) MyHP = 78000;
					hppush.str(" ");
					hppush << "+5000 HP";
					Hpblood.setString(hppush.str());
					Hpblood.setPosition({ player.GetPosition().x , player.GetPosition().y - 90 });
					SoundUp.play();
					checkAdd = true;
				}
			}
			if (checkAdd == true) {
				countTimeAdd += deltaTime;
				if (countTimeAdd > 0.75) {
					Hpblood.setPosition({ -800, 350 });
					countTimeAdd = 0;
					checkAdd = false;
				}
			}
			//Blooddown
			for (i = 0; i < BlooddownVector.size(); i++) {
				if (BlooddownVector[i].colBlooddown() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
					hppush.str(" ");
					hppush << "-5000 HP";
					Hpblood2.setString(hppush.str());
					Hpblood2.setPosition({ player.GetPosition().x,player.GetPosition().y - 90 });
					Sounddown.play();
					checkSub = true;
				}
			}
			if (checkSub == true) {
				countTimeSub += deltaTime;
				if (countTimeSub > 0.75) {
					Hpblood2.setPosition({ -800, 350 });
					countTimeSub = 0;
					checkSub = false;
				}
			}
			//X10
			x10.setPosition(player.GetPosition().x, player.GetPosition().y - 30);
			if (player.getBuffStatus() == true) {
				state = 1;
			}
			else {
				state = 0;
			}

			ee.setPosition(view.getCenter().x - 540, 0);
			pp.setPosition(view.getCenter().x - 540, 0);
			pr.setPosition(view.getCenter().x - 540, 0);
			pm.setPosition(view.getCenter().x - 540, 0);
			pe.setPosition(view.getCenter().x - 540, 0);
			
			mission.setPosition(view.getCenter().x - 540, 0);
			NewScore.setPosition(view.getCenter().x - 108, 277);

			
			window.clear();
			window.setView(view);
			
			window.draw(background);
		
			if (state == 1) {
				window.draw(x10);
			}
			if (checkcoli == true) {
				if (q < 10) {
					if (q % 2 == 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) {
						checkdraw = true;
						q++;
						timercoli.restart();
					}
					else if (q % 2 != 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) {
						checkdraw = false;
						q++;
						timercoli.restart();
					}
					if (q == 10) {
						checkcoli = false;
					}
				}
			}
			if (checkdraw == false) {
				player.Draw(window);
			}
			
			window.draw(HP);
			window.draw(Score);
			window.draw(scoregame);
			window.draw(Hpblood);
			window.draw(Hpblood2);

			for (int i = 0; i < alienVector.size(); i++) {
				alienVector[i].draw(window);
			}

			for (int i = 0; i < alien1Vector.size(); i++) {
				alien1Vector[i].draw(window);
			}
			for (int i = 0; i < fish1Vector.size(); i++) {
				fish1Vector[i].draw(window);
			}
			for (int i = 0; i < fish2Vector.size(); i++) {
				fish2Vector[i].draw(window);
			}

			for (int i = 0; i < starVector.size(); i++) {
				starVector[i]->draw(window);
			}
			for (int i = 0; i < BloodupVector.size(); i++) {
				BloodupVector[i].draw(window);
			}
			for (int i = 0; i < BlooddownVector.size(); i++) {
				BlooddownVector[i].draw(window);
			}
			for (int i = 0; i < X2Vector.size(); i++) {
				X2Vector[i].draw(window);
			}
			
			if (endGame == false && state != 3) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
					checkpause = true;
				}
			}
			//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
			if (checkpause == true) {
				music1.pause();
				window.draw(pp);
				Send.setPosition(520, 220);
				window.draw(Send);
				if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 307 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 368)
				{
					window.draw(pr);
					Send.setPosition(520, 220);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						checkpause = false;
						music1.play();
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 397 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 457)
				{
					window.draw(pm);
					Send.setPosition(520, 220);
					window.draw(Send);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						music1.stop();
						musicend.stop();
						timerpausemenu.restart();
						checkpause = false;
						MENU = true;
						START = false;
						Rank = false;

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 486 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 546)
				{
					window.draw(pe);
					Send.setPosition(520, 220);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						window.close();
						break;
					}
				}
			}

			if (checkpause == false) {
				
				aww += 0.001;
				if (aww >= 20)
				{
					aww = 5;
				}
				MyHP -= 5+aww;
			}
			if (MyHP < 78000) {
				HP.setSize(sf::Vector2f(MyHP / 200.0f, 30));
				if (MyHP < 0 || player.GetPosition().y >= 600) {
					MyHP = 0;
					endGame = true;
					for (; soundcount < 1; soundcount++) {
						sound_over = true;
					}
				}
			}
			if (endGame == true) {
				music1.stop();
				window.draw(ee);
				NewScore.setPosition(500, 355);
				window.draw(NewScore);
				
				//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;
				if (sf::Mouse::getPosition(window).x >= 400 &&
					sf::Mouse::getPosition(window).y >= 600 &&
					sf::Mouse::getPosition(window).x <= 680 &&
					sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						Soundch.play();
						cout << "Save score" << endl;

						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("database/keephighscore.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;
						musicend.stop();

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
						realscore = 0;
						aww = 0;
					}
				}
			}
			if (sound_over == true) {
				musicend.play();
			}
			sound_over = false;
			if (state == 3) {
				music1.stop();
				window.draw(mission);
				window.draw(NewScore);

				if (sf::Mouse::getPosition(window).x >= 400 &&
					sf::Mouse::getPosition(window).y >= 600 &&
					sf::Mouse::getPosition(window).x <= 680 &&
					sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Soundch.play();
						cout << "Save score" << endl;
						
						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("database/keephighscore.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;
						musicend.stop();

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
			}
	
			window.display();
		}
		
		countloop++;
		endGame = false;
		player.SetPosition(200, 520);
		player.ResetNumstar();

		for (int i = 0; i < alienVector.size(); i++) {
			alienVector.erase(alienVector.begin() + i);
		}
		alienVector.clear();

		for (int i = 0; i < alien1Vector.size(); i++) {
			alien1Vector.erase(alien1Vector.begin() + i);
		}
		alien1Vector.clear();

		for (int i = 0; i < fish1Vector.size(); i++) {
			fish1Vector.erase(fish1Vector.begin() + i);
		}
		fish1Vector.clear();

		for (int i = 0; i < fish2Vector.size(); i++) {
			fish2Vector.erase(fish2Vector.begin() + i);
		}
		fish2Vector.clear();

		

		for (int i = 0; i < starVector.size(); i++) {
			starVector.erase(starVector.begin() + i);
		}
		starVector.clear();

		for (int i = 0; i < BloodupVector.size(); i++) {
			BloodupVector.erase(BloodupVector.begin() + i);
		}
		BloodupVector.clear();

		for (int i = 0; i < BlooddownVector.size(); i++) {
			BlooddownVector.erase(BlooddownVector.begin() + i);
		}
		BlooddownVector.clear();

		for (int i = 0; i < X2Vector.size(); i++) {
			X2Vector.erase(X2Vector.begin() + i);
		}
		X2Vector.clear();
	}
	return 0;
}
