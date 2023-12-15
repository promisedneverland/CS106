#include"card.h"
#include<iostream>
using namespace std;
ostream& operator<<(ostream& os, Card d) {
    return os << d.toString();
}
Card::Card(std::string str) {
    rank = 0;
    suit = SPADES;
}
Card::Card(int rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
}
string toString(Suit suit) {
    return to_string(int(suit));
}
Suit operator++(Suit& suit, int) {
    Suit old = Suit(suit + 1);
    suit = old;
    return old;
}
string Card::toString(){
    return to_string(rank) + "+" + ::toString(suit);
}