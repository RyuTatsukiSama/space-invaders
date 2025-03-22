#include "GameState.h"
#include "ShipController.h"


GameState::GameState()
{
	background_image_.loadFromFile("images/background.jpg");
	background_.setTexture(background_image_);

	ship_ = new Spaceship(&bolt_pool_);

	input_handler_ = new ShipController(ship_);
	drawables_.push_back(ship_);
}

GameState::~GameState()
{
	delete ship_;
}

void GameState::update(float dt)
{
	bolt_pool_.update(dt);
}

void GameState::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);

	window.draw(background_);

	for (auto bolt : bolt_pool_.getBolts())
		window.draw(*bolt);

	for (auto drawable : drawables_)
		window.draw(*drawable);

	window.display();
}

void GameState::onEnter()
{

}

void GameState::onExit()
{

}
