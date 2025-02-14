#ifndef COMMON__H
#define COMMON__H

#include <iostream>
#include <time.h>

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/OpenGL.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

sf::Sprite LoadSprite(const std::string _path , bool);
void BlitSprite(sf::Sprite _sprite, sf::Vector2f _pos, float _angle, sf::RenderWindow& _window);
void DrawPixel(sf::Image& _image, sf::Vector2i _pos, sf::Color _color);

#endif
