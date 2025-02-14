#include "EnergyBoltPool.h"

EnergyBoltPool::EnergyBoltPool()
{
	models_[(int) Plasma::BLUE] = std::shared_ptr<PlasmaBoltModel>(new PlasmaBoltModel(Plasma::BLUE));
	models_[(int) Plasma::RED] = std::shared_ptr<PlasmaBoltModel>(new PlasmaBoltModel(Plasma::RED));
}

PlasmaBolt* EnergyBoltPool::createBolt(Plasma type)
{
	if (_recharging < 100.f)
		return nullptr;

	_recharging = 0.f;
	PlasmaBolt* bolt = new PlasmaBolt(models_[(int) type]);
	bolts_.push_back(bolt);
	return bolt;
}

void EnergyBoltPool::update(float dt)
{
	_recharging += dt / BOLT_RECHARGING_TIME * 100;
	for (auto bolt : bolts_)
	{
		bolt->move(0.f, bolt->getVelocity() * dt);
	}
}
