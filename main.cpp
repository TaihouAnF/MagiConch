#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

auto init = []{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

void showContent(vector<string>& pool) {
    cout << "You've entered:\n";
    int n = pool.size(), i = 0;
    for (; i < n - 1; i++) {
        cout << pool[i] << " ";
    }
    cout << pool[i] << "\n";
}

int randGenerate(int range) {
    random_device rd;
    uniform_int_distribution<int> d(0, range - 1);
    mt19937 en(rd());
    return d(en);
}

void makeChoice(vector<string>& pool) {
    string line = "";
    // Getting Options inputs
    getline(cin, line);
    if (line.empty()) {
        cout << "You haven't provided anything yet.\n";
        return;
    }
    istringstream ss(line);
    string n = "";
    while (ss >> n) pool.emplace_back(n);
    
    // Core Logic
    if (pool.empty()) {
        cout << "You haven't provided anything yet.\n";
        return;
    } else {
        showContent(pool);
        // uniform_int_distribution<int> d(0, pool.size() - 1);
        // mt19937 en(time(nullptr));
        cout << "I suggest you choose: " << pool[randGenerate(pool.size())] << "\n";
    }
}

void showBoard(vector<vector<int>>& board) {
    if (board.size() == 0 || board[0].size() == 0) {
        cout << "You don't have a valid board.\n";
        return;
    }
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; ++i) {
        // Last one doesn't need a space, but would require a new line
        for (int j = 0; j < m - 1; ++j) {
            cout << board[i][j] << " ";
        }
        cout << board[i][m - 1] << "\n";
    }
}

vector<vector<int>> generateBoard(int n) {
    vector<vector<int>> res_board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res_board[i][j] = randGenerate(2);
        }
    }
    return res_board;
}

int main() {
    string line = "";
    vector<string> pool;
    
    while (1) {
        cout << "please enter options, 0 for RNG, 1 for board.\n";
        string o = "";
        getline(cin, o);
        // Dinner option RNG
        if (o == "0") {
            makeChoice(pool);
            pool.clear();
        } else if (o == "1") {
            // Show the board first
            vector<vector<int>> b = generateBoard(4);
            showBoard(b);
        } else {
            cout << "invalid option";
        }
        // Ask for Continuation
        cout << "Do you want to ask again?\n Press 'Y' and 'Enter' to Continue; Press 'N' and 'Enter' to Exit.\n";
        getline(cin, o);
        if (o == "Y" || o == "y") { continue; }
        break;
    }
    
    return 0;
}