#pragma once

#include "entity.h"
#include "coreEngine.h"
#include "profiling.h"

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	virtual void Init(const Window& window) {}
	virtual void ProcessInput(const Input& input, float delta);
	virtual void Update(float delta);
	virtual void Render(RenderingEngine* renderingEngine);
	
	inline double DisplayInputTime(double dividend) { return m_inputTimer.DisplayAndReset("Input Time: ", dividend); }
	inline double DisplayUpdateTime(double dividend) { return m_updateTimer.DisplayAndReset("Update Time: ", dividend); }
	
	inline void SetEngine(CoreEngine* engine) { m_root.SetEngine(engine); }
protected:
	void AddToScene(Entity* child) { m_root.AddChild(child); }
private:
	Game(Game& game) {}
	void operator=(Game& game) {}
	
	ProfileTimer m_updateTimer;
	ProfileTimer m_inputTimer;
	Entity       m_root;
};