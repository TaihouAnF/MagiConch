#include <iostream>
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

int main() {
    init();
    string n = "";
    vector<string> pool;
    cout << "please enter options\n";
    while (1) {
        pool.clear();
        while (cin >> n) {
            pool.emplace_back(n);
            if (cin.get() == '\n') break;
        }
        int k = pool.size();
        if(!k) cout << "等下先。\n";
        else {
            uniform_int_distribution<int> d(0, k - 1);
            mt19937 en(time(nullptr));
            cout << pool[d(en)] << "\n";
        }

        cout << "Do you want to ask again?\n Input 'Y' then Press 'Enter' to continue; Press 'N' and 'Enter' to Exit.\n";
        string c = "";
        cin >> c;
        if (c == "N") break;
    }
    
    return 0;
}