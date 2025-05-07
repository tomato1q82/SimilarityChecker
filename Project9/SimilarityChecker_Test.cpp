#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"
#include <string>

using namespace std;

class SimularityCheckFixture : public testing::Test {
public:
	SimilarityChecker simchecker;
};

TEST_F(SimularityCheckFixture, lengthTest1) {
	string inputStringA = "ASD";
	string inputSTringB = "DSA";
	
	int actualScore = simchecker.getLengthAndScore(inputStringA, inputSTringB);
	int expectedScore = 60;

	EXPECT_EQ(actualScore, expectedScore);
}

TEST_F(SimularityCheckFixture, lengthTest2) {
	string inputStringA = "A";
	string inputSTringB = "BB";

	int actualScore = simchecker.getLengthAndScore(inputStringA, inputSTringB);
	int expectedScore = 0;

	EXPECT_EQ(actualScore, expectedScore);
}

TEST_F(SimularityCheckFixture, lengthTest3) {
	string inputStringA = "AAABB";
	string inputSTringB = "BAA";

	int actualScore = simchecker.getLengthAndScore(inputStringA, inputSTringB);
	int expectedScore = 20;

	EXPECT_EQ(actualScore, expectedScore);
}

TEST_F(SimularityCheckFixture, lengthTest4) {
	string inputStringA = "AA";
	string inputSTringB = "AAE";

	int actualScore = simchecker.getLengthAndScore(inputStringA, inputSTringB);
	int expectedScore = 30;

	EXPECT_EQ(actualScore, expectedScore);
}