#pragma once

#include "Core.h"

namespace Wal{

	class WAL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
}

