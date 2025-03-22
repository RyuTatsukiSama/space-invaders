#pragma once

#include "PlasmaBolt.h"

constexpr float BOLT_RECHARGING_TIME = .2f;

class EnergyBoltPool
{
public:
	EnergyBoltPool();
	PlasmaBolt* createBolt(Plasma type);

	void update(float dt);
	std::vector<PlasmaBolt*> getBolts() const { return bolts_; }

private:
	float _recharging = 100.;
	std::vector<PlasmaBolt*> bolts_;
	std::shared_ptr<PlasmaBoltModel> models_[(int) Plasma::MODEL_COUNT];
};