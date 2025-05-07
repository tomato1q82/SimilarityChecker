#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SimilarityChecker {
public:
    int getLengthAndScore(const string inputA, const string inputB) const {
        int lengthA = inputA.length();
        int lengthB = inputB.length();

        int gap = 0;
        int score = 0;

        if (lengthA == lengthB) {
            score = maxLengthScore;
        }
        else if (lengthA > lengthB) {
            gap = (lengthA - lengthB) * 100 / lengthB;
            score = (100 - gap) * maxLengthScore / 100;
        }
        else {
            gap = (lengthB - lengthA) * 100 / lengthA;
            score = (100 - gap) * maxLengthScore / 100;
        }

        if (score < 0) score = 0;

        return score;
    }

    int CheckAlphabetAndScore(const string inputA, const string inputB) const {
        set<char> stringSetA(inputA.begin(), inputA.end());
        set<char> stringSetB(inputB.begin(), inputB.end());
        
        int score = 0;
        int totalCnt = 0;
        int sameCnt = 0;

        // sameCnt
        for (char ch : stringSetA) {
            if (stringSetB.count(ch)) {
                ++sameCnt;
            }
        }

        totalCnt = stringSetA.size() + stringSetB.size() - sameCnt;
        if (totalCnt == sameCnt)
        {
            score = maxAlphabetScore;
        }
        else
        {
            score = sameCnt * 40 / totalCnt;
        }
        return score;
    }

private:
    const static int maxLengthScore = 60;
    const static int maxAlphabetScore = 40;
    const static int minScore = 0;
};