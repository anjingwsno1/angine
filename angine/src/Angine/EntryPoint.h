#pragma once

#ifdef AG_PLATFORM_WINDOWS

extern Angine::Application* Angine::CreateApplication();

int main(int argc,char** argv)
{
	printf("Angine engine");
	auto app = Angine::CreateApplication(); 
	app->Run();
	delete app;
} 
#endif