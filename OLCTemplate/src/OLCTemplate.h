#pragma once

#include <olcPixelGameEngine.h>

int Main(int argc, char** argv);

class OLCTemplate : public olc::PixelGameEngine
{
public:
	OLCTemplate();
protected:
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float elapsedTime) override;
	virtual bool OnUserDestroy() override;
private:

};
