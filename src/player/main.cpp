#include "../engine/3DEngine.h"
#include "../engine/testing.h"

#include "../engine/components/freeLook.h"
#include "../engine/components/freeMove.h"
#include "../engine/components/physicsEngineComponent.h"
#include "../engine/components/physicsObjectComponent.h"
#include "../engine/physics/boundingSphere.h"

class TestGame : public Game
{
public:
	TestGame() {}
	
	virtual void Init(const Window& window);
protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}
};

void TestGame::Init(const Window& window)
{
	Material defaultMaterial("defaultMaterial", Texture("white.png"), 0.0f, 0, 
			Texture("defaultTexture.png"), Texture("default_disp.png"), 0.03f, -0.5f);

	Material wood("wood", Texture("wood.tga"), 0.0f, 0,
		Texture("wood_normal.tga"), Texture("wood_disp.png"), 1.0f, -0.5f);

	Material tile("tile", Texture("tile.tga"), 0.0f, 0,
		Texture("tile_normal.tga"), Texture("tile_disp.png"), 100, 0.0f);
	
	AddToScene((new Entity(Vector3f(0, -1, 5), Quaternion(), 5.0f))
		->AddComponent(new MeshRenderer(Mesh("plane4.obj"), Material("tile"))));
		
	AddToScene((new Entity(Vector3f(7,0,7)))
		->AddComponent(new PointLight(Vector3f(0,1.5f,0), 1.0f, Attenuation(0,0,1))));
	
	AddToScene((new Entity(Vector3f(20,1,5), Quaternion(Vector3f(1,0,0), ToRadians(-60.0f)) * Quaternion(Vector3f(0,1,0), ToRadians(90.0f))))
		->AddComponent(new SpotLight(Vector3f(0, 1.5f,1), 1.0f, Attenuation(0,0,0.02f), ToRadians(91.1f), 7, 1.0f, 0.5f)));
	
	AddToScene((new Entity(Vector3f(), Quaternion(Vector3f(1,0,0), ToRadians(-45))))
		->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f, 10, 80.0f, 1.0f)));
	
	AddToScene((new Entity(Vector3f(30, 0.5f, 0), Quaternion(Vector3f(0,1,0), 180.0f), 1.0f))
		->AddComponent(new MeshRenderer(Mesh("cube.obj"), Material("wood")))
		->AddChild((new Entity(Vector3f(0, 0, 25)))
			->AddComponent(new MeshRenderer(Mesh("cube.obj"), Material("tile")))
			->AddChild((new Entity())
				->AddComponent(new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f)))
				->AddComponent(new FreeLook(window.GetCenter()))
				->AddComponent(new FreeMove(10.0f)))));
	
	AddToScene((new Entity(Vector3f(24,0.5f,5), Quaternion(Vector3f(0,1,0), ToRadians(30.0f))))
		->AddComponent(new MeshRenderer(Mesh("cube.obj"), Material("wood"))));
		
	AddToScene((new Entity(Vector3f(0,1,7), Quaternion(), 1.0f))
		->AddComponent(new MeshRenderer(Mesh("cube.obj"), Material("wood"))));


	//TODO: Temporary Physics Engine Code!
	PhysicsEngine physicsEngine;
	
	physicsEngine.AddObject(PhysicsObject(
			new BoundingSphere(Vector3f(0.0f, 1.5f, 0.0f), 1.0f),
		   	Vector3f(0.0f, 0.0f, 1.141f/2.0f)));

	physicsEngine.AddObject(PhysicsObject(
			new BoundingSphere(Vector3f(1.414f/2.0f * 7.0f, 1.5f, 1.414f/2.0f * 7.0f), 1.0f),
			Vector3f(-1.414f/2.0f, 0.0f, -1.414f/2.0f))); 


	PhysicsEngineComponent* physicsEngineComponent 
		= new PhysicsEngineComponent(physicsEngine);

	for(unsigned int i = 0; 
		i < physicsEngineComponent->GetPhysicsEngine().GetNumObjects(); 
		i++)
	{
		
		AddToScene((new Entity(Vector3f(0,5,0), Quaternion(), 
					1.0f))
			->AddComponent(new PhysicsObjectComponent(
					&physicsEngineComponent->GetPhysicsEngine().GetObject(i)))
			->AddComponent(new MeshRenderer(Mesh("sphere.obj"), Material("wood"))));
	}

	AddToScene((new Entity())
		->AddComponent(physicsEngineComponent));

	AddToScene((new Entity(Vector3f(), Quaternion(Vector3f(1,0,0), ToRadians(-45))))
		->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f, 10, 80.0f, 1.0f)));

	//AddToScene((new Entity())
	//			->AddComponent(new CameraComponent(Matrix4f().InitPerspective(
	//						ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f)))
	//			->AddComponent(new FreeLook(window.GetCenter()))
	//			->AddComponent(new FreeMove(10.0f)));

	//static const int CUBE_SIZE = 3;

	//AddToScene((new Entity())
	//	->AddComponent(new PointLight(Vector3f(1,1,1), 
	//			(CUBE_SIZE * CUBE_SIZE) * 2, Attenuation(0,0,1))));

	//for(int i = -CUBE_SIZE; i <= CUBE_SIZE; i++)
	//{
	//	for(int j = -CUBE_SIZE; j <= CUBE_SIZE; j++)
	//	{
	//		for(int k = -CUBE_SIZE; k <= CUBE_SIZE; k++)
	//		{
	//			if(i == -CUBE_SIZE || i == CUBE_SIZE ||
	//			   j == -CUBE_SIZE || j == CUBE_SIZE ||
	//			   k == -CUBE_SIZE || k == CUBE_SIZE)
	//			{
	//				if(i == 0 || j == 0 || k == 0)
	//				{
	//					AddToScene((new Entity(Vector3f(i * 2, j * 2, k * 2)))
	//						->AddComponent(new MeshRenderer(Mesh("sphere.obj"), 
	//								Material("wood"))));
	//				}
	//				else
	//				{
	//					AddToScene((new Entity(Vector3f(i * 2, j * 2, k * 2)))
	//						->AddComponent(new MeshRenderer(Mesh("cube.obj"), 
	//								Material("tile"))));
	//				}
	//		
	//			}
	//		}
	//	}
	//}


}

#include <iostream>

int main()
{
	Testing::RunAllTests();

	TestGame game;
	Window window(1280, 720, "3D Game Engine");
	RenderingEngine renderer(window);
	
	//window.SetFullScreen(true);
	
	CoreEngine engine(60, &window, &renderer, &game);
	engine.Start();
	
	//window.SetFullScreen(false);

//	Window window(800, 600, "My Window");
//	RenderingEngine engine(window);
//	
//	Material bricks2("bricks2", Texture("bricks2.jpg"), 1, 8, Texture("bricks2_normal.png"), Texture("bricks2_disp.jpg"), 0.04f, -1.0f);
//	GameObject root;
//	Transform cameraTransform;
//	Camera camera(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f), &cameraTransform);
//	
//	root.AddChild((new GameObject(Vector3f(0, 2, 0), Quaternion(Vector3f(0,1,0), 0.4f), 1.0f))
//		->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
//		->AddChild((new GameObject(Vector3f(0, 0, 25)))
//			->AddComponent(new MeshRenderer(Mesh("plane3.obj"), Material("bricks2")))
//			//->AddChild((new GameObject())
//				->AddComponent(new FreeLook(window.GetCenter()))
//				->AddComponent(new FreeMove())));
//	
//	while(!window.IsCloseRequested())
//	{
//		window.Update();
//		root.ProcessInputAll(window.GetInput(), 0.01f);
//		root.UpdateAll(0.01f);
//		engine.Render(root, camera);
//		window.SwapBuffers();
//	}
	
	return 0;
}
