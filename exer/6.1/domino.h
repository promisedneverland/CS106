#ifndef __domino_h__
#define __domino_h__
#include<string>
class domino {
public:
    domino(int leftDots = 0, int rightDots = 0) {
        this->leftDots = leftDots;
        this->rightDots = rightDots;
    }
    std::string toString() {
        return std::to_string(leftDots) + " and " + std::to_string(rightDots);
    }
private:
    int leftDots, rightDots;
};

std::ostream& operator<<(std::ostream& os, domino d);
#endif