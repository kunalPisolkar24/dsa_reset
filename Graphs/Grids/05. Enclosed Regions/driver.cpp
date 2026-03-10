#include <bits/stdc++.h>
#include "Solution.cpp"

using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string RESET;
    static const string BOLD;
};

const string Color::RED = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::RESET = "\033[0m";
const string Color::BOLD = "\033[1m";

struct TestCase {
    vector<vector<char>> grid;
    vector<vector<char>> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {
                {'O', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'}
            }, {
                {'O', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'O'},
                {'O', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'}
            } },
            { {
                {'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'O', 'O', 'X'},
                {'X', 'O', 'X', 'X', 'O'}
            }, {
                {'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'O', 'O', 'X'},
                {'X', 'O', 'X', 'X', 'O'}
            } },
            { {
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'O', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X'}
            }, {
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X'}
            } },
            { {
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'O', 'X', 'O', 'X', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            }, {
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            } },
            { {
                {'O', 'O', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'O', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'O', 'O', 'X'}
            }, {
                {'O', 'O', 'X', 'O', 'O', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'O', 'O', 'X'}
            } },
            { {
                {'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O'},
                {'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'O', 'O', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
                {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X'}
            }, {
                {'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X'}
            } },
            { {
                {'O', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'X'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X'}
            }, {
                {'O', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X'}
            } },
            { {
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'O', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'O', 'O'},
                {'X', 'O', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X'}
            }, {
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X'}
            } },
            { {
                {'O', 'O', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'O', 'O', 'X', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'O', 'X', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'O', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'O', 'X', 'O'}
            }, {
                {'O', 'O', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'O', 'O', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'X', 'X', 'O', 'X', 'O'}
            } },
            { {
                {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X'},
                {'O', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O'},
                {'O', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X'}
            }, {
                {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X'}
            } },
            { {
                {'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'}
            }, {
                {'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'}
            } },
            { {
                {'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'O', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'O', 'O', 'O', 'O'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'O', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'O', 'O', 'X', 'X'},
                {'X', 'O', 'O', 'O', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'O', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O'}
            }, {
                {'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'O', 'O', 'O', 'O'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O'}
            } },
            { {
                {'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'X', 'O'},
                {'X', 'O', 'X', 'X', 'X', 'O', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            }, {
                {'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            } },
            { {
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            }, {
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
            } },
            { {
                {'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'O', 'X', 'X'},
                {'X', 'X', 'O', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'O', 'X', 'O', 'X'}
            }, {
                {'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                {'O', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', 'X', 'O', 'O', 'X', 'O', 'X'}
            } }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<vector<char>> result = sol.solveEnclosedRegions(tc.grid);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [Matrix]\n"; cout << "     " << Color::RED << "Got:      [Matrix]" << Color::RESET << "\n";
            }
            
            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) {
                    cout << "     " << line << "\n";
                }
            }
            
            cout << "\n";
        }
        
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")" << Color::RESET << "\n";
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)" << Color::RESET << "\n";
            cout << Color::RED << "  (╯°□°）╯︵ ┻━┻" << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
