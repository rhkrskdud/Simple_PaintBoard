#pragma once
#include <string>
class Screen;
class AbstractButton
{
public:
	AbstractButton();
	AbstractButton(std::string title);

	// setBounds 함수는 위치와 크기를 설정하는 함수.
	void setBounds(int x, int y, int width, int height);

	// setLocation 은 위치를 결정하는 함수
	void setLocation(int x, int y);

	// setSize는 크기를 결정하는 함수
	void setSize(int width, int height);
	virtual void repaint();
	void setParent(Screen *);		// 스크린 객체 포인터를 저장하는 함수
	virtual bool areYouThere(int x, int y);  // 해당 위치에 버튼이 있는지 알려주는 함수
	std::string getActionString();	// 버튼 제목(명령어로 활용)을 돌려주는 함수
	virtual void onClick() = 0;			// 버튼 클릭되면 자동 호출되는 함수

protected:
	std::string title_;	// 버튼 제목
	int x_, y_, width_, height_;
	Screen* parent_;
};



