#include "Toast.h"
#include <time.h>


Toast::Toast(string message, int windowHeight)
{
	msg = message;
	height = windowHeight;
	toastActive = true;
	start = time(0);
	displayFont.load("VCR_OSD_MONO_1.001.ttf", 20);

	update();
}	

void Toast::update() {
	while (toastActive){
		displayFont.drawString(msg, height/2, displayFont.getAscenderHeight());
		if (start > 3)
		{
			toastActive = false;
		}

	}
}

Toast::~Toast()
{
}
