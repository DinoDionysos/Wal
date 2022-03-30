#include "Application.h"

#include "Wal/Events/ApplicationEvent.h"
#include "Wal/Log.h"

namespace Wal {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	// dummy function
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			WL_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			WL_CLIENT_TRACE(e);
		}

		while (true);
	}
}