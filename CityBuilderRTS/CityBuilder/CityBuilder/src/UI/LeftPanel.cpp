#include "LeftPanel.h"
#include "Button.h"

LeftPanel::LeftPanel(string _panelName) : Panel(_panelName)
{
	initValues();
}

void LeftPanel::initValues()
{
	float diff = 0.72265625;
	buttonScaledPositions.push_back(ofVec2f(0.73046875 - diff, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.796875 - diff, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.86328125 - diff, 0.03703704));
	buttonScaledPositions.push_back(ofVec2f(0.9296875 - diff, 0.03703704));

	buttonScaledPositions.push_back(ofVec2f(0.73046875 - diff, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.796875 - diff, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.86328125 - diff, 0.35185185));
	buttonScaledPositions.push_back(ofVec2f(0.9296875 - diff, 0.35185185));

	buttonScaledPositions.push_back(ofVec2f(0.73046875 - diff, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.796875 - diff, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.86328125 - diff, 0.666666));
	buttonScaledPositions.push_back(ofVec2f(0.9296875 - diff, 0.666666));

	max_panel_count = buttonScaledPositions.size();
}