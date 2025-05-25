#pragma once
#include "Screen.h"
#include "MyRect.h"
#include "MyOval.h"
#include "JButton.h"
class PainterScreen :
    public Screen
{
public:
    PainterScreen();
    PainterScreen(std::wstring, int, int);

	// override�ϴ� �Լ���.
	void initialize() override;
	void onLButtonDown(MyEvent e) override;
	void onLButtonUp(MyEvent e) override;
	void repaint() override;

    void setFigType(JButton*);
	void setGrid(bool);
	
private:
	Figure* myfigure[100];
	int numRect = 0;
	// �ӽ� ����
	int startx, starty, endx, endy;
	int figType_ = 0;

	//
	bool gridOn_ = false;
};

