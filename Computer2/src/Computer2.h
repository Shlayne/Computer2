#pragma once

#include <olcPixelGameEngine.h>

int Main(int argc, char** argv);

class Computer2 : public olc::PixelGameEngine
{
public:
	Computer2();
protected:
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float elapsedTime) override;
	virtual bool OnUserDestroy() override;
private:

};
