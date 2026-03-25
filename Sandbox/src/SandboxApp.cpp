#include <Angine.h>

class Sandbox : public Angine::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Angine::Application* Angine::CreateApplication()
{
	return new Sandbox();
}
