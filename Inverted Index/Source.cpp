#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>
#include<fstream>
#include<conio.h>
#include<sstream>
using namespace std;

class wordPosition {
public:
	string file;
	int line;
	int indexNumber;
	wordPosition() : file("\0"), line(0), indexNumber(0) {}
};

class InvertedIndex {
	vector<pair<string, vector<wordPosition>>>  allWordsWithPositions;
	vector<string> files;
	pair<bool, int> isWordDuplicate(string word) {
		int size = allWordsWithPositions.size();
		pair<bool, int> details;
		details.first = false;
		for (int i = 0; i < size; i++) {
			if (allWordsWithPositions[i].first == word) {
				details.first = true;
				details.second = i;
				return details;
			}
		}
		return details;
	}

	int findIndex(vector<pair<string, int>> rank, string checker) {
		for (int i = 0; i < rank.size(); i++)
			if (rank[i].first == checker) return i;
	}

public:
	void addFile() {
		string fileName;
		cout << "Enter File name to add it to the checklist: ";
		cin.ignore();
		getline(cin, fileName);
		fstream open(fileName + ".txt", ios::in);
		if (!open) {
			cout << "File Not Found!!!\n";
			_getch();
			return;
		}
		files.push_back(fileName);
		int lineNumber = 0, words = 0;
		string line, word;
		while (getline(open, line)) {
			lineNumber++;
			words = 0;
			stringstream tempLine(line);
			while (tempLine >> word) {
				words++;
				pair<bool, int> temp = this->isWordDuplicate(word);
				wordPosition pos;
				pos.file = fileName;
				pos.line = lineNumber;
				pos.indexNumber = words;
				if (temp.first == true)
					this->allWordsWithPositions[temp.second].second.push_back(pos);
				else {
					pair<string, vector<wordPosition>> newWord;
					newWord.first = word;
					newWord.second.push_back(pos);
					this->allWordsWithPositions.push_back(newWord);
				}
			}
		}
		open.close();
	}
	void searchFromFile() {
		string Word;
		cout << "Enter Word to Search: ";
		cin >> Word;
		pair<bool, int> find = isWordDuplicate(Word);
		if (!find.first) {
			cout << "No Occurance of the Word is Found!";
			_getch();
			return;
		}
		int size = allWordsWithPositions[find.second].second.size();
		int occuranceNumber = 0;
		vector<pair<string, int>> Ranking;
		string check = "\0";
		for (int i = 0; i < size; i++) {
			if (allWordsWithPositions[find.second].second[i].file != check) {
				pair<string, int> input;
				input.first = allWordsWithPositions[find.second].second[i].file;
				input.second = 1;
				Ranking.push_back(input);
			}
			else if (allWordsWithPositions[find.second].second[i].file == check)
				Ranking[findIndex(Ranking, check)].second++;
			cout << "\nOccurance Number " << ++occuranceNumber << ":\n";
			cout << "File Name: " << allWordsWithPositions[find.second].second[i].file << endl;
			cout << "Line Number: " << allWordsWithPositions[find.second].second[i].line << endl;
			cout << "Index Number: " << allWordsWithPositions[find.second].second[i].indexNumber << endl;
			check = allWordsWithPositions[find.second].second[i].file;
		}

		cout << "\n\nRanking of Files:\n\n";
		for (auto a : Ranking)
			cout << "File Name: " << a.first << " ,Occurances: " << a.second << endl;

		_getch();
	}
	void showAddedFiles() {
		int size = files.size();
		for (int i = 0; i < size; i++)
			cout << "File no. " << i + 1 << ": " << files[i] << endl;
		_getch();
	}
};

int main() {
	InvertedIndex data; int choice;
again:
	system("cls");
	cout << "1. Add File\n2. Search a Word\n3. Show Added Files\n4. Exit\n\nYour Choice: ";
	cin >> choice;
	if (choice == 1) {
		data.addFile();
		goto again;
	}
	else if (choice == 2) {
		data.searchFromFile();
		goto again;
	}
	else if (choice == 3) {
		data.showAddedFiles();
		goto again;
	}
	else exit(0);
}