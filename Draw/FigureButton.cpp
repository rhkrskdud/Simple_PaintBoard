#include "FigureButton.h"
#include "PainterScreen.h"
#include "Globals.h"

FigureButton::FigureButton() :JButton() {

}
FigureButton::FigureButton(std::string s) :JButton(s) {

}
void FigureButton::onClick() {
	JButton::onClick();
	debugPrint(title_ + " clicked.");
	((PainterScreen*)parent_)->setFigType(this);
}