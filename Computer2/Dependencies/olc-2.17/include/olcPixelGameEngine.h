#pragma once

#pragma region license_and_help
/*



	A HEAVILY modified version of the...



	olcPixelGameEngine.h

	+-------------------------------------------------------------+
	|           OneLoneCoder Pixel Game Engine v2.17              |
	|  "What do you need? Pixels... Lots of Pixels..." - javidx9  |
	+-------------------------------------------------------------+

	What is this?
	~~~~~~~~~~~~~
	_OLC PixelGameEngine is a single file, cross platform graphics and userinput
	framework used for games, visualisations, algorithm exploration and learning.
	It was developed by YouTuber "javidx9" as an assistive tool for many of his
	videos. The goal of this project is to provide high speed graphics with
	minimal project setup complexity, to encourage new programmers, younger people,
	and anyone else that wants to make fun things.

	However, _OLC PixelGameEngine is not a toy! It is a powerful and fast utility
	capable of delivering high resolution, high speed, high quality applications
	which behave the same way regardless of the operating system or platform.

	This file provides the core utility set of the _OLC PixelGameEngine, including
	window creation, keyboard/mouse input, main game thread, timing, pixel drawing
	routines, image/sprite loading and drawing routines, and a bunch of utility
	types to make rapid development of games/visualisations possible.


	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018 - 2022 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without modification,
	are permitted provided that the following conditions are met:

	1. Redistributions or derivations of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce the above
	copyright notice. This list of conditions and the following	disclaimer must be
	reproduced in the documentation and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its contributors may
	be used to endorse or promote products derived from this software without specific
	prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS	"AS IS" AND ANY
	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
	OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
	SHALL THE COPYRIGHT	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
	INCIDENTAL,	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
	TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
	BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	SUCH DAMAGE.

	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
				https://www.youtube.com/javidx9extra
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Homepage:	https://www.onelonecoder.com
	Patreon:	https://www.patreon.com/javidx9
	Community:  https://community.onelonecoder.com



	Compiling in Linux
	~~~~~~~~~~~~~~~~~~
	You will need a modern C++ compiler, so update yours!
	To compile use the command:

	g++ -o YourProgName YourSource.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

	On some Linux configurations, the frame rate is locked to the refresh
	rate of the monitor. This engine tries to unlock it but may not be
	able to, in which case try launching your program like this:

	vblank_mode=0 ./YourProgName



	Compiling in Code::Blocks on Windows
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Well I wont judge you, but make sure your Code::Blocks installation
	is really up to date - you may even consider updating your C++ toolchain
	to use MinGW32-W64.

	Guide for installing recent GCC for Windows:
	https://www.msys2.org/
	Guide for configuring code::blocks:
	https://solarianprogrammer.com/2019/11/05/install-gcc-windows/
	https://solarianprogrammer.com/2019/11/16/install-codeblocks-gcc-windows-build-c-cpp-fortran-programs/

	Add these libraries to "Linker Options":
	user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs

	Set these compiler options: -std=c++17



	Compiling on Mac - EXPERIMENTAL! PROBABLY HAS BUGS
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Yes yes, people use Macs for C++ programming! Who knew? Anyway, enough
	arguing, thanks to Mumflr the PGE is now supported on Mac. Now I know nothing
	about Mac, so if you need support, I suggest checking out the instructions
	here: https://github.com/MumflrFumperdink/olcPGEMac

	clang++ -arch x86_64 -std=c++17 -mmacosx-version-min=10.15 -Wall -framework OpenGL 
		-framework GLUT -framework Carbon -lpng YourSource.cpp -o YourProgName



	Compiling with Emscripten (New & Experimental)
	~~~~~~~~~~~~~~~~~~~~~~~~~
	Emscripten compiler will turn your awesome C++ PixelGameEngine project into WASM!
	This means you can run your application in teh browser, great for distributing
	and submission in to jams and things! It's a bit new at the moment.

	em++ -std=c++17 -O2 -s ALLOW_MEMORY_GROWTH=1 -s MAX_WEBGL_VERSION=2 -s MIN_WEBGL_VERSION=2 -s USE_LIBPNG=1 ./YourSource.cpp -o pge.html



	Using stb_image.h
	~~~~~~~~~~~~~~~~~
	The PGE will load png images by default (with help from libpng on non-windows systems).
	However, the excellent "stb_image.h" can be used instead, supporting a variety of
	image formats, and has no library dependence - something we like at OLC studios ;)
	To use stb_image.h, make sure it's in your code base, and simply:

	#define OLC_IMAGE_STB

	Before including the olcPixelGameEngine.h header file. stb_image.h works on many systems
	and can be downloaded here: https://github.com/nothings/stb/blob/master/stb_image.h



	Multiple cpp file projects?
	~~~~~~~~~~~~~~~~~~~~~~~~~~~
	As a single header solution, the OLC_PGE_APPLICATION definition is used to
	insert the engine implementation at a project location of your choosing.
	The simplest way to setup multifile projects is to create a file called
	"olcPixelGameEngine.cpp" which includes the following:

	#define OLC_PGE_APPLICATION
	#include "olcPixelGameEngine.h"

	That's all it should include. You can also include PGEX includes and 
	defines in here too. With this in place, you dont need to 
	#define OLC_PGE_APPLICATION anywhere, and can simply include this 
	header file as an when you need to.



	Ports
	~~~~~
	_OLC PixelGameEngine has been ported and tested with varying degrees of
	success to: WinXP, Win7, Win8, Win10, Various Linux, Raspberry Pi,
	Chromebook, Playstation Portable (PSP) and Nintendo Switch. If you are
	interested in the details of these ports, come and visit the Discord!



	Thanks
	~~~~~~
	I'd like to extend thanks to Ian McKay, Bispoo, Eremiell, slavka, Kwizatz77, gurkanctn, Phantim,
	IProgramInCPP, JackOJC, KrossX, Huhlig, Dragoneye, Appa, JustinRichardsMusic, SliceNDice, 
	dandistine,	Ralakus, Gorbit99, raoul, joshinils, benedani, Moros1138, Alexio, SaladinAkara 
	& MagetzUb for advice, ideas and testing, and I'd like to extend my appreciation to the
	250K YouTube followers,	80+ Patreons, 4.8K Twitch followers and 10K Discord server members 
	who give me	the motivation to keep going with all this :D

	Significant Contributors: @Moros1138, @SaladinAkara, @MaGetzUb, @slavka,
							  @Dragoneye, @Gorbit99, @dandistine & @Mumflr

	Special thanks to those who bring gifts!
	GnarGnarHead.......Domina
	Gorbit99...........Bastion, Ori & The Blind Forest, Terraria, Spelunky 2, Skully
	Marti Morta........Gris
	Danicron...........Terraria
	SaladinAkara.......Aseprite, Inside, Quern: Undying Thoughts, Outer Wilds
	AlterEgo...........Final Fantasy XII - The Zodiac Age
	SlicEnDicE.........Noita, Inside
	TGD................Voucher Gift

	Special thanks to my Patreons too - I wont name you on here, but I've
	certainly enjoyed my tea and flapjacks :D



	Author
	~~~~~~
	David Barr, aka javidx9, ©OneLoneCoder 2018, 2019, 2020, 2021, 2022
*/
#pragma endregion

#pragma region version_history
/*
	2.01: Made renderer and platform static for multifile projects
	2.02: Added Decal destructor, optimised Pixel constructor
	2.03: Added FreeBSD flags, Added DrawStringDecal()
	2.04: Windows Full-Screen bug fixed
	2.05: +DrawPartialWarpedDecal() - draws a warped decal from a subset image
		  +DrawPartialRotatedDecal() - draws a rotated decal from a subset image
	2.06: +GetTextSize() - returns area occupied by multiline string
		  +GetWindowSize() - returns actual window size
		  +GetElapsedTime() - returns last calculated fElapsedTime
		  +GetWindowMouse() - returns actual mouse location in window
		  +DrawExplicitDecal() - bow-chikka-bow-bow
		  +DrawPartialDecal(pos, size) - draws a partial decal to specified area
		  +FillRectDecal() - draws a flat shaded rectangle as a decal
		  +GradientFillRectDecal() - draws a rectangle, with unique colour corners
		  +Modified DrawCircle() & FillCircle() - Thanks IanM-Matrix1 (#PR121)
		  +Gone someway to appeasing pedants
	2.07: +GetPixelSize() - returns user specified pixel size
		  +GetScreenPixelSize() - returns actual size in monitor pixels
		  +Pixel Cohesion Mode (flag in Construct()) - disallows arbitrary window scaling
		  +Working VSYNC in Windows windowed application - now much smoother
		  +Added string conversion for _OLC vectors
		  +Added comparator operators for _OLC vectors
		  +Added DestroyWindow() on windows platforms for serial PGE launches
		  +Added GetMousePos() to stop TarriestPython whinging
	2.08: Fix SetScreenSize() aspect ratio pre-calculation
		  Fix DrawExplicitDecal() - stupid oversight with multiple decals
		  Disabled _OLC Sprite copy constructor
		  +_OLC Sprite Duplicate() - produces a new clone of the sprite
		  +_OLC Sprite Duplicate(pos, size) - produces a new sprite from the region defined
		  +Unary operators for vectors
		  +More pedant mollification - Thanks TheLandfill
		  +ImageLoader modules - user selectable image handling core, gdi+, libpng, stb_image
		  +Mac Support via GLUT - thanks Mumflr!
	2.09: Fix _OLC Renderable Image load error - Thanks MaGetzUb & Zij-IT for finding and moaning about it
		  Fix file rejection in image loaders when using resource packs
		  Tidied Compiler defines per platform - Thanks slavka
		  +Pedant fixes, const correctness in parts
		  +DecalModes - Normal, Additive, Multiplicative blend modes
		  +Pixel Operators & Lerping
		  +Filtered Decals - If you hate pixels, then erase this file
		  +DrawStringProp(), GetTextSizeProp(), DrawStringPropDecal() - Draws non-monospaced font
	2.10: Fix PixelLerp() - oops my bad, lerped the wrong way :P
		  Fix "Shader" support for strings - thanks Megarev for crying about it
		  Fix GetTextSizeProp() - Height was just plain wrong...
		  +vec2d operator overloads (element wise *=, /=)
		  +vec2d comparison operators... :| yup... hmmmm...
		  +vec2d ceil(), floor(), min(), max() functions - surprising how often I do it manually
		  +DrawExplicitDecal(... uint32_t elements) - complete control over convex polygons and lines
		  +DrawPolygonDecal() - to keep Bispoo happy, required significant rewrite of EVERYTHING, but hey ho
		  +Complete rewrite of decal renderer
		  +OpenGL 3.3 Renderer (also supports Raspberry Pi)
		  +PGEX Break-In Hooks - with a push from Dandistine
		  +Wireframe Decal Mode - For debug overlays
	2.11: Made PGEX hooks optional - (provide true to super constructor)
	2.12: Fix for MinGW compiler non-compliance :( - why is its sdk structure different?? why???
	2.13: +GetFontSprite() - allows access to font data	 
	2.14: Fix WIN32 Definition reshuffle
		  Fix DrawPartialDecal() - messed up dimension during renderer experiment, didnt remove junk code, thanks Alexio
		  Fix? Strange error regarding GDI+ Image Loader not knowing about COM, SDK change?
	2.15: Big Reformat
		  +WASM Platform (via Emscripten) - Big Thanks to OLC Community - See Platform for details		  
		  +Sample Mode for Decals
		  +Made olc_ConfigureSystem() accessible
		  +Added OLC_----_CUSTOM_EX for externalised platforms, renderers and image loaders
		  =Refactored _OLC Sprite pixel data store
		  -Deprecating LoadFromPGESprFile()
		  -Deprecating SaveToPGESprFile()
		  Fix Pixel -= operator (thanks Au Lit)
	2.16: FIX Emscripten JS formatting in VS IDE (thanks Moros)
		  +"Headless" Mode
		  +DrawLineDecal()
		  +Mouse Button Constants
		  +Move Constructor for _OLC Renderable
		  +Polar/Cartesian conversion for v2d_generic
		  +DrawRotatedStringDecal()/DrawRotatedStringPropDecal() (thanks Oso-Grande/Sopadeoso (PR #209))
		  =Using _OLC Renderable for layer surface
		  +Major Mac and GLUT Update (thanks Mumflr)
	2.17: +Clipping for DrawLine() functions
		  +Reintroduced sub-pixel decals
		  +Modified DrawPartialDecal() to quantise and correctly sample from tile atlasses
		  +_OLC Sprite::GetPixel() - Clamp Mode

		  
	!! Apple Platforms will not see these updates immediately - Sorry, I dont have a mac to test... !!
	!!   Volunteers willing to help appreciated, though PRs are manually integrated with credit     !!
*/
#pragma endregion

// O-----------------------------------------------------------------------------O
// | Example "Hello World" Program (main.cpp)                                    |
// O-----------------------------------------------------------------------------O
#pragma region hello_world_example
/*
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class Example : public _OLC PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, _OLC Pixel(rand() % 256, rand() % 256, rand() % 256));
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}

*/
#pragma endregion

#ifndef OLC_PGE_DECLARATIONS
#define OLC_PGE_DECLARATIONS

// O-----------------------------------------------------------------------------O
// | STANDARD INCLUDES                                                           |
// O-----------------------------------------------------------------------------O
#pragma region std_includes
#include <cmath>
#include <cstdint>
#include <string>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <fstream>
#include <map>
#include <functional>
#include <algorithm>
#include <array>
#include <cstring>
#pragma endregion

static inline constexpr uint32_t PGE_VER = 217;

// O-----------------------------------------------------------------------------O
// | COMPILER CONFIGURATION ODDITIES                                             |
// O-----------------------------------------------------------------------------O
#pragma region compiler_config
#define USE_EXPERIMENTAL_FS
#ifdef _WIN32
	#if _MSC_VER >= 1920 && _MSVC_LANG >= 201703L
		#undef USE_EXPERIMENTAL_FS
	#endif
#endif
#if defined(__linux__) || defined(__MINGW32__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__) || defined(__APPLE__)
	#if __cplusplus >= 201703L
		#undef USE_EXPERIMENTAL_FS
	#endif
#endif


#if defined(USE_EXPERIMENTAL_FS) || defined(FORCE_EXPERIMENTAL_FS)
	// C++14
	#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
	#include <experimental/filesystem>
	namespace _gfs = _STD experimental::filesystem::v1;
#else
	// C++17
	#include <filesystem>
	namespace _gfs = _STD filesystem;
#endif

#if defined(UNICODE) || defined(_UNICODE)
	#define olcT(s) L##s
#else
	#define olcT(s) s
#endif

#define UNUSED(...) static_cast<void>(__VA_ARGS__)

// O-----------------------------------------------------------------------------O
// | PLATFORM SELECTION CODE, Thanks slavka!                                      |
// O-----------------------------------------------------------------------------O

// Platform
#if !defined(OLC_PLATFORM_WINAPI) && !defined(OLC_PLATFORM_X11) && !defined(OLC_PLATFORM_GLUT) && !defined(OLC_PLATFORM_EMSCRIPTEN)
	#ifndef OLC_PLATFORM_CUSTOM_EX
		#ifdef _WIN32
			#define OLC_PLATFORM_WINAPI
		#endif
		#if defined(__linux__) || defined(__FreeBSD__)
			#define OLC_PLATFORM_X11
		#endif
		#ifdef __APPLE__
			#define GL_SILENCE_DEPRECATION
			#define OLC_PLATFORM_GLUT
		#endif
		#ifdef __EMSCRIPTEN__
			#define OLC_PLATFORM_EMSCRIPTEN
		#endif
	#endif
#endif

// Start Situation
#if defined(OLC_PLATFORM_GLUT) || defined(OLC_PLATFORM_EMSCRIPTEN)
	#define PGE_USE_CUSTOM_START
#endif

// Renderer
#if !defined(OLC_GFX_OPENGL10) && !defined(OLC_GFX_OPENGL33) && !defined(OLC_GFX_DIRECTX10)
	#ifndef OLC_GFX_CUSTOM_EX
		#ifdef OLC_PLATFORM_EMSCRIPTEN
			#define OLC_GFX_OPENGL33
		#else
			#define OLC_GFX_OPENGL10
		#endif
	#endif
#endif

// Image loader
#if !defined(OLC_IMAGE_STB) && !defined(OLC_IMAGE_GDI) && !defined(OLC_IMAGE_LIBPNG)
	#ifndef OLC_IMAGE_CUSTOM_EX
		#ifdef _WIN32
			#define	OLC_IMAGE_GDI
		#endif
		#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
			#define	OLC_IMAGE_LIBPNG
		#endif
	#endif
#endif


// O-----------------------------------------------------------------------------O
// | PLATFORM-SPECIFIC DEPENDENCIES                                               |
// O-----------------------------------------------------------------------------O
#ifndef OLC_PGE_HEADLESS
#ifdef OLC_PLATFORM_WINAPI
	// Thanks Cornchipss
	#define _WINSOCKAPI_
		#ifndef VC_EXTRALEAN
			#define VC_EXTRALEAN
		#endif
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	// In Code::Blocks
	#ifndef _WIN32_WINNT
		#ifdef HAVE_MSMF
			#define _WIN32_WINNT 0x0600 // Windows Vista
		#else
			#define _WIN32_WINNT 0x0500 // Windows 2000
		#endif
	#endif

	#include <Windows.h>
	#undef _WINSOCKAPI_
#endif

#ifdef OLC_PLATFORM_X11
	namespace X11
	{
		#include <X11/X.h>
		#include <X11/Xlib.h>
	}
#endif

#ifdef OLC_PLATFORM_GLUT
	#ifdef __linux__
		#include <GL/glut.h>
		#include <GL/freeglut_ext.h>
	#endif
	#ifdef __APPLE__
		#include <GLUT/glut.h>
	#include <objc/message.h>
	#include <objc/NSObjCRuntime.h>
	#endif
#endif
#endif
#pragma endregion

// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine INTERFACE DECLARATION                                    |
// O-----------------------------------------------------------------------------O
#pragma region pge_declaration
#define _OLC ::olc:: 
namespace olc
{
	class PixelGameEngine;
	class Sprite;

	// Pixel Game Engine Advanced Configuration
	constexpr uint8_t  nMouseButtons = 5;
	constexpr uint8_t  nDefaultAlpha = 0xFF;
	constexpr uint32_t nDefaultPixel = _OLC nDefaultAlpha << 24;
	constexpr uint8_t  nTabSizeInSpaces = 4;
	enum class rcode
	{
		FAIL,
		OK,
		NO_FILE
	};

	// O-----------------------------------------------------------------------------O
	// | olc::Pixel - Represents a 32-Bit RGBA colour                                |
	// O-----------------------------------------------------------------------------O
	struct Pixel
	{
		union
		{
			uint32_t n = _OLC nDefaultPixel;
			struct
			{
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			};
		};

		constexpr Pixel() noexcept = default;
		// This definition has to be here for the color constants, because they are used in the definitions as default values.
		constexpr Pixel(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha = _OLC nDefaultAlpha) noexcept
			: n(red | (green << 8) | (blue << 16) | (alpha << 24)) {} // Thanks jarekpelczar
		constexpr Pixel(const uint32_t p) noexcept;
		constexpr _OLC Pixel& operator= (const _OLC Pixel&) noexcept = default;
		constexpr bool operator==(const _OLC Pixel& p) const noexcept;
		constexpr bool operator!=(const _OLC Pixel& p) const noexcept;
		constexpr _OLC Pixel  operator+ (const _OLC Pixel p) const noexcept;
		constexpr _OLC Pixel& operator+=(const _OLC Pixel p) noexcept;
		constexpr _OLC Pixel  operator- (const _OLC Pixel p) const noexcept;
		constexpr _OLC Pixel& operator-=(const _OLC Pixel p) noexcept;
		constexpr _OLC Pixel  operator* (const float i) const noexcept;
		constexpr _OLC Pixel& operator*=(const float i) noexcept;
		constexpr _OLC Pixel  operator/ (const float i) const noexcept;
		constexpr _OLC Pixel& operator/=(const float i) noexcept;
		constexpr _OLC Pixel  inv() const noexcept;
	};

	constexpr _OLC Pixel PixelF(const float red, const float green, const float blue, const float alpha = 1.0f) noexcept;
	constexpr _OLC Pixel PixelLerp(const _OLC Pixel p1, const _OLC Pixel p2, const float t) noexcept;

	enum class PixelMode
	{
		NORMAL,
		MASK,
		ALPHA,
		CUSTOM
	};

	// O-----------------------------------------------------------------------------O
	// | USEFUL CONSTANTS                                                            |
	// O-----------------------------------------------------------------------------O
	namespace Color
	{
		static constexpr _OLC Pixel
			GREY(192, 192, 192), DARK_GREY(128, 128, 128), VERY_DARK_GREY(64, 64, 64),
			RED(255, 0, 0), DARK_RED(128, 0, 0), VERY_DARK_RED(64, 0, 0),
			ORANGE(255, 102, 0), DARK_ORANGE(194, 78, 0), VERY_DARK_ORANGE(133, 53, 0),
			YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0), VERY_DARK_YELLOW(64, 64, 0),
			GREEN(0, 255, 0), DARK_GREEN(0, 128, 0), VERY_DARK_GREEN(0, 64, 0),
			CYAN(0, 255, 255), DARK_CYAN(0, 128, 128), VERY_DARK_CYAN(0, 64, 64),
			BLUE(0, 0, 255), DARK_BLUE(0, 0, 128), VERY_DARK_BLUE(0, 0, 64),
			MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128), VERY_DARK_MAGENTA(64, 0, 64),
			WHITE(255, 255, 255), BLACK(0, 0, 0), BLANK(0, 0, 0, 0);
	}

	// Thanks to scripticuk and others for updating the key maps
	// NOTE: The GLUT platform will need updating, open to contributions ;)
	using Key = uint8_t;
	enum : _OLC Key
	{
		Key_NONE,
		Key_A, Key_B, Key_C, Key_D, Key_E, Key_F, Key_G, Key_H, Key_I, Key_J, Key_K, Key_L, Key_M, Key_N, Key_O, Key_P, Key_Q, Key_R, Key_S, Key_T, Key_U, Key_V, Key_W, Key_X, Key_Y, Key_Z,
		Key_K0, Key_K1, Key_K2, Key_K3, Key_K4, Key_K5, Key_K6, Key_K7, Key_K8, Key_K9,
		Key_F1, Key_F2, Key_F3, Key_F4, Key_F5, Key_F6, Key_F7, Key_F8, Key_F9, Key_F10, Key_F11, Key_F12,
		Key_UP, Key_DOWN, Key_LEFT, Key_RIGHT,
		Key_SPACE, Key_TAB, Key_SHIFT, Key_CTRL, Key_INS, Key_DEL, Key_HOME, Key_END, Key_PGUP, Key_PGDN,
		Key_BACK, Key_ESCAPE, Key_RETURN, Key_ENTER, Key_PAUSE, Key_SCROLL,
		Key_NP0, Key_NP1, Key_NP2, Key_NP3, Key_NP4, Key_NP5, Key_NP6, Key_NP7, Key_NP8, Key_NP9,
		Key_NP_MUL, Key_NP_DIV, Key_NP_ADD, Key_NP_SUB, Key_NP_DECIMAL, Key_PERIOD,
		Key_EQUALS, Key_COMMA, Key_MINUS,
		Key_OEM_1, Key_OEM_2, Key_OEM_3, Key_OEM_4, Key_OEM_5, Key_OEM_6, Key_OEM_7, Key_OEM_8,
		Key_CAPS_LOCK,

		Key_ENUM_END
	};

	using MouseButton = uint32_t;
	enum : _OLC MouseButton
	{
		MouseButton_LEFT,
		MouseButton_RIGHT,
		MouseButton_MIDDLE,
		MouseButton_BACK,
		MouseButton_FRONT
	};

	// O-----------------------------------------------------------------------------O
	// | olc::HWButton - Represents the state of a hardware button (mouse/key/joy)   |
	// O-----------------------------------------------------------------------------O
	struct HWButton
	{
		bool bPressed  : 1 = false; // Set once during the frame the event occurs
		bool bReleased : 1 = false; // Set once during the frame the event occurs
		bool bHeld     : 1 = false; // Set true for all frames between pressed (inclusive) and released (exclusive) events
	};

	// O-----------------------------------------------------------------------------O
	// | olc::vX2d - A generic 2D vector type                                        |
	// O-----------------------------------------------------------------------------O
#ifndef OLC_IGNORE_VEC2D
	
#pragma region v2d_declarations
	template<typename T>
	struct v2d_generic
	{
		T x = 0;
		T y = 0;

		constexpr v2d_generic() noexcept = default;

		// All this template buisness is so the compiler will use the copy constructor if T2 is a v2d_generic.
	private:
		template<typename T2> struct is_v2d : _STD false_type {};
		template<typename T2> struct is_v2d<_OLC v2d_generic<T2>> : _STD true_type {};
		template<typename T2> static constexpr bool is_v2d_v = _OLC v2d_generic<T>::is_v2d<_STD remove_cvref_t<T2>>::value;
	public:
		// I can't get the definition to not be inline here, otherwise it would be.
		template<typename T2, _STD enable_if_t<!(_OLC v2d_generic<T>::is_v2d_v<T2>), int> = 0>
		constexpr v2d_generic(const T2 n) noexcept : x(static_cast<T>(n)), y(static_cast<T>(n)) {}

		template<typename T2> constexpr v2d_generic(const T2 x, const T2 y) noexcept;
		template<typename T2> constexpr v2d_generic(const _OLC v2d_generic<T>& v) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator=(const _OLC v2d_generic<T2>& v) noexcept;
		template<typename T2> constexpr operator _OLC v2d_generic<T2>() const noexcept;

		constexpr T mag2() const noexcept;
		T mag() const noexcept;
		_OLC v2d_generic<T> norm() const noexcept;
		constexpr _OLC v2d_generic<T> perp() const noexcept;
		_OLC v2d_generic<T> floor() const noexcept;
		_OLC v2d_generic<T> ceil() const noexcept;
		constexpr _OLC v2d_generic<T> max(const _OLC v2d_generic<T>& v) const noexcept;
		constexpr _OLC v2d_generic<T> min(const _OLC v2d_generic<T>& v) const noexcept;
		_OLC v2d_generic<T> cart() const noexcept;
		_OLC v2d_generic<T> polar() const noexcept;
		constexpr T dot(const _OLC v2d_generic<T>& rhs) const noexcept;
		constexpr T cross(const _OLC v2d_generic<T>& rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator+ (const _OLC v2d_generic<T2>& rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator+=(const _OLC v2d_generic<T2>& rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator- (const _OLC v2d_generic<T2>& rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator-=(const _OLC v2d_generic<T2>& rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator* (const _OLC v2d_generic<T2>& rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator*=(const _OLC v2d_generic<T2>& rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator/ (const _OLC v2d_generic<T2>& rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator/=(const _OLC v2d_generic<T2>& rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator+ (const T2 rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator+=(const T2 rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator- (const T2 rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator-=(const T2 rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator* (const T2 rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator*=(const T2 rhs) noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>  operator/ (const T2 rhs) const noexcept;
		template<typename T2> constexpr _OLC v2d_generic<T>& operator/=(const T2 rhs) noexcept;
		constexpr _OLC v2d_generic<T> operator+() const noexcept;
		constexpr _OLC v2d_generic<T> operator-() const noexcept;
		constexpr bool operator==(const _OLC v2d_generic<T>& rhs) const noexcept;
		constexpr bool operator!=(const _OLC v2d_generic<T>& rhs) const noexcept;
		explicit constexpr operator bool() const noexcept;
		_NODISCARD _STD string str() const;

		// To stop dandistine from crying...
		template<typename T2> constexpr bool operator<(const _OLC v2d_generic<T2>& rhs) const noexcept;
		template<typename T2> constexpr bool operator>(const _OLC v2d_generic<T2>& rhs) const noexcept;
	};

	template<typename T> _STD ostream& operator<<(_STD ostream& os, const _OLC v2d_generic<T>& rhs);

	// Note: joshinils has some good suggestions here, but they are complicated to implement at this moment, 
	// however they will appear in a future version of PGE
	template<typename T1, typename T2> constexpr _OLC v2d_generic<T2> operator*(const T2 lhs, const _OLC v2d_generic<T1>& rhs) noexcept;
	template<typename T1, typename T2> constexpr _OLC v2d_generic<T2> operator/(const T2 lhs, const _OLC v2d_generic<T1>& rhs) noexcept;
#pragma endregion

#pragma region v2d_definitions
#pragma warning(push)
#pragma warning(disable: 4244)
	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>::v2d_generic(const T2 x, const T2 y) noexcept
		: x(static_cast<T>(x)), y(static_cast<T>(y)) {}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>::v2d_generic(const _OLC v2d_generic<T>& v) noexcept
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& _OLC v2d_generic<T>::operator=(const _OLC v2d_generic<T2>& v) noexcept
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>::operator _OLC v2d_generic<T2>() const noexcept
	{
		return { x, y };
	}

	template<typename T>
	constexpr T (_OLC v2d_generic<T>::mag2)() const noexcept
	{
		return dot(*this);
	}

	template<typename T>
	T (_OLC v2d_generic<T>::mag)() const noexcept
	{
		return static_cast<T>(_STD sqrt(mag2()));
	}

	template<typename T>
	_OLC v2d_generic<T> (_OLC v2d_generic<T>::norm)() const noexcept
	{
		return +*this /= mag();
	}

	template<typename T>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::perp)() const noexcept
	{
		return { -y, x };
	}

	template<typename T>
	_OLC v2d_generic<T> (_OLC v2d_generic<T>::floor)() const noexcept
	{
		return { _STD floor(x), _STD floor(y) };
	}

	template<typename T>
	_OLC v2d_generic<T> (_OLC v2d_generic<T>::ceil)() const noexcept
	{
		return { _STD ceil(x), _STD ceil(y) };
	}

	template<typename T>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::max)(const _OLC v2d_generic<T>& v) const noexcept
	{
		return _OLC v2d_generic<T>(_STD max(x, v.x), _STD max(y, v.y));
	}

	template<typename T>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::min)(const _OLC v2d_generic<T>& v) const noexcept
	{
		return _OLC v2d_generic<T>(_STD min(x, v.x), _STD min(y, v.y));
	}

	template<typename T>
	_OLC v2d_generic<T> (_OLC v2d_generic<T>::cart)() const noexcept
	{
		return { _STD cos(y) * x, _STD sin(y) * x };
	}

	template<typename T>
	_OLC v2d_generic<T> (_OLC v2d_generic<T>::polar)() const noexcept
	{
		return { mag(), _STD atan2(y, x) };
	}

	template<typename T>
	constexpr T (_OLC v2d_generic<T>::dot)(const _OLC v2d_generic<T>& rhs) const noexcept
	{
		return x * rhs.x + y * rhs.y;
	}

	template<typename T>
	constexpr T (_OLC v2d_generic<T>::cross)(const _OLC v2d_generic<T>& rhs) const noexcept
	{
		return x * rhs.y - y * rhs.x;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::operator+)(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return +*this += rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator+=)(const _OLC v2d_generic<T2>& rhs) noexcept
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator-)(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return +*this -= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator-=)(const _OLC v2d_generic<T2>& rhs) noexcept
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator*)(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return +*this *= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator*=)(const _OLC v2d_generic<T2>& rhs) noexcept
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator/)(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return +*this /= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator/=)(const _OLC v2d_generic<T2>& rhs) noexcept
	{
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator+)(const T2 rhs) const noexcept
	{
		return +*this += rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator+=)(const T2 rhs) noexcept
	{
		x += rhs;
		y += rhs;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator-)(const T2 rhs) const noexcept
	{
		return +*this -= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator-=)(const T2 rhs) noexcept
	{
		x -= rhs;
		y -= rhs;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator*)(const T2 rhs) const noexcept
	{
		return +*this *= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator*=)(const T2 rhs) noexcept
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>(_OLC v2d_generic<T>::operator/)(const T2 rhs) const noexcept
	{
		return +*this /= rhs;
	}

	template<typename T>
	template<typename T2>
	constexpr _OLC v2d_generic<T>& (_OLC v2d_generic<T>::operator/=)(const T2 rhs) noexcept
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	template<typename T>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::operator+)() const noexcept
	{
		return { +x, +y };
	}

	template<typename T>
	constexpr _OLC v2d_generic<T> (_OLC v2d_generic<T>::operator-)() const noexcept
	{
		return { -x, -y };
	}

	template<typename T>
	constexpr bool _OLC v2d_generic<T>::operator==(const _OLC v2d_generic<T>& rhs) const noexcept
	{
		return x == rhs.x && y == rhs.y;
	}

	template<typename T>
	constexpr bool _OLC v2d_generic<T>::operator!=(const _OLC v2d_generic<T>& rhs) const noexcept
	{
		return x != rhs.x || y != rhs.y;
	}

	template<typename T>
	constexpr _OLC v2d_generic<T>::operator bool() const noexcept
	{
		return x != 0 && y != 0;
	}

	template<typename T>
	_NODISCARD _STD string (_OLC v2d_generic<T>::str)() const
	{
		return '(' + _STD to_string(x) + ", " + _STD to_string(y) + ')';
	}

	template<typename T>
	_STD ostream& operator<<(_STD ostream& os, const _OLC v2d_generic<T>& rhs)
	{
		return os << rhs.str();
	}

	template<typename T>
	template<typename T2>
	constexpr bool _OLC v2d_generic<T>::operator<(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return y < rhs.y || (y == rhs.y && x < rhs.x);
	}

	template<typename T>
	template<typename T2>
	constexpr bool _OLC v2d_generic<T>::operator>(const _OLC v2d_generic<T2>& rhs) const noexcept
	{
		return y > rhs.y || (y == rhs.y && x > rhs.x);
	}

	template<typename T1, typename T2>
	constexpr _OLC v2d_generic<T2> operator*(const T2 lhs, const _OLC v2d_generic<T1>& rhs) noexcept
	{
		return _OLC v2d_generic<T2>(lhs * rhs.x, lhs * rhs.y);
	}

	template<typename T1, typename T2>
	constexpr _OLC v2d_generic<T2> operator/(const T2 lhs, const _OLC v2d_generic<T1>& rhs) noexcept
	{
		return _OLC v2d_generic<T2>(lhs / rhs.x, lhs / rhs.y);
	}
#pragma warning(pop)
#pragma endregion

	using vi2d = _OLC v2d_generic<int32_t>;
	using vu2d = _OLC v2d_generic<uint32_t>;
	using vf2d = _OLC v2d_generic<float>;
	using vd2d = _OLC v2d_generic<double>;
#endif

	// O-----------------------------------------------------------------------------O
	// | olc::ResourcePack - A virtual scrambled filesystem to pack your assets into |
	// O-----------------------------------------------------------------------------O
	struct ResourceBuffer : public _STD streambuf
	{
		ResourceBuffer(_STD ifstream& ifs, const uint32_t offset, const uint32_t size);
		_STD vector<char> vMemory;
	};

	class ResourcePack : public _STD streambuf
	{
	public:
		~ResourcePack();
	public:
		bool AddFile(const _STD string& sFile);
		bool LoadPack(const _STD string& sFile, const _STD string& sKey);
		bool SavePack(const _STD string& sFile, const _STD string& sKey);
		_OLC ResourceBuffer GetFileBuffer(const _STD string& sFile);
		bool Loaded();
	private:
		_STD vector<char> scramble(const _STD vector<char>& data, const _STD string& key);
		_STD string makeposix(const _STD string& path);
	private:
		struct sResourceFile
		{
			uint32_t nSize = 0;
			uint32_t nOffset = 0;
		};
		_STD map<_STD string, sResourceFile> mapFiles;
		_STD ifstream baseFile;
	};

	class ImageLoader
	{
	public:
		virtual ~ImageLoader() = default;
	public:
		virtual _OLC rcode LoadImageResource(_OLC Sprite* spr, const _STD string& sImageFile, _OLC ResourcePack* pack) = 0;
		virtual _OLC rcode SaveImageResource(_OLC Sprite* spr, const _STD string& sImageFile) = 0;
	};

	// O-----------------------------------------------------------------------------O
	// | olc::Sprite - An image represented by a 2D array of olc::Pixel              |
	// O-----------------------------------------------------------------------------O
	class Sprite
	{
	public:
		constexpr Sprite() noexcept = default;
		Sprite(const _STD string& sImageFile, _OLC ResourcePack* pack = nullptr);
		Sprite(const int32_t width, const int32_t height);
		Sprite(const _OLC Sprite&) = delete;
		void Recreate(const int32_t width, const int32_t height, const _OLC Pixel* pixels);
		void Clear() noexcept;
	public:
		_OLC rcode LoadFromFile(const _STD string& sImageFile, _OLC ResourcePack* pack = nullptr);
		_OLC rcode WriteToFile(const _STD string& sImageFile);
	public:
		enum class Mode
		{
			NORMAL,
			PERIODIC,
			CLAMP
		};

		using Flip = uint8_t;
		enum : Flip
		{
			Flip_NONE  = 0,
			Flip_HORIZ = 1 << 0,
			Flip_VERT  = 1 << 1
		};
	public:
		int32_t GetWidth() const noexcept;
		int32_t GetHeight() const noexcept;
		_OLC vi2d GetSize() const noexcept;
		_STD vector<_OLC Pixel>& GetPixels() noexcept;
		const _STD vector<_OLC Pixel>& GetPixels() const noexcept;
		_OLC Pixel* GetData() noexcept;
		const _OLC Pixel* GetData() const noexcept;

		_OLC Pixel GetPixel(const int32_t x, const int32_t y) const;
		_OLC Pixel GetPixel(const _OLC vi2d& a) const;
		bool SetPixel(const int32_t x, const int32_t y, const _OLC Pixel p);
		bool SetPixel(const _OLC vi2d& a, const _OLC Pixel p);
		_OLC Pixel Sample(const float x, const float y) const;
		_OLC Pixel SampleBL(float u, float v) const;
		_OLC Sprite* Duplicate() const;
		_OLC Sprite* Duplicate(const _OLC vi2d& vPos, const _OLC vi2d& vSize) const;
	public:
		_OLC Sprite::Mode modeSample = Sprite::Mode::NORMAL;

		static _STD unique_ptr<_OLC ImageLoader> loader;
	private:
		int32_t width = 0;
		int32_t height = 0;
		_STD vector<_OLC Pixel> pColData;
	};

	// O-----------------------------------------------------------------------------O
	// | olc::Decal - A GPU resident storage of an olc::Sprite                       |
	// O-----------------------------------------------------------------------------O
	class Decal
	{
	public:
		Decal(_OLC Sprite* spr, bool filter = false, bool clamp = true);
		Decal(uint32_t nExistingTextureResource, _OLC Sprite* spr);
		virtual ~Decal();
	public:
		void Update();
		void UpdateSprite();
	public: // But dont touch // Then just make whatever uses this a friend????
		int32_t id = -1;
		_OLC Sprite* sprite = nullptr;
		_OLC vf2d vUVScale{ 1.0f };
	};

	enum class DecalMode
	{
		NORMAL,
		ADDITIVE,
		MULTIPLICATIVE,
		STENCIL,
		ILLUMINATE,
		WIREFRAME,
		MODEL3D,
	};

	enum class DecalStructure
	{
		LINE,
		FAN,
		STRIP,
		LIST
	};

	// O-----------------------------------------------------------------------------O
	// | olc::Renderable - Convenience class to keep a sprite and decal together     |
	// O-----------------------------------------------------------------------------O
	class Renderable
	{
	public:
		Renderable() = default;		
		Renderable(_OLC Renderable&& r) noexcept;
		Renderable(const _OLC Renderable&) = delete;
	public:
		_OLC rcode Load(const _STD string& sFile, _OLC ResourcePack* pack = nullptr, bool filter = false, bool clamp = true);
		void Create(uint32_t width, uint32_t height, bool filter = false, bool clamp = true);
	public:
		_OLC Decal* Decal() const;
		_OLC Sprite* Sprite() const;
	private:
		_STD unique_ptr<_OLC Sprite> pSprite = nullptr;
		_STD unique_ptr<_OLC Decal> pDecal = nullptr;
	};

	// O-----------------------------------------------------------------------------O
	// | Auxilliary components internal to engine                                    |
	// O-----------------------------------------------------------------------------O

	struct DecalInstance
	{
		_OLC Decal* decal = nullptr;
		_STD vector<_OLC vf2d> pos;
		_STD vector<_OLC vf2d> uv;
		_STD vector<float> w;
		_STD vector<_OLC Pixel> tint;
		_OLC DecalMode mode = _OLC DecalMode::NORMAL;
		_OLC DecalStructure structure = _OLC DecalStructure::FAN;
		uint32_t points = 0;
	};

	struct LayerDesc
	{
		_OLC vf2d vOffset{ 0, 0 };
		_OLC vf2d vScale{ 1, 1 };
		bool bShow = false;
		bool bUpdate = false;
		_OLC Renderable pDrawTarget;
		uint32_t nResID = 0;
		_STD vector<_OLC DecalInstance> vecDecalInstance;
		_OLC Pixel tint = _OLC Color::WHITE;
		_STD function<void()> funcHook = nullptr;
	};

	class Renderer
	{
	public:
		virtual ~Renderer() = default;
		virtual void       PrepareDevice() = 0;
		virtual _OLC rcode CreateDevice(_STD vector<void*> params, bool bFullScreen, bool bVSYNC) = 0;
		virtual _OLC rcode DestroyDevice() = 0;
		virtual void       DisplayFrame() = 0;
		virtual void       PrepareDrawing() = 0;
		virtual void	   SetDecalMode(_OLC DecalMode mode) = 0;
		virtual void       DrawLayerQuad(const _OLC vf2d& offset, const _OLC vf2d& scale, _OLC Pixel tint) = 0;
		virtual void       DrawDecal(const _OLC DecalInstance& decal) = 0;
		virtual uint32_t   CreateTexture(uint32_t width, uint32_t height, bool filtered = false, bool clamp = true) = 0;
		virtual void       UpdateTexture(uint32_t id, _OLC Sprite* spr) = 0;
		virtual void       ReadTexture(uint32_t id, _OLC Sprite* spr) = 0;
		virtual uint32_t   DeleteTexture(uint32_t id) = 0;
		virtual void       ApplyTexture(uint32_t id) = 0;
		virtual void       UpdateViewport(const _OLC vi2d& pos, const _OLC vi2d& size) = 0;
		virtual void       ClearBuffer(_OLC Pixel p, bool bDepth) = 0;
		static _OLC PixelGameEngine* ptrPGE;
	};

	class Platform
	{
	public:
		virtual ~Platform() = default;
		virtual _OLC rcode ApplicationStartUp() = 0;
		virtual _OLC rcode ApplicationCleanUp() = 0;
		virtual _OLC rcode ThreadStartUp() = 0;
		virtual _OLC rcode ThreadCleanUp() = 0;
		virtual _OLC rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC, const _OLC vi2d& vViewPos, const _OLC vi2d& vViewSize) = 0;
		virtual _OLC rcode CreateWindowPane(const _OLC vi2d& vWindowPos, _OLC vi2d& vWindowSize, bool bFullScreen) = 0;
		virtual _OLC rcode SetWindowTitle(const _STD string& s) = 0;
		virtual _OLC rcode StartSystemEventLoop() = 0;
		virtual _OLC rcode HandleSystemEvent() = 0;
		static _OLC PixelGameEngine* ptrPGE;
	};

	class PGEX;

	// The Static Twins (plus one) // Then its the static triplets....
	static _STD unique_ptr<_OLC Renderer> renderer;
	static _STD unique_ptr<_OLC Platform> platform;
	static _STD map<size_t, uint8_t> mapKeys;

	// O-----------------------------------------------------------------------------O
	// | olc::PixelGameEngine - The main BASE class for your application             |
	// O-----------------------------------------------------------------------------O
	class PixelGameEngine
	{
	public:
		PixelGameEngine();
		virtual ~PixelGameEngine() = default;
	public:
		_OLC rcode Construct(const _OLC vi2d& screenSize, const _OLC vi2d& pixelSize = { 1 }, const bool fullscreen = false, const bool vsync = true, const bool cohesion = false);
		_OLC rcode Construct(const int32_t screenWidth, const int32_t screenHeight, const int32_t pixelWidth = 1, const int32_t pixelHeight = 1, const bool fullscreen = false, const bool vsync = true, const bool cohesion = false);
		_OLC rcode Start();
	protected: // User Override Interfaces
		// Called once on application startup, use to load your resources
		virtual bool OnUserCreate();
		// Called every frame, and provides you with a time per frame value
		virtual bool OnUserUpdate(float fElapsedTime);
		// Called once on application termination, so you can be one clean coder
		virtual bool OnUserDestroy();
	public: // Hardware Interfaces
		// Returns true if window is currently in focus
		bool IsFocused() const;
		// Get the state of a specific keyboard button
		_OLC HWButton GetKey(const _OLC Key key) const;
		// Get the state of a specific mouse button
		_OLC HWButton GetMouseButton(const MouseButton button) const;
		// Get Mouse X coordinate in "pixel" space
		int32_t GetMouseX() const;
		// Get Mouse Y coordinate in "pixel" space
		int32_t GetMouseY() const;
		// Get Mouse Wheel Delta
		int32_t GetMouseWheel() const;
		// Get the mouse in window space
		const _OLC vi2d& GetWindowMouse() const;
		// Gets the mouse as a vector to keep Tarriest happy
		const _OLC vi2d& GetMousePos() const;
		// Returns the keymap.
		static const _STD map<size_t, uint8_t>& GetKeyMap();
	public: // Utility
		// Returns the width of the screen in "pixels"
		int32_t ScreenWidth() const;
		// Returns the height of the screen in "pixels"
		int32_t ScreenHeight() const;
		// Returns the width of the currently selected drawing target in "pixels"
		int32_t GetDrawTargetWidth() const;
		// Returns the height of the currently selected drawing target in "pixels"
		int32_t GetDrawTargetHeight() const;
		// Returns the currently active draw target
		_OLC Sprite* GetDrawTarget() const;
		// Resize the primary screen sprite
		void SetScreenSize(const int32_t width, const int32_t height);
		// Gets the current Frames Per Second
		uint32_t GetFPS() const;
		// Gets last update of elapsed time
		float GetElapsedTime() const;
		// Gets Actual Window size
		const _OLC vi2d& GetWindowSize() const;
		// Gets pixel scale
		const _OLC vi2d& GetPixelSize() const;
		// Gets actual pixel scale
		const _OLC vi2d& GetScreenPixelSize() const;
	public: // CONFIGURATION ROUTINES
		// Layer targeting functions

		// Specify which Sprite should be the target of drawing functions, use nullptr to specify the primary screen
		void SetDrawTarget(_OLC Sprite* target);
		void SetDrawTarget(const uint8_t layer);
		void EnableLayer(const uint8_t layer, const bool enabled);
		void SetLayerOffset(const uint8_t layer, const _OLC vf2d& offset);
		void SetLayerOffset(const uint8_t layer, const float x, const float y);
		void SetLayerScale(const uint8_t layer, const _OLC vf2d& scale);
		void SetLayerScale(const uint8_t layer, const float x, const float y);
		void SetLayerTint(const uint8_t layer, const _OLC Pixel tint);
		void SetLayerCustomRenderFunction(const uint8_t layer, const _STD function<void()>& f);

		_STD vector<_OLC LayerDesc>& GetLayers();
		uint32_t CreateLayer();

		// Change the pixel mode for different optimisations
		// _OLC PixelMode::NORMAL = No transparency
		// _OLC PixelMode::MASK   = Transparent if alpha is < 255
		// _OLC PixelMode::ALPHA  = Full transparency
		_OLC PixelMode GetPixelMode() const;
		void SetPixelMode(const _OLC PixelMode m);
		// Use a custom blend function
		void SetPixelMode(const _STD function<_OLC Pixel(int32_t x, int32_t y, _OLC Pixel pSource, _OLC Pixel pDest)>& pixelMode);
		// Change the blend factor from between 0.0f to 1.0f;
		void SetPixelBlend(const float fBlend);
	public: // DRAWING ROUTINES
		// Draws a single Pixel
		bool Draw(const _OLC vi2d& pos, const _OLC Pixel p = _OLC Color::WHITE);
		virtual bool Draw(const int32_t x, const int32_t y, const _OLC Pixel p = _OLC Color::WHITE);
		// Draws a line from (x1,y1) to (x2,y2)
		void DrawLine(const _OLC vi2d& pos1, const _OLC vi2d& pos2, const _OLC Pixel p = _OLC Color::WHITE, uint32_t pattern = 0xFFFFFFFF);
		void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const _OLC Pixel p = _OLC Color::WHITE, uint32_t pattern = 0xFFFFFFFF);
		// Draws a circle located at (x,y) with radius
		void DrawCircle(const _OLC vi2d& pos, const int32_t radius, const _OLC Pixel p = _OLC Color::WHITE, uint8_t mask = 0xFF);
		void DrawCircle(const int32_t x, const int32_t y, const int32_t radius, const _OLC Pixel p = _OLC Color::WHITE, uint8_t mask = 0xFF);
		// Fills a circle located at (x,y) with radius
		void FillCircle(const _OLC vi2d& pos, const int32_t radius, const _OLC Pixel p = _OLC Color::WHITE);
		void FillCircle(const int32_t x, const int32_t y, const int32_t radius, const _OLC Pixel p = _OLC Color::WHITE);
		// Draws a rectangle at (x,y) to (x+w,y+h)
		void DrawRect(const _OLC vi2d& pos, const _OLC vi2d& size, const _OLC Pixel p = _OLC Color::WHITE);
		void DrawRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h, const _OLC Pixel p = _OLC Color::WHITE);
		// Fills a rectangle at (x,y) to (x+w,y+h)
		void FillRect(const _OLC vi2d& pos, const _OLC vi2d& size, const _OLC Pixel p = _OLC Color::WHITE);
		void FillRect(int32_t x, int32_t y, const int32_t w, const int32_t h, const _OLC Pixel p = _OLC Color::WHITE);
		// Draws a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void DrawTriangle(const _OLC vi2d& pos1, const _OLC vi2d& pos2, const _OLC vi2d& pos3, const _OLC Pixel p = _OLC Color::WHITE);
		void DrawTriangle(const int32_t x1, const int32_t y1, const int32_t x2, const int32_t y2, const int32_t x3, const int32_t y3, const _OLC Pixel p = _OLC Color::WHITE);
		// Flat fills a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void FillTriangle(const _OLC vi2d& pos1, const _OLC vi2d& pos2, const _OLC vi2d& pos3, const _OLC Pixel p = _OLC Color::WHITE);
		void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const _OLC Pixel p = _OLC Color::WHITE);
		// Draws an entire sprite at location (x,y)
		void DrawSprite(const _OLC vi2d& pos, _OLC Sprite* sprite, const uint32_t scale = 1, const Sprite::Flip flip = _OLC Sprite::Flip_NONE);
		void DrawSprite(const int32_t x, const int32_t y, _OLC Sprite* sprite, const uint32_t scale = 1, const Sprite::Flip flip = _OLC Sprite::Flip_NONE);
		// Draws an area of a sprite at location (x,y), where the
		// selected area is (ox,oy) to (ox+w,oy+h)
		void DrawPartialSprite(const _OLC vi2d& pos, _OLC Sprite* sprite, const _OLC vi2d& sourcepos, const _OLC vi2d& size, const uint32_t scale = 1, const Sprite::Flip flip = _OLC Sprite::Flip_NONE);
		void DrawPartialSprite(const int32_t x, const int32_t y, _OLC Sprite* sprite, const int32_t ox, const int32_t oy, const int32_t w, const int32_t h, const uint32_t scale = 1, const Sprite::Flip flip = _OLC Sprite::Flip_NONE);
		// Draws a single line of text - traditional monospaced
		void DrawString(const _OLC vi2d& pos, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const uint32_t scale = 1);
		void DrawString(const int32_t x, const int32_t y, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const uint32_t scale = 1);
		_OLC vi2d GetTextSize(const _STD string& s);
		// Draws a single line of text - non-monospaced
		void DrawStringProp(const _OLC vi2d& pos, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const uint32_t scale = 1);
		void DrawStringProp(const int32_t x, const int32_t y, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const uint32_t scale = 1);
		_OLC vi2d GetTextSizeProp(const _STD string& s);

		// Decal Quad functions
		void SetDecalMode(const _OLC DecalMode mode);
		void SetDecalStructure(const _OLC DecalStructure& structure);
		// Draws a whole decal, with optional scale and tinting
		void DrawDecal(const _OLC vf2d& pos, _OLC Decal* decal, const _OLC vf2d& scale = { 1.0f }, const _OLC Pixel tint = _OLC Color::WHITE);
		// Draws a region of a decal, with optional scale and tinting
		void DrawPartialDecal(const _OLC vf2d& pos, _OLC Decal* decal, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC vf2d& scale = { 1.0f }, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawPartialDecal(const _OLC vf2d& pos, const _OLC vf2d& size, _OLC Decal* decal, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint = _OLC Color::WHITE);
		// Draws fully user controlled 4 vertices, pos(pixels), uv(pixels), colours
		void DrawExplicitDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC vf2d* uv, const _OLC Pixel* col, const uint32_t elements = 4);
		// Draws a decal with 4 arbitrary points, warping the texture to look "correct"
		void DrawWarpedDecal(_OLC Decal* decal, const _STD array<_OLC vf2d, 4>& pos, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawWarpedDecal(_OLC Decal* decal, const _OLC vf2d(&pos)[4], const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawWarpedDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC Pixel tint = _OLC Color::WHITE);
		// As above, but you can specify a region of a decal source sprite
		void DrawPartialWarpedDecal(_OLC Decal* decal, const _OLC vf2d(&pos)[4], const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawPartialWarpedDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawPartialWarpedDecal(_OLC Decal* decal, const _STD array<_OLC vf2d, 4>& pos, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint = _OLC Color::WHITE);
		// Draws a decal rotated to specified angle, wit point of rotation offset
		void DrawRotatedDecal(const _OLC vf2d& pos, _OLC Decal* decal, const float fAngle, const _OLC vf2d& center = { 0.0f }, const _OLC vf2d& scale = { 1.0f }, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawPartialRotatedDecal(const _OLC vf2d& pos, _OLC Decal* decal, const float fAngle, const _OLC vf2d& center, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC vf2d& scale = { 1.0f }, const _OLC Pixel tint = _OLC Color::WHITE);
		// Draws a multiline string as a decal, with tiniting and scaling
		void DrawStringDecal(const _OLC vf2d& pos, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const _OLC vf2d& scale = { 1.0f });
		void DrawStringPropDecal(const _OLC vf2d& pos, const _STD string& sText, const _OLC Pixel col = _OLC Color::WHITE, const _OLC vf2d& scale = { 1.0f });
		// Draws a single shaded filled rectangle as a decal
		void FillRectDecal(const _OLC vf2d& pos, const _OLC vf2d& size, const _OLC Pixel col = _OLC Color::WHITE);
		// Draws a corner shaded rectangle as a decal
		void GradientFillRectDecal(const _OLC vf2d& pos, const _OLC vf2d& size, const _OLC Pixel colTL, const _OLC Pixel colBL, const _OLC Pixel colBR, const _OLC Pixel colTR);
		// Draws an arbitrary convex textured polygon using GPU
		void DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<_OLC vf2d>& uv, const _OLC Pixel tint = _OLC Color::WHITE);
		void DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<_OLC vf2d>& uv, const _STD vector<_OLC Pixel>& tint);
		void DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<float>& depth, const _STD vector<_OLC vf2d>& uv, const _OLC Pixel tint = _OLC Color::WHITE);

		// Draws a line in Decal Space
		void DrawLineDecal(const _OLC vf2d& pos1, const _OLC vf2d& pos2, const _OLC Pixel p = _OLC Color::WHITE);
		void DrawRotatedStringDecal(const _OLC vf2d& pos, const _STD string& sText, const float fAngle, const _OLC vf2d& center = { 0.0f }, const _OLC Pixel col = _OLC Color::WHITE, const _OLC vf2d& scale = { 1.0f });
		void DrawRotatedStringPropDecal(const _OLC vf2d& pos, const _STD string& sText, const float fAngle, const _OLC vf2d& center = { 0.0f }, const _OLC Pixel col = _OLC Color::WHITE, const _OLC vf2d& scale = { 1.0f });
		
		// Clears entire draw target to Pixel
		void Clear(const _OLC Pixel p = _OLC Color::BLACK);
		// Clears the rendering back buffer
		void ClearBuffer(const _OLC Pixel p = _OLC Color::BLACK, bool bDepth = true);
		// Returns the font sprite
		_OLC Sprite* GetFontSprite();
		// Returns the font decal
		_OLC Decal* GetFontDecal();

		// Clip a line segment to visible area
		bool ClipLineToScreen(_OLC vi2d& in_p1, _OLC vi2d& in_p2);

		// Experimental Lightweight 3D Routines ================
#ifdef OLC_ENABLE_EXPERIMENTAL
		// Set Manual View Matrix
		void LW3D_View(const _STD array<float, 16>& m);
		// Set Manual World Matrix
		void LW3D_World(const _STD array<float, 16>& m);
		// Set Manual Projection Matrix
		void LW3D_Projection(const _STD array<float, 16>& m);
		
		// Draws a vector of vertices, interprted as individual triangles
		void LW3D_DrawTriangles(_OLC Decal* decal, const _STD vector<_STD array<float,3>>& pos, const _STD vector<_OLC vf2d>& tex, const _STD vector<_OLC Pixel>& col);

		void LW3D_ModelTranslate(const float x, const float y, const float z);
		
		// Camera convenience functions
		void LW3D_SetCameraAtTarget(const float fEyeX, const float fEyeY, const float fEyeZ,
			const float fTargetX, const float fTargetY, const float fTargetZ,
			const float fUpX = 0.0f, const float fUpY = 1.0f, const float fUpZ = 0.0f);
		void LW3D_SetCameraAlongDirection(const float fEyeX, const float fEyeY, const float fEyeZ,
			const float fDirX, const float fDirY, const float fDirZ,
			const float fUpX = 0.0f, const float fUpY = 1.0f, const float fUpZ = 0.0f);

		// 3D Rendering Flags
		void LW3D_EnableDepthTest(const bool bEnableDepth);
		void LW3D_EnableBackfaceCulling(const bool bEnableCull);
#endif
	public: // Branding
		_STD string sAppName;
	private: // Inner mysterious workings
		_OLC Sprite* pDrawTarget = nullptr;
		_OLC PixelMode nPixelMode = _OLC PixelMode::NORMAL;
		float fBlendFactor = 1.0f;
		_OLC vi2d vScreenSize{ 256, 240 };
		_OLC vf2d vInvScreenSize = 1.0f / vScreenSize;
		_OLC vi2d vPixelSize{ 4 };
		_OLC vi2d vScreenPixelSize{ 4 };
		_OLC vi2d vMousePos{ 0 };
		int32_t nMouseWheelDelta = 0;
		_OLC vi2d vMousePosCache{ 0 };
		_OLC vi2d vMouseWindowPos{ 0 };
		int32_t nMouseWheelDeltaCache = 0;
		_OLC vi2d vWindowSize{ 0 };
		_OLC vi2d vViewPos{ 0 };
		_OLC vi2d vViewSize{ 0 };
		bool bFullScreen = false;
		_OLC vf2d vPixel{ 1.0f };
		bool bHasInputFocus = false;
		bool bHasMouseFocus = false;
		bool bEnableVSYNC = false;
		float fFrameTimer = 1.0f;
		float fLastElapsed = 0.0f;
		int nFrameCount = 0;
		_OLC Sprite* fontSprite = nullptr;
		_OLC Decal* fontDecal = nullptr;
		_STD vector<_OLC LayerDesc> vLayers;
		uint8_t nTargetLayer = 0;
		uint32_t nLastFPS = 0;
		bool bPixelCohesion = false;
		_OLC DecalMode nDecalMode = _OLC DecalMode::NORMAL;
		_OLC DecalStructure nDecalStructure = _OLC DecalStructure::FAN;
		_STD function<_OLC Pixel(int32_t x, int32_t y, _OLC Pixel pSource, _OLC Pixel pDest)> funcPixelMode;
		_STD chrono::time_point<_STD chrono::system_clock> m_tp1, m_tp2;
		_STD vector<_OLC vi2d> vFontSpacing;

		// State of keyboard
		bool pKeyNewState[256]{ 0 };
		bool pKeyOldState[256]{ 0 };
		_OLC HWButton pKeyboardState[256]{ 0 };

		// State of mouse
		bool pMouseNewState[nMouseButtons]{ 0 };
		bool pMouseOldState[nMouseButtons]{ 0 };
		_OLC HWButton pMouseState[nMouseButtons]{ 0 };

		// The main engine thread
		void EngineThread();

		// If anything sets this flag to false, the engine "should" shut down gracefully
		static _STD atomic_bool bAtomActive;
	public:
		// "Break In" Functions
		void olc_UpdateMouse(int32_t x, int32_t y);
		void olc_UpdateMouseWheel(const int32_t delta);
		void olc_UpdateWindowSize(const int32_t x, const int32_t y);
		void olc_UpdateMouseState(const _OLC MouseButton button, const bool state);
		void olc_UpdateKeyState(const _OLC Key key, const bool state);
		void olc_UpdateMouseFocus(const bool state);
		void olc_UpdateKeyFocus(const bool state);
		void olc_UpdateViewport();
		void olc_ConstructFontSheet();
		void olc_PrepareEngine();
		void olc_CoreUpdate();
		void olc_Terminate();
		void olc_Reanimate();
		bool olc_IsRunning();

		// At the very end of this file, chooses which components to compile
		virtual void olc_ConfigureSystem();
	public: // PGEX Stuff
		friend class _OLC PGEX;
		void pgex_Register(_OLC PGEX* pgex);
	private:
		_STD vector<_OLC PGEX*> vExtensions;
	};

	// O-----------------------------------------------------------------------------O
	// | PGE EXTENSION BASE CLASS - Permits access to PGE functions from extension   |
	// O-----------------------------------------------------------------------------O
	class PGEX
	{
	public:
		PGEX(bool bHook = false);
		constexpr virtual ~PGEX() noexcept = default;
	protected:
		virtual void OnBeforeUserCreate();
		virtual void OnAfterUserCreate();
		virtual bool OnBeforeUserUpdate(float& fElapsedTime);
		virtual void OnAfterUserUpdate(float fElapsedTime);
	protected:
		friend class _OLC PixelGameEngine;
		static _OLC PixelGameEngine* pge;
	};
}
#pragma endregion

// O-----------------------------------------------------------------------------O
// | constexpr impl, aka what must be included with definitions, just put after  |
// O-----------------------------------------------------------------------------O
#pragma region pge_constexpr_impl
namespace olc
{
	// O-----------------------------------------------------------------------------O
	// | olc::Pixel IMPLEMENTATION                                                   |
	// O-----------------------------------------------------------------------------O
	constexpr Pixel::Pixel(const uint32_t p) noexcept
		: n(p) {}

	constexpr bool Pixel::operator==(const _OLC Pixel& p) const noexcept
	{
		return n == p.n;
	}

	constexpr bool Pixel::operator!=(const _OLC Pixel& p) const noexcept
	{
		return n != p.n;
	}

	constexpr _OLC Pixel Pixel::operator+(const _OLC Pixel p) const noexcept
	{
		uint8_t r = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->r) + static_cast<int32_t>(p.r), 0, 255));
		uint8_t g = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->g) + static_cast<int32_t>(p.g), 0, 255));
		uint8_t b = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->b) + static_cast<int32_t>(p.b), 0, 255));
		return _OLC Pixel(r, g, b, a);
	}

	constexpr _OLC Pixel& Pixel::operator+=(const _OLC Pixel p) noexcept
	{
		r = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(r) + static_cast<int32_t>(p.r), 0, 255));
		g = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(g) + static_cast<int32_t>(p.g), 0, 255));
		b = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(b) + static_cast<int32_t>(p.b), 0, 255));
		return *this;
	}

	constexpr _OLC Pixel Pixel::operator-(const _OLC Pixel p) const noexcept
	{
		uint8_t r = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->r) - static_cast<int32_t>(p.r), 0, 255));
		uint8_t g = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->g) - static_cast<int32_t>(p.g), 0, 255));
		uint8_t b = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(this->b) - static_cast<int32_t>(p.b), 0, 255));
		return _OLC Pixel(r, g, b, a);
	}

	constexpr _OLC Pixel& Pixel::operator-=(const _OLC Pixel p) noexcept // Thanks Au Lit
	{
		r = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(r) - static_cast<int32_t>(p.r), 0, 255));
		g = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(g) - static_cast<int32_t>(p.g), 0, 255));
		b = static_cast<uint8_t>(_STD clamp(static_cast<int32_t>(b) - static_cast<int32_t>(p.b), 0, 255));
		return *this;
	}

	constexpr _OLC Pixel Pixel::operator*(const float i) const noexcept
	{
		uint8_t r = static_cast<uint8_t>(_STD clamp(this->r * i, 0.0f, 255.0f));
		uint8_t g = static_cast<uint8_t>(_STD clamp(this->g * i, 0.0f, 255.0f));
		uint8_t b = static_cast<uint8_t>(_STD clamp(this->b * i, 0.0f, 255.0f));
		return _OLC Pixel(r, g, b, a);
	}

	constexpr _OLC Pixel& Pixel::operator*=(const float i) noexcept
	{
		r = static_cast<uint8_t>(_STD clamp(r * i, 0.0f, 255.0f));
		g = static_cast<uint8_t>(_STD clamp(g * i, 0.0f, 255.0f));
		b = static_cast<uint8_t>(_STD clamp(b * i, 0.0f, 255.0f));
		return *this;
	}

	constexpr _OLC Pixel Pixel::operator/(const float i) const noexcept
	{
		uint8_t r = static_cast<uint8_t>(_STD clamp(this->r / i, 0.0f, 255.0f));
		uint8_t g = static_cast<uint8_t>(_STD clamp(this->g / i, 0.0f, 255.0f));
		uint8_t b = static_cast<uint8_t>(_STD clamp(this->b / i, 0.0f, 255.0f));
		return _OLC Pixel(r, g, b, a);
	}

	constexpr _OLC Pixel& Pixel::operator/=(const float i) noexcept
	{
		r = static_cast<uint8_t>(_STD clamp(r / i, 0.0f, 255.0f));
		g = static_cast<uint8_t>(_STD clamp(g / i, 0.0f, 255.0f));
		b = static_cast<uint8_t>(_STD clamp(b / i, 0.0f, 255.0f));
		return *this;
	}

	constexpr _OLC Pixel Pixel::inv() const noexcept
	{
		uint8_t r = static_cast<uint8_t>(_STD clamp(255 - static_cast<int32_t>(this->r), 0, 255));
		uint8_t g = static_cast<uint8_t>(_STD clamp(255 - static_cast<int32_t>(this->g), 0, 255));
		uint8_t b = static_cast<uint8_t>(_STD clamp(255 - static_cast<int32_t>(this->b), 0, 255));
		return _OLC Pixel(r, g, b, a);
	}

	constexpr _OLC Pixel PixelF(const float red, const float green, const float blue, const float alpha) noexcept
	{
		return _OLC Pixel(
			static_cast<uint8_t>(_STD clamp(red, 0.0f, 1.0f) * 255.0f),
			static_cast<uint8_t>(_STD clamp(green, 0.0f, 1.0f) * 255.0f),
			static_cast<uint8_t>(_STD clamp(blue, 0.0f, 1.0f) * 255.0f),
			static_cast<uint8_t>(_STD clamp(alpha, 0.0f, 1.0f) * 255.0f)
		);
	}

	constexpr _OLC Pixel PixelLerp(const _OLC Pixel p1, const _OLC Pixel p2, const float t) noexcept
	{
		return (p2 * t) + p1 * (1.0f - t);
	}
}
#pragma endregion

#endif // OLC_PGE_DECLARATIONS

// O-----------------------------------------------------------------------------O
// | START OF OLC_PGE_APPLICATION                                                |
// O-----------------------------------------------------------------------------O
#ifdef OLC_PGE_APPLICATION
#undef OLC_PGE_APPLICATION

// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine INTERFACE IMPLEMENTATION (CORE)                          |
// | Note: The core implementation is platform independent                       |
// O-----------------------------------------------------------------------------O
#pragma region pge_implementation
namespace olc
{
	// O-----------------------------------------------------------------------------O
	// | olc::ResourcePack IMPLEMENTATION                                            |
	// O-----------------------------------------------------------------------------O

	//=============================================================
	// Resource Packs - Allows you to store files in one large 
	// scrambled file - Thanks MaGetzUb for debugging a null char in std::stringstream bug
	_OLC ResourceBuffer::ResourceBuffer(_STD ifstream& ifs, const uint32_t offset, const uint32_t size)
	{
		vMemory.resize(size);
		ifs.seekg(offset);
		ifs.read(vMemory.data(), vMemory.size());
		setg(vMemory.data(), vMemory.data(), vMemory.data() + size);
	}

	_OLC ResourcePack::~ResourcePack()
	{
		baseFile.close();
	}

	bool _OLC ResourcePack::AddFile(const _STD string& sFile)
	{
		_STD string file = makeposix(sFile);

		if (_gfs::exists(file))
		{
			_OLC ResourcePack::sResourceFile e;
			e.nSize = static_cast<uint32_t>(_gfs::file_size(file));
			e.nOffset = 0; // Unknown at this stage			
			mapFiles[file] = e;
			return true;
		}
		return false;
	}

	bool _OLC ResourcePack::LoadPack(const _STD string& sFile, const _STD string& sKey)
	{
		// Open the resource file
		baseFile.open(sFile, _STD ifstream::binary);
		if (!baseFile.is_open())
			return false;

		// 1) Read Scrambled index
		uint32_t nIndexSize = 0;
		baseFile.read((char*)&nIndexSize, sizeof(uint32_t));

		_STD vector<char> buffer(nIndexSize);
		for (uint32_t j = 0; j < nIndexSize; j++)
			buffer[j] = baseFile.get();

		_STD vector<char> decoded = scramble(buffer, sKey);
		size_t pos = 0;
		auto read = [&decoded, &pos](char* dst, size_t size)
		{
			memcpy_s((void*)dst, size, (const void*)(decoded.data() + pos), size);
			pos += size;
		};

		auto get = [&read]() -> int
		{
			char c;
			read(&c, 1);
			return c;
		};

		// 2) Read Map
		uint32_t nMapEntries = 0;
		read((char*)&nMapEntries, sizeof(uint32_t));
		for (uint32_t i = 0; i < nMapEntries; i++)
		{
			uint32_t nFilePathSize = 0;
			read((char*)&nFilePathSize, sizeof(uint32_t));

			_STD string sFileName(nFilePathSize, ' ');
			for (uint32_t j = 0; j < nFilePathSize; j++)
				sFileName[j] = get();

			_OLC ResourcePack::sResourceFile e;
			read((char*)&e.nSize, sizeof(uint32_t));
			read((char*)&e.nOffset, sizeof(uint32_t));
			mapFiles[sFileName] = e;
		}

		// Don't close base file! we will provide a stream
		// pointer when the file is requested
		return true;
	}

	bool _OLC ResourcePack::SavePack(const _STD string& sFile, const _STD string& sKey)
	{
		// Create/Overwrite the resource file
		_STD ofstream ofs(sFile, _STD ofstream::binary);
		if (!ofs.is_open())
			return false;

		// Iterate through map
		uint32_t nIndexSize = 0; // Unknown for now
		ofs.write((char*)&nIndexSize, sizeof(uint32_t));
		uint32_t nMapSize = uint32_t(mapFiles.size());
		ofs.write((char*)&nMapSize, sizeof(uint32_t));
		for (auto& e : mapFiles)
		{
			// Write the path of the file
			size_t nPathSize = e.first.size();
			ofs.write((char*)&nPathSize, sizeof(uint32_t));
			ofs.write(e.first.c_str(), nPathSize);

			// Write the file entry properties
			ofs.write((char*)&e.second.nSize, sizeof(uint32_t));
			ofs.write((char*)&e.second.nOffset, sizeof(uint32_t));
		}

		// 2) Write the individual Data
		_STD streampos offset = ofs.tellp();
		nIndexSize = static_cast<uint32_t>(offset);
		for (auto& e : mapFiles)
		{
			// Store beginning of file offset within resource pack file
			e.second.nOffset = static_cast<uint32_t>(offset);

			// Load the file to be added
			_STD vector<uint8_t> vBuffer(e.second.nSize);
			_STD ifstream i(e.first, _STD ifstream::binary);
			i.read((char*)vBuffer.data(), e.second.nSize);
			i.close();

			// Write the loaded file into resource pack file
			ofs.write((char*)vBuffer.data(), e.second.nSize);
			offset += e.second.nSize;
		}

		// 3) Scramble Index
		_STD vector<char> stream;
		auto write = [&stream](const char* data, size_t size)
		{
			size_t sizeNow = stream.size();
			stream.resize(sizeNow + size);
			memcpy_s(stream.data() + sizeNow, size, data, size);
		};

		// Iterate through map
		write((char*)&nMapSize, sizeof(uint32_t));
		for (auto& e : mapFiles)
		{
			// Write the path of the file
			size_t nPathSize = e.first.size();
			write((char*)&nPathSize, sizeof(uint32_t));
			write(e.first.c_str(), nPathSize);

			// Write the file entry properties
			write((char*)&e.second.nSize, sizeof(uint32_t));
			write((char*)&e.second.nOffset, sizeof(uint32_t));
		}
		_STD vector<char> sIndexString = scramble(stream, sKey);
		uint32_t nIndexStringLen = static_cast<uint32_t>(sIndexString.size());
		// 4) Rewrite Map (it has been updated with offsets now) at start of file
		ofs.seekp(0, _STD ios::beg);
		ofs.write((char*)&nIndexStringLen, sizeof(uint32_t));
		ofs.write(sIndexString.data(), nIndexStringLen);
		ofs.close();
		return true;
	}

	_OLC ResourceBuffer (_OLC ResourcePack::GetFileBuffer)(const _STD string& sFile)
	{
		return _OLC ResourceBuffer(baseFile, mapFiles[sFile].nOffset, mapFiles[sFile].nSize);
	}

	bool _OLC ResourcePack::Loaded()
	{
		return baseFile.is_open();
	}

	_STD vector<char> (_OLC ResourcePack::scramble)(const _STD vector<char>& data, const _STD string& key)
	{
		if (key.empty())
			return data;
		_STD vector<char> o;
		size_t c = 0;
		for (auto s : data)
			o.push_back(s ^ key[(c++) % key.size()]);
		return o;
	};

	_STD string (_OLC ResourcePack::makeposix)(const _STD string& path)
	{
		_STD string o;
		for (auto s : path)
			o += s == '\\' ? '/' : s;
		return o;
	};

	// O-----------------------------------------------------------------------------O
	// | olc::Sprite IMPLEMENTATION                                                  |
	// O-----------------------------------------------------------------------------O
	_OLC Sprite::Sprite(const _STD string& sImageFile, _OLC ResourcePack* pack)
	{
		LoadFromFile(sImageFile, pack);
	}

	_OLC Sprite::Sprite(const int32_t width, const int32_t height)
		: width(width), height(height), pColData(static_cast<size_t>(width) * height, nDefaultPixel) {}

	void _OLC Sprite::Recreate(const int32_t width, const int32_t height, const _OLC Pixel* pixels)
	{
		this->width = width;
		this->height = height;
		size_t pixelCount = static_cast<size_t>(width) * height;
		pColData.resize(pixelCount);
		memcpy_s(pColData.data(), pixelCount * 4, pixels, pixelCount * 4);
	}

	void _OLC Sprite::Clear() noexcept
	{
		width = 0;
		height = 0;
		pColData.clear();
	}

	_OLC rcode (_OLC Sprite::LoadFromFile)(const _STD string& sImageFile, _OLC ResourcePack* pack)
	{
		UNUSED(pack);
		return loader->LoadImageResource(this, sImageFile, pack);
	}

	_OLC rcode (_OLC Sprite::WriteToFile)(const _STD string& sImageFile)
	{
		return loader->SaveImageResource(this, sImageFile);
	}

	int32_t (_OLC Sprite::GetWidth)() const noexcept
	{
		return width;
	}

	int32_t (_OLC Sprite::GetHeight)() const noexcept
	{
		return height;
	}

	_OLC vi2d (_OLC Sprite::GetSize)() const noexcept
	{
		return { width, height };
	}

	_STD vector<_OLC Pixel>& (_OLC Sprite::GetPixels)() noexcept
	{
		return pColData;
	}

	const _STD vector<_OLC Pixel>& (_OLC Sprite::GetPixels)() const noexcept
	{
		return pColData;
	}

	_OLC Pixel* _OLC Sprite::GetData() noexcept
	{
		return pColData.data();
	}

	const _OLC Pixel* _OLC Sprite::GetData() const noexcept
	{
		return pColData.data();
	}

	_OLC Pixel (_OLC Sprite::GetPixel)(const _OLC vi2d& a) const
	{
		return GetPixel(a.x, a.y);
	}

	_OLC Pixel (_OLC Sprite::GetPixel)(const int32_t x, const int32_t y) const
	{
		if (modeSample == _OLC Sprite::Mode::NORMAL)
		{
			if (x >= 0 && x < width && y >= 0 && y < height)
				return pColData[static_cast<size_t>(y) * width + x];
			return _OLC Color::BLANK;
		}

		if (modeSample == _OLC Sprite::Mode::PERIODIC)
			return pColData[static_cast<size_t>(_STD abs(y % height)) * width + _STD abs(x % width)];
		return pColData[static_cast<size_t>(_STD clamp(y, 0, height - 1)) * width + _STD clamp(x, 0, width - 1)];
	}

	bool _OLC Sprite::SetPixel(const _OLC vi2d& a, _OLC Pixel p)
	{
		return SetPixel(a.x, a.y, p);
	}

	bool _OLC Sprite::SetPixel(const int32_t x, const int32_t y, const _OLC Pixel p)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
		{
			pColData[static_cast<size_t>(y) * width + x] = p;
			return true;
		}
		return false;
	}

	_OLC Pixel (_OLC Sprite::Sample)(const float x, const float y) const
	{
		int32_t sx = _STD min(static_cast<int32_t>(x * width), width - 1);
		int32_t sy = _STD min(static_cast<int32_t>(y * height), height - 1);
		return GetPixel(sx, sy);
	}

	_OLC Pixel (_OLC Sprite::SampleBL)(float u, float v) const
	{
		u = u * width - 0.5f;
		v = v * height - 0.5f;
		int32_t x = static_cast<int32_t>(floor(u)); // cast to int rounds toward zero, not downward
		int32_t y = static_cast<int32_t>(floor(v)); // Thanks @joshinils
		float u_ratio = u - x;
		float v_ratio = v - y;
		float u_opposite = 1 - u_ratio;
		float v_opposite = 1 - v_ratio;

		_OLC Pixel p1 = GetPixel(_STD max(x, 0), _STD max(y, 0));
		_OLC Pixel p2 = GetPixel(_STD min(x + 1, width - 1), _STD max(y, 0));
		_OLC Pixel p3 = GetPixel(_STD max(x, 0), _STD min(y + 1, height - 1));
		_OLC Pixel p4 = GetPixel(_STD min(x + 1, width - 1), _STD min(y + 1, height - 1));

		return _OLC Pixel(
			static_cast<uint8_t>((p1.r * u_opposite + p2.r * u_ratio) * v_opposite + (p3.r * u_opposite + p4.r * u_ratio) * v_ratio),
			static_cast<uint8_t>((p1.g * u_opposite + p2.g * u_ratio) * v_opposite + (p3.g * u_opposite + p4.g * u_ratio) * v_ratio),
			static_cast<uint8_t>((p1.b * u_opposite + p2.b * u_ratio) * v_opposite + (p3.b * u_opposite + p4.b * u_ratio) * v_ratio)
		);
	}

	_OLC Sprite* _OLC Sprite::Duplicate() const
	{
		_OLC Sprite* spr = new _OLC Sprite(width, height);
		size_t size = sizeof(_OLC Pixel) * width * height;
		memcpy_s(spr->GetData(), size, GetData(), size);
		spr->modeSample = modeSample;
		return spr;
	}

	_OLC Sprite* _OLC Sprite::Duplicate(const _OLC vi2d& vPos, const _OLC vi2d& vSize) const
	{
		_OLC Sprite* spr = new _OLC Sprite(vSize.x, vSize.y);
		for (int32_t y = 0; y < vSize.y; y++)
			// TODO: this inner loop can be replaced with memcpy_s with the proper bounds.
			// As in each memcpy_s will copy its subsection of each row.
			for (int32_t x = 0; x < vSize.x; x++)
				spr->SetPixel(x, y, GetPixel(vPos.x + x, vPos.y + y));
		return spr;
	}

	// O-----------------------------------------------------------------------------O
	// | olc::Decal IMPLEMENTATION                                                   |
	// O-----------------------------------------------------------------------------O
	_OLC Decal::Decal(_OLC Sprite* spr, bool filter, bool clamp)
	{
		id = -1;
		if (spr == nullptr)
			return;
		sprite = spr;
		id = renderer->CreateTexture(sprite->GetWidth(), sprite->GetHeight(), filter, clamp);
		Update();
	}

	_OLC Decal::Decal(uint32_t nExistingTextureResource, _OLC Sprite* spr)
	{
		if (spr == nullptr)
			return;
		id = nExistingTextureResource;
	}

	_OLC Decal::~Decal()
	{
		if (id != -1)
		{
			renderer->DeleteTexture(id);
			id = -1;
		}
	}

	void _OLC Decal::Update()
	{
		if (sprite == nullptr)
			return;
		vUVScale = 1.0f / _OLC vf2d(sprite->GetSize());
		renderer->ApplyTexture(id);
		renderer->UpdateTexture(id, sprite);
	}

	void _OLC Decal::UpdateSprite()
	{
		if (sprite == nullptr)
			return;
		renderer->ApplyTexture(id);
		renderer->ReadTexture(id, sprite);
	}

	// O-----------------------------------------------------------------------------O
	// | olc::Renderable IMPLEMENTATION                                              |
	// O-----------------------------------------------------------------------------O
	_OLC Renderable::Renderable(_OLC Renderable&& r) noexcept
		: pSprite(_STD move(r.pSprite)), pDecal(_STD move(r.pDecal)) {}

	_OLC rcode (_OLC Renderable::Load)(const _STD string& sFile, _OLC ResourcePack* pack, bool filter, bool clamp)
	{
		pSprite = _STD make_unique<_OLC Sprite>();
		if (pSprite->LoadFromFile(sFile, pack) == _OLC rcode::OK)
		{
			pDecal = _STD make_unique<_OLC Decal>(pSprite.get(), filter, clamp);
			return _OLC rcode::OK;
		}

		pSprite.reset();
		return _OLC rcode::NO_FILE;
	}

	void _OLC Renderable::Create(uint32_t width, uint32_t height, bool filter, bool clamp)
	{
		pSprite = _STD make_unique<_OLC Sprite>(width, height);
		pDecal = _STD make_unique<_OLC Decal>(pSprite.get(), filter, clamp);
	}

	_OLC Decal* _OLC Renderable::Decal() const
	{
		return pDecal.get();
	}

	_OLC Sprite* _OLC Renderable::Sprite() const
	{
		return pSprite.get();
	}

	// O-----------------------------------------------------------------------------O
	// | olc::PixelGameEngine IMPLEMENTATION                                         |
	// O-----------------------------------------------------------------------------O
	_OLC PixelGameEngine::PixelGameEngine()
	{
		sAppName = "Undefined";
		_OLC PGEX::pge = this;

		// Bring in relevant Platform & Rendering systems depending
		// on compiler parameters
		olc_ConfigureSystem();
	}

	_OLC rcode (_OLC PixelGameEngine::Construct)(const _OLC vi2d& screenSize, const _OLC vi2d& pixelSize, const bool fullscreen, const bool vsync, const bool cohesion)
	{
		return Construct(screenSize.x, screenSize.y, pixelSize.x, pixelSize.y, fullscreen, vsync, cohesion);
	}

	_OLC rcode (_OLC PixelGameEngine::Construct)(const int32_t screenWidth, const int32_t screenHeight, const int32_t pixelWidth, const int32_t pixelHeight, const bool fullscreen, const bool vsync, const bool cohesion)
	{
		bPixelCohesion = cohesion;
		vScreenSize = { screenWidth, screenHeight };
		vInvScreenSize = 1.0f / vScreenSize;
		vPixelSize = { pixelWidth, pixelHeight };
		vWindowSize = vScreenSize * vPixelSize;
		bFullScreen = fullscreen;
		bEnableVSYNC = vsync;
		vPixel = 2.0f / vScreenSize;

		if (vPixelSize.x <= 0 || vPixelSize.y <= 0 || vScreenSize.x <= 0 || vScreenSize.y <= 0)
			return _OLC rcode::FAIL;
		return _OLC rcode::OK;
	}

#ifndef PGE_USE_CUSTOM_START
	_OLC rcode (_OLC PixelGameEngine::Start)()
	{
		if (platform->ApplicationStartUp() != _OLC rcode::OK)
			return _OLC rcode::FAIL;

		// Construct the window
		if (platform->CreateWindowPane({ 30 }, vWindowSize, bFullScreen) != _OLC rcode::OK)
			return _OLC rcode::FAIL;
		olc_UpdateWindowSize(vWindowSize.x, vWindowSize.y);

		// Start the thread
		bAtomActive = true;
		_STD thread t = _STD thread(&PixelGameEngine::EngineThread, this);

		// Some implementations may form an event loop here
		platform->StartSystemEventLoop();

		// Wait for thread to be exited
		t.join();

		if (platform->ApplicationCleanUp() != _OLC rcode::OK)
			return _OLC rcode::FAIL;
		return _OLC rcode::OK;
	}
#endif

	// User must override these functions as required. I have not made
	// them abstract because I do need a default behaviour to occur if
	// they are not overwritten

	bool _OLC PixelGameEngine::OnUserCreate()
	{
		return false;
	}

	bool _OLC PixelGameEngine::OnUserUpdate(float fElapsedTime)
	{
		UNUSED(fElapsedTime);
		return false;
	}

	bool _OLC PixelGameEngine::OnUserDestroy()
	{
		return true;
	}

	bool _OLC PixelGameEngine::IsFocused() const
	{
		return bHasInputFocus;
	}

	_OLC HWButton (_OLC PixelGameEngine::GetKey)(const _OLC Key key) const
	{
		return pKeyboardState[key];
	}

	_OLC HWButton (_OLC PixelGameEngine::GetMouseButton)(const MouseButton button) const
	{
		return pMouseState[button];
	}

	int32_t (_OLC PixelGameEngine::GetMouseX)() const
	{
		return vMousePos.x;
	}

	int32_t (_OLC PixelGameEngine::GetMouseY)() const
	{
		return vMousePos.y;
	}

	int32_t (_OLC PixelGameEngine::GetMouseWheel)() const
	{
		return nMouseWheelDelta;
	}

	const _OLC vi2d& _OLC PixelGameEngine::GetWindowMouse() const
	{
		return vMouseWindowPos;
	}

	const _OLC vi2d& _OLC PixelGameEngine::GetMousePos() const
	{
		return vMousePos;
	}

	const _STD map<size_t, uint8_t>& _OLC PixelGameEngine::GetKeyMap()
	{
		return mapKeys;
	}

	int32_t (_OLC PixelGameEngine::ScreenWidth)() const
	{
		return vScreenSize.x;
	}

	int32_t (_OLC PixelGameEngine::ScreenHeight)() const
	{
		return vScreenSize.y;
	}

	int32_t (_OLC PixelGameEngine::GetDrawTargetWidth)() const
	{
		return pDrawTarget ? pDrawTarget->GetWidth() : 0;
	}

	int32_t (_OLC PixelGameEngine::GetDrawTargetHeight)() const
	{
		return pDrawTarget ? pDrawTarget->GetHeight() : 0;
	}

	_OLC Sprite* _OLC PixelGameEngine::GetDrawTarget() const
	{
		return pDrawTarget;
	}

	void _OLC PixelGameEngine::SetScreenSize(const int32_t width, const int32_t height)
	{
		if (width <= 0 || height <= 0)
			return; // This should really return an _OLC rcode.

		vScreenSize = { width, height };
		vInvScreenSize = 1.0f / vScreenSize;
		for (auto& layer : vLayers)
		{
			layer.pDrawTarget.Create(vScreenSize.x, vScreenSize.y);
			layer.bUpdate = true;
		}
		SetDrawTarget(nullptr);
		renderer->ClearBuffer(_OLC Color::BLACK, true);
		renderer->DisplayFrame();
		renderer->ClearBuffer(_OLC Color::BLACK, true);
		renderer->UpdateViewport(vViewPos, vViewSize);
	}

	uint32_t (_OLC PixelGameEngine::GetFPS)() const
	{
		return nLastFPS;
	}

	float _OLC PixelGameEngine::GetElapsedTime() const
	{
		return fLastElapsed;
	}

	const _OLC vi2d& _OLC PixelGameEngine::GetWindowSize() const
	{
		return vWindowSize;
	}

	const _OLC vi2d& _OLC PixelGameEngine::GetPixelSize() const
	{
		return vPixelSize;
	}

	const _OLC vi2d& _OLC PixelGameEngine::GetScreenPixelSize() const
	{
		return vScreenPixelSize;
	}

	void _OLC PixelGameEngine::SetDrawTarget(_OLC Sprite* target)
	{
		if (target)
			pDrawTarget = target;
		else
		{
			nTargetLayer = 0;
			pDrawTarget = vLayers.front().pDrawTarget.Sprite();
		}
	}

	void _OLC PixelGameEngine::SetDrawTarget(const uint8_t layer)
	{
		if (layer < vLayers.size())
		{
			pDrawTarget = vLayers[layer].pDrawTarget.Sprite();
			vLayers[layer].bUpdate = true;
			nTargetLayer = layer;
		}
	}

	void _OLC PixelGameEngine::EnableLayer(const uint8_t layer, const bool enabled)
	{
		if (layer < vLayers.size())
			vLayers[layer].bShow = enabled;
	}

	void _OLC PixelGameEngine::SetLayerOffset(const uint8_t layer, const _OLC vf2d& offset)
	{
		SetLayerOffset(layer, offset.x, offset.y);
	}

	void _OLC PixelGameEngine::SetLayerOffset(const uint8_t layer, const float x, const float y)
	{
		if (layer < vLayers.size())
			vLayers[layer].vOffset = { x, y };
	}

	void _OLC PixelGameEngine::SetLayerScale(const uint8_t layer, const _OLC vf2d& scale)
	{
		SetLayerScale(layer, scale.x, scale.y);
	}

	void _OLC PixelGameEngine::SetLayerScale(const uint8_t layer, const float x, const float y)
	{
		if (layer < vLayers.size())
			vLayers[layer].vScale = { x, y };
	}

	void _OLC PixelGameEngine::SetLayerTint(const uint8_t layer, const _OLC Pixel tint)
	{
		if (layer < vLayers.size())
			vLayers[layer].tint = tint;
	}

	void _OLC PixelGameEngine::SetLayerCustomRenderFunction(const uint8_t layer, const _STD function<void()>& f)
	{
		if (layer < vLayers.size())
			vLayers[layer].funcHook = f;
	}

	_STD vector<_OLC LayerDesc>& _OLC PixelGameEngine::GetLayers()
	{
		return vLayers;
	}

	uint32_t (_OLC PixelGameEngine::CreateLayer)()
	{
		_OLC LayerDesc ld;
		ld.pDrawTarget.Create(vScreenSize.x, vScreenSize.y);
		vLayers.push_back(_STD move(ld));
		return static_cast<uint32_t>(vLayers.size()) - 1;
	}

	_OLC PixelMode (_OLC PixelGameEngine::GetPixelMode)() const
	{
		return nPixelMode;
	}

	void _OLC PixelGameEngine::SetPixelMode(const _OLC PixelMode m)
	{
		nPixelMode = m;
	}

	void _OLC PixelGameEngine::SetPixelMode(const _STD function<_OLC Pixel(int32_t x, int32_t y, _OLC Pixel pSource, _OLC Pixel pDest)>& pixelMode)
	{
		funcPixelMode = pixelMode;
		nPixelMode = _OLC PixelMode::CUSTOM;
	}

	void _OLC PixelGameEngine::SetPixelBlend(const float fBlend)
	{
		fBlendFactor = _STD clamp(fBlend, 0.0f, 1.0f);
	}

	bool _OLC PixelGameEngine::Draw(const _OLC vi2d& pos, const _OLC Pixel p)
	{
		return Draw(pos.x, pos.y, p);
	}

	// This is it, the critical function that plots a pixel
	bool _OLC PixelGameEngine::Draw(const int32_t x, const int32_t y, const _OLC Pixel p)
	{
		if (pDrawTarget == nullptr)
			return false;

		if (nPixelMode == _OLC PixelMode::NORMAL)
			return pDrawTarget->SetPixel(x, y, p);

		if (nPixelMode == _OLC PixelMode::MASK && p.a == 255)
			return pDrawTarget->SetPixel(x, y, p);

		if (nPixelMode == _OLC PixelMode::ALPHA)
		{
			_OLC Pixel d = pDrawTarget->GetPixel(x, y);
			float a = (p.a / 255.0f) * fBlendFactor;
			float c = 1.0f - a;
			uint8_t r = static_cast<uint8_t>(a * p.r + c * d.r);
			uint8_t g = static_cast<uint8_t>(a * p.g + c * d.g);
			uint8_t b = static_cast<uint8_t>(a * p.b + c * d.b);
			return pDrawTarget->SetPixel(x, y, _OLC Pixel(r, g, b/*, static_cast<uint8_t>(p.a * fBlendFactor)*/));
		}

		if (nPixelMode == _OLC PixelMode::CUSTOM)
			return pDrawTarget->SetPixel(x, y, funcPixelMode(x, y, p, pDrawTarget->GetPixel(x, y)));

		return false;
	}

	void _OLC PixelGameEngine::DrawLine(const _OLC vi2d& pos1, const _OLC vi2d& pos2, _OLC Pixel p, uint32_t pattern)
	{
		DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, p, pattern);
	}

	void _OLC PixelGameEngine::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const _OLC Pixel p, uint32_t pattern)
	{
		int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
		dx = x2 - x1;
		dy = y2 - y1;

		auto rol = [&pattern]()
		{
			pattern = (pattern << 1) | (pattern >> 31);
			return pattern & 1;
		};

		_OLC vi2d p1(x1, y1), p2(x2, y2);
		if (!ClipLineToScreen(p1, p2))
			return;
		x1 = p1.x;
		y1 = p1.y;
		x2 = p2.x;
		y2 = p2.y;

		// straight lines idea by gurkanctn
		if (dx == 0) // Line is vertical
		{
			if (y2 < y1)
				_STD swap(y1, y2);
			for (y = y1; y <= y2; y++)
				if (rol())
					Draw(x1, y, p);
			return;
		}

		if (dy == 0) // Line is horizontal
		{
			if (x2 < x1)
				_STD swap(x1, x2);
			for (x = x1; x <= x2; x++)
				if (rol())
					Draw(x, y1, p);
			return;
		}

		// Line is Funk-aye
		dx1 = _STD abs(dx);
		dy1 = _STD abs(dy);
		px = 2 * dy1 - dx1;
		py = 2 * dx1 - dy1;
		if (dy1 <= dx1)
		{
			if (dx >= 0)
			{
				x = x1;
				y = y1;
				xe = x2;
			}
			else
			{
				x = x2;
				y = y2;
				xe = x1;
			}

			if (rol())
				Draw(x, y, p);

			for (i = 0; x < xe; i++)
			{
				x++;
				if (px < 0)
					px += 2 * dy1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						y++;
					else
						y--;
					px += 2 * (dy1 - dx1);
				}
				if (rol())
					Draw(x, y, p);
			}
		}
		else
		{
			if (dy >= 0)
			{
				x = x1;
				y = y1;
				ye = y2;
			}
			else
			{
				x = x2;
				y = y2;
				ye = y1;
			}

			if (rol())
				Draw(x, y, p);

			for (i = 0; y < ye; i++)
			{
				y = y + 1;
				if (py <= 0)
					py += 2 * dx1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						x++;
					else
						x--;
					py += 2 * (dx1 - dy1);
				}
				if (rol())
					Draw(x, y, p);
			}
		}
	}

	void _OLC PixelGameEngine::DrawCircle(const _OLC vi2d& pos, const int32_t radius, _OLC Pixel p, uint8_t mask)
	{
		DrawCircle(pos.x, pos.y, radius, p, mask);
	}

	void _OLC PixelGameEngine::DrawCircle(const int32_t x, const int32_t y, const int32_t radius, _OLC Pixel p, uint8_t mask)
	{
		// Thanks to IanM-Matrix1 #PR121
		if (radius < 0 || x < -radius || y < -radius || x - GetDrawTargetWidth() > radius || y - GetDrawTargetHeight() > radius)
			return;

		if (radius > 0)
		{
			int32_t x0 = 0;
			int32_t y0 = radius;
			int32_t d = 3 - 2 * radius;

			while (y0 >= x0) // only formulate 1/8 of circle
			{
				// Draw even octants
				if (mask & 0x01)
					Draw(x + x0, y - y0, p); // Q6 - upper right right
				if (mask & 0x04)
					Draw(x + y0, y + x0, p); // Q4 - lower lower right
				if (mask & 0x10)
					Draw(x - x0, y + y0, p); // Q2 - lower left left
				if (mask & 0x40)
					Draw(x - y0, y - x0, p); // Q0 - upper upper left
				if (x0 != 0 && x0 != y0)
				{
					if (mask & 0x02)
						Draw(x + y0, y - x0, p); // Q7 - upper upper right
					if (mask & 0x08)
						Draw(x + x0, y + y0, p); // Q5 - lower right right
					if (mask & 0x20)
						Draw(x - y0, y + x0, p); // Q3 - lower lower left
					if (mask & 0x80)
						Draw(x - x0, y - y0, p); // Q1 - upper left left
				}

				if (d < 0)
					d += 4 * x0++ + 6;
				else
					d += 4 * (x0++ - y0--) + 10;
			}
		}
		else
			Draw(x, y, p);
	}

	void _OLC PixelGameEngine::FillCircle(const _OLC vi2d& pos, const int32_t radius, const _OLC Pixel p)
	{
		FillCircle(pos.x, pos.y, radius, p);
	}

	void _OLC PixelGameEngine::FillCircle(const int32_t x, const int32_t y, const int32_t radius, const _OLC Pixel p)
	{
		// Thanks to IanM-Matrix1 #PR121
		if (radius < 0 || x < -radius || y < -radius || x - GetDrawTargetWidth() > radius || y - GetDrawTargetHeight() > radius)
			return;

		if (radius > 0)
		{
			int32_t x0 = 0;
			int32_t y0 = radius;
			int32_t d = 3 - 2 * radius;

			auto drawline = [&](int32_t sx, int32_t ex, int32_t y)
			{
				for (int32_t x = sx; x <= ex; x++)
					Draw(x, y, p);
			};

			while (y0 >= x0)
			{
				drawline(x - y0, x + y0, y - x0);
				if (x0 > 0)
					drawline(x - y0, x + y0, y + x0);

				if (d < 0)
					d += 4 * x0++ + 6;
				else
				{
					if (x0 != y0)
					{
						drawline(x - x0, x + x0, y - y0);
						drawline(x - x0, x + x0, y + y0);
					}
					d += 4 * (x0++ - y0--) + 10;
				}
			}
		}
		else
			Draw(x, y, p);
	}

	void _OLC PixelGameEngine::DrawRect(const _OLC vi2d& pos, const _OLC vi2d& size, const _OLC Pixel p)
	{
		DrawRect(pos.x, pos.y, size.x, size.y, p);
	}

	void _OLC PixelGameEngine::DrawRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h, const _OLC Pixel p)
	{
		DrawLine(x, y, x + w, y, p);
		DrawLine(x + w, y, x + w, y + h, p);
		DrawLine(x + w, y + h, x, y + h, p);
		DrawLine(x, y + h, x, y, p);
	}

	void _OLC PixelGameEngine::FillRect(const _OLC vi2d& pos, const _OLC vi2d& size, const _OLC Pixel p)
	{
		FillRect(pos.x, pos.y, size.x, size.y, p);
	}

	void _OLC PixelGameEngine::FillRect(int32_t x, int32_t y, const int32_t w, const int32_t h, const _OLC Pixel p)
	{
		int32_t x2 = x + w;
		int32_t y2 = y + h;

		x = _STD clamp(x, 0, GetDrawTargetWidth());
		y = _STD clamp(y, 0, GetDrawTargetHeight());
		x2 = _STD clamp(x2, 0, GetDrawTargetWidth());
		y2 = _STD clamp(y2, 0, GetDrawTargetHeight());

		for (int32_t i = x; i < x2; i++)
			for (int32_t j = y; j < y2; j++)
				Draw(i, j, p);
	}

	void _OLC PixelGameEngine::DrawTriangle(const _OLC vi2d& pos1, const _OLC vi2d& pos2, const _OLC vi2d& pos3, const _OLC Pixel p)
	{
		DrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, p);
	}

	void _OLC PixelGameEngine::DrawTriangle(const int32_t x1, const int32_t y1, const int32_t x2, const int32_t y2, const int32_t x3, const int32_t y3, const _OLC Pixel p)
	{
		DrawLine(x1, y1, x2, y2, p);
		DrawLine(x2, y2, x3, y3, p);
		DrawLine(x3, y3, x1, y1, p);
	}

	void _OLC PixelGameEngine::FillTriangle(const _OLC vi2d& pos1, const _OLC vi2d& pos2, const _OLC vi2d& pos3, const _OLC Pixel p)
	{
		FillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, p);
	}

	// https://www.avrfreaks.net/sites/default/files/triangles.c
	void _OLC PixelGameEngine::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const _OLC Pixel p)
	{
		auto drawline = [this, p](int32_t sx, int32_t ex, int32_t ny)
		{
			for (int32_t i = sx; i <= ex; i++)
				Draw(i, ny, p);
		};

		int32_t t1x, t2x, y, minx, maxx, t1xp, t2xp;
		bool changed1 = false;
		bool changed2 = false;
		int32_t signx1, signx2, dx1, dy1, dx2, dy2;
		int32_t e1, e2;
		// Sort vertices
		if (y1 > y2)
		{
			_STD swap(y1, y2);
			_STD swap(x1, x2);
		}
		if (y1 > y3)
		{
			_STD swap(y1, y3);
			_STD swap(x1, x3);
		}
		if (y2 > y3)
		{
			_STD swap(y2, y3);
			_STD swap(x2, x3);
		}

		t1x = t2x = x1; y = y1; // Starting points
		dx1 = static_cast<int32_t>(x2 - x1);
		if (dx1 < 0)
		{
			dx1 = -dx1;
			signx1 = -1;
		}
		else
			signx1 = 1;
		dy1 = static_cast<int32_t>(y2 - y1);

		dx2 = static_cast<int32_t>(x3 - x1);
		if (dx2 < 0)
		{
			dx2 = -dx2;
			signx2 = -1;
		}
		else
			signx2 = 1;
		dy2 = static_cast<int32_t>(y3 - y1);

		if (dy1 > dx1)
		{
			_STD swap(dx1, dy1);
			changed1 = true;
		}
		if (dy2 > dx2)
		{
			_STD swap(dy2, dx2);
			changed2 = true;
		}

		e2 = static_cast<int32_t>(dx2 >> 1);
		// Flat top, just process the second half
		if (y1 == y2)
			goto next;
		e1 = static_cast<int32_t>(dx1 >> 1);

		for (int32_t i = 0; i < dx1; )
		{
			t1xp = 0;
			t2xp = 0;
			if (t1x < t2x)
			{
				minx = t1x;
				maxx = t2x;
			}
			else
			{
				minx = t2x;
				maxx = t1x;
			}
			// process first line until y value is about to change
			while (i < dx1)
			{
				i++;
				e1 += dy1;
				while (e1 >= dx1)
				{
					e1 -= dx1;
					if (changed1)
						t1xp = signx1; //t1x += signx1;
					else
						goto next1;
				}
				if (changed1)
					break;
				else
					t1x += signx1;
			}
			// Move line
		next1:
			// process second line until y value is about to change
			while (true)
			{
				e2 += dy2;
				while (e2 >= dx2)
				{
					e2 -= dx2;
					if (changed2)
						t2xp = signx2; //t2x += signx2;
					else
						goto next2;
				}
				if (changed2)
					break;
				else
					t2x += signx2;
			}
		next2:
			if (minx > t1x)
				minx = t1x;
			if (minx > t2x)
				minx = t2x;
			if (maxx < t1x)
				maxx = t1x;
			if (maxx < t2x)
				maxx = t2x;
			drawline(minx, maxx, y);
			// Draw line from min to max points found on the y, now increase y.
			if (!changed1)
				t1x += signx1;
			t1x += t1xp;
			if (!changed2)
				t2x += signx2;
			t2x += t2xp;
			y++;
			if (y == y2)
				break;
		}
	next:
		// Second half
		dx1 = static_cast<int32_t>(x3 - x2);
		if (dx1 < 0)
		{
			dx1 = -dx1;
			signx1 = -1;
		}
		else
			signx1 = 1;
		dy1 = static_cast<int32_t>(y3 - y2);
		t1x = x2;

		if (dy1 > dx1)
		{
			_STD swap(dy1, dx1);
			changed1 = true;
		}
		else
			changed1 = false;

		e1 = static_cast<int32_t>(dx1 >> 1);

		for (int32_t i = 0; i <= dx1; i++)
		{
			t1xp = 0;
			t2xp = 0;
			if (t1x < t2x)
			{
				minx = t1x;
				maxx = t2x;
			}
			else
			{
				minx = t2x;
				maxx = t1x;
			}
			// process first line until y value is about to change
			while (i < dx1)
			{
				e1 += dy1;
				while (e1 >= dx1)
				{
					e1 -= dx1;
					if (changed1)
					{
						t1xp = signx1;
						break;
					} // t1x += signx1;
					else          goto next3;
				}
				if (changed1)
					break;
				else
					t1x += signx1;
				if (i < dx1)
					i++;
			}
		next3:
			// process second line until y value is about to change
			while (t2x != x3)
			{
				e2 += dy2;
				while (e2 >= dx2)
				{
					e2 -= dx2;
					if (changed2)
						t2xp = signx2;
					else
						goto next4;
				}
				if (changed2)
					break;
				else
					t2x += signx2;
			}
		next4:
			if (minx > t1x)
				minx = t1x;
			if (minx > t2x)
				minx = t2x;
			if (maxx < t1x)
				maxx = t1x;
			if (maxx < t2x)
				maxx = t2x;
			drawline(minx, maxx, y);
			if (!changed1)
				t1x += signx1;
			t1x += t1xp;
			if (!changed2)
				t2x += signx2;
			t2x += t2xp;
			y++;
			if (y > y3)
				return;
		}
	}

	void _OLC PixelGameEngine::DrawSprite(const _OLC vi2d& pos, _OLC Sprite* sprite, const uint32_t scale, const Sprite::Flip flip)
	{
		DrawSprite(pos.x, pos.y, sprite, scale, flip);
	}

	void _OLC PixelGameEngine::DrawSprite(const int32_t x, const int32_t y, _OLC Sprite* sprite, const uint32_t scale, const Sprite::Flip flip)
	{
		if (sprite == nullptr)
			return;

		int32_t fxs = 0, fxm = 1, fx = 0;
		int32_t fys = 0, fym = 1, fy = 0;
		if (flip & _OLC Sprite::Flip_HORIZ)
		{
			fxs = sprite->GetWidth() - 1;
			fxm = -1;
		}
		if (flip & _OLC Sprite::Flip_VERT)
		{
			fys = sprite->GetHeight() - 1;
			fym = -1;
		}

		if (scale > 1)
		{
			fx = fxs;
			for (int32_t i = 0; i < sprite->GetWidth(); i++, fx += fxm)
			{
				fy = fys;
				for (int32_t j = 0; j < sprite->GetHeight(); j++, fy += fym)
					for (uint32_t is = 0; is < scale; is++)
						for (uint32_t js = 0; js < scale; js++)
							Draw(x + (i * scale) + is, y + (j * scale) + js, sprite->GetPixel(fx, fy));
			}
		}
		else
		{
			fx = fxs;
			for (int32_t i = 0; i < sprite->GetWidth(); i++, fx += fxm)
			{
				fy = fys;
				for (int32_t j = 0; j < sprite->GetHeight(); j++, fy += fym)
					Draw(x + i, y + j, sprite->GetPixel(fx, fy));
			}
		}
	}

	void _OLC PixelGameEngine::DrawPartialSprite(const _OLC vi2d& pos, _OLC Sprite* sprite, const _OLC vi2d& sourcepos, const _OLC vi2d& size, const uint32_t scale, const Sprite::Flip flip)
	{
		DrawPartialSprite(pos.x, pos.y, sprite, sourcepos.x, sourcepos.y, size.x, size.y, scale, flip);
	}

	void _OLC PixelGameEngine::DrawPartialSprite(const int32_t x, const int32_t y, _OLC Sprite* sprite, const int32_t ox, const int32_t oy, const int32_t w, const int32_t h, const uint32_t scale, const Sprite::Flip flip)
	{
		if (sprite == nullptr)
			return;

		int32_t fxs = 0, fxm = 1, fx = 0;
		int32_t fys = 0, fym = 1, fy = 0;
		if (flip & _OLC Sprite::Flip_HORIZ)
		{
			fxs = w - 1;
			fxm = -1;
		}
		if (flip & _OLC Sprite::Flip_VERT)
		{
			fys = h - 1;
			fym = -1;
		}

		if (scale > 1)
		{
			fx = fxs;
			for (int32_t i = 0; i < w; i++, fx += fxm)
			{
				fy = fys;
				for (int32_t j = 0; j < h; j++, fy += fym)
					for (uint32_t is = 0; is < scale; is++)
						for (uint32_t js = 0; js < scale; js++)
							Draw(x + (i * scale) + is, y + (j * scale) + js, sprite->GetPixel(fx + ox, fy + oy));
			}
		}
		else
		{
			fx = fxs;
			for (int32_t i = 0; i < w; i++, fx += fxm)
			{
				fy = fys;
				for (int32_t j = 0; j < h; j++, fy += fym)
					Draw(x + i, y + j, sprite->GetPixel(fx + ox, fy + oy));
			}
		}
	}

	void _OLC PixelGameEngine::DrawString(const _OLC vi2d& pos, const _STD string& sText, const _OLC Pixel col, const uint32_t scale)
	{
		DrawString(pos.x, pos.y, sText, col, scale);
	}

	void _OLC PixelGameEngine::DrawString(const int32_t x, const int32_t y, const _STD string& sText, const _OLC Pixel col, const uint32_t scale)
	{
		int32_t sx = 0;
		int32_t sy = 0;
		_OLC PixelMode m = nPixelMode;
		// Thanks @tucna, spotted bug with col.ALPHA :P
		if (m != _OLC PixelMode::CUSTOM) // Thanks @Megarev, required for "shaders"
			SetPixelMode(col.a != 255 ? _OLC PixelMode::ALPHA : _OLC PixelMode::MASK);
		for (auto c : sText)
		{
			if (c == '\n')
			{
				sx = 0;
				sy += 8 * scale;
			}
			else if (c == '\t')
				sx += 8 * nTabSizeInSpaces * scale;
			else			
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;

				if (scale > 1)
				{
					for (uint32_t i = 0; i < 8; i++)
						for (uint32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
								for (uint32_t is = 0; is < scale; is++)
									for (uint32_t js = 0; js < scale; js++)
										Draw(x + sx + (i * scale) + is, y + sy + (j * scale) + js, col);
				}
				else
				{
					for (uint32_t i = 0; i < 8; i++)
						for (uint32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
								Draw(x + sx + i, y + sy + j, col);
				}
				sx += 8 * scale;
			}
		}
		SetPixelMode(m);
	}

	_OLC vi2d (_OLC PixelGameEngine::GetTextSize)(const _STD string& s)
	{
		_OLC vi2d size{ 0, 1 };
		_OLC vi2d pos{ 0, 1 };
		for (auto c : s)
		{
			if (c == '\n')
			{
				pos.y++;
				pos.x = 0;
			}
			else if (c == '\t')
			{
				pos.x += nTabSizeInSpaces;
			}
			else
				pos.x++;
			size.x = _STD max(size.x, pos.x);
			size.y = _STD max(size.y, pos.y);
		}
		return size * 8;
	}

	void _OLC PixelGameEngine::DrawStringProp(const _OLC vi2d& pos, const _STD string& sText, const _OLC Pixel col, const uint32_t scale)
	{
		DrawStringProp(pos.x, pos.y, sText, col, scale);
	}

	void _OLC PixelGameEngine::DrawStringProp(const int32_t x, const int32_t y, const _STD string& sText, const _OLC Pixel col, const uint32_t scale)
	{
		int32_t sx = 0;
		int32_t sy = 0;
		_OLC PixelMode m = nPixelMode;

		if (m != _OLC PixelMode::CUSTOM)
			SetPixelMode(col.a != 255 ? _OLC PixelMode::ALPHA : _OLC PixelMode::MASK);
		for (auto c : sText)
		{
			if (c == '\n')
			{
				sx = 0;
				sy += 8 * scale;
			}
			else if (c == '\t')
				sx += 8 * nTabSizeInSpaces * scale;
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;

				if (scale > 1)
				{
					for (int32_t i = 0; i < vFontSpacing[static_cast<size_t>(c) - 32].y; i++)
						for (int32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8 + vFontSpacing[static_cast<size_t>(c) - 32].x, j + oy * 8).r > 0)
								for (int32_t is = 0; is < static_cast<int32_t>(scale); is++)
									for (int32_t js = 0; js < static_cast<int32_t>(scale); js++)
										Draw(x + sx + (i * scale) + is, y + sy + (j * scale) + js, col);
				}
				else
				{
					for (int32_t i = 0; i < vFontSpacing[static_cast<size_t>(c) - 32].y; i++)
						for (int32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8 + vFontSpacing[static_cast<size_t>(c) - 32].x, j + oy * 8).r > 0)
								Draw(x + sx + i, y + sy + j, col);
				}
				sx += vFontSpacing[static_cast<size_t>(c) - 32].y * scale;
			}
		}
		SetPixelMode(m);
	}

	_OLC vi2d (_OLC PixelGameEngine::GetTextSizeProp)(const _STD string& s)
	{
		_OLC vi2d size{ 0, 1 };
		_OLC vi2d pos{ 0, 1 };
		for (auto c : s)
		{
			if (c == '\n')
			{
				pos.y++;
				pos.x = 0;
			}
			else if (c == '\t')
				pos.x += nTabSizeInSpaces * 8;
			else
				pos.x += vFontSpacing[static_cast<size_t>(c) - 32].y;
			size.x = _STD max(size.x, pos.x);
			size.y = _STD max(size.y, pos.y);
		}

		size.y *= 8;
		return size;
	}

	void _OLC PixelGameEngine::SetDecalMode(const _OLC DecalMode mode)
	{
		nDecalMode = mode;
	}

	void _OLC PixelGameEngine::SetDecalStructure(const _OLC DecalStructure& structure)
	{
		nDecalStructure = structure;
	}

	void _OLC PixelGameEngine::DrawDecal(const _OLC vf2d& pos, _OLC Decal* decal, const _OLC vf2d& scale, const _OLC Pixel tint)
	{
		_OLC vf2d vScreenSpacePos = -(pos * vInvScreenSize * 2.0f - 1.0f).perp();
		_OLC vf2d vScreenSpaceDim
		{
			vScreenSpacePos.x + (2.0f * (decal->sprite->GetWidth() * vInvScreenSize.x)) * scale.x,
			vScreenSpacePos.y - (2.0f * (decal->sprite->GetHeight() * vInvScreenSize.y)) * scale.y
		};

		_OLC DecalInstance di;
		di.decal = decal;
		di.points = 4;
		di.tint = { tint };
		di.pos = { { vScreenSpacePos.x, vScreenSpacePos.y }, { vScreenSpacePos.x, vScreenSpaceDim.y }, { vScreenSpaceDim.x, vScreenSpaceDim.y }, { vScreenSpaceDim.x, vScreenSpacePos.y } };
		di.uv = { { 0.0f, 0.0f }, { 0.0f, 1.0f }, {1.0f, 1.0f}, { 1.0f, 0.0f } };
		di.w = { 1 };
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawPartialDecal(const _OLC vf2d& pos, _OLC Decal* decal, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC vf2d& scale, const _OLC Pixel tint)
	{
		_OLC vf2d vScreenSpacePos = -(pos * vInvScreenSize * 2.0f - 1.0f).perp();
		_OLC vf2d vScreenSpaceDim = -((pos + source_size * scale) * vInvScreenSize * 2.0f - 1.0f).perp();

		_OLC vf2d vWindow = vViewSize;
		_OLC vf2d vQuantisedPos = ((vScreenSpacePos * vWindow) + _OLC vf2d(0.5f, 0.5f)).floor() / vWindow;
		_OLC vf2d vQuantisedDim = ((vScreenSpaceDim * vWindow) + _OLC vf2d(0.5f, -0.5f)).ceil() / vWindow;

		_OLC DecalInstance di;
		di.points = 4;
		di.decal = decal;
		di.tint = { tint };
		di.pos = { { vQuantisedPos.x, vQuantisedPos.y }, { vQuantisedPos.x, vQuantisedDim.y }, { vQuantisedDim.x, vQuantisedDim.y }, { vQuantisedDim.x, vQuantisedPos.y } };
		_OLC vf2d uvtl = (source_pos + 0.0001f) * decal->vUVScale;
		_OLC vf2d uvbr = (source_pos + source_size - 0.0001f) * decal->vUVScale;
		di.uv = { { uvtl.x, uvtl.y }, { uvtl.x, uvbr.y }, { uvbr.x, uvbr.y }, { uvbr.x, uvtl.y } };
		di.w = { 1 };
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawPartialDecal(const _OLC vf2d& pos, const _OLC vf2d& size, _OLC Decal* decal, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint)
	{
		_OLC vf2d vScreenSpacePos = -(pos * vInvScreenSize * 2.0f - 1.0f).perp();
		_OLC vf2d vScreenSpaceDim
		{
			vScreenSpacePos.x + (2.0f * size.x * vInvScreenSize.x),
			vScreenSpacePos.y - (2.0f * size.y * vInvScreenSize.y)
		};

		_OLC DecalInstance di;
		di.points = 4;
		di.decal = decal;
		di.tint = { tint };
		di.pos = { { vScreenSpacePos.x, vScreenSpacePos.y }, { vScreenSpacePos.x, vScreenSpaceDim.y }, { vScreenSpaceDim.x, vScreenSpaceDim.y }, { vScreenSpaceDim.x, vScreenSpacePos.y } };
		_OLC vf2d uvtl = source_pos * decal->vUVScale;
		_OLC vf2d uvbr = uvtl + source_size * decal->vUVScale;
		di.uv = { { uvtl.x, uvtl.y }, { uvtl.x, uvbr.y }, { uvbr.x, uvbr.y }, { uvbr.x, uvtl.y } };
		di.w = { 1 };
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawExplicitDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC vf2d* uv, const _OLC Pixel* col, const uint32_t elements)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.pos.resize(elements);
		di.uv.resize(elements);
		di.w.resize(elements);
		di.tint.resize(elements);
		di.points = elements;
		for (uint32_t i = 0; i < elements; i++)
		{
			di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			di.uv[i] = uv[i];
			di.tint[i] = col[i];
			di.w[i] = 1.0f;
		}
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawWarpedDecal(_OLC Decal* decal, const _STD array<_OLC vf2d, 4>& pos, const _OLC Pixel tint)
	{
		DrawWarpedDecal(decal, pos.data(), tint);
	}

	void _OLC PixelGameEngine::DrawWarpedDecal(_OLC Decal* decal, const _OLC vf2d(&pos)[4], const _OLC Pixel tint)
	{
		DrawWarpedDecal(decal, &pos[0], tint);
	}

	void _OLC PixelGameEngine::DrawWarpedDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC Pixel tint)
	{
		// Thanks Nathan Reed, a brilliant article explaining whats going on here
		// http://www.reedbeta.com/blog/quadrilateral-interpolation-part-1/
		_OLC DecalInstance di;
		di.points = 4;
		di.decal = decal;
		di.tint = { tint };
		di.w = { 1 };
		di.pos.resize(4);
		di.uv = { { 0.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f }, { 1.0f, 0.0f } };
		_OLC vf2d center;
		float rd = ((pos[2].x - pos[0].x) * (pos[3].y - pos[1].y) - (pos[3].x - pos[1].x) * (pos[2].y - pos[0].y));
		if (rd != 0)
		{
			rd = 1.0f / rd;
			float rn = ((pos[3].x - pos[1].x) * (pos[0].y - pos[1].y) - (pos[3].y - pos[1].y) * (pos[0].x - pos[1].x)) * rd;
			float sn = ((pos[2].x - pos[0].x) * (pos[0].y - pos[1].y) - (pos[2].y - pos[0].y) * (pos[0].x - pos[1].x)) * rd;
			if (!(rn < 0.f || rn > 1.f || sn < 0.f || sn > 1.f))
				center = pos[0] + rn * (pos[2] - pos[0]);
			float d[4]{ 0.0f };
			for (int32_t i = 0; i < 4; i++)
				d[i] = (pos[i] - center).mag();
			for (int32_t i = 0; i < 4; i++)
			{
				float q = d[i] == 0.0f ? 1.0f : (d[i] + d[(i + 2) & 3]) / d[(i + 2) & 3];
				di.uv[i] *= q; di.w[i] *= q;
				di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			}
			di.mode = nDecalMode;
			di.structure = nDecalStructure;
			vLayers[nTargetLayer].vecDecalInstance.push_back(di);
		}
	}

	void _OLC PixelGameEngine::DrawPartialWarpedDecal(_OLC Decal* decal, const _OLC vf2d(&pos)[4], const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint)
	{
		DrawPartialWarpedDecal(decal, &pos[0], source_pos, source_size, tint);
	}

	void _OLC PixelGameEngine::DrawPartialWarpedDecal(_OLC Decal* decal, const _STD array<_OLC vf2d, 4>& pos, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint)
	{
		DrawPartialWarpedDecal(decal, pos.data(), source_pos, source_size, tint);
	}

	void _OLC PixelGameEngine::DrawPartialWarpedDecal(_OLC Decal* decal, const _OLC vf2d* pos, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC Pixel tint)
	{
		_OLC DecalInstance di;
		di.points = 4;
		di.decal = decal;
		di.tint = { tint };
		di.w = { 1 };
		di.pos.resize(4);
		di.uv = { { 0.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f }, { 1.0f, 0.0f } };
		_OLC vf2d center;
		float rd = ((pos[2].x - pos[0].x) * (pos[3].y - pos[1].y) - (pos[3].x - pos[1].x) * (pos[2].y - pos[0].y));
		if (rd != 0)
		{
			_OLC vf2d uvtl = source_pos * decal->vUVScale;
			_OLC vf2d uvbr = uvtl + (source_size * decal->vUVScale);
			di.uv = { { uvtl.x, uvtl.y }, { uvtl.x, uvbr.y }, { uvbr.x, uvbr.y }, { uvbr.x, uvtl.y } };

			rd = 1.0f / rd;
			float rn = ((pos[3].x - pos[1].x) * (pos[0].y - pos[1].y) - (pos[3].y - pos[1].y) * (pos[0].x - pos[1].x)) * rd;
			float sn = ((pos[2].x - pos[0].x) * (pos[0].y - pos[1].y) - (pos[2].y - pos[0].y) * (pos[0].x - pos[1].x)) * rd;
			if (!(rn < 0.f || rn > 1.f || sn < 0.f || sn > 1.f))
				center = pos[0] + rn * (pos[2] - pos[0]);
			float d[4]{ 0.0f };
			for (int i = 0; i < 4; i++)
				d[i] = (pos[i] - center).mag();
			for (int i = 0; i < 4; i++)
			{
				float q = d[i] == 0.0f ? 1.0f : (d[i] + d[(i + 2) & 3]) / d[(i + 2) & 3];
				di.uv[i] *= q; di.w[i] *= q;
				di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			}
			di.mode = nDecalMode;
			di.structure = nDecalStructure;
			vLayers[nTargetLayer].vecDecalInstance.push_back(di);
		}
	}

	void _OLC PixelGameEngine::DrawRotatedDecal(const _OLC vf2d& pos, _OLC Decal* decal, const float fAngle, const _OLC vf2d& center, const _OLC vf2d& scale, const _OLC Pixel tint)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.pos.resize(4);
		di.uv = { { 0.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f }, { 1.0f, 0.0f } };
		di.w = { 1 };
		di.tint = { tint };
		di.points = 4;
		di.pos[0] = -center * scale;
		di.pos[1] = (_OLC vf2d(0.0f, static_cast<float>(decal->sprite->GetHeight())) - center) * scale;
		di.pos[2] = (_OLC vf2d(static_cast<float>(decal->sprite->GetWidth()), static_cast<float>(decal->sprite->GetHeight())) - center) * scale;
		di.pos[3] = (_OLC vf2d(static_cast<float>(decal->sprite->GetWidth()), 0.0f) - center) * scale;
		float c = _STD cos(fAngle), s = _STD sin(fAngle);
		for (int32_t i = 0; i < 4; i++)
		{
			di.pos[i] = pos + _OLC vf2d(di.pos[i].x * c - di.pos[i].y * s, di.pos[i].x * s + di.pos[i].y * c);
			di.pos[i] = di.pos[i] * vInvScreenSize * 2.0f - 1.0f;
			di.pos[i].y *= -1.0f;
			di.w[i] = 1;
		}
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}


	void _OLC PixelGameEngine::DrawPartialRotatedDecal(const _OLC vf2d& pos, _OLC Decal* decal, const float fAngle, const _OLC vf2d& center, const _OLC vf2d& source_pos, const _OLC vf2d& source_size, const _OLC vf2d& scale, const _OLC Pixel tint)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.points = 4;
		di.tint = { tint };
		di.w = { 1 };
		di.pos.resize(4);
		di.pos[0] = -center * scale;
		di.pos[1] = (_OLC vf2d(0.0f, source_size.y) - center) * scale;
		di.pos[2] = (_OLC vf2d(source_size.x, source_size.y) - center) * scale;
		di.pos[3] = (_OLC vf2d(source_size.x, 0.0f) - center) * scale;
		float c = _STD cos(fAngle), s = _STD sin(fAngle);
		for (int32_t i = 0; i < 4; i++)
		{
			di.pos[i] = pos + _OLC vf2d(di.pos[i].x * c - di.pos[i].y * s, di.pos[i].x * s + di.pos[i].y * c);
			di.pos[i] = di.pos[i] * vInvScreenSize * 2.0f - 1.0f;
			di.pos[i].y *= -1.0f;
		}

		_OLC vf2d uvtl = source_pos * decal->vUVScale;
		_OLC vf2d uvbr = uvtl + source_size * decal->vUVScale;
		di.uv = { { uvtl.x, uvtl.y }, { uvtl.x, uvbr.y }, { uvbr.x, uvbr.y }, { uvbr.x, uvtl.y } };
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawStringDecal(const _OLC vf2d& pos, const _STD string& sText, const _OLC Pixel col, const _OLC vf2d& scale)
	{
		_OLC vf2d spos{ 0.0f };
		for (auto c : sText)
		{
			if (c == '\n')
			{
				spos.x = 0;
				spos.y += 8.0f * scale.y;
			}
			else if (c == '\t')
				spos.x += (8.0f * nTabSizeInSpaces) * scale.x;
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;
				DrawPartialDecal(pos + spos, fontDecal, { ox * 8.0f, oy * 8.0f }, { 8.0f }, scale, col);
				spos.x += 8.0f * scale.x;
			}
		}
	}

	void _OLC PixelGameEngine::DrawStringPropDecal(const _OLC vf2d& pos, const _STD string& sText, const _OLC Pixel col, const _OLC vf2d& scale)
	{
		_OLC vf2d spos{ 0.0f };
		for (auto c : sText)
		{
			if (c == '\n')
			{
				spos.x = 0;
				spos.y += 8.0f * scale.y;
			}
			else if (c == '\t')
				spos.x += (8.0f * nTabSizeInSpaces) * scale.x;
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;
				DrawPartialDecal(pos + spos, fontDecal, { ox * 8.0f + static_cast<float>(vFontSpacing[static_cast<size_t>(c) - 32].x), oy * 8.0f }, { static_cast<float>(vFontSpacing[static_cast<size_t>(c) - 32].y), 8.0f }, scale, col);
				spos.x += vFontSpacing[static_cast<size_t>(c) - 32].y * scale.x;
			}
		}
	}

	void _OLC PixelGameEngine::FillRectDecal(const _OLC vf2d& pos, const _OLC vf2d& size, const _OLC Pixel col)
	{
		_OLC vf2d vNewSize = _OLC vf2d(size - 0.375f).ceil();
		_STD array<_OLC vf2d, 4> points = { { { pos }, { pos.x, pos.y + vNewSize.y }, { pos + vNewSize }, { pos.x + vNewSize.x, pos.y } } };
		_STD array<_OLC vf2d, 4> uvs = { { { 0 }, { 0 }, { 0 }, { 0 } } };
		_STD array<_OLC Pixel, 4> cols = { { col, col, col, col } };
		DrawExplicitDecal(nullptr, points.data(), uvs.data(), cols.data(), 4);
	}

	void _OLC PixelGameEngine::GradientFillRectDecal(const _OLC vf2d& pos, const _OLC vf2d& size, const _OLC Pixel colTL, const _OLC Pixel colBL, const _OLC Pixel colBR, const _OLC Pixel colTR)
	{
		_STD array<_OLC vf2d, 4> points = { { { pos }, { pos.x, pos.y + size.y }, { pos + size }, { pos.x + size.x, pos.y } } };
		_STD array<_OLC vf2d, 4> uvs = { { { 0 }, { 0 }, { 0 }, { 0 } } };
		_STD array<_OLC Pixel, 4> cols = { { colTL, colBL, colBR, colTR } };
		DrawExplicitDecal(nullptr, points.data(), uvs.data(), cols.data(), 4);
	}

	void _OLC PixelGameEngine::DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<_OLC vf2d>& uv, const _OLC Pixel tint)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.points = static_cast<uint32_t>(pos.size());
		di.pos.resize(di.points);
		di.uv.resize(di.points);
		di.w.resize(di.points);
		di.tint.resize(di.points);
		for (uint32_t i = 0; i < di.points; i++)
		{
			di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			di.uv[i] = uv[i];
			di.tint[i] = tint;
			di.w[i] = 1.0f;
		}
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<_OLC vf2d>& uv, const _STD vector<_OLC Pixel> &tint)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.points = static_cast<uint32_t>(pos.size());
		di.pos.resize(di.points);
		di.uv.resize(di.points);
		di.w.resize(di.points);
		di.tint.resize(di.points);
		for (uint32_t i = 0; i < di.points; i++)
		{
			di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			di.uv[i] = uv[i];
			di.tint[i] = tint[i];
			di.w[i] = 1.0f;
		}
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawPolygonDecal(_OLC Decal* decal, const _STD vector<_OLC vf2d>& pos, const _STD vector<float>& depth, const _STD vector<_OLC vf2d>& uv, const _OLC Pixel tint)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.points = static_cast<uint32_t>(pos.size());
		di.pos.resize(di.points);
		di.uv.resize(di.points);
		di.w.resize(di.points);
		di.tint.resize(di.points);
		for (uint32_t i = 0; i < di.points; i++)
		{
			di.pos[i] = { (pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
			di.uv[i] = uv[i];
			di.tint[i] = tint;
			di.w[i] = 1.0f;
		}
		di.mode = nDecalMode;
		di.structure = nDecalStructure;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	void _OLC PixelGameEngine::DrawLineDecal(const _OLC vf2d& pos1, const _OLC vf2d& pos2, const _OLC Pixel p)
	{
		_OLC DecalInstance di;
		di.decal = nullptr;
		di.points = 2;
		di.pos.resize(di.points);
		di.uv.resize(di.points);
		di.w.resize(di.points);
		di.tint.resize(di.points);
		di.pos[0] = { (pos1.x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos1.y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
		di.uv[0] = { 0.0f };
		di.tint[0] = p;
		di.w[0] = 1.0f;
		di.pos[1] = { (pos2.x * vInvScreenSize.x) * 2.0f - 1.0f, ((pos2.y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f };
		di.uv[1] = { 0.0f };
		di.tint[1] = p;
		di.w[1] = 1.0f;
		di.mode = _OLC DecalMode::WIREFRAME;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}

	// Thanks Oso-Grande/Sopadeoso For these awesome and stupidly clever Text Rotation routines... duh XD
	void _OLC PixelGameEngine::DrawRotatedStringDecal(const _OLC vf2d& pos, const _STD string& sText, const float fAngle, const _OLC vf2d& center, const _OLC Pixel col, const _OLC vf2d& scale)
	{
		_OLC vf2d spos = center;
		for (auto c : sText)
		{
			if (c == '\n')
			{
				spos.x = center.x;
				spos.y -= 8.0f;
			}
			else if (c == '\t')
				spos.x += 8.0f * nTabSizeInSpaces * scale.x;
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;
				DrawPartialRotatedDecal(pos, fontDecal, fAngle, spos, { ox * 8.0f, oy * 8.0f }, { 8.0f, 8.0f }, scale, col);
				spos.x -= 8.0f;
			}
		}
	}

	void _OLC PixelGameEngine::DrawRotatedStringPropDecal(const _OLC vf2d& pos, const _STD string& sText, const float fAngle, const _OLC vf2d& center, const _OLC Pixel col, const _OLC vf2d& scale)
	{
		_OLC vf2d spos = center;
		for (auto c : sText)
		{
			if (c == '\n')
			{
				spos.x = center.x;
				spos.y -= 8.0f;
			}
			else if (c == '\t')
				spos.x += 8.0f * nTabSizeInSpaces * scale.x;
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;
				DrawPartialRotatedDecal(pos, fontDecal, fAngle, spos,
					{ ox * 8.0f + static_cast<float>(vFontSpacing[static_cast<size_t>(c) - 32].x), oy * 8.0f },
					{ static_cast<float>(vFontSpacing[static_cast<size_t>(c) - 32].y), 8.0f },
					scale, col
				);
				spos.x -= vFontSpacing[static_cast<size_t>(c) - 32].y;
			}
		}
	}

	void _OLC PixelGameEngine::Clear(const _OLC Pixel p)
	{
		int32_t pixels = GetDrawTargetWidth() * GetDrawTargetHeight();
		_OLC Pixel* m = GetDrawTarget()->GetData();
		for (int32_t i = 0; i < pixels; i++)
			m[i] = p;
	}

	void _OLC PixelGameEngine::ClearBuffer(const _OLC Pixel p, const bool bDepth)
	{
		renderer->ClearBuffer(p, bDepth);
	}

	_OLC Sprite* _OLC PixelGameEngine::GetFontSprite()
	{
		return fontSprite;
	}

	_OLC Decal* _OLC PixelGameEngine::GetFontDecal()
	{
		return fontDecal;
	}

	bool _OLC PixelGameEngine::ClipLineToScreen(_OLC vi2d& in_p1, _OLC vi2d& in_p2)
	{
		// https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
		static constexpr uint8_t SEG_I = 0b0000, SEG_L = 0b0001, SEG_R = 0b0010, SEG_B = 0b0100, SEG_T = 0b1000;
		auto Segment = [&vScreenSize = vScreenSize](const _OLC vi2d& v)
		{
			uint8_t i = SEG_I;
			if (v.x < 0)
				i |= SEG_L;
			else if (v.x > vScreenSize.x)
				i |= SEG_R;
			if (v.y < 0)
				i |= SEG_B;
			else if (v.y > vScreenSize.y)
				i |= SEG_T;
			return i;
		};

		uint8_t s1 = Segment(in_p1), s2 = Segment(in_p2);

		while (true)
		{
			if (!(s1 | s2))
				return true;
			else if (s1 & s2)
				return false;
			else
			{
				uint8_t s3 = s2 > s1 ? s2 : s1;
				_OLC vi2d n;
				if (s3 & SEG_T)
				{
					n.x = in_p1.x + (in_p2.x - in_p1.x) * (vScreenSize.y - 1 - in_p1.y) / (in_p2.y - in_p1.y);
					n.y = vScreenSize.y - 1;
				}
				else if (s3 & SEG_B)
				{
					n.x = in_p1.x + (in_p2.x - in_p1.x) * (0 - in_p1.y) / (in_p2.y - in_p1.y);
					n.y = 0;
				}
				else if (s3 & SEG_R)
				{
					n.x = vScreenSize.x - 1;
					n.y = in_p1.y + (in_p2.y - in_p1.y) * (vScreenSize.x - 1 - in_p1.x) / (in_p2.x - in_p1.x);
				}
				else if (s3 & SEG_L)
				{
					n.x = 0;
					n.y = in_p1.y + (in_p2.y - in_p1.y) * (0 - in_p1.x) / (in_p2.x - in_p1.x);
				}
				if (s3 == s1)
				{
					in_p1 = n;
					s1 = Segment(in_p1);
				}
				else
				{
					in_p2 = n;
					s2 = Segment(in_p2);
				}
			}
		}
		return true;
	}

#ifdef OLC_ENABLE_EXPERIMENTAL
	// Lightweight 3D
	void _OLC PixelGameEngine::LW3D_DrawTriangles(_OLC Decal* decal, const _STD vector<_STD array<float, 3>>& pos, const _STD vector<_OLC vf2d>& tex, const _STD vector<_OLC Pixel>& col)
	{
		_OLC DecalInstance di;
		di.decal = decal;
		di.points = static_cast<uint32_t>(pos.size());
		di.pos.resize(di.points);
		di.uv.resize(di.points);
		di.w.resize(di.points);
		di.tint.resize(di.points);
		for (uint32_t i = 0; i < di.points; i++)
		{
			di.pos[i] = { pos[i][0], pos[i][1] };
			di.w[i] = pos[i][2];
			di.uv[i] = tex[i];
			di.tint[i] = col[i];			
		}
		di.mode = _OLC DecalMode::MODEL3D;
		vLayers[nTargetLayer].vecDecalInstance.push_back(di);
	}
#endif

	void _OLC PixelGameEngine::EngineThread()
	{
		// Allow platform to do stuff here if needed, since its now in the
		// context of this thread
		if (platform->ThreadStartUp() == _OLC rcode::FAIL)
			return;

		// Do engine context specific initialisation
		olc_PrepareEngine();

		// Create user resources as part of this thread
		for (auto& ext : vExtensions)
			ext->OnBeforeUserCreate();
		if (!OnUserCreate())
			bAtomActive = false;
		for (auto& ext : vExtensions)
			ext->OnAfterUserCreate();

		while (bAtomActive)
		{
			// Run as fast as possible
			while (bAtomActive)
				olc_CoreUpdate();

			// Allow the user to free resources if they have overrided the destroy function
			if (!OnUserDestroy())
			{
				// User denied destroy for some reason, so continue running
				bAtomActive = true;
			}
		}

		platform->ThreadCleanUp();
	}

	void _OLC PixelGameEngine::olc_UpdateMouse(int32_t x, int32_t y)
	{
		// Mouse coords come in screen space
		// But leave in pixel space
		bHasMouseFocus = true;
		vMouseWindowPos = { x, y };
		// Full Screen mode may have a weird viewport we must clamp to
		x -= vViewPos.x;
		y -= vViewPos.y;
		vMousePosCache = (_OLC vf2d{ x, y } / (vWindowSize - vViewPos * 2.0f)) * vScreenSize;
		if (vMousePosCache.x >= vScreenSize.x)
			vMousePosCache.x = vScreenSize.x - 1;
		if (vMousePosCache.y >= vScreenSize.y)
			vMousePosCache.y = vScreenSize.y - 1;
		if (vMousePosCache.x < 0)
			vMousePosCache.x = 0;
		if (vMousePosCache.y < 0)
			vMousePosCache.y = 0;
	}

	void _OLC PixelGameEngine::olc_UpdateMouseWheel(const int32_t delta)
	{
		nMouseWheelDeltaCache += delta;
	}

	void _OLC PixelGameEngine::olc_UpdateWindowSize(const int32_t x, const int32_t y)
	{
		vWindowSize = { x, y };
		olc_UpdateViewport();
	}

	void _OLC PixelGameEngine::olc_UpdateMouseState(const _OLC MouseButton button, const bool state)
	{
		pMouseNewState[button] = state;
	}

	void _OLC PixelGameEngine::olc_UpdateKeyState(const _OLC Key key, const bool state)
	{
		pKeyNewState[key] = state;
	}

	void _OLC PixelGameEngine::olc_UpdateMouseFocus(const bool state)
	{
		bHasMouseFocus = state;
	}

	void _OLC PixelGameEngine::olc_UpdateKeyFocus(const bool state)
	{
		bHasInputFocus = state;
	}
	
	void _OLC PixelGameEngine::olc_UpdateViewport()
	{
		int32_t ww = vScreenSize.x * vPixelSize.x;
		int32_t wh = vScreenSize.y * vPixelSize.y;
		float wasp = static_cast<float>(ww) / wh;

		if (bPixelCohesion)
		{
			vScreenPixelSize = vWindowSize / vScreenSize;
			vViewSize = vScreenPixelSize * vScreenSize;
		}
		else
		{
			vViewSize.x = static_cast<int32_t>(vWindowSize.x);
			vViewSize.y = static_cast<int32_t>(vViewSize.x / wasp);

			if (vViewSize.y > vWindowSize.y)
			{
				vViewSize.y = vWindowSize.y;
				vViewSize.x = static_cast<int32_t>(vViewSize.y * wasp);
			}
		}

		vViewPos = (vWindowSize - vViewSize) / 2;
	}

	void _OLC PixelGameEngine::olc_ConstructFontSheet()
	{
		_STD string data;
		data += "?Q`0001oOch0o01o@F40o0<AGD4090LAGD<090@A7ch0?00O7Q`0600>00000000";
		data += "O000000nOT0063Qo4d8>?7a14Gno94AA4gno94AaOT0>o3`oO400o7QN00000400";
		data += "Of80001oOg<7O7moBGT7O7lABET024@aBEd714AiOdl717a_=TH013Q>00000000";
		data += "720D000V?V5oB3Q_HdUoE7a9@DdDE4A9@DmoE4A;Hg]oM4Aj8S4D84@`00000000";
		data += "OaPT1000Oa`^13P1@AI[?g`1@A=[OdAoHgljA4Ao?WlBA7l1710007l100000000";
		data += "ObM6000oOfMV?3QoBDD`O7a0BDDH@5A0BDD<@5A0BGeVO5ao@CQR?5Po00000000";
		data += "Oc``000?Ogij70PO2D]??0Ph2DUM@7i`2DTg@7lh2GUj?0TO0C1870T?00000000";
		data += "70<4001o?P<7?1QoHg43O;`h@GT0@:@LB@d0>:@hN@L0@?aoN@<0O7ao0000?000";
		data += "OcH0001SOglLA7mg24TnK7ln24US>0PL24U140PnOgl0>7QgOcH0K71S0000A000";
		data += "00H00000@Dm1S007@DUSg00?OdTnH7YhOfTL<7Yh@Cl0700?@Ah0300700000000";
		data += "<008001QL00ZA41a@6HnI<1i@FHLM81M@@0LG81?O`0nC?Y7?`0ZA7Y300080000";
		data += "O`082000Oh0827mo6>Hn?Wmo?6HnMb11MP08@C11H`08@FP0@@0004@000000000";
		data += "00P00001Oab00003OcKP0006@6=PMgl<@440MglH@000000`@000001P00000000";
		data += "Ob@8@@00Ob@8@Ga13R@8Mga172@8?PAo3R@827QoOb@820@0O`0007`0000007P0";
		data += "O`000P08Od400g`<3V=P0G`673IP0`@3>1`00P@6O`P00g`<O`000GP800000000";
		data += "?P9PL020O`<`N3R0@E4HC7b0@ET<ATB0@@l6C4B0O`H3N7b0?P01L3R000000020";

		fontSprite = new _OLC Sprite(128, 48);
		int32_t px = 0, py = 0;
		for (size_t b = 0; b < 1024; b += 4)
		{
			uint32_t sym1 = static_cast<uint32_t>(data[b + 0] - 48);
			uint32_t sym2 = static_cast<uint32_t>(data[b + 1] - 48);
			uint32_t sym3 = static_cast<uint32_t>(data[b + 2] - 48);
			uint32_t sym4 = static_cast<uint32_t>(data[b + 3] - 48);
			uint32_t r = sym1 << 18 | sym2 << 12 | sym3 << 6 | sym4;

			for (int32_t i = 0; i < 24; i++)
			{
				int32_t k = r & (1 << i) ? 255 : 0;
				fontSprite->SetPixel(px, py, _OLC Pixel(k, k, k, k));
				if (++py == 48)
				{
					px++;
					py = 0;
				}
			}
		}

		fontDecal = new _OLC Decal(fontSprite);

		constexpr _STD array<uint8_t, 96> vSpacing
		{
			0x03,0x25,0x16,0x08,0x07,0x08,0x08,0x04,0x15,0x15,0x08,0x07,0x15,0x07,0x24,0x08,
			0x08,0x17,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x24,0x15,0x06,0x07,0x16,0x17,
			0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x17,0x08,0x08,0x17,0x08,0x08,0x08,
			0x08,0x08,0x08,0x08,0x17,0x08,0x08,0x08,0x08,0x17,0x08,0x15,0x08,0x15,0x08,0x08,
			0x24,0x18,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x33,0x17,0x17,0x33,0x18,0x17,0x17,
			0x17,0x17,0x17,0x17,0x07,0x17,0x17,0x18,0x18,0x17,0x17,0x07,0x33,0x07,0x08,0x00,
		};

		for (auto c : vSpacing)
			vFontSpacing.push_back({ c >> 4, c & 15 });
	}

	void _OLC PixelGameEngine::olc_PrepareEngine()
	{
		// Start OpenGL, the context is owned by the game thread
		if (platform->CreateGraphics(bFullScreen, bEnableVSYNC, vViewPos, vViewSize) == _OLC rcode::FAIL)
			return;

		// Construct default font sheet
		olc_ConstructFontSheet();

		// Create Primary Layer "0"
		CreateLayer();
		vLayers.front().bUpdate = true;
		vLayers.front().bShow = true;
		SetDrawTarget(nullptr);

		m_tp1 = _STD chrono::system_clock::now();
		m_tp2 = _STD chrono::system_clock::now();
	}


	void _OLC PixelGameEngine::olc_CoreUpdate()
	{
		// Handle Timing
		m_tp2 = _STD chrono::system_clock::now();
		_STD chrono::duration<float> elapsedTime = m_tp2 - m_tp1;
		m_tp1 = m_tp2;

		// Our time per frame coefficient
		float fElapsedTime = elapsedTime.count();
		fLastElapsed = fElapsedTime;

		// Some platforms will need to check for events
		platform->HandleSystemEvent();

		// Compare hardware input states from previous frame
		auto ScanHardware = [](_OLC HWButton* pKeys, bool* pStateOld, bool* pStateNew, uint32_t nKeyCount)
		{
			for (uint32_t i = 0; i < nKeyCount; i++)
			{
				pKeys[i].bPressed = false;
				pKeys[i].bReleased = false;
				if (pStateNew[i] != pStateOld[i])
				{
					if (pStateNew[i])
					{
						pKeys[i].bPressed = !pKeys[i].bHeld;
						pKeys[i].bHeld = true;
					}
					else
					{
						pKeys[i].bReleased = true;
						pKeys[i].bHeld = false;
					}
				}
				pStateOld[i] = pStateNew[i];
			}
		};

		ScanHardware(pKeyboardState, pKeyOldState, pKeyNewState, 256);
		ScanHardware(pMouseState, pMouseOldState, pMouseNewState, nMouseButtons);

		// Cache mouse coordinates so they remain consistent during frame
		vMousePos = vMousePosCache;
		nMouseWheelDelta = nMouseWheelDeltaCache;
		nMouseWheelDeltaCache = 0;

		// renderer->ClearBuffer(_OLC Color::BLACK, true);

		// Handle Frame Update
		bool bExtensionBlockFrame = false;
		for (auto& ext : vExtensions)
			bExtensionBlockFrame |= ext->OnBeforeUserUpdate(fElapsedTime);
		if (!bExtensionBlockFrame && !OnUserUpdate(fElapsedTime))
			bAtomActive = false;
		for (auto& ext : vExtensions)
			ext->OnAfterUserUpdate(fElapsedTime);

		// Display Frame
		renderer->UpdateViewport(vViewPos, vViewSize);
		renderer->ClearBuffer(_OLC Color::BLACK, true);

		// Layer 0 must always exist
		vLayers[0].bUpdate = true;
		vLayers[0].bShow = true;
		SetDecalMode(_OLC DecalMode::NORMAL);
		renderer->PrepareDrawing();

		for (auto layer = vLayers.rbegin(); layer != vLayers.rend(); ++layer)
		{
			if (layer->bShow)
			{
				if (layer->funcHook == nullptr)
				{
					renderer->ApplyTexture(layer->pDrawTarget.Decal()->id);
					if (layer->bUpdate)
					{
						layer->pDrawTarget.Decal()->Update();
						layer->bUpdate = false;
					}

					renderer->DrawLayerQuad(layer->vOffset, layer->vScale, layer->tint);

					// Display Decals in order for this layer
					for (auto& decal : layer->vecDecalInstance)
						renderer->DrawDecal(decal);
					layer->vecDecalInstance.clear();
				}
				else
				{
					// Mwa ha ha.... Have Fun!!!
					layer->funcHook();
				}
			}
		}

		// Present Graphics to screen
		renderer->DisplayFrame();

		// Update Title Bar
		fFrameTimer += fElapsedTime;
		nFrameCount++;
		if (fFrameTimer >= 1.0f)
		{
			nLastFPS = nFrameCount;
			fFrameTimer -= 1.0f;
			_STD string sTitle = "OneLoneCoder.com - Pixel Game Engine - " + sAppName + " - FPS: " + _STD to_string(nFrameCount);
			platform->SetWindowTitle(sTitle);
			nFrameCount = 0;
		}
	}

	void _OLC PixelGameEngine::olc_Terminate()
	{
		bAtomActive = false;
	}

	void _OLC PixelGameEngine::olc_Reanimate()
	{
		bAtomActive = true;
	}

	bool _OLC PixelGameEngine::olc_IsRunning()
	{
		return bAtomActive;
	}

	void _OLC PixelGameEngine::pgex_Register(_OLC PGEX* pgex)
	{
		if (_STD find(vExtensions.begin(), vExtensions.end(), pgex) == vExtensions.end())
			vExtensions.push_back(pgex);			
	}

	// O-----------------------------------------------------------------------------O
	// | olc::PGEX IMPLEMENTATION                                                    |
	// O-----------------------------------------------------------------------------O
	_OLC PGEX::PGEX(bool bHook)
	{
		if (bHook)
			pge->pgex_Register(this);
	}

	void _OLC PGEX::OnBeforeUserCreate()
	{

	}

	void _OLC PGEX::OnAfterUserCreate()
	{

	}

	bool _OLC PGEX::OnBeforeUserUpdate(float& fElapsedTime)
	{
		return false;
	}

	void _OLC PGEX::OnAfterUserUpdate(float fElapsedTime)
	{

	}

	// Need a couple of statics as these are singleton instances
	// read from multiple locations
	_STD atomic_bool (_OLC PixelGameEngine::bAtomActive) = false;
	_OLC PixelGameEngine* _OLC PGEX::pge = nullptr;
	_OLC PixelGameEngine* _OLC Platform::ptrPGE = nullptr;
	_OLC PixelGameEngine* _OLC Renderer::ptrPGE = nullptr;
	_STD unique_ptr<_OLC ImageLoader> (_OLC Sprite::loader) = nullptr;
};
#pragma endregion

#ifndef OLC_PGE_HEADLESS


// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine Renderers - the draw-y bits                              |
// O-----------------------------------------------------------------------------O


// O-----------------------------------------------------------------------------O
// | START RENDERER: OpenGL 1.0 (the original, the best...) <- That's an opinion |
// O-----------------------------------------------------------------------------O
#pragma region renderer_ogl10
#ifdef OLC_GFX_OPENGL10

#ifdef OLC_PLATFORM_WINAPI
	#include <dwmapi.h>
	#include <GL/gl.h>
	#ifndef __MINGW32__
		#pragma comment(lib, "Dwmapi.lib")
	#endif
	typedef BOOL(WINAPI wglSwapInterval_t) (int interval);
	static wglSwapInterval_t* wglSwapInterval = nullptr;
	typedef HDC glDeviceContext_t;
	typedef HGLRC glRenderContext_t;
#endif

#if defined(__linux__) || defined(__FreeBSD__)
	#include <GL/gl.h>
#endif

#ifdef OLC_PLATFORM_X11
	namespace X11
	{
		#include <GL/glx.h>
	}
	typedef int(glSwapInterval_t)(X11::Display* dpy, X11::GLXDrawable drawable, int interval);
	static glSwapInterval_t* glSwapIntervalEXT;
	typedef X11::GLXContext glDeviceContext_t;
	typedef X11::GLXContext glRenderContext_t;
#endif

#ifdef __APPLE__
	#define GL_SILENCE_DEPRECATION
	#include <OpenGL/OpenGL.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#endif

namespace olc
{
	class Renderer_OGL10 : public _OLC Renderer
	{
	private:
#ifdef OLC_PLATFORM_GLUT
		bool mFullScreen = false;
#else
		glDeviceContext_t glDeviceContext = 0;
		glRenderContext_t glRenderContext = 0;
#endif

		bool bSync = false;
		_OLC DecalMode nDecalMode = _OLC DecalMode(-1); // Thanks Gusgo & Bispoo
		_OLC DecalStructure nDecalStructure = _OLC DecalStructure(-1);
#ifdef OLC_PLATFORM_X11
		X11::Display* olc_Display = nullptr;
		X11::Window* olc_Window = nullptr;
		X11::XVisualInfo* olc_VisualInfo = nullptr;
#endif

	public:
		virtual void PrepareDevice() override
		{
#ifdef OLC_PLATFORM_GLUT
			//glutInit has to be called with main() arguments, make fake ones
			int argc = 0;
			char* argv[1] = { (char*)"" };
			glutInit(&argc, argv);
			glutInitWindowPosition(0, 0);
			glutInitWindowSize(512, 512);
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
			// Creates the window and the OpenGL context for it
			glutCreateWindow("OneLoneCoder.com - Pixel Game Engine");
			glEnable(GL_TEXTURE_2D); // Turn on texturing
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
#endif
		}

		virtual _OLC rcode CreateDevice(_STD vector<void*> params, bool bFullScreen, bool bVSYNC) override
		{
#ifdef OLC_PLATFORM_WINAPI
			// Create Device Context
			glDeviceContext = GetDC((HWND)(params[0]));
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR), 1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
				PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				PFD_MAIN_PLANE, 0, 0, 0, 0
			};

			int pf = 0;
			if (!(pf = ChoosePixelFormat(glDeviceContext, &pfd)))
				return _OLC rcode::FAIL;
			SetPixelFormat(glDeviceContext, pf, &pfd);

			if (!(glRenderContext = wglCreateContext(glDeviceContext)))
				return _OLC rcode::FAIL;
			wglMakeCurrent(glDeviceContext, glRenderContext);

			// Remove Frame cap
			wglSwapInterval = (wglSwapInterval_t*)wglGetProcAddress("wglSwapIntervalEXT");
			if (wglSwapInterval)
				wglSwapInterval(!!bVSYNC);
			bSync = bVSYNC;
#endif

#ifdef OLC_PLATFORM_X11
			using namespace X11;
			// Linux has tighter coupling between OpenGL and X11, so we store
			// various "platform" handles in the renderer
			olc_Display = (X11::Display*)(params[0]);
			olc_Window = (X11::Window*)(params[1]);
			olc_VisualInfo = (X11::XVisualInfo*)(params[2]);

			glDeviceContext = glXCreateContext(olc_Display, olc_VisualInfo, nullptr, GL_TRUE);
			glXMakeCurrent(olc_Display, *olc_Window, glDeviceContext);

			XWindowAttributes gwa;
			XGetWindowAttributes(olc_Display, *olc_Window, &gwa);
			glViewport(0, 0, gwa.width, gwa.height);

			glSwapIntervalEXT = nullptr;
			glSwapIntervalEXT = (glSwapInterval_t*)glXGetProcAddress((unsigned char*)"glXSwapIntervalEXT");

			if (glSwapIntervalEXT == nullptr && !bVSYNC)
			{
				printf("NOTE: Could not disable VSYNC, glXSwapIntervalEXT() was not found!\n");
				printf("      Don't worry though, things will still work, it's just the\n");
				printf("      frame rate will be capped to your monitors refresh rate - javidx9\n");
			}

			if (glSwapIntervalEXT != nullptr && !bVSYNC)
				glSwapIntervalEXT(olc_Display, *olc_Window, 0);
#endif

#ifdef OLC_PLATFORM_GLUT
			mFullScreen = bFullScreen;
			if (!bVSYNC)
			{
#ifdef __APPLE__
				GLint sync = 0;
				CGLContextObj ctx = CGLGetCurrentContext();
				if (ctx)
					CGLSetParameter(ctx, kCGLCPSwapInterval, &sync);
#endif
			}
#else
			glEnable(GL_TEXTURE_2D); // Turn on texturing
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
#endif
			return _OLC rcode::OK;
		}

		virtual _OLC rcode DestroyDevice() override
		{
#ifdef OLC_PLATFORM_WINAPI
			wglDeleteContext(glRenderContext);
#endif

#ifdef OLC_PLATFORM_X11
			glXMakeCurrent(olc_Display, None, NULL);
			glXDestroyContext(olc_Display, glDeviceContext);
#endif

#ifdef OLC_PLATFORM_GLUT
			glutDestroyWindow(glutGetWindow());
#endif
			return _OLC rcode::OK;
		}

		virtual void DisplayFrame() override
		{
#ifdef OLC_PLATFORM_WINAPI
			SwapBuffers(glDeviceContext);
			if (bSync)
				DwmFlush(); // Woooohooooooo!!!! SMOOOOOOOTH!
#endif

#ifdef OLC_PLATFORM_X11
			X11::glXSwapBuffers(olc_Display, *olc_Window);
#endif

#ifdef OLC_PLATFORM_GLUT
			glutSwapBuffers();
#endif
		}

		virtual void PrepareDrawing() override
		{
			// ClearBuffer(_OLC Colors::GREEN, true);
			glEnable(GL_BLEND);
			nDecalMode = _OLC DecalMode::NORMAL;
			nDecalStructure = _OLC DecalStructure::FAN;
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		virtual void SetDecalMode(_OLC DecalMode mode)
		{
			if (mode != nDecalMode)
			{
				switch (mode)
				{
					case _OLC DecalMode::NORMAL:
					case _OLC DecalMode::MODEL3D:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					case _OLC DecalMode::ADDITIVE:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE);
						break;
					case _OLC DecalMode::MULTIPLICATIVE:
						glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
						break;
					case _OLC DecalMode::STENCIL:
						glBlendFunc(GL_ZERO, GL_SRC_ALPHA);
						break;
					case _OLC DecalMode::ILLUMINATE:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
						break;
					case _OLC DecalMode::WIREFRAME:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
				}

				nDecalMode = mode;
			}
		}

		virtual void DrawLayerQuad(const _OLC vf2d& offset, const _OLC vf2d& scale, _OLC Pixel tint) override
		{
			glBegin(GL_QUADS);
			glColor4ub(tint.r, tint.g, tint.b, tint.a);
			glTexCoord2f(0.0f * scale.x + offset.x, 1.0f * scale.y + offset.y);
			glVertex3f(-1.0f /*+ vSubPixelOffset.x*/, -1.0f /*+ vSubPixelOffset.y*/, 0.0f);
			glTexCoord2f(0.0f * scale.x + offset.x, 0.0f * scale.y + offset.y);
			glVertex3f(-1.0f /*+ vSubPixelOffset.x*/, 1.0f /*+ vSubPixelOffset.y*/, 0.0f);
			glTexCoord2f(1.0f * scale.x + offset.x, 0.0f * scale.y + offset.y);
			glVertex3f(1.0f /*+ vSubPixelOffset.x*/, 1.0f /*+ vSubPixelOffset.y*/, 0.0f);
			glTexCoord2f(1.0f * scale.x + offset.x, 1.0f * scale.y + offset.y);
			glVertex3f(1.0f /*+ vSubPixelOffset.x*/, -1.0f /*+ vSubPixelOffset.y*/, 0.0f);
			glEnd();
		}

		virtual void DrawDecal(const _OLC DecalInstance& decal) override
		{
			SetDecalMode(decal.mode);

			if (decal.decal == nullptr)
				glBindTexture(GL_TEXTURE_2D, 0);
			else
				glBindTexture(GL_TEXTURE_2D, decal.decal->id);
			
			if (nDecalMode == _OLC DecalMode::MODEL3D)
			{
#ifdef OLC_ENABLE_EXPERIMENTAL
				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glMatrixMode(GL_MODELVIEW);
				glPushMatrix();

				glEnable(GL_DEPTH_TEST);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1, 1000);

				#pragma comment (lib, "winmm.lib")

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(0, -40, -200);
				glRotatef(static_cast<float>(clock()) * 0.1f, 1, 0, 0);
				glRotatef(static_cast<float>(clock()) * 0.1f * 2, 0, 1, 0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

				glBegin(GL_TRIANGLES);


				// Render as 3D Spatial Entity
				for (uint32_t n = 0; n < decal.points; n++)
				{
					glColor4ub(decal.tint[n].r, decal.tint[n].g, decal.tint[n].b, decal.tint[n].a);
					glTexCoord2f(decal.uv[n].x, decal.uv[n].y);
					glVertex3f(decal.pos[n].x, decal.pos[n].y, decal.w[n]);
				}

				glEnd();

				glMatrixMode(GL_PROJECTION);
				glPopMatrix();
				glMatrixMode(GL_MODELVIEW);
				glPopMatrix();
				glDisable(GL_DEPTH_TEST);
#endif
			}
			else
			{
				if (nDecalMode == _OLC DecalMode::WIREFRAME)
					glBegin(GL_LINE_LOOP);
				else
				{
					if(decal.structure == _OLC DecalStructure::FAN)
						glBegin(GL_TRIANGLE_FAN);
					else if(decal.structure == _OLC DecalStructure::STRIP)
						glBegin(GL_TRIANGLE_STRIP);
					else if(decal.structure == _OLC DecalStructure::LIST)
						glBegin(GL_TRIANGLES);
				}

				// Render as 2D Spatial entity
				for (uint32_t n = 0; n < decal.points; n++)
				{
					glColor4ub(decal.tint[n].r, decal.tint[n].g, decal.tint[n].b, decal.tint[n].a);
					glTexCoord4f(decal.uv[n].x, decal.uv[n].y, 0.0f, decal.w[n]);
					glVertex2f(decal.pos[n].x, decal.pos[n].y);
				}

				glEnd();
			}


			//glDisable(GL_DEPTH_TEST);
		}

		virtual uint32_t CreateTexture(uint32_t width, uint32_t height, bool filtered, bool clamp) override
		{
			UNUSED(width);
			UNUSED(height);
			uint32_t id = 0;
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);
			if (filtered)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			}
			else
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			}

			if (clamp)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			}
			else
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			}

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			return id;
		}

		virtual void UpdateTexture(uint32_t id, _OLC Sprite* spr) override
		{
			UNUSED(id);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, spr->GetWidth(), spr->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, spr->GetData());
		}

		virtual void ReadTexture(uint32_t id, _OLC Sprite* spr) override
		{
			glReadPixels(0, 0, spr->GetWidth(), spr->GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, spr->GetData());
		}

		virtual uint32_t DeleteTexture(uint32_t id) override
		{
			glDeleteTextures(1, &id);
			return id;
		}

		virtual void ApplyTexture(uint32_t id) override
		{
			glBindTexture(GL_TEXTURE_2D, id);
		}

		virtual void UpdateViewport(const _OLC vi2d& pos, const _OLC vi2d& size) override
		{
			glViewport(pos.x, pos.y, size.x, size.y);
		}

		virtual void ClearBuffer(_OLC Pixel p, bool bDepth) override
		{
			glClearColor(p.r / 255.0f, p.g / 255.0f, p.b / 255.0f, p.a / 255.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			if (bDepth)
				glClear(GL_DEPTH_BUFFER_BIT);
		}
	};
}
#endif
// O-----------------------------------------------------------------------------O
// | END RENDERER: OpenGL 1.0 (the original, the best...)                        |
// O-----------------------------------------------------------------------------O
#pragma endregion

// O-----------------------------------------------------------------------------O
// | START RENDERER: OpenGL 3.3 (3.0 es) (sh-sh-sh-shaders....)                  |
// O-----------------------------------------------------------------------------O
#pragma region renderer_ogl33
#ifdef OLC_GFX_OPENGL33

#ifdef OLC_PLATFORM_WINAPI
	#include <dwmapi.h>
	#include <gl/GL.h>
	#ifndef __MINGW32__
		#pragma comment(lib, "Dwmapi.lib")
	#endif		
	typedef void __stdcall locSwapInterval_t(GLsizei n);
	typedef HDC glDeviceContext_t;
	typedef HGLRC glRenderContext_t;
	#define CALLSTYLE __stdcall
	#define OGL_LOAD(t, n) (t*)wglGetProcAddress(#n)
#endif

#if defined(__linux__) || defined(__FreeBSD__)
	#include <GL/gl.h>
#endif

#ifdef OLC_PLATFORM_X11
	namespace X11
	{
		#include <GL/glx.h>
	}
	typedef int(locSwapInterval_t)(X11::Display* dpy, X11::GLXDrawable drawable, int interval);
	typedef X11::GLXContext glDeviceContext_t;
	typedef X11::GLXContext glRenderContext_t;
	#define CALLSTYLE 
	#define OGL_LOAD(t, n) (t*)glXGetProcAddress((unsigned char*)#n);
#endif

#ifdef __APPLE__
	#define GL_SILENCE_DEPRECATION
	#include <OpenGL/OpenGL.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#endif

#ifdef OLC_PLATFORM_EMSCRIPTEN
	#include <EGL/egl.h>
	#include <GLES2/gl2.h>
	#define GL_GLEXT_PROTOTYPES
	#include <GLES2/gl2ext.h>
	#include <emscripten/emscripten.h>
	#define CALLSTYLE
	typedef EGLBoolean(locSwapInterval_t)(EGLDisplay display, EGLint interval);
	#define GL_CLAMP GL_CLAMP_TO_EDGE
	#define OGL_LOAD(t, n) n;
#endif

namespace olc
{
	typedef char GLchar;
	typedef ptrdiff_t GLsizeiptr;
	typedef GLuint CALLSTYLE locCreateShader_t(GLenum type);
	typedef GLuint CALLSTYLE locCreateProgram_t(void);
	typedef void CALLSTYLE locDeleteShader_t(GLuint shader);
#ifdef OLC_PLATFORM_EMSCRIPTEN
	typedef void CALLSTYLE locShaderSource_t(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
#else
	typedef void CALLSTYLE locShaderSource_t(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
#endif
	typedef void CALLSTYLE locCompileShader_t(GLuint shader);
	typedef void CALLSTYLE locLinkProgram_t(GLuint program);
	typedef void CALLSTYLE locDeleteProgram_t(GLuint program);
	typedef void CALLSTYLE locAttachShader_t(GLuint program, GLuint shader);
	typedef void CALLSTYLE locBindBuffer_t(GLenum target, GLuint buffer);
	typedef void CALLSTYLE locBufferData_t(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
	typedef void CALLSTYLE locGenBuffers_t(GLsizei n, GLuint* buffers);
	typedef void CALLSTYLE locVertexAttribPointer_t(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	typedef void CALLSTYLE locEnableVertexAttribArray_t(GLuint index);
	typedef void CALLSTYLE locUseProgram_t(GLuint program);
	typedef void CALLSTYLE locBindVertexArray_t(GLuint array);
	typedef void CALLSTYLE locGenVertexArrays_t(GLsizei n, GLuint* arrays);
	typedef void CALLSTYLE locGetShaderInfoLog_t(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

	constexpr size_t OLC_MAX_VERTS = 128;

	class Renderer_OGL33 : public _OLC Renderer
	{
	private:
#ifdef OLC_PLATFORM_EMSCRIPTEN
		EGLDisplay olc_Display;
		EGLConfig olc_Config;
		EGLContext olc_Context;
		EGLSurface olc_Surface;
#endif

#ifdef OLC_PLATFORM_GLUT
		bool mFullScreen = false;
#else
	#ifndef OLC_PLATFORM_EMSCRIPTEN
		glDeviceContext_t glDeviceContext = 0;
		glRenderContext_t glRenderContext = 0;
	#endif
#endif
		bool bSync = false;
		_OLC DecalMode nDecalMode = _OLC DecalMode(-1); // Thanks Gusgo & Bispoo
#ifdef OLC_PLATFORM_X11
		X11::Display* olc_Display = nullptr;
		X11::Window* olc_Window = nullptr;
		X11::XVisualInfo* olc_VisualInfo = nullptr;
#endif
	private:
		locCreateShader_t* locCreateShader = nullptr;
		locShaderSource_t* locShaderSource = nullptr;
		locCompileShader_t* locCompileShader = nullptr;
		locDeleteShader_t* locDeleteShader = nullptr;
		locCreateProgram_t* locCreateProgram = nullptr;
		locDeleteProgram_t* locDeleteProgram = nullptr;
		locLinkProgram_t* locLinkProgram = nullptr;
		locAttachShader_t* locAttachShader = nullptr;
		locBindBuffer_t* locBindBuffer = nullptr;
		locBufferData_t* locBufferData = nullptr;
		locGenBuffers_t* locGenBuffers = nullptr;
		locVertexAttribPointer_t* locVertexAttribPointer = nullptr;
		locEnableVertexAttribArray_t* locEnableVertexAttribArray = nullptr;
		locUseProgram_t* locUseProgram = nullptr;
		locBindVertexArray_t* locBindVertexArray = nullptr;
		locGenVertexArrays_t* locGenVertexArrays = nullptr;
		locSwapInterval_t* locSwapInterval = nullptr;
		locGetShaderInfoLog_t* locGetShaderInfoLog = nullptr;

		uint32_t m_nFS = 0;
		uint32_t m_nVS = 0;
		uint32_t m_nQuadShader = 0;
		uint32_t m_vbQuad = 0;
		uint32_t m_vaQuad = 0;

		struct locVertex
		{
			float pos[3];
			_OLC vf2d tex;
			_OLC Pixel col;
		};

		locVertex pVertexMem[OLC_MAX_VERTS];

		_OLC Renderable rendBlankQuad;

	public:
		virtual void PrepareDevice() override
		{
#ifdef OLC_PLATFORM_GLUT
			//glutInit has to be called with main() arguments, make fake ones
			int argc = 0;
			char* argv[1] = { (char*)"" };
			glutInit(&argc, argv);
			glutInitWindowPosition(0, 0);
			glutInitWindowSize(512, 512);
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
			// Creates the window and the OpenGL context for it
			glutCreateWindow("OneLoneCoder.com - Pixel Game Engine");
			glEnable(GL_TEXTURE_2D); // Turn on texturing
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
#endif
		}

		virtual _OLC rcode CreateDevice(_STD vector<void*> params, bool bFullScreen, bool bVSYNC) override
		{
			// Create OpenGL Context
#ifdef OLC_PLATFORM_WINAPI
			// Create Device Context
			glDeviceContext = GetDC((HWND)(params[0]));
			PIXELFORMATDESCRIPTOR pfd
			{
				sizeof(PIXELFORMATDESCRIPTOR), 1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
				PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				PFD_MAIN_PLANE, 0, 0, 0, 0
			};

			int pf = 0;
			if (!(pf = ChoosePixelFormat(glDeviceContext, &pfd)))
				return _OLC rcode::FAIL;
			SetPixelFormat(glDeviceContext, pf, &pfd);

			if (!(glRenderContext = wglCreateContext(glDeviceContext)))
				return _OLC rcode::FAIL;
			wglMakeCurrent(glDeviceContext, glRenderContext);

			// Set Vertical Sync
			locSwapInterval = OGL_LOAD(locSwapInterval_t, "wglSwapIntervalEXT");
			if (locSwapInterval)
				locSwapInterval(!!bVSYNC);
			bSync = bVSYNC;
#endif

#ifdef OLC_PLATFORM_X11
			using namespace X11;
			// Linux has tighter coupling between OpenGL and X11, so we store
			// various "platform" handles in the renderer
			olc_Display = (X11::Display*)(params[0]);
			olc_Window = (X11::Window*)(params[1]);
			olc_VisualInfo = (X11::XVisualInfo*)(params[2]);

			glDeviceContext = glXCreateContext(olc_Display, olc_VisualInfo, nullptr, GL_TRUE);
			glXMakeCurrent(olc_Display, *olc_Window, glDeviceContext);

			XWindowAttributes gwa;
			XGetWindowAttributes(olc_Display, *olc_Window, &gwa);
			glViewport(0, 0, gwa.width, gwa.height);

			locSwapInterval = OGL_LOAD(locSwapInterval_t, "glXSwapIntervalEXT");

			if (locSwapInterval == nullptr && !bVSYNC)
			{
				printf("NOTE: Could not disable VSYNC, glXSwapIntervalEXT() was not found!\n");
				printf("      Don't worry though, things will still work, it's just the\n");
				printf("      frame rate will be capped to your monitors refresh rate - javidx9\n");
			}

			if (locSwapInterval != nullptr)
				locSwapInterval(olc_Display, *olc_Window, !!bYSYNC);
#endif

#ifdef OLC_PLATFORM_EMSCRIPTEN
			EGLint const attribute_list[] = { EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8, EGL_NONE };
			EGLint const context_config[] = { EGL_CONTEXT_CLIENT_VERSION , 2, EGL_NONE };
			EGLint num_config;

			olc_Display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
			eglInitialize(olc_Display, nullptr, nullptr);
			eglChooseConfig(olc_Display, attribute_list, &olc_Config, 1, &num_config);

			/* create an EGL rendering context */
			olc_Context = eglCreateContext(olc_Display, olc_Config, EGL_NO_CONTEXT, context_config);
			olc_Surface = eglCreateWindowSurface(olc_Display, olc_Config, NULL, nullptr);
			eglMakeCurrent(olc_Display, olc_Surface, olc_Surface, olc_Context);
			//eglSwapInterval is currently a NOP, plement anyways in case it becomes supported
			locSwapInterval = &eglSwapInterval;
			locSwapInterval(olc_Display, !!bVSYNC);
#endif

#ifdef OLC_PLATFORM_GLUT
			mFullScreen = bFullScreen;
			if (!bVSYNC)
			{
#ifdef __APPLE__
				GLint sync = 0;
				CGLContextObj ctx = CGLGetCurrentContext();
				if (ctx)
					CGLSetParameter(ctx, kCGLCPSwapInterval, &sync);
#endif
			}
#else
	#ifndef OLC_PLATFORM_EMSCRIPTEN
			glEnable(GL_TEXTURE_2D); // Turn on texturing
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	#endif
#endif
			// Load External OpenGL Functions
			locCreateShader = OGL_LOAD(locCreateShader_t, glCreateShader);
			locCompileShader = OGL_LOAD(locCompileShader_t, glCompileShader);
			locShaderSource = OGL_LOAD(locShaderSource_t, glShaderSource);
			locDeleteShader = OGL_LOAD(locDeleteShader_t, glDeleteShader);
			locCreateProgram = OGL_LOAD(locCreateProgram_t, glCreateProgram);
			locDeleteProgram = OGL_LOAD(locDeleteProgram_t, glDeleteProgram);
			locLinkProgram = OGL_LOAD(locLinkProgram_t, glLinkProgram);
			locAttachShader = OGL_LOAD(locAttachShader_t, glAttachShader);
			locBindBuffer = OGL_LOAD(locBindBuffer_t, glBindBuffer);
			locBufferData = OGL_LOAD(locBufferData_t, glBufferData);
			locGenBuffers = OGL_LOAD(locGenBuffers_t, glGenBuffers);
			locVertexAttribPointer = OGL_LOAD(locVertexAttribPointer_t, glVertexAttribPointer);
			locEnableVertexAttribArray = OGL_LOAD(locEnableVertexAttribArray_t, glEnableVertexAttribArray);
			locUseProgram = OGL_LOAD(locUseProgram_t, glUseProgram);
			locGetShaderInfoLog = OGL_LOAD(locGetShaderInfoLog_t, glGetShaderInfoLog);
#ifndef OLC_PLATFORM_EMSCRIPTEN
			locBindVertexArray = OGL_LOAD(locBindVertexArray_t, glBindVertexArray);
			locGenVertexArrays = OGL_LOAD(locGenVertexArrays_t, glGenVertexArrays);
#else
			locBindVertexArray = glBindVertexArrayOES;
			locGenVertexArrays = glGenVertexArraysOES;
#endif

			// Load & Compile Quad Shader - assumes no errors
			m_nFS = locCreateShader(0x8B30);
			const GLchar* strFS =
#if defined(__arm__) || defined(OLC_PLATFORM_EMSCRIPTEN)
				"#version 300 es\n"
				"precision mediump float;"
#else
				"#version 330 core\n"
#endif
				"out vec4 pixel;\n"
				"in vec2 oTex;\n"
				"in vec4 oCol;\n"
				"uniform sampler2D sprTex;\n"
				"void main(){pixel = texture(sprTex, oTex) * oCol;}";
			locShaderSource(m_nFS, 1, &strFS, NULL);
			locCompileShader(m_nFS);

			m_nVS = locCreateShader(0x8B31);
			const GLchar* strVS =
#if defined(__arm__) || defined(OLC_PLATFORM_EMSCRIPTEN)
				"#version 300 es\n"
				"precision mediump float;"
#else
				"#version 330 core\n"
#endif
				"layout(location = 0) in vec3 aPos;\n"
				"layout(location = 1) in vec2 aTex;\n"
				"layout(location = 2) in vec4 aCol;\n"
				"out vec2 oTex;\n"
				"out vec4 oCol;\n"
				"void main(){ float p = 1.0 / aPos.z; gl_Position = p * vec4(aPos.x, aPos.y, 0.0, 1.0); oTex = p * aTex; oCol = aCol;}";
			locShaderSource(m_nVS, 1, &strVS, NULL);
			locCompileShader(m_nVS);

			m_nQuadShader = locCreateProgram();
			locAttachShader(m_nQuadShader, m_nFS);
			locAttachShader(m_nQuadShader, m_nVS);
			locLinkProgram(m_nQuadShader);

			// Create Quad
			locGenBuffers(1, &m_vbQuad);
			locGenVertexArrays(1, &m_vaQuad);
			locBindVertexArray(m_vaQuad);
			locBindBuffer(0x8892, m_vbQuad);

			locVertex verts[OLC_MAX_VERTS];
			locBufferData(0x8892, sizeof(locVertex) * OLC_MAX_VERTS, verts, 0x88E0);
			locVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(locVertex), 0); locEnableVertexAttribArray(0);
			locVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(locVertex), (void*)(3 * sizeof(float))); locEnableVertexAttribArray(1);
			locVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(locVertex), (void*)(5 * sizeof(float)));	locEnableVertexAttribArray(2);
			locBindBuffer(0x8892, 0);
			locBindVertexArray(0);

			// Create blank texture for spriteless decals
			rendBlankQuad.Create(1, 1);
			rendBlankQuad.Sprite()->GetData()[0] = _OLC Color::WHITE;
			rendBlankQuad.Decal()->Update();
			return _OLC rcode::OK;
		}

		virtual _OLC rcode DestroyDevice() override
		{
#ifdef OLC_PLATFORM_WINAPI
			wglDeleteContext(glRenderContext);
#endif

#ifdef OLC_PLATFORM_X11
			glXMakeCurrent(olc_Display, None, NULL);
			glXDestroyContext(olc_Display, glDeviceContext);
#endif

#ifdef OLC_PLATFORM_GLUT
			glutDestroyWindow(glutGetWindow());
#endif

#ifdef OLC_PLATFORM_EMSCRIPTEN
			eglMakeCurrent(olc_Display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
			eglDestroyContext(olc_Display, olc_Context);
			eglDestroySurface(olc_Display, olc_Surface);
			eglTerminate(olc_Display);
			olc_Display = EGL_NO_DISPLAY;
			olc_Surface = EGL_NO_SURFACE;
			olc_Context = EGL_NO_CONTEXT;
#endif
			return _OLC rcode::OK;
		}

		virtual void DisplayFrame() override
		{
#ifdef OLC_PLATFORM_WINAPI
			SwapBuffers(glDeviceContext);
			if (bSync)
				DwmFlush(); // Woooohooooooo!!!! SMOOOOOOOTH!
#endif

#ifdef OLC_PLATFORM_X11
			X11::glXSwapBuffers(olc_Display, *olc_Window);
#endif

#ifdef OLC_PLATFORM_GLUT
			glutSwapBuffers();
#endif

#ifdef OLC_PLATFORM_EMSCRIPTEN
			eglSwapBuffers(olc_Display, olc_Surface);
#endif
		}

		virtual void PrepareDrawing() override
		{
			glEnable(GL_BLEND);
			nDecalMode = _OLC DecalMode::NORMAL;
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			locUseProgram(m_nQuadShader);
			locBindVertexArray(m_vaQuad);

#ifdef OLC_PLATFORM_EMSCRIPTEN
			locVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(locVertex), 0); locEnableVertexAttribArray(0);
			locVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(locVertex), (void*)(3 * sizeof(float))); locEnableVertexAttribArray(1);
			locVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(locVertex), (void*)(5 * sizeof(float)));	locEnableVertexAttribArray(2);
#endif
		}

		virtual void SetDecalMode(_OLC DecalMode mode) override
		{
			if (mode != nDecalMode)
			{
				switch (mode)
				{
					case _OLC DecalMode::NORMAL: glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	break;
					case _OLC DecalMode::ADDITIVE: glBlendFunc(GL_SRC_ALPHA, GL_ONE); break;
					case _OLC DecalMode::MULTIPLICATIVE: glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);	break;
					case _OLC DecalMode::STENCIL: glBlendFunc(GL_ZERO, GL_SRC_ALPHA); break;
					case _OLC DecalMode::ILLUMINATE: glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);	break;
					case _OLC DecalMode::WIREFRAME: glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	break;
				}

				nDecalMode = mode;
			}
		}

		virtual void DrawLayerQuad(const _OLC vf2d& offset, const _OLC vf2d& scale, _OLC Pixel tint) override
		{
			locBindBuffer(0x8892, m_vbQuad);
			locVertex verts[4]
			{
				{ { -1.0f, -1.0f, 1.0f }, { 0.0f * scale.x + offset.x, 1.0f * scale.y + offset.y }, tint },
				{ { +1.0f, -1.0f, 1.0f }, { 1.0f * scale.x + offset.x, 1.0f * scale.y + offset.y }, tint },
				{ { -1.0f, +1.0f, 1.0f }, { 0.0f * scale.x + offset.x, 0.0f * scale.y + offset.y }, tint },
				{ { +1.0f, +1.0f, 1.0f }, { 1.0f * scale.x + offset.x, 0.0f * scale.y + offset.y }, tint },
			};

			locBufferData(0x8892, sizeof(locVertex) * 4, verts, 0x88E0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		}

		virtual void DrawDecal(const _OLC DecalInstance& decal) override
		{
			SetDecalMode(decal.mode);
			if (decal.decal == nullptr)
				glBindTexture(GL_TEXTURE_2D, rendBlankQuad.Decal()->id);
			else
				glBindTexture(GL_TEXTURE_2D, decal.decal->id);

			locBindBuffer(0x8892, m_vbQuad);

			for (uint32_t i = 0; i < decal.points; i++)
				pVertexMem[i] = { { decal.pos[i].x, decal.pos[i].y, decal.w[i] }, { decal.uv[i].x, decal.uv[i].y }, decal.tint[i] };

			locBufferData(0x8892, sizeof(locVertex) * decal.points, pVertexMem, 0x88E0);

			if (nDecalMode == _OLC DecalMode::WIREFRAME)
				glDrawArrays(GL_LINE_LOOP, 0, decal.points);
			else
				glDrawArrays(GL_TRIANGLE_FAN, 0, decal.points);
		}

		virtual uint32_t CreateTexture(uint32_t width, uint32_t height, bool filtered, bool clamp) override
		{
			UNUSED(width, height);
			uint32_t id = 0;
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);

			if (filtered)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			}
			else
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			}

			if (clamp)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			}
			else
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			}
#ifndef OLC_PLATFORM_EMSCRIPTEN
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
#endif
			return id;
		}

		virtual void UpdateTexture(uint32_t id, _OLC Sprite* spr) override
		{
			UNUSED(id);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, spr->GetWidth(), spr->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, spr->GetData());
		}

		virtual void ReadTexture(uint32_t id, _OLC Sprite* spr) override
		{
			glReadPixels(0, 0, spr->GetWidth(), spr->GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, spr->GetData());
		}

		virtual uint32_t DeleteTexture(uint32_t id) override
		{
			glDeleteTextures(1, &id);
			return id;
		}

		virtual void ApplyTexture(uint32_t id) override
		{
			glBindTexture(GL_TEXTURE_2D, id);
		}

		virtual void UpdateViewport(const _OLC vi2d& pos, const _OLC vi2d& size) override
		{
			glViewport(pos.x, pos.y, size.x, size.y);
		}

		virtual void ClearBuffer(_OLC Pixel p, bool bDepth) override
		{
			glClearColor(p.r / 255.0f, p.g / 255.0f, p.b / 255.0f, p.a / 255.0f);
			GLbitfield clearMask = GL_COLOR_BUFFER_BIT;
			if (bDepth)
				clearMask |= GL_DEPTH_BUFFER_BIT;
			glClear(clearMask);
		}
	};
}
#endif
// O-----------------------------------------------------------------------------O
// | END RENDERER: OpenGL 3.3 (3.0 es) (sh-sh-sh-shaders....)                    |
// O-----------------------------------------------------------------------------O
#pragma endregion


// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine Image loaders                                            |
// O-----------------------------------------------------------------------------O


// O-----------------------------------------------------------------------------O
// | START IMAGE LOADER: stb_image.h, all systems, very fast                     |
// O-----------------------------------------------------------------------------O
#pragma region image_stb
// Thanks to Sean Barrett - https://github.com/nothings/stb/blob/master/stb_image.h
// MIT License - Copyright(c) 2017 Sean Barrett

// Note you need to download the above file into your project folder, and
// #define OLC_IMAGE_STB 
// #define OLC_PGE_APPLICATION
// #include "olcPixelGameEngine.h"

#ifdef OLC_IMAGE_STB
#include <stb_image.h>
#include <stb_image_write.h>

namespace olc
{
	class ImageLoader_STB : public _OLC ImageLoader
	{
	public:
		_OLC rcode LoadImageResource(_OLC Sprite* spr, const _STD string& sImageFile, _OLC ResourcePack* pack) override
		{
			// Clear out existing sprite
			spr->Clear();

			// Open file
			stbi_uc* bytes = nullptr;
			int width = 0, height = 0, channels = 0;
			if (pack != nullptr)
			{
				ResourceBuffer rb = pack->GetFileBuffer(sImageFile);
				bytes = stbi_load_from_memory((stbi_uc*)rb.vMemory.data(), static_cast<int>(rb.vMemory.size()), &width, &height, &channels, 4);
			}
			else
			{
				// Check if the file exists
				if (!_gfs::exists(sImageFile))
					return _OLC rcode::NO_FILE;
				bytes = stbi_load(sImageFile.c_str(), &width, &height, &channels, 4);
			}

			if (!bytes)
				return _OLC rcode::FAIL;
			spr->Recreate(width, height, (const _OLC Pixel*)bytes);
			stbi_image_free(bytes);
			return _OLC rcode::OK;
		}

		_OLC rcode SaveImageResource(_OLC Sprite* spr, const _STD string& sImageFile) override
		{
			if (!stbi_write_png(sImageFile.c_str(), spr->GetWidth(), spr->GetHeight(), 4, spr->GetData(), 0))
				return _OLC rcode::FAIL;
			return _OLC rcode::OK;
		}
	};
}
#endif
// O-----------------------------------------------------------------------------O
// | END IMAGE LOADER: stb_image.h                                               |
// O-----------------------------------------------------------------------------O
#pragma endregion


// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine Platforms                                                |
// O-----------------------------------------------------------------------------O


// O-----------------------------------------------------------------------------O
// | START PLATFORM: MICROSOFT WINDOWS XP, VISTA, 7, 8, 10                       |
// O-----------------------------------------------------------------------------O
#pragma region platform_windows
#ifdef OLC_PLATFORM_WINAPI

#if defined(_WIN32) && !defined(__MINGW32__)
	#pragma comment(lib, "user32.lib")		// Visual Studio Only
	#pragma comment(lib, "gdi32.lib")		// For other Windows Compilers please add
	#pragma comment(lib, "opengl32.lib")	// these libs to your linker input
#endif

namespace olc
{
	class Platform_Windows : public _OLC Platform
	{
	private:
		HWND olc_hWnd = nullptr;
		_STD wstring wsAppName;

		_STD wstring ConvertS2W(const _STD string& s)
		{
#ifdef __MINGW32__
			wchar_t* buffer = new wchar_t[s.length() + 1];
			mbstowcs(buffer, s.c_str(), s.length());
			buffer[s.length()] = L'\0';
#else
			int count = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
			wchar_t* buffer = new wchar_t[count];
			MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, buffer, count);
#endif
			_STD wstring w(buffer);
			delete[] buffer;
			return w;
		}

	public:
		virtual _OLC rcode ApplicationStartUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ApplicationCleanUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadStartUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadCleanUp() override
		{
			renderer->DestroyDevice();
			PostMessage(olc_hWnd, WM_DESTROY, 0, 0);
			return _OLC rcode::OK;
		}

		virtual _OLC rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC, const _OLC vi2d& vViewPos, const _OLC vi2d& vViewSize) override
		{
			if (renderer->CreateDevice({ olc_hWnd }, bFullScreen, bEnableVSYNC) == _OLC rcode::OK)
			{
				renderer->UpdateViewport(vViewPos, vViewSize);
				return _OLC rcode::OK;
			}
			return _OLC rcode::FAIL;
		}

		virtual _OLC rcode CreateWindowPane(const _OLC vi2d& vWindowPos, _OLC vi2d& vWindowSize, bool bFullScreen) override
		{
			UNUSED(vWindowPos);

			WNDCLASS wc{};
			wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			wc.hInstance = GetModuleHandle(nullptr);
			wc.lpfnWndProc = olc_WindowEvent;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.lpszMenuName = nullptr;
			wc.hbrBackground = nullptr;
			wc.lpszClassName = olcT("OLC_PIXEL_GAME_ENGINE");
			RegisterClass(&wc);

			// Define window furniture
			DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
			DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE | WS_BORDER;

			HMONITOR hmon = MonitorFromWindow(olc_hWnd, MONITOR_DEFAULTTONEAREST);
			MONITORINFO mi{ sizeof(mi) };
			if (!GetMonitorInfo(hmon, &mi))
				return _OLC rcode::FAIL;
			_OLC vi2d monitorSize{ mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top };

			_OLC vi2d vTopLeft;

			// Handle Fullscreen
			if (bFullScreen)
			{
				dwExStyle = 0;
				dwStyle = WS_VISIBLE | WS_POPUP;
				vWindowSize = monitorSize;
				vTopLeft.x = 0;
				vTopLeft.y = 0;
			}

			// Keep client size as requested
			RECT rWndRect{ 0, 0, vWindowSize.x, vWindowSize.y };
			AdjustWindowRectEx(&rWndRect, dwStyle, FALSE, dwExStyle);
			int width = rWndRect.right - rWndRect.left;
			int height = rWndRect.bottom - rWndRect.top;

			if (!bFullScreen)
				vTopLeft = (monitorSize - _OLC vi2d{ width, height - 7 }) / 2;

			olc_hWnd = CreateWindowEx(dwExStyle, wc.lpszClassName, olcT(""), dwStyle,
				vTopLeft.x, vTopLeft.y, width, height, NULL, NULL, wc.hInstance, this);

			// Create Keyboard Mapping
			mapKeys[0x00] = _OLC Key_NONE;
			mapKeys[0x41] = _OLC Key_A; mapKeys[0x42] = _OLC Key_B; mapKeys[0x43] = _OLC Key_C; mapKeys[0x44] = _OLC Key_D; mapKeys[0x45] = _OLC Key_E;
			mapKeys[0x46] = _OLC Key_F; mapKeys[0x47] = _OLC Key_G; mapKeys[0x48] = _OLC Key_H; mapKeys[0x49] = _OLC Key_I; mapKeys[0x4A] = _OLC Key_J;
			mapKeys[0x4B] = _OLC Key_K; mapKeys[0x4C] = _OLC Key_L; mapKeys[0x4D] = _OLC Key_M; mapKeys[0x4E] = _OLC Key_N; mapKeys[0x4F] = _OLC Key_O;
			mapKeys[0x50] = _OLC Key_P; mapKeys[0x51] = _OLC Key_Q; mapKeys[0x52] = _OLC Key_R; mapKeys[0x53] = _OLC Key_S; mapKeys[0x54] = _OLC Key_T;
			mapKeys[0x55] = _OLC Key_U; mapKeys[0x56] = _OLC Key_V; mapKeys[0x57] = _OLC Key_W; mapKeys[0x58] = _OLC Key_X; mapKeys[0x59] = _OLC Key_Y;
			mapKeys[0x5A] = _OLC Key_Z;

			mapKeys[VK_F1] = _OLC Key_F1; mapKeys[VK_F2]  = _OLC Key_F2;  mapKeys[VK_F3]  = _OLC Key_F3;  mapKeys[VK_F4]  = _OLC Key_F4;
			mapKeys[VK_F5] = _OLC Key_F5; mapKeys[VK_F6]  = _OLC Key_F6;  mapKeys[VK_F7]  = _OLC Key_F7;  mapKeys[VK_F8]  = _OLC Key_F8;
			mapKeys[VK_F9] = _OLC Key_F9; mapKeys[VK_F10] = _OLC Key_F10; mapKeys[VK_F11] = _OLC Key_F11; mapKeys[VK_F12] = _OLC Key_F12;

			mapKeys[VK_DOWN] = _OLC Key_DOWN; mapKeys[VK_LEFT] = _OLC Key_LEFT; mapKeys[VK_RIGHT] = _OLC Key_RIGHT; mapKeys[VK_UP] = _OLC Key_UP;

			mapKeys[VK_BACK]   = _OLC Key_BACK;   mapKeys[VK_ESCAPE]  = _OLC Key_ESCAPE; mapKeys[VK_RETURN] = _OLC Key_ENTER; mapKeys[VK_PAUSE]  = _OLC Key_PAUSE;
			mapKeys[VK_SCROLL] = _OLC Key_SCROLL; mapKeys[VK_TAB]     = _OLC Key_TAB;    mapKeys[VK_DELETE] = _OLC Key_DEL;   mapKeys[VK_HOME]   = _OLC Key_HOME;
			mapKeys[VK_END]    = _OLC Key_END;    mapKeys[VK_PRIOR]   = _OLC Key_PGUP;   mapKeys[VK_NEXT]   = _OLC Key_PGDN;  mapKeys[VK_INSERT] = _OLC Key_INS;
			mapKeys[VK_SHIFT]  = _OLC Key_SHIFT;  mapKeys[VK_CONTROL] = _OLC Key_CTRL;
			mapKeys[VK_SPACE]  = _OLC Key_SPACE;

			mapKeys[0x30] = _OLC Key_K0; mapKeys[0x31] = _OLC Key_K1; mapKeys[0x32] = _OLC Key_K2; mapKeys[0x33] = _OLC Key_K3; mapKeys[0x34] = _OLC Key_K4;
			mapKeys[0x35] = _OLC Key_K5; mapKeys[0x36] = _OLC Key_K6; mapKeys[0x37] = _OLC Key_K7; mapKeys[0x38] = _OLC Key_K8; mapKeys[0x39] = _OLC Key_K9;

			mapKeys[VK_NUMPAD0]  = _OLC Key_NP0;    mapKeys[VK_NUMPAD1] = _OLC Key_NP1; mapKeys[VK_NUMPAD2]   = _OLC Key_NP2; mapKeys[VK_NUMPAD3]     = _OLC Key_NP3;    mapKeys[VK_NUMPAD4] = _OLC Key_NP4;
			mapKeys[VK_NUMPAD5]  = _OLC Key_NP5;    mapKeys[VK_NUMPAD6] = _OLC Key_NP6; mapKeys[VK_NUMPAD7]   = _OLC Key_NP7; mapKeys[VK_NUMPAD8]     = _OLC Key_NP8;    mapKeys[VK_NUMPAD9] = _OLC Key_NP9;
			mapKeys[VK_MULTIPLY] = _OLC Key_NP_MUL; mapKeys[VK_ADD]     = _OLC Key_NP_ADD; mapKeys[VK_DIVIDE] = _OLC Key_NP_DIV; mapKeys[VK_SUBTRACT] = _OLC Key_NP_SUB; mapKeys[VK_DECIMAL] = _OLC Key_NP_DECIMAL;

			// Thanks scripticuk
			mapKeys[VK_OEM_1]      = _OLC Key_OEM_1;		// On US and UK keyboards this is the ';:' key
			mapKeys[VK_OEM_2]      = _OLC Key_OEM_2;		// On US and UK keyboards this is the '/?' key
			mapKeys[VK_OEM_3]      = _OLC Key_OEM_3;		// On US keyboard this is the '~' key
			mapKeys[VK_OEM_4]      = _OLC Key_OEM_4;		// On US and UK keyboards this is the '[{' key
			mapKeys[VK_OEM_5]      = _OLC Key_OEM_5;		// On US keyboard this is '\|' key.
			mapKeys[VK_OEM_6]      = _OLC Key_OEM_6;		// On US and UK keyboards this is the ']}' key
			mapKeys[VK_OEM_7]      = _OLC Key_OEM_7;		// On US keyboard this is the single/double quote key. On UK, this is the single quote/@ symbol key
			mapKeys[VK_OEM_8]      = _OLC Key_OEM_8;		// miscellaneous characters. Varies by keyboard
			mapKeys[VK_OEM_PLUS]   = _OLC Key_EQUALS;		// the '+' key on any keyboard
			mapKeys[VK_OEM_COMMA]  = _OLC Key_COMMA;		// the comma key on any keyboard
			mapKeys[VK_OEM_MINUS]  = _OLC Key_MINUS;		// the minus key on any keyboard
			mapKeys[VK_OEM_PERIOD] = _OLC Key_PERIOD;		// the period key on any keyboard
			mapKeys[VK_CAPITAL]    = _OLC Key_CAPS_LOCK;

			return _OLC rcode::OK;
		}

		virtual _OLC rcode SetWindowTitle(const _STD string& s) override
		{
#ifdef UNICODE
			SetWindowText(olc_hWnd, ConvertS2W(s).c_str());
#else
			SetWindowText(olc_hWnd, s.c_str());
#endif
			return _OLC rcode::OK;
		}

		virtual _OLC rcode StartSystemEventLoop() override
		{
			MSG msg;
			while (GetMessage(&msg, NULL, 0, 0) > 0)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			return _OLC rcode::OK;
		}

		virtual _OLC rcode HandleSystemEvent() override
		{
			return _OLC rcode::FAIL;
		}

		// Windows Event Handler - this is statically connected to the windows event system
		static LRESULT CALLBACK olc_WindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch (uMsg)
			{
				case WM_MOUSEMOVE:
				{
					// Thanks @ForAbby (Discord)
					uint16_t x = lParam & 0xFFFF;
					uint16_t y = (lParam >> 16) & 0xFFFF;
					ptrPGE->olc_UpdateMouse(*(int16_t*)&x, *(int16_t*)&y);
					return 0;
				}
				case WM_SIZE:        ptrPGE->olc_UpdateWindowSize(lParam & 0xFFFF, (lParam >> 16) & 0xFFFF); return 0;
				case WM_MOUSEWHEEL:  ptrPGE->olc_UpdateMouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));           return 0;
				case WM_MOUSEHOVER:  ptrPGE->olc_UpdateMouseFocus(true);                                     return 0;
				case WM_MOUSELEAVE:  ptrPGE->olc_UpdateMouseFocus(false);                                    return 0;
				case WM_SETFOCUS:    ptrPGE->olc_UpdateKeyFocus(true);                                       return 0;
				case WM_KILLFOCUS:   ptrPGE->olc_UpdateKeyFocus(false);                                      return 0;
				case WM_KEYDOWN:     ptrPGE->olc_UpdateKeyState(mapKeys[wParam], true);                      return 0;
				case WM_KEYUP:       ptrPGE->olc_UpdateKeyState(mapKeys[wParam], false);                     return 0;
				case WM_SYSKEYDOWN:  ptrPGE->olc_UpdateKeyState(mapKeys[wParam], true);                      return 0;
				case WM_SYSKEYUP:    ptrPGE->olc_UpdateKeyState(mapKeys[wParam], false);                     return 0;
				case WM_LBUTTONDOWN: ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, true);              return 0;
				case WM_LBUTTONUP:   ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, false);             return 0;
				case WM_RBUTTONDOWN: ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, true);             return 0;
				case WM_RBUTTONUP:   ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, false);            return 0;
				case WM_MBUTTONDOWN: ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, true);            return 0;
				case WM_MBUTTONUP:   ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, false);           return 0;
				case WM_XBUTTONDOWN:
				case WM_XBUTTONUP:
				{
					MouseButton button = _OLC MouseButton_MIDDLE;
					for (uint16_t xButton = GET_XBUTTON_WPARAM(wParam); xButton != 0; xButton >>= 1)
						button++;
					ptrPGE->olc_UpdateMouseState(button, uMsg == WM_XBUTTONDOWN);
					return 0;
				}
				case WM_QUIT:
				case WM_CLOSE:       ptrPGE->olc_Terminate();                                                return 0;
				case WM_DESTROY:     PostQuitMessage(0); DestroyWindow(hWnd);                                return 0;
			}
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	};
}
#endif
// O-----------------------------------------------------------------------------O
// | END PLATFORM: MICROSOFT WINDOWS XP, VISTA, 7, 8, 10                         |
// O-----------------------------------------------------------------------------O
#pragma endregion

// O-----------------------------------------------------------------------------O
// | START PLATFORM: LINUX                                                       |
// O-----------------------------------------------------------------------------O
#pragma region platform_linux
#ifdef OLC_PLATFORM_X11
namespace olc
{
	class Platform_Linux : public _OLC Platform
	{
	private:
		X11::Display*             olc_Display = nullptr;
		X11::Window               olc_WindowRoot;
		X11::Window               olc_Window;
		X11::XVisualInfo*         olc_VisualInfo;
		X11::Colormap             olc_ColourMap;
		X11::XSetWindowAttributes olc_SetWindowAttribs;

	public:
		virtual _OLC rcode ApplicationStartUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ApplicationCleanUp() override
		{
			XDestroyWindow(olc_Display, olc_Window);
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadStartUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadCleanUp() override
		{
			renderer->DestroyDevice();
			return _OLC rcode::OK;
		}

		virtual _OLC rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC, const _OLC vi2d& vViewPos, const _OLC vi2d& vViewSize) override
		{
			if (renderer->CreateDevice({ olc_Display, &olc_Window, olc_VisualInfo }, bFullScreen, bEnableVSYNC) == _OLC rcode::OK)
			{
				renderer->UpdateViewport(vViewPos, vViewSize);
				return _OLC rcode::OK;
			}
			return _OLC rcode::FAIL;
		}

		virtual _OLC rcode CreateWindowPane(const _OLC vi2d& vWindowPos, _OLC vi2d& vWindowSize, bool bFullScreen) override
		{
			using namespace X11;
			XInitThreads();

			// Grab the deafult display and window
			olc_Display = XOpenDisplay(NULL);
			olc_WindowRoot = DefaultRootWindow(olc_Display);

			// Based on the display capabilities, configure the appearance of the window
			GLint olc_GLAttribs[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
			olc_VisualInfo = glXChooseVisual(olc_Display, 0, olc_GLAttribs);
			olc_ColourMap = XCreateColormap(olc_Display, olc_WindowRoot, olc_VisualInfo->visual, AllocNone);
			olc_SetWindowAttribs.colormap = olc_ColourMap;

			// Register which events we are interested in receiving
			olc_SetWindowAttribs.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask |
				ButtonPressMask | ButtonReleaseMask | PointerMotionMask | FocusChangeMask | StructureNotifyMask;

			// Create the window
			olc_Window = XCreateWindow(olc_Display, olc_WindowRoot, vWindowPos.x, vWindowPos.y,
				vWindowSize.x, vWindowSize.y,
				0, olc_VisualInfo->depth, InputOutput, olc_VisualInfo->visual,
				CWColormap | CWEventMask, &olc_SetWindowAttribs);

			Atom wmDelete = XInternAtom(olc_Display, "WM_DELETE_WINDOW", true);
			XSetWMProtocols(olc_Display, olc_Window, &wmDelete, 1);

			XMapWindow(olc_Display, olc_Window);
			XStoreName(olc_Display, olc_Window, "OneLoneCoder.com - Pixel Game Engine");

			if (bFullScreen) // Thanks DragonEye, again :D
			{
				Atom wm_state;
				Atom fullscreen;
				wm_state = XInternAtom(olc_Display, "_NET_WM_STATE", False);
				fullscreen = XInternAtom(olc_Display, "_NET_WM_STATE_FULLSCREEN", False);
				XEvent xev{ 0 };
				xev.type = ClientMessage;
				xev.xclient.window = olc_Window;
				xev.xclient.message_type = wm_state;
				xev.xclient.format = 32;
				xev.xclient.data.l[0] = !!bFullScreen; // the action (0: off, 1: on, 2: toggle)
				xev.xclient.data.l[1] = fullscreen;    // first property to alter
				xev.xclient.data.l[2] = 0;             // second property to alter
				xev.xclient.data.l[3] = 0;             // source indication
				XMapWindow(olc_Display, olc_Window);
				XSendEvent(olc_Display, DefaultRootWindow(olc_Display), False,
					SubstructureRedirectMask | SubstructureNotifyMask, &xev);
				XFlush(olc_Display);
				XWindowAttributes gwa;
				XGetWindowAttributes(olc_Display, olc_Window, &gwa);
				vWindowSize.x = gwa.width;
				vWindowSize.y = gwa.height;
			}

			// Create Keyboard Mapping
			mapKeys[0x00] = _OLC Key_NONE;
			mapKeys[0x61] = _OLC Key_A; mapKeys[0x62] = _OLC Key_B; mapKeys[0x63] = _OLC Key_C; mapKeys[0x64] = _OLC Key_D; mapKeys[0x65] = _OLC Key_E;
			mapKeys[0x66] = _OLC Key_F; mapKeys[0x67] = _OLC Key_G; mapKeys[0x68] = _OLC Key_H; mapKeys[0x69] = _OLC Key_I; mapKeys[0x6A] = _OLC Key_J;
			mapKeys[0x6B] = _OLC Key_K; mapKeys[0x6C] = _OLC Key_L; mapKeys[0x6D] = _OLC Key_M; mapKeys[0x6E] = _OLC Key_N; mapKeys[0x6F] = _OLC Key_O;
			mapKeys[0x70] = _OLC Key_P; mapKeys[0x71] = _OLC Key_Q; mapKeys[0x72] = _OLC Key_R; mapKeys[0x73] = _OLC Key_S; mapKeys[0x74] = _OLC Key_T;
			mapKeys[0x75] = _OLC Key_U; mapKeys[0x76] = _OLC Key_V; mapKeys[0x77] = _OLC Key_W; mapKeys[0x78] = _OLC Key_X; mapKeys[0x79] = _OLC Key_Y;
			mapKeys[0x7A] = _OLC Key_Z;

			mapKeys[XK_F1] = _OLC Key_F1; mapKeys[XK_F2]  = _OLC Key_F2;  mapKeys[XK_F3]  = _OLC Key_F3;  mapKeys[XK_F4]  = _OLC Key_F4;
			mapKeys[XK_F5] = _OLC Key_F5; mapKeys[XK_F6]  = _OLC Key_F6;  mapKeys[XK_F7]  = _OLC Key_F7;  mapKeys[XK_F8]  = _OLC Key_F8;
			mapKeys[XK_F9] = _OLC Key_F9; mapKeys[XK_F10] = _OLC Key_F10; mapKeys[XK_F11] = _OLC Key_F11; mapKeys[XK_F12] = _OLC Key_F12;

			mapKeys[XK_Down]     = _OLC Key_DOWN;  mapKeys[XK_Left]   = _OLC Key_LEFT; mapKeys[XK_Right] = _OLC Key_RIGHT; mapKeys[XK_Up] = _OLC Key_UP;
			mapKeys[XK_KP_Enter] = _OLC Key_ENTER; mapKeys[XK_Return] = _OLC Key_ENTER;

			mapKeys[XK_BackSpace]   = _OLC Key_BACK;   mapKeys[XK_Escape]  = _OLC Key_ESCAPE; mapKeys[XK_Linefeed]  = _OLC Key_ENTER; mapKeys[XK_Pause]     = _OLC Key_PAUSE;
			mapKeys[XK_Scroll_Lock] = _OLC Key_SCROLL; mapKeys[XK_Tab]     = _OLC Key_TAB;    mapKeys[XK_Delete]    = _OLC Key_DEL;   mapKeys[XK_Home]      = _OLC Key_HOME;
			mapKeys[XK_End]         = _OLC Key_END;    mapKeys[XK_Page_Up] = _OLC Key_PGUP;   mapKeys[XK_Page_Down] = _OLC Key_PGDN;	 mapKeys[XK_Insert]    = _OLC Key_INS;
			mapKeys[XK_Shift_L]     = _OLC Key_SHIFT;  mapKeys[XK_Shift_R] = _OLC Key_SHIFT;  mapKeys[XK_Control_L] = _OLC Key_CTRL;  mapKeys[XK_Control_R] = _OLC Key_CTRL;
			mapKeys[XK_space]       = _OLC Key_SPACE;  mapKeys[XK_period]  = _OLC Key_PERIOD;

			mapKeys[XK_0] = _OLC Key_K0; mapKeys[XK_1] = _OLC Key_K1; mapKeys[XK_2] = _OLC Key_K2; mapKeys[XK_3] = _OLC Key_K3; mapKeys[XK_4] = _OLC Key_K4;
			mapKeys[XK_5] = _OLC Key_K5; mapKeys[XK_6] = _OLC Key_K6; mapKeys[XK_7] = _OLC Key_K7; mapKeys[XK_8] = _OLC Key_K8; mapKeys[XK_9] = _OLC Key_K9;

			mapKeys[XK_KP_0]        = _OLC Key_NP0;    mapKeys[XK_KP_1]   = _OLC Key_NP1;    mapKeys[XK_KP_2]      = _OLC Key_NP2;    mapKeys[XK_KP_3]        = _OLC Key_NP3;    mapKeys[XK_KP_4]       = _OLC Key_NP4;
			mapKeys[XK_KP_5]        = _OLC Key_NP5;    mapKeys[XK_KP_6]   = _OLC Key_NP6;    mapKeys[XK_KP_7]      = _OLC Key_NP7;    mapKeys[XK_KP_8]        = _OLC Key_NP8;    mapKeys[XK_KP_9]       = _OLC Key_NP9;
			mapKeys[XK_KP_Multiply] = _OLC Key_NP_MUL; mapKeys[XK_KP_Add] = _OLC Key_NP_ADD; mapKeys[XK_KP_Divide] = _OLC Key_NP_DIV; mapKeys[XK_KP_Subtract] = _OLC Key_NP_SUB; mapKeys[XK_KP_Decimal] = _OLC Key_NP_DECIMAL;

			// These keys vary depending on the keyboard. I've included comments for US and UK keyboard layouts
			mapKeys[XK_semicolon]    = _OLC Key_OEM_1; 	// On US and UK keyboards this is the ';:' key
			mapKeys[XK_slash]        = _OLC Key_OEM_2; 	// On US and UK keyboards this is the '/?' key
			mapKeys[XK_asciitilde]   = _OLC Key_OEM_3; 	// On US keyboard this is the '~' key
			mapKeys[XK_bracketleft]  = _OLC Key_OEM_4; 	// On US and UK keyboards this is the '[{' key
			mapKeys[XK_backslash]    = _OLC Key_OEM_5; 	// On US keyboard this is '\|' key.
			mapKeys[XK_bracketright] = _OLC Key_OEM_6; 	// On US and UK keyboards this is the ']}' key
			mapKeys[XK_apostrophe]   = _OLC Key_OEM_7; 	// On US keyboard this is the single/double quote key. On UK, this is the single quote/@ symbol key
			mapKeys[XK_numbersign]   = _OLC Key_OEM_8; 	// miscellaneous characters. Varies by keyboard. I believe this to be the '#~' key on UK keyboards
			mapKeys[XK_equal]        = _OLC Key_EQUALS;	// the '+' key on any keyboard
			mapKeys[XK_comma]        = _OLC Key_COMMA; 	// the comma key on any keyboard
			mapKeys[XK_minus]        = _OLC Key_MINUS; 	// the minus key on any keyboard

			mapKeys[XK_Caps_Lock]    = _OLC Key_CAPS_LOCK;

			return _OLC rcode::OK;
		}

		virtual _OLC rcode SetWindowTitle(const _STD string& s) override
		{
			X11::XStoreName(olc_Display, olc_Window, s.c_str());
			return _OLC rcode::OK;
		}

		virtual _OLC rcode StartSystemEventLoop() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode HandleSystemEvent() override
		{
			using namespace X11;
			// Handle Xlib Message Loop - we do this in the
			// same thread that OpenGL was created so we dont
			// need to worry too much about multithreading with X11
			XEvent xev;
			while (XPending(olc_Display))
			{
				XNextEvent(olc_Display, &xev);
				if (xev.type == Expose)
				{
					XWindowAttributes gwa;
					XGetWindowAttributes(olc_Display, olc_Window, &gwa);
					ptrPGE->olc_UpdateWindowSize(gwa.width, gwa.height);
				}
				else if (xev.type == ConfigureNotify)
				{
					XConfigureEvent xce = xev.xconfigure;
					ptrPGE->olc_UpdateWindowSize(xce.width, xce.height);
				}
				else if (xev.type == KeyPress)
				{
					KeySym sym = XLookupKeysym(&xev.xkey, 0);
					ptrPGE->olc_UpdateKeyState(mapKeys[sym], true);
					XKeyEvent* e = (XKeyEvent*)&xev; // Because DragonEye loves numpads
					XLookupString(e, NULL, 0, &sym, NULL);
					ptrPGE->olc_UpdateKeyState(mapKeys[sym], true);
				}
				else if (xev.type == KeyRelease)
				{
					KeySym sym = XLookupKeysym(&xev.xkey, 0);
					ptrPGE->olc_UpdateKeyState(mapKeys[sym], false);
					XKeyEvent* e = (XKeyEvent*)&xev;
					XLookupString(e, NULL, 0, &sym, NULL);
					ptrPGE->olc_UpdateKeyState(mapKeys[sym], false);
				}
				else if (xev.type == ButtonPress)
				{
					switch (xev.xbutton.button)
					{
						case 1:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, true); break;
						case 2:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, true); break;
						case 3:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, true); break;
						case 4:	ptrPGE->olc_UpdateMouseWheel(120); break;
						case 5:	ptrPGE->olc_UpdateMouseWheel(-120); break;
						default: break;
					}
				}
				else if (xev.type == ButtonRelease)
				{
					switch (xev.xbutton.button)
					{
						case 1:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, false); break;
						case 2:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, false); break;
						case 3:	ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, false); break;
						default: break;
					}
				}
				else if (xev.type == MotionNotify)
				{
					ptrPGE->olc_UpdateMouse(xev.xmotion.x, xev.xmotion.y);
				}
				else if (xev.type == FocusIn)
				{
					ptrPGE->olc_UpdateKeyFocus(true);
				}
				else if (xev.type == FocusOut)
				{
					ptrPGE->olc_UpdateKeyFocus(false);
				}
				else if (xev.type == ClientMessage)
				{
					ptrPGE->olc_Terminate();
				}
			}
			return _OLC rcode::OK;
		}
	};
}
#endif
// O-----------------------------------------------------------------------------O
// | END PLATFORM: LINUX                                                         |
// O-----------------------------------------------------------------------------O
#pragma endregion

// O-----------------------------------------------------------------------------O
// | START PLATFORM: Emscripten - Totally Game Changing...                       |
// O-----------------------------------------------------------------------------O
#pragma region platform_emscripten
//	Firstly a big mega thank you to members of the OLC Community for sorting this 
//	out. Making a browser compatible version has been a priority for quite some
//	time, but I lacked the expertise to do it. This awesome feature is possible
//	because a group of former strangers got together and formed friendships over
//	their shared passion for code. If anything demonstrates how powerful helping
//	each other can be, it's this. - Javidx9

//	Emscripten Platform: MaGetzUb, Moros1138, Slavka, Dandistine, Gorbit99, Bispoo
//				   also: Ishidex, Gusgo99, SlicEnDicE, Alexio


#ifdef OLC_PLATFORM_EMSCRIPTEN

#include <emscripten/html5.h>
#include <emscripten/key_codes.h>

extern "C" 
{
	EMSCRIPTEN_KEEPALIVE inline int olc_OnPageUnload()
	{
		_OLC platform->ApplicationCleanUp();
		return 0;
	}
}

namespace olc
{
	class Platform_Emscripten : public _OLC Platform
	{
	public:
		virtual _OLC rcode ApplicationStartUp() override 
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ApplicationCleanUp() override 
		{
			ThreadCleanUp();
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadStartUp() override
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode ThreadCleanUp() override
		{
			renderer->DestroyDevice();
			return _OLC rcode::OK;
		}

		virtual _OLC rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC, const _OLC vi2d& vViewPos, const _OLC vi2d& vViewSize) override
		{
			if (renderer->CreateDevice({}, bFullScreen, bEnableVSYNC) == _OLC rcode::OK)
			{
				renderer->UpdateViewport(vViewPos, vViewSize);
				return _OLC rcode::OK;
			}
			return _OLC rcode::FAIL;
		}

		virtual _OLC rcode CreateWindowPane(const _OLC vi2d& vWindowPos, _OLC vi2d& vWindowSize, bool bFullScreen) override
		{
			emscripten_set_canvas_element_size("#canvas", vWindowSize.x, vWindowSize.y);

			mapKeys[DOM_PK_UNKNOWN] = _OLC Key_NONE;
			mapKeys[DOM_PK_A]  = _OLC Key_A;  mapKeys[DOM_PK_B] = _OLC Key_B; mapKeys[DOM_PK_C]  = _OLC Key_C; mapKeys[DOM_PK_D] = _OLC Key_D;
			mapKeys[DOM_PK_E]  = _OLC Key_E;  mapKeys[DOM_PK_F] = _OLC Key_F; mapKeys[DOM_PK_G]  = _OLC Key_G; mapKeys[DOM_PK_H] = _OLC Key_H;
			mapKeys[DOM_PK_I]  = _OLC Key_I;  mapKeys[DOM_PK_J] = _OLC Key_J; mapKeys[DOM_PK_K]  = _OLC Key_K; mapKeys[DOM_PK_L] = _OLC Key_L;
			mapKeys[DOM_PK_M]  = _OLC Key_M;  mapKeys[DOM_PK_N] = _OLC Key_N; mapKeys[DOM_PK_O]  = _OLC Key_O; mapKeys[DOM_PK_P] = _OLC Key_P;
			mapKeys[DOM_PK_Q]  = _OLC Key_Q;  mapKeys[DOM_PK_R] = _OLC Key_R; mapKeys[DOM_PK_S]  = _OLC Key_S; mapKeys[DOM_PK_T] = _OLC Key_T;
			mapKeys[DOM_PK_U]  = _OLC Key_U;  mapKeys[DOM_PK_V] = _OLC Key_V; mapKeys[DOM_PK_W]  = _OLC Key_W; mapKeys[DOM_PK_X] = _OLC Key_X;
			mapKeys[DOM_PK_Y]  = _OLC Key_Y;  mapKeys[DOM_PK_Z] = _OLC Key_Z;
			mapKeys[DOM_PK_0]  = _OLC Key_K0; mapKeys[DOM_PK_1] = _OLC Key_K1; mapKeys[DOM_PK_2] = _OLC Key_K2;
			mapKeys[DOM_PK_3]  = _OLC Key_K3; mapKeys[DOM_PK_4] = _OLC Key_K4; mapKeys[DOM_PK_5] = _OLC Key_K5;
			mapKeys[DOM_PK_6]  = _OLC Key_K6; mapKeys[DOM_PK_7] = _OLC Key_K7; mapKeys[DOM_PK_8] = _OLC Key_K8;
			mapKeys[DOM_PK_9]  = _OLC Key_K9;
			mapKeys[DOM_PK_F1] = _OLC Key_F1; mapKeys[DOM_PK_F2] = Key_F2; mapKeys[DOM_PK_F3] = Key_F3; mapKeys[DOM_PK_F4] = Key_F4;
			mapKeys[DOM_PK_F5] = _OLC Key_F5; mapKeys[DOM_PK_F6] = Key_F6; mapKeys[DOM_PK_F7] = Key_F7; mapKeys[DOM_PK_F8] = Key_F8;
			mapKeys[DOM_PK_F9] = _OLC Key_F9; mapKeys[DOM_PK_F10] = Key_F10; mapKeys[DOM_PK_F11] = Key_F11; mapKeys[DOM_PK_F12] = Key_F12;
			mapKeys[DOM_PK_ARROW_UP]        = _OLC Key_UP;    mapKeys[DOM_PK_ARROW_DOWN]    = _OLC Key_DOWN;
			mapKeys[DOM_PK_ARROW_LEFT]      = _OLC Key_LEFT;  mapKeys[DOM_PK_ARROW_RIGHT]   = _OLC Key_RIGHT;
			mapKeys[DOM_PK_SPACE]           = _OLC Key_SPACE; mapKeys[DOM_PK_TAB]           = _OLC Key_TAB;
			mapKeys[DOM_PK_SHIFT_LEFT]      = _OLC Key_SHIFT; mapKeys[DOM_PK_SHIFT_RIGHT]   = _OLC Key_SHIFT;
			mapKeys[DOM_PK_CONTROL_LEFT]    = _OLC Key_CTRL;  mapKeys[DOM_PK_CONTROL_RIGHT] = _OLC Key_CTRL;
			mapKeys[DOM_PK_INSERT]          = _OLC Key_INS;   mapKeys[DOM_PK_DELETE]        = _OLC Key_DEL;  mapKeys[DOM_PK_HOME]      = _OLC Key_HOME;
			mapKeys[DOM_PK_END]             = _OLC Key_END;   mapKeys[DOM_PK_PAGE_UP]       = _OLC Key_PGUP; mapKeys[DOM_PK_PAGE_DOWN] = _OLC Key_PGDN;
			mapKeys[DOM_PK_BACKSPACE]       = _OLC Key_BACK;  mapKeys[DOM_PK_ESCAPE]        = _OLC Key_ESCAPE;
			mapKeys[DOM_PK_ENTER]           = _OLC Key_ENTER; mapKeys[DOM_PK_NUMPAD_EQUAL]  = _OLC Key_EQUALS;
			mapKeys[DOM_PK_NUMPAD_ENTER]    = _OLC Key_ENTER; mapKeys[DOM_PK_PAUSE]         = _OLC Key_PAUSE;
			mapKeys[DOM_PK_SCROLL_LOCK]     = _OLC Key_SCROLL;
			mapKeys[DOM_PK_NUMPAD_0]        = _OLC Key_NP0; mapKeys[DOM_PK_NUMPAD_1] = _OLC Key_NP1; mapKeys[DOM_PK_NUMPAD_2] = _OLC Key_NP2;
			mapKeys[DOM_PK_NUMPAD_3]        = _OLC Key_NP3; mapKeys[DOM_PK_NUMPAD_4] = _OLC Key_NP4; mapKeys[DOM_PK_NUMPAD_5] = _OLC Key_NP5;
			mapKeys[DOM_PK_NUMPAD_6]        = _OLC Key_NP6; mapKeys[DOM_PK_NUMPAD_7] = _OLC Key_NP7; mapKeys[DOM_PK_NUMPAD_8] = _OLC Key_NP8;
			mapKeys[DOM_PK_NUMPAD_9]        = _OLC Key_NP9;
			mapKeys[DOM_PK_NUMPAD_MULTIPLY] = _OLC Key_NP_MUL; mapKeys[DOM_PK_NUMPAD_DIVIDE]   = _OLC Key_NP_DIV;
			mapKeys[DOM_PK_NUMPAD_ADD]      = _OLC Key_NP_ADD; mapKeys[DOM_PK_NUMPAD_SUBTRACT] = _OLC Key_NP_SUB;
			mapKeys[DOM_PK_NUMPAD_DECIMAL]  = _OLC Key_NP_DECIMAL;
			mapKeys[DOM_PK_PERIOD]          = _OLC Key_PERIOD; mapKeys[DOM_PK_EQUAL] = _OLC Key_EQUALS;
			mapKeys[DOM_PK_COMMA]           = _OLC Key_COMMA;  mapKeys[DOM_PK_MINUS] = _OLC Key_MINUS;
			mapKeys[DOM_PK_CAPS_LOCK]       = _OLC Key_CAPS_LOCK;
			mapKeys[DOM_PK_SEMICOLON]       = _OLC Key_OEM_1; mapKeys[DOM_PK_SLASH]     = _OLC Key_OEM_2; mapKeys[DOM_PK_BACKQUOTE]     = _OLC Key_OEM_3;
			mapKeys[DOM_PK_BRACKET_LEFT]    = _OLC Key_OEM_4; mapKeys[DOM_PK_BACKSLASH] = _OLC Key_OEM_5; mapKeys[DOM_PK_BRACKET_RIGHT] = _OLC Key_OEM_6;
			mapKeys[DOM_PK_QUOTE]           = _OLC Key_OEM_7; mapKeys[DOM_PK_BACKSLASH] = _OLC Key_OEM_8;

			// Keyboard Callbacks
			emscripten_set_keydown_callback("#canvas", 0, 1, keyboard_callback);
			emscripten_set_keyup_callback("#canvas", 0, 1, keyboard_callback);

			// Mouse Callbacks
			emscripten_set_wheel_callback("#canvas", 0, 1, wheel_callback);
			emscripten_set_mousedown_callback("#canvas", 0, 1, mouse_callback);
			emscripten_set_mouseup_callback("#canvas", 0, 1, mouse_callback);
			emscripten_set_mousemove_callback("#canvas", 0, 1, mouse_callback);

			// Touch Callbacks
			emscripten_set_touchstart_callback("#canvas", 0, 1, touch_callback);
			emscripten_set_touchmove_callback("#canvas", 0, 1, touch_callback);
			emscripten_set_touchend_callback("#canvas", 0, 1, touch_callback);

			// Canvas Focus Callbacks
			emscripten_set_blur_callback("#canvas", 0, 1, focus_callback);
			emscripten_set_focus_callback("#canvas", 0, 1, focus_callback);
			
#pragma warning disable format
			EM_ASM( window.onunload = Module._olc_OnPageUnload; );

			// IMPORTANT! - Sorry About This...
			//
			//	In order to handle certain browser based events, such as resizing and
			//	going to full screen, we have to effectively inject code into the container
			//	running the PGE. Yes, I vomited about 11 times too when the others were
			//	convincing me this is the future. Well, this isnt the future, and if it
			//	were to be, I want no part of what must be a miserable distopian free
			//	for all of anarchic code injection to get rudimentary events like "Resize()".
			//
			//	Wake up people! Of course theres a spoon. There has to be to keep feeding
			//	the giant web baby.


			// Fullscreen and Resize Observers
			EM_ASM({

			// cache for reuse
			Module._olc_EmscriptenShellCss = "width: 100%; height: 70vh; margin-left: auto; margin-right: auto;";

			// width / height = aspect ratio
			Module._olc_WindowAspectRatio = $0 / $1;
			Module.canvas.parentNode.addEventListener("resize", function(e)
			{
				if (e.defaultPrevented)
				{
					e.stopPropagation();
					return;
				}
				var viewWidth = e.detail.width;
				var viewHeight = e.detail.width / Module._olc_WindowAspectRatio;
				if (viewHeight > e.detail.height)
				{
					viewHeight = e.detail.height;
					viewWidth = e.detail.height * Module._olc_WindowAspectRatio;
				}
					
				if (Module.canvas.parentNode.className == 'emscripten_border')
					Module.canvas.parentNode.style.cssText = Module._olc_EmscriptenShellCss + " width: " + viewWidth.toString() + "px; height: " + viewHeight.toString() + "px;";

				Module.canvas.setAttribute("width", viewWidth);
				Module.canvas.setAttribute("height", viewHeight);

				if (document.fullscreenElement != null)
				{						
					var top = (e.detail.height - viewHeight) / 2;
					var left = (e.detail.width - viewWidth) / 2;
					Module.canvas.style.position = "fixed";
					Module.canvas.style.top = top.toString() + "px";
					Module.canvas.style.left = left.toString() + "px";
					Module.canvas.style.width = "";
					Module.canvas.style.height = "";
				}

				// trigger PGE update
				Module._olc_PGE_UpdateWindowSize(viewWidth, viewHeight);
				// this is really only needed when enter/exiting fullscreen
				Module.canvas.focus();
				// prevent this event from ever affecting the document beyond this element
				e.stopPropagation();
			});

			// helper function to prevent repeating the same code everywhere
			Module._olc_ResizeCanvas = function()
			{
				// yes, we still have to wait, sigh..
				setTimeout(function()
				{
					// if default template, stretch width as well
					if (Module.canvas.parentNode.className == 'emscripten_border')
						Module.canvas.parentNode.style.cssText = Module._olc_EmscriptenShellCss;

					// override it's styling so we can get it's stretched size
					Module.canvas.style.cssText = "width: 100%; height: 100%; outline: none;";

					// setup custom resize event
					var resizeEvent = new CustomEvent('resize', 
					{
						detail:
						{
							width : Module.canvas.clientWidth,
							height : Module.canvas.clientHeight
						},
						bubbles : true,
						cancelable : true
					});

					// trigger custom resize event on canvas element
					Module.canvas.dispatchEvent(resizeEvent);
				}, 50);
			};


			// Disable Refresh Gesture on mobile
			document.body.style.cssText += " overscroll-behavior-y: contain;";

			if (Module.canvas.parentNode.className == 'emscripten_border')
			{
				// force body to have no margin in emscripten's minimal shell
				document.body.style.margin = "0";
				Module.canvas.parentNode.style.cssText = Module._olc_EmscriptenShellCss;
			}

			Module._olc_ResizeCanvas();

			// observe and react to resizing of the container element
			var resizeObserver = new ResizeObserver(function(entries) { Module._olc_ResizeCanvas(); }).observe(Module.canvas.parentNode);

			// observe and react to changes that occur when entering/exiting fullscreen
			var mutationObserver = new MutationObserver(function(mutationsList, observer)
			{
				// a change has occurred, let's check them out!
				for (var i = 0; i < mutationsList.length; i++)
				{
					// cycle through all of the newly added elements
					for (var j = 0; j < mutationsList[i].addedNodes.length; j++)
					{
						// if this element is a our canvas, trigger resize
						if (mutationsList[i].addedNodes[j].id == 'canvas')
							Module._olc_ResizeCanvas();
					}
				}
			}).observe(Module.canvas.parentNode, 
			{
				attributes: false,
				childList : true,
				subtree : false
			});

			// add resize listener on window
			window.addEventListener("resize", function(e) { Module._olc_ResizeCanvas(); });

			}, vWindowSize.x, vWindowSize.y); // Fullscreen and Resize Observers
#pragma warning restore format
			return _OLC rcode::OK;
		}

		// Interface PGE's UpdateWindowSize, for use in Javascript
		void UpdateWindowSize(int width, int height)
		{
			ptrPGE->olc_UpdateWindowSize(width, height);
		}

		//TY Gorbit
		static EM_BOOL focus_callback(int eventType, const EmscriptenFocusEvent* focusEvent, void* userData) 
		{
			if (eventType == EMSCRIPTEN_EVENT_BLUR)
			{
				ptrPGE->olc_UpdateKeyFocus(false);
				ptrPGE->olc_UpdateMouseFocus(false);
			}
			else if (eventType == EMSCRIPTEN_EVENT_FOCUS)
			{
				ptrPGE->olc_UpdateKeyFocus(true);
				ptrPGE->olc_UpdateMouseFocus(true);
			}

			return 0;
		}

		//TY Moros
		static EM_BOOL keyboard_callback(int eventType, const EmscriptenKeyboardEvent* e, void* userData)
		{
			if (eventType == EMSCRIPTEN_EVENT_KEYDOWN)
				ptrPGE->olc_UpdateKeyState(mapKeys[emscripten_compute_dom_pk_code(e->code)], true);

			// THANK GOD!! for this compute function. And thanks Dandistine for pointing it out!
			if (eventType == EMSCRIPTEN_EVENT_KEYUP)
				ptrPGE->olc_UpdateKeyState(mapKeys[emscripten_compute_dom_pk_code(e->code)], false);

			// Consume keyboard events so that keys like F1 and F5 don't do weird things
			return EM_TRUE;
		}

		//TY Moros
		static EM_BOOL wheel_callback(int eventType, const EmscriptenWheelEvent* e, void* userData)
		{
			if (eventType == EMSCRIPTEN_EVENT_WHEEL)
				ptrPGE->olc_UpdateMouseWheel(-1 * e->deltaY);

			return EM_TRUE;
		}

		//TY Bispoo
		static EM_BOOL touch_callback(int eventType, const EmscriptenTouchEvent* e, void* userData)
		{
			// Move
			if (eventType == EMSCRIPTEN_EVENT_TOUCHMOVE)
				ptrPGE->olc_UpdateMouse(e->touches->targetX, e->touches->targetY);

			// Start
			if (eventType == EMSCRIPTEN_EVENT_TOUCHSTART)
			{
				ptrPGE->olc_UpdateMouse(e->touches->targetX, e->touches->targetY);
				ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, true);
			}

			// End
			if (eventType == EMSCRIPTEN_EVENT_TOUCHEND)
				ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, false);

			return EM_TRUE;
		}

		//TY Moros
		static EM_BOOL mouse_callback(int eventType, const EmscriptenMouseEvent* e, void* userData)
		{
			//Mouse Movement
			if (eventType == EMSCRIPTEN_EVENT_MOUSEMOVE)
				ptrPGE->olc_UpdateMouse(e->targetX, e->targetY);


			//Mouse button press
			if (e->button == 0) // left click
			{
				if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, true);
				else if (eventType == EMSCRIPTEN_EVENT_MOUSEUP)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_LEFT, false);
			}

			if (e->button == 2) // right click
			{
				if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, true);
				else if (eventType == EMSCRIPTEN_EVENT_MOUSEUP)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_RIGHT, false);

			}

			if (e->button == 1) // middle click
			{
				if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, true);
				else if (eventType == EMSCRIPTEN_EVENT_MOUSEUP)
					ptrPGE->olc_UpdateMouseState(_OLC MouseButton_MIDDLE, false);

				// at the moment only middle mouse needs to consume events.
				return EM_TRUE;
			}

			return EM_FALSE;
		}


		virtual _OLC rcode SetWindowTitle(const _STD string& s) override
		{
			emscripten_set_window_title(s.c_str());
			return _OLC rcode::OK;
		}

		virtual _OLC rcode StartSystemEventLoop() override 
		{
			return _OLC rcode::OK;
		}

		virtual _OLC rcode HandleSystemEvent() override
		{
			return _OLC rcode::OK;
		}

		static void MainLoop()
		{
			_OLC Platform::ptrPGE->olc_CoreUpdate();
			if (!ptrPGE->olc_IsRunning())
			{
				if (ptrPGE->OnUserDestroy())
				{
					emscripten_cancel_main_loop();
					platform->ApplicationCleanUp();
				}
				else
					ptrPGE->olc_Reanimate();
			}
		}
	};

	//Emscripten needs a special Start function
	//Much of this is usually done in EngineThread, but that isn't used here
	_OLC rcode PixelGameEngine::Start()
	{
		if (platform->ApplicationStartUp() != _OLC rcode::OK)
			return _OLC rcode::FAIL;

		// Construct the window
		if (platform->CreateWindowPane({ 30,30 }, vWindowSize, bFullScreen) != _OLC rcode::OK)
			return _OLC rcode::FAIL;
		olc_UpdateWindowSize(vWindowSize.x, vWindowSize.y);

		// Some implementations may form an event loop here
		if (platform->ThreadStartUp() == _OLC rcode::FAIL)
			return _OLC rcode::FAIL;

		// Do engine context specific initialisation
		olc_PrepareEngine();

		// Consider the "thread" started
		bAtomActive = true;

		// Create user resources as part of this thread
		for (auto& ext : vExtensions)
			ext->OnBeforeUserCreate();
		if (!OnUserCreate())
			bAtomActive = false;
		for (auto& ext : vExtensions)
			ext->OnAfterUserCreate();

		platform->StartSystemEventLoop();

		//This causes a heap memory corruption in Emscripten for some reason
		//Platform_Emscripten::bActiveRef = &bAtomActive;
		emscripten_set_main_loop(&Platform_Emscripten::MainLoop, 0, 1);

		// Wait for thread to be exited
		if (platform->ApplicationCleanUp() != _OLC rcode::OK)
			return _OLC rcode::FAIL;
		return _OLC rcode::OK;
	}
}

extern "C" 
{
	EMSCRIPTEN_KEEPALIVE inline void olc_PGE_UpdateWindowSize(int width, int height)
	{
		emscripten_set_canvas_element_size("#canvas", width, height);
		// Thanks slavka
		((_OLC Platform_Emscripten*)_OLC platform.get())->UpdateWindowSize(width, height);
	}
}

#endif
// O-----------------------------------------------------------------------------O
// | END PLATFORM: Emscripten                                                    |
// O-----------------------------------------------------------------------------O
#pragma endregion


#endif // OLC_PGE_HEADLESS

// O-----------------------------------------------------------------------------O
// | olcPixelGameEngine Auto-Configuration                                       |
// O-----------------------------------------------------------------------------O
#pragma region pge_config
namespace olc
{
	void PixelGameEngine::olc_ConfigureSystem()
	{
#ifndef OLC_PGE_HEADLESS


#ifdef OLC_GFX_OPENGL10
		renderer = _STD make_unique<_OLC Renderer_OGL10>();
#endif
#ifdef OLC_GFX_OPENGL33
		renderer = _STD make_unique<_OLC Renderer_OGL33>();
#endif
#ifdef OLC_GFX_OPENGLES2
		renderer = _STD make_unique<_OLC Renderer_OGLES2>();
#endif
#ifdef OLC_GFX_DIRECTX10
		renderer = _STD make_unique<_OLC Renderer_DX10>();
#endif
#ifdef OLC_GFX_DIRECTX11
		renderer = _STD make_unique<_OLC Renderer_DX11>();
#endif
#ifdef OLC_GFX_CUSTOM_EX
		renderer = _STD make_unique<OLC_RENDERER_CUSTOM_EX>();
#endif


#ifdef OLC_IMAGE_STB
		_OLC Sprite::loader = _STD make_unique<_OLC ImageLoader_STB>();
#endif
#ifdef OLC_IMAGE_CUSTOM_EX
		_OLC Sprite::loader = _STD make_unique<OLC_IMAGE_CUSTOM_EX>();
#endif


#ifdef OLC_PLATFORM_WINAPI
		platform = _STD make_unique<_OLC Platform_Windows>();
#endif
#ifdef OLC_PLATFORM_X11
		platform = _STD make_unique<_OLC Platform_Linux>();
#endif
#ifdef OLC_PLATFORM_EMSCRIPTEN
		platform = _STD make_unique<_OLC Platform_Emscripten>();
#endif
#ifdef OLC_PLATFORM_CUSTOM_EX
		platform = _STD make_unique<OLC_PLATFORM_CUSTOM_EX>();
#endif


		// Associate components with PGE instance
		renderer->ptrPGE = this;
		platform->ptrPGE = this;
#else
		renderer = nullptr;
		_OLC Sprite::loader = nullptr;
		platform = nullptr;
#endif
	}
}

#pragma endregion

#endif // OLC_PGE_APPLICATION

// O-----------------------------------------------------------------------------O
// | END OF OLC_PGE_APPLICATION                                                  |
// O-----------------------------------------------------------------------------O

