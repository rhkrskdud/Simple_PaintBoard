#pragma once
#include <string>
class Screen;
class AbstractButton
{
public:
	AbstractButton();
	AbstractButton(std::string title);

	// setBounds �Լ��� ��ġ�� ũ�⸦ �����ϴ� �Լ�.
	void setBounds(int x, int y, int width, int height);

	// setLocation �� ��ġ�� �����ϴ� �Լ�
	void setLocation(int x, int y);

	// setSize�� ũ�⸦ �����ϴ� �Լ�
	void setSize(int width, int height);
	virtual void repaint();
	void setParent(Screen *);		// ��ũ�� ��ü �����͸� �����ϴ� �Լ�
	virtual bool areYouThere(int x, int y);  // �ش� ��ġ�� ��ư�� �ִ��� �˷��ִ� �Լ�
	std::string getActionString();	// ��ư ����(��ɾ�� Ȱ��)�� �����ִ� �Լ�
	virtual void onClick() = 0;			// ��ư Ŭ���Ǹ� �ڵ� ȣ��Ǵ� �Լ�

protected:
	std::string title_;	// ��ư ����
	int x_, y_, width_, height_;
	Screen* parent_;
};



