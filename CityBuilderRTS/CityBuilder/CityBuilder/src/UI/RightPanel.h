#pragma once
#include "Panel.h"

class RightPanel : public Panel
{
public:
	RightPanel(string _panelName);
	void initValues() override;
};