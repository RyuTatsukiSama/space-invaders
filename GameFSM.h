#pragma once

#include <cassert>
#include <unordered_map>

#include "InputHandler.h"
#include "SFML/Graphics.hpp"

enum class State
{
    NONE = 0,
	GAME ,
	MENU,
    STATE_COUNT
};

class IState
{
public:
    virtual ~IState() { delete input_handler_; }

    virtual void handleInput(const float dt)
    { 
        Command* cmd = input_handler_->handleInput(); 
        cmd->execute(dt);
    }
    
    virtual void update(const float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    virtual void onEnter() = 0;
    virtual void onExit() = 0;

protected:
    InputHandler* input_handler_;
};

class GameFSM
{
public:
    GameFSM();
    ~GameFSM();

    void handleInput(const float dt)
    {
        if (current_state_)
            return current_state_->handleInput(dt);
    }

    void update(const float dt)
    {
        if (current_state_)
            current_state_->update(dt);
    }

    void render(sf::RenderWindow& window)
    {
        if (current_state_)
            current_state_->render(window);
    }

    void transition(State state)
    {
        if (current_state_)
            current_state_->onExit();
        current_state_ = states_[(int) state];

        assert(current_state_ != nullptr);
        current_state_->onEnter();
    }


private:
    IState* states_[(int) State::STATE_COUNT];
    IState* current_state_;

    void add(State name, IState* state)
    {
        states_[(int)name] = state;
    }
};
