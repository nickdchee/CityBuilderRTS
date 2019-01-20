#include "RightPanel.h"
#include "Button.h"

RightPanel::RightPanel(string _panelName) : Panel(_panelName)
{
	initValues();
}

void RightPanel::initValues()
{
	buttonScaledPositions.push_back(ofVec2f(0.73046875, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.796875, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.86328125, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.9296875, 0.03703704));

	buttonScaledPositions.push_back(ofVec2f(0.73046875, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.796875, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.86328125, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.9296875, 0.35185185));

	buttonScaledPositions.push_back(ofVec2f(0.73046875, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.796875, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.86328125, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.9296875, 0.666666));

	max_panel_count = buttonScaledPositions.size();
}