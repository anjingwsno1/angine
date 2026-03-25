workspace "Angine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Angine"
	location "Angine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	buildoptions { "/utf-8" }

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
		systemversion "10.0.26100.0"

		defines
		{
			"AG_PLATFORM_WINDOWS",
			"AG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	buildoptions { "/utf-8" }

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Angine/vendor/spdlog/include",
		"Angine/src"
	}

	links
	{
		"Angine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.26100.0"

		defines
		{
			"AG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AG_DIST"
		optimize "On"