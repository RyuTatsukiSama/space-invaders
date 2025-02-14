#pragma once

class Command
{
public:
	virtual ~Command() {};

	virtual void execute(const float dt) = 0;
};

class CombinedCommand : public Command
{
public:
	CombinedCommand(Command* cmd1, Command* cmd2)
	{
		cmd1_ = cmd1;
		cmd2_ = cmd2;
	}

	~CombinedCommand() {};

	void execute(const float dt)
	{
		cmd1_->execute(dt);
		cmd2_->execute(dt);
	}

private:
	Command* cmd1_;
	Command* cmd2_;

};
