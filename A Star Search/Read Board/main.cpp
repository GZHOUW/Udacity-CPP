#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum class State { kEmpty, kObstacle }; // define a new type: 'State'


string CellString( State cell ){
    // take a cell's State as input, output its print value
    if (cell == State::kObstacle) {
        return "X  ";
    }
    else {
        return "0  ";
    }
}

vector<State> ParseLine(string s) {
    // take a file's row (str) as input, make it a vector and return it
    istringstream sstream(s);
    char comma;
    int number;
    vector<State> row;
    while (sstream >> number >> comma) { // read two chars at one time
        if (number == 0) { // 0 is empty space, 1 is obstacle
            row.push_back(State::kEmpty);
        }
        else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string filePath) {
    // Read the board file one line at a time, and return the 2D vector contained in it
    ifstream file(filePath);
    string line;
    vector<vector<State>> board;

    while (getline(file, line)) {
        board.push_back(ParseLine(line));
    }
    return board;
}


void PrintBoard(const vector<vector<State>> board) {
    // print the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<State>> board = ReadBoardFile("b.board");
    PrintBoard(board);
}