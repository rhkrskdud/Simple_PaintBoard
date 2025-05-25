#include "Screen.h"
#include "Etc.h"
#include "JButton.h"
#include <iostream>



Screen::Screen() :Screen(L"����Ʈ", 800, 600) {
	// ���� ������ �ʰ� ����.
}

Screen::Screen(std::wstring title, int width, int height) {
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWin", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // ���� �ּ�ȭ �ִ�ȭ ������
		WS_THICKFRAME,  // resize�� �����ϰ�
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	graphics_ = new Graphics(hDC_);
	invalidate();
}


// run �Լ��� �����ϸ� ������.
void Screen::eventLoop() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

void Screen::initialize() {
	// �� ���� ����.
}

bool Screen::eventHandler(MyEvent e)
{
	// Stage 4. ���⿡ ��ư ã�� ����� �߰�
	

	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (e.isLButtonDownEvent()) {
		tempBtn = findButton(e);
		if (tempBtn == nullptr) {
			this->onLButtonDown(e);
		}
	}
	else if (e.isLButtonUpEvent()) {
		AbstractButton* jb = findButton(e);
		if (jb != nullptr && jb == tempBtn) {
			tempBtn->onClick();
		}
		else if (tempBtn == nullptr && jb == nullptr) {
			this->onLButtonUp(e);

		} 
		tempBtn = nullptr;
	}
	return false;
}

void Screen::repaint() {
	// �׷����� ��� ���� ���⿡. �Ʒ� ���� �����̴� �������Ѵ�.
	//getGraphics()->drawRect(100, 100, 200, 200);
	for (int i = 0; i < numButtons; i++) {
		button_[i]->repaint();
	}

}

void Screen::invalidate() {
	// �� �޼ҵ带 �θ��� ȭ���� �ٽ� �׸��� �ȴ�.
	InvalidateRect(hWnd_, nullptr, true);

	// �ٽ� ���ؼ� ȭ���� ������ ���� repaint�Լ��� �ٽ� ȣ��ȴ�.
}


Graphics * Screen::getGraphics() {
	return graphics_;
}

void Screen::onLButtonDown(MyEvent e)
{
	// Nothing
}


void Screen::onLButtonUp(MyEvent e)
{
	// Nothing
}

void Screen::add(AbstractButton* jb) {
	button_[numButtons++] = jb;
	jb->setParent(this);
}

AbstractButton* Screen::findButton(MyEvent e) {
	for (int i = 0; i < numButtons; i++) {
		if (button_[i]->areYouThere(e.getX(), e.getY())) {
			return button_[i];
		}
	}
	return nullptr;
}

