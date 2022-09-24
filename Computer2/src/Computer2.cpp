#include "Computer2.h"
#include "Computer/Assembler.h"

Computer2::Computer2() : olc::PixelGameEngine()
{
	sAppName = "Computer2";
}

bool Computer2::OnUserCreate()
{
	std::string testProgramSource;
	{
		std::ifstream testProgramFile("./test/test_program.asm");
		if (testProgramFile.is_open())
		{
			std::stringstream testProgramStream;
			testProgramStream << testProgramFile.rdbuf();
			testProgramFile.close();
			testProgramSource = testProgramStream.str();
		}
	}
	Assembler::Assemble(testProgramSource);

	return true;
}

bool Computer2::OnUserUpdate(float elapsedTime)
{
	return true;
}

bool Computer2::OnUserDestroy()
{
	return true;
}

int Main(int argc, char** argv)
{
	UNUSED(argc, argv);

	Computer2 app;

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
