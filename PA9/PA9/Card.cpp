#include "Card.hpp"


Card::Card(float x, float y, int value): mPosition(x, y), mValue(value), mFaceUp(false), mMatched(false) 
{
    mShape.setSize(Vector2f(100, 150));//sets the size of the card
    mShape.setPosition(mPosition);//sets the position to whatever mPosition is 
    mShape.setFillColor(Color::Red);// sets the card color to red
    mShape.setOutlineThickness(2);//setting outline thickness
    mShape.setOutlineColor(Color::Black);//setting outline color
}

// Setters

//function for setting position
void Card::setPosition(float x, float y) 
{
    mPosition = { x, y };
    mShape.setPosition(mPosition);
}

//function for setting face up  boolean
void Card::setFaceUp(bool faceUp) 
{
    mFaceUp = faceUp;
}

//function for setting match boolean
void Card::setMatched(bool matched) 
{
    mMatched = matched;
    if (mMatched) //if card is matched then this loop will run
    {
        mShape.setFillColor(Color::Green);
    }
}
//function for setting card value
void Card::setValue(int value) 
{
    mValue = value;
}

// Getters

//function for getting the position
Vector2f Card::getPosition() const 
{
    return mPosition;
}

//function for getting the value
int Card::getValue() const 
{
    return mValue;
}

//function for getting the face up value
bool Card::getFaceUp() const 
{
    return mFaceUp;
}

//function for getting the mathced value 
bool Card::getMatched() const 
{
    return mMatched;
}

//function for getting the bounds of the card
FloatRect Card::getBounds() const 
{
    return mShape.getGlobalBounds();
}

//function for drawing the card 
void Card::draw(RenderWindow& window) 
{
    window.draw(mShape);
    if (mFaceUp) //if the card is face up it will run the loop
    {
        //if card is face up it will draw the card face
        drawCardFace(window);
    }
}

//function for getting the contaminents of the card
bool Card::contains(Vector2f point) const 
{
    return mShape.getGlobalBounds().contains(point);
}