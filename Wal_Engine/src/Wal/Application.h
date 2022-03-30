#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Wal/Events/ApplicationEvent.h"
#include "Window.h"

namespace Wal{

	class WAL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// has to be defined in Stonecold
	Application* CreateApplication();
}

