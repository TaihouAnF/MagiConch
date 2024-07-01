#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showContent(vector<string>& pool) {
    int n = pool.size(), i = 0;
    for (; i < n - 1; i++) {
        cout << pool[i] << " ";
    }
    cout << pool[i] << "\n";
}

int main() {
    init();
    string line = "";
    vector<string> pool;
    
    while (1) {
        pool.clear();
        cout << "please enter options\n";

        // Getting Options inputs
        getline(cin, line);
        if (line.empty()) break;    // Empty
        istringstream ss(line);
        string n = "";
        while (ss >> n) pool.emplace_back(n);
        
        // Core Logic
        if (pool.empty()) {
            cout << "You haven't provided anything yet.\n";
            continue;
        }
        else {
            showContent(pool);
            uniform_int_distribution<int> d(0, pool.size() - 1);
            mt19937 en(time(nullptr));
            cout << pool[d(en)] << "\n";
        }

        // Ask for Continuation
        // cout << "Do you want to ask again?\n Press 'N' and 'Enter' to Exit.\n";
        // string c = "";
        // cin >> c;
        
        break;
    }
    
    return 0;
}