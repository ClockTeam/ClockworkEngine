#pragma once

#include "../core/entityComponent.h"
#include "../physics/physicsEngine.h"

/** This class is temporary! */
class PhysicsObjectComponent : public EntityComponent
{
public:
	PhysicsObjectComponent(const PhysicsObject* object) :
		m_physicsObject(object) {}

	virtual void Update(float delta);
private:
	const PhysicsObject* m_physicsObject;
};