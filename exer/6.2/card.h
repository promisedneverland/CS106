#ifndef CARD_H__
#define CARD_H__

#include<string>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
#define ACE 1
#define KING 13

Suit operator++(Suit& suit, int);


class Card {
public:
    Card(){}
    Card(std::string str);
    Card(int rank, Suit suit);

    std::string toString();
private:
    int rank;
    Suit suit;
};

std::ostream& operator<<(std::ostream& os, Card d);
#endif