#include "GridCheckBox.h"
#include "PainterScreen.h"
GridCheckBox::GridCheckBox()
	:JCheckBox()
{
	//
}
GridCheckBox::GridCheckBox(std::string title)
	:JCheckBox(title)
{

}

void GridCheckBox::onClick()
{
	JCheckBox::onClick();
	((PainterScreen*)parent_)->setGrid(this->checked_);
}