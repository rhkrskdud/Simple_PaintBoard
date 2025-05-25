#include "AbstractButton.h"
#include "JButton.h"
#include "Globals.h"
#include "Screen.h"
AbstractButton::AbstractButton()
	:title_(""), x_(0), y_(0), width_(100), height_(25), parent_(nullptr)
{
	//
}
AbstractButton::AbstractButton(std::string title)
	:title_(title), x_(0), y_(0), width_(100), height_(25), parent_(nullptr)
{

}

void AbstractButton::setBounds(int x, int y, int width, int height) {
	setLocation(x, y);
	setSize(width, height);
}
void AbstractButton::setLocation(int x, int y) {
	x_ = x; y_ = y;
}
void AbstractButton::setSize(int width, int height) {
	width_ = width;
	height_ = height;
}
void AbstractButton::repaint() {
	if (parent_ == nullptr) return;
	parent_->getGraphics()->drawRect(x_, y_, width_, height_);
	parent_->getGraphics()->drawString(title_, x_ + 5, y_ + 5);
}
void AbstractButton::setParent(Screen* parent) {
	parent_ = parent;
}

bool AbstractButton::areYouThere(int x, int y) {
	return x_ <= x && x <= x_ + width_
		&& y_ <= y && y <= y_ + height_;
}

//void AbstractButton::onClick() {
	//
//}

std::string AbstractButton::getActionString() {
	return title_;
}
