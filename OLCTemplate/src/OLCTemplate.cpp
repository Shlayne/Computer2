#include "OLCTemplate.h"

OLCTemplate::OLCTemplate() : olc::PixelGameEngine()
{
	sAppName = "OLCTemplate";
}

bool OLCTemplate::OnUserCreate()
{
	return true;
}

bool OLCTemplate::OnUserUpdate(float elapsedTime)
{
	return true;
}

bool OLCTemplate::OnUserDestroy()
{
	return true;
}

int Main(int argc, char** argv)
{
	UNUSED(argc, argv);

	OLCTemplate app;

	if (app.Construct(320, 200, 4, 4) != olc::rcode::OK) // (1280, 800) / 4 -> 16:10 aspect ratio
	{
		std::cerr << "Failed to create application.\n";
		return 1;
	}

	if (app.Start() != olc::rcode::OK)
	{
		std::cerr << "Failed to run application.\n";
		return 2;
	}

	return 0;
}
