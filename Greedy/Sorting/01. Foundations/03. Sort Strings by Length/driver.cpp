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
            { {"apple", "kiwi", "banana", "fig"}, {"fig", "kiwi", "apple", "banana"} },
            { {"cat", "bat", "rat", "apple"}, {"bat", "cat", "rat", "apple"} },
            { {"a", "abc", "ab"}, {"a", "ab", "abc"} },
            { {"same", "size", "tags"}, {"same", "size", "tags"} }, // same size, sorted lexicographically
            { {"zebra", "ant", "bear"}, {"ant", "bear", "zebra"} },
            { {"longerstring", "short"}, {"short", "longerstring"} },
            { {"a", "b", "c", "aa", "bb", "cc"}, {"a", "b", "c", "aa", "bb", "cc"} },
            { {"abc", "ab", "a"}, {"a", "ab", "abc"} },
            { {"hello"}, {"hello"} },
            { {"world", "wide", "web"}, {"web", "wide", "world"} },
            { {"python", "cpp", "java", "ruby"}, {"cpp", "java", "ruby", "python"} },
            { {"", "a"}, {"", "a"} }, // empty string
            { {"zz", "z"}, {"z", "zz"} },
            { {"banana", "apple", "cherry"}, {"apple", "banana", "cherry"} },
            { {"d", "c", "b", "a"}, {"a", "b", "c", "d"} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Strings by Length..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            vector<string> result = sol.sortByLength(tc.arr);

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
