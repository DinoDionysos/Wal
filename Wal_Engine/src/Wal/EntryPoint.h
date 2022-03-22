#pragma once

#ifdef WL_PLATFORM_WINDOWS

extern Wal::Application* Wal::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Wal::CreateApplication();
	app->Run();
	delete app;
}

#endif