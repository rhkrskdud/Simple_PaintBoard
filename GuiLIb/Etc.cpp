#include "Etc.h"
#include <iostream>

MyEvent::MyEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam) 
{
	//  Nothing to do here.
}

// �̺�Ʈ�� Left ��ư�� ������ �̺�Ʈ�ΰ�
bool MyEvent::isLButtonDownEvent() {
	return msg_ == WM_LBUTTONDOWN;
}

// Left ��ư�� ������ �̺�Ʈ�ΰ�
bool MyEvent::isLButtonUpEvent() {
	return msg_ == WM_LBUTTONUP;
}

// R ��ư�� ���� �̺�Ʈ�ΰ�
bool MyEvent::isRButtonDownEvent() {
	return msg_ == WM_RBUTTONDOWN;
}


bool MyEvent::isRButtonUpEvent() {
	return msg_ == WM_RBUTTONUP;
}

// �̺�Ʈ �߻��� ctrl Ű�� ������ �־��°�
bool MyEvent::isCtrlKeyDown() {
	return wParam_ & MK_CONTROL;
}

// �̺�Ʈ �߻��� Shift Ű�� ������ �־��°�
bool MyEvent::isShiftKeyDown() {
	return wParam_ & MK_SHIFT;
}

// (���콺) �̺�Ʈ�� �߻��� x ��ǥ�� ���Ѵ�.
int MyEvent::getX() {
	return LOWORD(lParam_);
}

// (���콺) �̺�Ʈ�� �߻��� y ��ǥ�� ���Ѵ�.
int MyEvent::getY() {
	return HIWORD(lParam_);
}


// (���콺) �̺�Ʈ�� �߻��� x,y ��ǥ ����ü�� �����´�.
MyPoint MyEvent::getPoint() {
	return MyPoint(LOWORD(lParam_), HIWORD(lParam_));
}

// MyPoint Ŭ���� �Լ���.
MyPoint::MyPoint(int x, int y): x_(x), y_(y){

}

MyPoint::MyPoint() : x_(0), y_(0) {

}

