workspace "moloch"
	architecture "x86"

	configurations {
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "moloch"
	location "moloch"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs { "dependencies/SFML/include" }
	libdirs { "dependencies/SFML/lib" }


	defines { "SFML_STATIC" }

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		symbols "On"
		optimize "On"

	-- SFML windows specific links
	filter { "system:windows", "configurations:DEBUG" }
		links {
			"sfml-graphics-s-d",
			"sfml-window-s-d",
			"sfml-system-s-d",
			"opengl32",
			"freetype",
			"winmm",
			"gdi32"
		}

	filter { "system:windows", "configurations:RELEASE" }
		links {
			"sfml-graphics-s",
			"sfml-window-s",
			"sfml-system-s",
			"opengl32",
			"freetype",
			"winmm",
			"gdi32"
		}

	filter "system:windows"
		systemversion "latest"
		-- runtime "Multi-threaded Debug DLL (/MDd)" -- not tested

	-- SFML linux specific links
	-- not tested
	filter "system:linux"
		links {
			"lsfml-graphics",
			"lsfml-window",
			"lsfml-system"
		}