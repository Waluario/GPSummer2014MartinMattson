// DrawMngr.h //

#pragma once

class Sprite;

class DrawMngr {
public:
	DrawMngr(sf::RenderWindow *m_xpScreen);
	~DrawMngr();

	static void DrawSprite(Sprite *p_xpSprite); // Specialized drawing method for Sprites, isn't used
	static void DrawText(sf::Text *p_xpText); // Specialized drawing method for Text, isn't used
	static void DrawTexture(sf::Texture *p_xpTexture); // Specialized drawing method for Textures, isn't used
	static void Draw(sf::Drawable *p_xpDrawable); // Draws any and all objects afflitated with the sf::Drawable class

	static void Present(); // Presents the drawn screen in-game
	static void Clear(); // Clears the drawn screen

	static void SetScreen(sf::RenderWindow *p_xpScreen); // Sets the RenderWindow
	static sf::RenderWindow* GetScreen(); // Sends the RenderWindow

private:
	static sf::RenderWindow *m_xpScreen;
};