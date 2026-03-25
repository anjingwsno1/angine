#pragma once

#ifdef AG_PLATFORM_WINDOWS

extern Angine::Application* Angine::CreateApplication();

int main(int argc,char** argv)
{
	Angine::Log::Init();
	AG_CORE_WARN("Initialized Log!");
	int a = 5;
	AG_INFO("Hello! Var={0}",a);

	auto app = Angine::CreateApplication(); 
	app->Run();
	delete app;
} 
#endif