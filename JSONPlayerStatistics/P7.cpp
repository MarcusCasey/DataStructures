// imports
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "mainParse.h"
// using namespace std
using namespace std;
int main() {
string fileName = "PlayerStatistics.json";
mainParse jParse(fileName);
vector<vector<int>> youInfo(3);
// Simulate Data For One Suit
youInfo[0].push_back(5);
youInfo[0].push_back(5);
youInfo[0].push_back(30);
youInfo[0].push_back(18);
youInfo[0].push_back(78);
// Simulate Data For Two Suit
youInfo[1].push_back(3);
youInfo[1].push_back(5);
youInfo[1].push_back(45);
youInfo[1].push_back(34);
youInfo[1].push_back(98);
// Simulate Data For Four Suit
youInfo[2].push_back(0);
youInfo[2].push_back(5);
youInfo[2].push_back(999);
youInfo[2].push_back(999);
youInfo[2].push_back(86);
vector<vector<int> > meInfo(3);
// Simulate Data For One Suit
meInfo[0].push_back(0);
meInfo[0].push_back(5);
meInfo[0].push_back(999);
meInfo[0].push_back(999);
meInfo[0].push_back(12);
// Simulate Data For Two Suit
meInfo[1].push_back(2);
meInfo[1].push_back(5);
meInfo[1].push_back(65);
meInfo[1].push_back(11);
meInfo[1].push_back(78);
// Simulate Data For Four Suit
meInfo[2].push_back(5);
meInfo[2].push_back(5);
meInfo[2].push_back(56);
meInfo[2].push_back(67);
meInfo[2].push_back(98);
// update player 
jParse.updatePlayer("You", youInfo);
jParse.updatePlayer("Me", meInfo);
// out put file.
jParse.outputFile();
return 0;
}
