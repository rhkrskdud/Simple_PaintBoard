#include "PainterScreen.h"
#include "FigureButton.h"
#include "JCheckBox.h"
#include "GridCheckBox.h"
PainterScreen::PainterScreen() :Screen(L"", 800, 600) {
	// ���� ������ �ʰ� ����.
}

PainterScreen::PainterScreen(std::wstring title, int width, int height)
:Screen(){
	//:Screen(title, width, height) {
}

void PainterScreen::initialize() {
	// ������ �� ���� ����.
	JButton* jb1 = new FigureButton("�簢��");
	this->add(jb1); jb1->setBounds(10, 10, 100, 25);
	JButton* jb2 = new FigureButton("Ÿ��");
	add(jb2); jb2->setBounds(120, 10, 100, 25);
	JCheckBox* cb = new GridCheckBox("�׸���");
	add(cb); cb->setBounds(240, 10, 100, 25);
}

void PainterScreen::setFigType(JButton* jb) {
	if (jb->getActionString() == "�簢��")
		figType_ = 1;
	else if (jb->getActionString() == "Ÿ��")
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