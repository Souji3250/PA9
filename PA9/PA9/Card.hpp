#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::FloatRect;
using sf::Color;

class Card 
{
public:
    //constructor
    Card(float x, float y, int value);
    //destructor
    virtual ~Card() = default;

    // Setters
    void setPosition(float x, float y);
    void setFaceUp(bool faceUp);
    void setMatched(bool matched);
    void setValue(int value);

    // Getters
    Vector2f getPosition() const;
    int getValue() const;
    bool getFaceUp() const;
    bool getMatched() const;
    FloatRect getBounds() const;

    virtual void draw(RenderWindow& window);
    virtual void drawCardFace(RenderWindow& window) = 0;
    bool contains(Vector2f point) const;

protected:
    //protected members that only the inherited classes can access
    RectangleShape mShape;
    bool mFaceUp;
    bool mMatched;
    int mValue;
    Vector2f mPosition;
};
