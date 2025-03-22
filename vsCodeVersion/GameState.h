#pragma once

#include "GameFSM.h"
#include "Spaceship.h"

class GameState : public IState
{
public:
	GameState();
	~GameState();

	void update(const float dt) override;
	void render(sf::RenderWindow& window) override;

	void onEnter();
	void onExit();

private:
	std::vector<sf::Drawable*> drawables_;

	sf::Texture background_image_;
	sf::Sprite background_;

	Spaceship * ship_;
	EnergyBoltPool bolt_pool_;
};