#pragma once
#include "Windows.h"

// ȭ����� ���� ��Ÿ���� Ŭ����.
struct MyPoint {
	int x_, y_;
	MyPoint(int x, int y);
	MyPoint();
};

// �̺�Ʈ�� Ŭ����ȭ �Ѵ�.
struct MyEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
public:
	MyEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDownEvent(); // �̺�Ʈ�� Left ��ư�� ������ �̺�Ʈ�ΰ�
	bool isLButtonUpEvent(); // Left ��ư�� ������ �̺�Ʈ�ΰ�
	bool isRButtonDownEvent();  // Right button
	bool isRButtonUpEvent();  // Right button

	bool isCtrlKeyDown();   // �̺�Ʈ�� ���� �� ctrlŰ�� ���� ���¿��°�
	bool isShiftKeyDown();  // �̺�Ʈ�� ���� �� ShiftŰ�� ���� ���¿��°�
	int getX();
	int getY();
	MyPoint getPoint();

};

