#pragma once
#include "AbstractButton.h"
#include <string>
class Screen;
class JButton: public AbstractButton //AbstractButton
{
public:
	JButton();
	JButton(std::string title);

	//void repaint();
	//void setParent(Screen*);		// 스크린 객체 포인터를 저장하는 함수
	void onClick() override;			// 버튼 클릭되면 자동 호출되는 함수

protected:

};

