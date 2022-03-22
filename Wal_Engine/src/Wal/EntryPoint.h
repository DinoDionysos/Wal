#pragma once

#ifdef WL_PLATFORM_WINDOWS

extern Wal::Application* Wal::CreateApplication();

// the entry point uses the function CreateApplication which is defined
// externaly in the respective application that wants to access the entry point
int main(int argc, char** argv)
{
	auto app = Wal::CreateApplication();
	app->Run();
	delete app;
}

#endif