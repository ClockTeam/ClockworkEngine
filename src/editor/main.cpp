#include "../engine/3DEngine.h"


class TestGame : public Game
{
public:
	TestGame() {}
	~TestGame(){}

	virtual void Init(const Window& window);
	virtual void ProcessInput(const Input& input, float delta);
	virtual void Update(float delta);
	virtual void Render(RenderingEngine* renderingEngine);
protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}
};

void TestGame::Init(const Window& window)
{
	
	
}


void TestGame::ProcessInput(const Input& input, float delta)
{

}


void TestGame::Update(float detla)
{

}

void TestGame::Render(RenderingEngine* renderingEngine)
{
}


#include <iostream>

int main()
{

	TestGame game;
	Window window(1280, 720, "3D Game Engine");
	RenderingEngine renderer(window);

	CoreEngine engine(60, &window, &renderer, &game);
	engine.Start();

	return 0;
}
