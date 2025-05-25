#pragma once
#include "JButton.h"

class FigureButton :
    public JButton
{
public:
    FigureButton();
    FigureButton(std::string);
    void onClick() override;
};

