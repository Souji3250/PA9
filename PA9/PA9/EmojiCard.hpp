#include "Card.hpp"

class EmojiCard : public Card
{
public:
	//position and vlaue of the card (value based on emoji)
	EmojiCard(float x, float y, int value);
	//creates face value of card
	void draw_face(sf::RenderWindow& e_window);

};