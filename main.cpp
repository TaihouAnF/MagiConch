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
    return 0;
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

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high], i = low - 1;    // a place for pivot to stay
    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot) {
            ++i;                            // Update the place, proceed to next
            std::swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quicksort(vector<int>& nums, int low, int high) {
    if (low <= high) {
        int i = rand() % (high - low + 1) + low;    // randomized
        std::swap(nums[i], nums[high]);
        int p = partition(nums, low, high);
        quicksort(nums, low, p - 1);
        quicksort(nums, p + 1, high);
    }
}

void enterNumber(vector<int>& nums) {
    string line = "";
    getline(cin, line);
    if (line.empty()) {
        cout << "You haven't provided anything yet.\n";
        return;
    }
    istringstream ss(line);
    string n = "";
    while (ss >> n) nums.emplace_back(std::stoi(n));

    if (nums.empty()) {
        cout << "You haven't entered anything.\n";
    } else {
        srand((unsigned)time(nullptr));
        quicksort(nums, 0, nums.size() - 1);
        for (auto& i : nums) {
            cout << i << " ";
        }
    }
}

vector<int> solveSlime(vector<int>& slime) {
    int n = slime.size();
    vector<int> left(n), right(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        left[i] = slime[i] == 0;
        right[i] = slime[i] == 1;
    }
    
    
    for (int i = 1; i <= n; ++i) {
        for (int i = 0; i < n - 1; ++i) {
            left[i] = left[i + 1];
        }
        if (i == 1) left[n - 1] = 0;
        for (int i = n - 1; i > 0; --i) {
            right[i] = right[i - 1];
        }
        if (i == 1) right[0] = 0;
        
        vector<int> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = left[i] | right[i];
        }
        int sz = std::count(tmp.begin(), tmp.end(), 1);
        ans.emplace_back(n - sz);
    }
    return ans;
}

int main() {
    string line = "";
    vector<string> pool;
    vector<int> nums;
    
    while (1) {
        cout << "please enter options, 0 for RNG, 1 for board, 2 for quick sort, 3 for SlimeSolving\n";
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
        } else if (o == "2") {
            enterNumber(nums);
            cout << std::endl;
            nums.clear();
        } else if (o == "3") {
            int k = 0;
            cin >> k;
            vector<int> slime(k);
            for (int i = 0; i < k; ++i) {
                cin >> slime[i];
            }
            auto t = solveSlime(slime);

            for (auto& i : t) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            vector<int> test = {0, 1, 2, 3, 4, 5};
            std::fill(test.begin(), test.begin() + 1, 9);
            for (auto& e : test) {
                cout << e << " ";
            }
            cout << "\n";
        }
        // Ask for Continuation
        cout << "Do you want to ask again?\n Press 'Y' and 'Enter' to Continue; Press 'N' and 'Enter' to Exit.\n";
        getline(cin, o);
        pool.clear();
        nums.clear();
        if (o == "Y" || o == "y") { continue; }
        break;
    }
    
    return 0;
}