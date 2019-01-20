#pragma once
#include "Panel.h"

class LeftPanel : public Panel
{
public:
	LeftPanel(string _panelName);
	void initValues() override;
};