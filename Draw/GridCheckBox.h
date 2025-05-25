#pragma once
#include "JCheckBox.h"
class GridCheckBox :
    public JCheckBox
{
public:
    GridCheckBox();
    GridCheckBox(std::string title);
    void onClick() override;
};

