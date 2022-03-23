workspace "Wal_Engine" -- Name of the solution
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- buildcfg: Debug, Release
-- system = win, macos, linux
-- architecture= x64, ...
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wal_Engine" -- Name of the Project
	location "Wal_Engine" -- Name of the folder where the project is relative to premake5.lua
	kind "SharedLib"
	language "C++"

	-- prj.name = Wal_Engine
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"WL_PLATFORM_WINDOWS",
			"WL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Stonecold")
		}

	filter "configurations:Debug"
		defines "WL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WL_DIST"
		optimize "On"

project "Stonecold"
	location "Stonecold"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Wal_Engine/vendor/spdlog/include",
		"Wal_Engine/src"
	}

	links
	{
		"Wal_Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"WL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WL_DIST"
		optimize "On"
	
