#include <MiniEngine.hpp>

class SandBox : public MiniEngine::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

MiniEngine::Application* MiniEngine::CreateApplication()
{
	return new SandBox();
}