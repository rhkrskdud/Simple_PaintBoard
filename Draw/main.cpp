
#include "PainterScreen.h"
#include <iostream>
#include <exception>



// ????? ????(static)?? ???????.
Screen * Screen::mainScreen = new PainterScreen(L"???????2023", 1000, 800);

int main() {
	try {
		Screen::mainScreen->initialize();
		Screen::mainScreen->eventLoop();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
