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
	//void setParent(Screen*);		// ��ũ�� ��ü �����͸� �����ϴ� �Լ�
	void onClick() override;			// ��ư Ŭ���Ǹ� �ڵ� ȣ��Ǵ� �Լ�

protected:

};

