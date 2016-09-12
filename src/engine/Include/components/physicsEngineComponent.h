#pragma once

#include "../core/entityComponent.h"
#include "../physics/physicsEngine.h"

/** This class is temporary! */
class PhysicsEngineComponent : public EntityComponent
{
public:
	PhysicsEngineComponent(const PhysicsEngine& engine) :
		m_physicsEngine(engine) {}

	virtual void Update(float delta);

	inline const PhysicsEngine& GetPhysicsEngine() { return m_physicsEngine; }
private:
	PhysicsEngine m_physicsEngine;
};