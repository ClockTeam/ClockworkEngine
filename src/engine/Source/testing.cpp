#include "../include/testing.h"

#include "../include/physics/boundingSphere.h"
#include "../include/physics/aabb.h"
#include "../include/physics/plane.h"
#include "../include/physics/physicsObject.h"

#include <iostream>
#include <cassert>

void Testing::RunAllTests()
{
	BoundingSphere::Test();
	AABB::Test();
	Plane::Test();
	PhysicsObject::Test();
}


