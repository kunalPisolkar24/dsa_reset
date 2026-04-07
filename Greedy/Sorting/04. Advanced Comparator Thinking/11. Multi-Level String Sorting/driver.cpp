#include <bits/stdc++.h>
#include "solution.cpp"

using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string RESET;
    static const string BOLD;
};

const string Color::RED    = "\033[31m";
const string Color::GREEN  = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::RESET  = "\033[0m";
const string Color::BOLD   = "\033[1m";

struct TestCase {
    vector<string> arr;
    vector<string> expected;
};

class ResultFormatter {
public:
    static string vectorToString(const vector<string>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) {
            s += "\"" + v[i] + "\"";
            if (i + 1 < (int)v.size()) s += ", ";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {"cat", "bat", "apple", "dog"}, {"apple", "dog", "bat", "cat"} },
            { {"banana", "apple", "cherry"}, {"banana", "apple", "cherry"} },
            { {"abc", "abd", "abe"}, {"abc", "abd", "abe"} },
            { {"a", "b", "c"}, {"a", "b", "c"} },
            { {"za", "ya", "xa"}, {"xa", "ya", "za"} },
            { {"abc", "bc", "c"}, {"abc", "bc", "c"} }, // all end in 'c', len 3, 2, 1 -> "c", "bc", "abc"
            { {"ab", "ac", "ad"}, {"ab", "ac", "ad"} },
            { {"apple", "maple", "staple"}, {"apple", "maple", "staple"} },
            { {"test", "best", "rest"}, {"best", "rest", "test"} }, // all end 't', same len, lexicographical
            { {"a", "aa", "aaa"}, {"a", "aa", "aaa"} },
            { {"z", "zz", "zzz"}, {"z", "zz", "zzz"} },
            { {"abc", "aac", "acc"}, {"aac", "abc", "acc"} },
            { {"hello", "world"}, {"world", "hello"} },
            { {"abc", "aba", "abb"}, {"aba", "abb", "abc"} },
            { {"a", "ba", "ca", "b", "cb", "db"}, {"a", "ba", "ca", "b", "cb", "db"} }
        };
        
        // Correcting Case 6 Length order
        cases[5] = { {"abc", "bc", "c"}, {"c", "bc", "abc"} };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Multi-Level String Sorting..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            vector<string> result = sol.multiLevelSort(tc.arr);

            if (result == tc.expected) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: " << ResultFormatter::vectorToString(tc.arr) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << ResultFormatter::vectorToString(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << ResultFormatter::vectorToString(result) << Color::RESET << "\n";
            }
        }

        cout << "\n";
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD
                 << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")"
                 << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD
                 << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)"
                 << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
