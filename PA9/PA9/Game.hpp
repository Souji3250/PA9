#include <vector>
#include <memory>
#include <random>
#include "Card.hpp"

using std::vector;
using std::unique_ptr;
using sf::Clock;
using sf::RenderWindow;
using sf::Vector2f;

class Game
{
public:
	Game();
	//creates pairs of cards, shuffles them, and makes the game board
    void initialize_cards();
    //logic for choicing a pair of cards
    void handle_click(Vector2f mouse_pos);
    //handles the timing for flipping cards back
    void update();
    //displays cards to the window
    void draw(RenderWindow& window);
    //checks to see if all pairs have been found
    bool is_game_over() const;
    //for starting a new game
    void reset();

private:
    //vector to help store each card in the game
    vector<Card> m_cards;
    //pointers to track the players choices
    Card* m_first_choice;
    Card* m_second_choice;
    //counts how many pairs are found in the game
    int m_pairs_found;
    //storses the total pairs
    int m_total_pairs;
    //indicates waiting for cards to flip after a mismatch
    bool m_waiting_for_flip_back;
    //sfml clock to time card flips
    Clock m_flip_clock;
};
