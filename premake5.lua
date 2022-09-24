include "Dependencies/premake/Custom/solutionitems.lua"

workspace "Computer2"
	architecture "x86_64"
	startproject "Computer2"

	configurations { "Debug", "Release", "Dist" }

	solutionitems {
		-- Visual Studio
		".editorconfig",

		-- Git
		".gitignore",
		".gitattributes",

		-- Scripts
		"Scripts/GenerateProjects.bat",

		-- Lua Scripts
		"premake5.lua",
		"Dependencies/Dependencies.lua",
		"Dependencies/premake/Custom/solutionitems.lua",
		"Dependencies/premake/Custom/usestdpreproc.lua",
		
		-- Misc
		"README.md"
	}

	flags {
		"MultiProcessorCompile"
	}

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Dependencies/premake/Custom/usestdpreproc.lua"
include "Dependencies/Dependencies.lua"

group "Dependencies/Computer2"
	include "Computer2/Dependencies/olc-2.17"
	include "Computer2/Dependencies/stb-2.27"
group ""

-- Add any projects here with 'include "__PROJECT_NAME__"'
include "Computer2"
