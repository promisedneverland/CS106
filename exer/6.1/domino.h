class domino {
public:
    domino(int leftDots = 0, int rightDots = 0) {
        this->leftDots = leftDots;
        this->rightDots = rightDots;
    }
    std::string toString() {
        return std::to_string(leftDots) + " " + std::to_string(rightDots);
    }
private:
    int leftDots, rightDots;
};