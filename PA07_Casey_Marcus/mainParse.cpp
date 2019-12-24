// imports
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>
#include "mainParse.h"
using namespace std;

// main parse read in, fnc help from ECC
mainParse::mainParse(string fileName) {
	ifstream inputNameFile(fileName);
	string moveBuff((istreambuf_iterator<char>(inputNameFile)), istreambuf_iterator<char>());
	this->fileName = moveBuff;
}
// fewest moves
int mainParse::fewestMoves(vector<vector<int>> pStats) {
	int fewestMovesAmount = 9999;
	int amtThrough = 0;
	for(amtThrough = 0; amtThrough < 3; amtThrough++) {
		if(pStats[amtThrough][3] < fewestMovesAmount) {
			fewestMovesAmount = pStats[amtThrough][3];
		}
	}
	return fewestMovesAmount;
}
// top score
int mainParse::topScore(vector<vector<int>> pStats) {
	int topScoreAmount=0;
	int amtThrough=0;
	for(amtThrough=0; amtThrough<3; amtThrough++) {
		if(pStats[amtThrough][4]> topScoreAmount) {
			topScoreAmount=pStats[amtThrough][4];
		}
	}
	return topScoreAmount;
}
// fastest win
int mainParse::fastestWin(vector<vector<int> > pStats) {
	int fastestWinAmt=9999;
	int amtThrough=0;
	for(amtThrough=0; amtThrough<3; amtThrough++) {
		if(pStats[amtThrough][2]<fastestWinAmt) {
			fastestWinAmt=pStats[amtThrough][2];
		}
	}
	return fastestWinAmt;
}
// main occurence / buffer
size_t mainParse::findOccurrence(string inputName, int determineKth, size_t positionMain) {
	int amtThrough=0;
	size_t determineKthPos = positionMain;
	for(amtThrough=0; amtThrough < determineKth; amtThrough++) {
		determineKthPos = this->fileName.find(inputName, determineKthPos+1);
	}
	return determineKthPos--;
}
// win rate
float mainParse::determineWinRate(int amtPlayed, int amtWon) {
	return ((float)amtWon/(float)amtPlayed)*100;
}
// update player info
void mainParse::updatePlayer(string nameP, vector<vector<int> > pStats) {
	string amtWon="Games Won";
	string winRate="Win Rate";
	string amtPlayed="Games Played";
	string fastestWinAmt="Fastest Win";
	string fewestMovesAmt= "Fewest Moves";
	string topScoreAmt= "Top Score";
	size_t namePlayerLoc= this->findOccurrence(nameP, 1, 0);
	size_t amtWonLoc= this->findOccurrence(amtWon, 2, namePlayerLoc);
	size_t winRateLoc= this->findOccurrence(winRate, 2, namePlayerLoc);
	size_t amtPlayedLoc= this->findOccurrence(amtPlayed, 2, namePlayerLoc);
	size_t fastestWinLoc= this->findOccurrence(fastestWinAmt, 2, namePlayerLoc);
	size_t fewestMovesLoc= this->findOccurrence(fewestMovesAmt, 2, namePlayerLoc);
	size_t topScoreLoc= this->findOccurrence(topScoreAmt, 2, namePlayerLoc);

	int amtThrough= 2;
	for(amtThrough= 2; amtThrough < 5; amtThrough++) {
		updateNum(amtWon, pStats[amtThrough-2][0], amtWonLoc, 1);
		updateNum(winRate, this->determineWinRate(pStats[amtThrough-2][1], pStats[amtThrough-2][0]), winRateLoc, 1);
		updateNum(amtPlayed, pStats[amtThrough-2][1], amtPlayedLoc, 1);
		updateNum(fastestWinAmt, pStats[amtThrough-2][2], fastestWinLoc, 1);
		updateNum(fewestMovesAmt, pStats[amtThrough-2][3], fewestMovesLoc, 1);
		updateNum(topScoreAmt, pStats[amtThrough-2][4], topScoreLoc, 0);
		amtWonLoc=this->findOccurrence(amtWon, amtThrough+1, namePlayerLoc);
		winRateLoc= this->findOccurrence(winRate, amtThrough+1, namePlayerLoc);
		amtPlayedLoc= this->findOccurrence(amtPlayed, amtThrough+1, namePlayerLoc);
		fastestWinLoc= this->findOccurrence(fastestWinAmt, amtThrough+1, namePlayerLoc);
		fewestMovesLoc= this->findOccurrence(fewestMovesAmt, amtThrough+1, namePlayerLoc);
		topScoreLoc= this->findOccurrence(topScoreAmt, amtThrough+1, namePlayerLoc);
	}
	int totalGamesWon= pStats[0][0]+pStats[1][0]+pStats[2][0];
	int totalGamesPlayed= pStats[0][1]+pStats[1][1]+pStats[2][1];
	updateNum(amtWon, totalGamesWon, namePlayerLoc, 1);
	updateNum(winRate, (int)determineWinRate(totalGamesPlayed, totalGamesWon), namePlayerLoc, 1);
	updateNum(amtPlayed, totalGamesPlayed, namePlayerLoc, 1);
	updateNum(fastestWinAmt, fastestWin(pStats), namePlayerLoc, 1);
	updateNum(fewestMovesAmt, fewestMoves(pStats), namePlayerLoc, 1);
	updateNum(topScoreAmt, topScore(pStats), namePlayerLoc, 0);
}
// output file 
void mainParse::outputFile() {
	ofstream out("PlayerStatistics.json", ofstream::trunc);
	out << this->fileName;
	out.close();
}
// update num info
void mainParse::updateNum(string nameInfo, int replaceNum, size_t positionMain, int determineOn){
	size_t found;
	string i_amt;

	found= this->fileName.find(nameInfo, positionMain) + nameInfo.length() + 3;

	if(determineOn) {
		i_amt= to_string(replaceNum) + ",";
	} else {
		i_amt= to_string(replaceNum);
	}
	this->fileName.replace(found, i_amt.length(), i_amt);
}
