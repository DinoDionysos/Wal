#include "wlpch.h"
#include "Application.h"

#include "Wal/Events/ApplicationEvent.h"
#include "Wal/Log.h"


#include <GLFW/glfw3.h>

namespace Wal {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	// dummy function
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}