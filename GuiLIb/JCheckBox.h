#pragma once

#include "AbstractButton.h"
class JCheckBox :
    public AbstractButton
{
public:
    JCheckBox();
    JCheckBox(std::string title);
    void repaint();
    bool isChecked();
    void flip();
    void onClick() override;
protected:
    bool checked_ = false;
};

