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
    int n;
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
            { 1, {"0", "1"} },
            { 2, {"00", "01", "10", "11"} },
            { 3, {"000", "001", "010", "011", "100", "101", "110", "111"} },
            { 1, {"0", "1"} },
            { 2, {"00", "01", "10", "11"} },
            { 3, {"000", "001", "010", "011", "100", "101", "110", "111"} },
            { 4, {"0000","0001","0010","0011","0100","0101","0110","0111",
                  "1000","1001","1010","1011","1100","1101","1110","1111"} },
            { 1, {"0", "1"} },
            { 2, {"00", "01", "10", "11"} },
            { 3, {"000","001","010","011","100","101","110","111"} },
            { 4, {"0000","0001","0010","0011","0100","0101","0110","0111",
                  "1000","1001","1010","1011","1100","1101","1110","1111"} },
            { 1, {"0", "1"} },
            { 2, {"00", "01", "10", "11"} },
            { 3, {"000","001","010","011","100","101","110","111"} },
            { 4, {"0000","0001","0010","0011","0100","0101","0110","0111",
                  "1000","1001","1010","1011","1100","1101","1110","1111"} },
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Binary Strings of Length N..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];

            stringstream buffer;
            streambuf* oldBuf = cout.rdbuf(buffer.rdbuf());

            vector<string> result = sol.generate(tc.n);

            cout.rdbuf(oldBuf);
            string logs = buffer.str();

            vector<string> sortedResult   = result;
            vector<string> sortedExpected = tc.expected;
            sort(sortedResult.begin(),   sortedResult.end());
            sort(sortedExpected.begin(), sortedExpected.end());

            bool sizeOk  = (int)result.size() == (1 << tc.n);
            bool passed  = sizeOk && (sortedResult == sortedExpected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected (" << tc.expected.size() << "): "
                     << ResultFormatter::vectorToString(sortedExpected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got      (" << result.size() << "): "
                     << ResultFormatter::vectorToString(sortedResult) << Color::RESET << "\n";
            }

            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) {
                    cout << "     " << line << "\n";
                }
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
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD
                 << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)"
                 << Color::RESET << "\n";
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
