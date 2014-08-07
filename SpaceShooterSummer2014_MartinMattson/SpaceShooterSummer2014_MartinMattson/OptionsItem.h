// OptionsItem.h //

#pragma once

class OptionsItem {
public:
	virtual ~OptionsItem() {};

	virtual sf::Vector2f GetPosition() = 0;
	virtual void SetPosition(sf::Vector2f p_vPosition) = 0;

	virtual sf::Text* GetText() = 0;
	virtual void SetText(sf::Text *p_xpChoice) = 0;

	virtual void OnDraw() = 0;
	virtual void OnDrawWhenChosen() = 0;

	virtual void OnChosen() = 0;

	virtual bool CanMovePointer() = 0;
};