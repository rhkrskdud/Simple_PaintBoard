#include "JCheckBox.h"
#include "Screen.h"
JCheckBox::JCheckBox()
	:AbstractButton()
{
	//
}
JCheckBox::JCheckBox(std::string title)
	:AbstractButton(title)
{

}

void JCheckBox::repaint() {
	if (parent_ == nullptr) return;
	parent_->getGraphics()->drawRect(x_, y_, width_, height_);
	if (checked_)
		parent_->getGraphics()->drawString("[v] ", x_ + 5, y_ + 5);
	else
		parent_->getGraphics()->drawString("[ ] ", x_ + 5, y_ + 5);
	parent_->getGraphics()->drawString(title_, x_ + 25, y_ + 5);
}

bool JCheckBox::isChecked() {
	return checked_;
}

void JCheckBox::flip() {
	checked_ = !checked_;
}

void JCheckBox::onClick() {
	flip();
	parent_->invalidate();
}
