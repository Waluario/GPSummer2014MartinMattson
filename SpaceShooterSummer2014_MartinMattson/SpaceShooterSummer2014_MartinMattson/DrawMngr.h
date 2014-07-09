// DrawMngr.h //

#pragma once

class Sprite;

class DrawMngr {
public:
	DrawMngr(sf::RenderWindow *m_xpScreen);
	~DrawMngr();

	static void DrawSprite(Sprite *p_xpSprite);
	static void DrawText(sf::Text *p_xpText);
	static void DrawTexture(sf::Texture *p_xpTexture);
	static void Draw(sf::Drawable *p_xpDrawable);

	static void Present();
	static void Clear();

	void SetScreen(sf::RenderWindow *p_xpScreen);
	static sf::RenderWindow* GetScreen();

private:
	static sf::RenderWindow *m_xpScreen;
};