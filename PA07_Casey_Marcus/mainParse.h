#include <iostream>
#include <string>
#include <vector>
using namespace std;
class mainParse {
	public:
		mainParse(string fileName);
		int fastestWin(vector<vector<int>>);
		int fewestMoves(vector<vector<int>>);
		int topScore(vector<vector<int>>);
		size_t findOccurrence(string, int, size_t);
		float determineWinRate(int, int);
		void outputFile();
		void updateNum(string, int, size_t, int);
		void updatePlayer(string, vector<vector<int>>);
	private:
		string fileName;
};
