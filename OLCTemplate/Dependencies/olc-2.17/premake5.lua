project "olc"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	cdialect "C17"
	staticruntime "On"

	targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. OutputDir .. "/%{prj.name}")

	files {
		"include/olcPixelGameEngine.h",
		"src/olcPixelGameEngine.cpp",
	}

	includedirs {
		"include",

		-- Add any project source directories here.
		-- "%{wks.location}/__PROJECT_NAME__/src",

		-- Add any dependency includes here.
		"%{IncludeDir.stb}",
	}

	filter "system:windows"
		systemversion "latest"
		usestdpreproc "On"
		buildoptions "/wd5105" -- Until Microsoft updates Windows 10 to not have terrible code (aka never), this must be here to prevent a warning.
		defines "SYSTEM_WINDOWS"

	filter "configurations:Debug"
		runtime "Debug"
		optimize "Debug"
		symbols "Full"
		defines "CONFIG_DEBUG"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		symbols "On"
		defines "CONFIG_RELEASE"

	filter "configurations:Dist"
		runtime "Release"
		optimize "Full"
		symbols "Off"
		defines "CONFIG_DIST"
