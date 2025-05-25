#pragma once
#include "Windows.h"
#include <string>
class Graphics
{
public:
	Graphics(HDC);
	
	// �׸��� �Լ����� Java�� �׸��� �Լ��� �䳻�� ��.
	// 
	// �簢�� �׸���
	void drawRect(int x, int y, int width, int height);
	
	// Ÿ�� �׸���
	void drawOval(int x, int y, int width, int height);
	
	// ���� �׸���
	//void drawLine(int x1, int y1, int x2, int y2);
	
	// �ؽ�Ʈ �׸���
	void drawString(std::string s, int x, int y);
	
	// �� �� �����ϱ�
	//void setColor(Color c);

	// ������ �����ϱ�
	//void setFillColor(Color c);
private:
	HDC hDC_;
};

