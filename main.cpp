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
    cout << "please enter options" << "\n";
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
    return 0;
}