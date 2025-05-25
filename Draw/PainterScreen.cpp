#include "PainterScreen.h"
#include "FigureButton.h"
#include "JCheckBox.h"
#include "GridCheckBox.h"
PainterScreen::PainterScreen() :Screen(L"", 800, 600) {
	// 현재 사용되지 않고 있음.
}

PainterScreen::PainterScreen(std::wstring title, int width, int height)
:Screen(){
	//:Screen(title, width, height) {
}

void PainterScreen::initialize() {
	// 아직은 할 일이 없음.
	JButton* jb1 = new FigureButton("사각형");
	this->add(jb1); jb1->setBounds(10, 10, 100, 25);
	JButton* jb2 = new FigureButton("타원");
	add(jb2); jb2->setBounds(120, 10, 100, 25);
	JCheckBox* cb = new GridCheckBox("그리드");
	add(cb); cb->setBounds(240, 10, 100, 25);
}

void PainterScreen::setFigType(JButton* jb) {
	if (jb->getActionString() == "사각형")
		figType_ = 1;
	else if (jb->getActionString() == "타원")
		figType_ = 2;
}

void PainterScreen::onLButtonDown(MyEvent e)
{
	startx = e.getX();
	starty = e.getY();
}


void PainterScreen::onLButtonUp(MyEvent e)
{
	endx = e.getX();
	endy = e.getY();
	if (gridOn_) {
		startx = startx / 50 * 50;
		starty = starty / 50 * 50;
		endx = endx / 50 * 50;
		endy = endy / 50 * 50;
	}
	if (figType_ == 1) {
		myfigure[numRect++] = new MyRect(startx, starty, endx, endy, graphics_);
	}
	else if (figType_ == 2) {
		myfigure[numRect++] = new MyOval(startx, starty, endx, endy, graphics_);
	}
	invalidate();
}

void PainterScreen::repaint() {

	Screen::repaint();

	for (int i = 0; i < numRect; i++) {
		myfigure[i]->draw();
	}
}

void PainterScreen::setGrid(bool flag) {
	gridOn_ = flag;
}