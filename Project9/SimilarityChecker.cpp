#include <string>
#include <cstdlib> // for std::abs
using namespace std;

class SimilarityChecker {
public:
    int getLengthAndScore(string inputA, string inputB) {
        int lengthA = inputA.length();
        int lengthB = inputB.length();

        int gap = 0;
        int score = 0;

        if (lengthA == lengthB) {
            score = maxScore;
        }
        else if (lengthA > lengthB) {
            gap = (lengthA - lengthB) * 100 / lengthB;
            score = (100 - gap) * maxScore / 100;
        }
        else {
            gap = (lengthB - lengthA) * 100 / lengthA;
            score = (100 - gap) * maxScore / 100;
        }

        if (score < 0) score = 0;

        return score;
    }

private:
    const int maxScore = 60;
};