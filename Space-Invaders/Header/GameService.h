#pragma once

class GameService
{
private:
	void Initialize();
	void Destroy();

public:
	GameService();
	~GameService();

	void Ignite();
	void Update();
	void Render();
	bool IsRunning();
};
