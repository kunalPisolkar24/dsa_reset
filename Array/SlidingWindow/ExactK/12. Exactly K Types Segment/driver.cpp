#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;
struct Color { static const string RED, GREEN, YELLOW, RESET, BOLD; };
const string Color::RED="\033[31m", Color::GREEN="\033[32m", Color::YELLOW="\033[33m", Color::RESET="\033[0m", Color::BOLD="\033[1m";
struct TestCase { string s; int k; int expected; };
class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            {"pqpqs", 2, 7}, {"aaaa", 1, 10}, {"abc", 2, 2}, {"aababc", 3, 4},
            {"abcabc", 2, 5}, {"aabb", 1, 6}, {"aabb", 2, 4}, {"xyz", 1, 3},
            {"aaab", 2, 3}, {"abcdef", 3, 4}, {"abcabc", 1, 6}, {"aaa", 2, 0},
            {"abac", 2, 4}, {"abcba", 2, 5}, {"aabbcc", 2, 8}
        };
        Solution sol; int passedCount=0, totalCount=cases.size();
        cout<<Color::BOLD<<"Running "<<totalCount<<" Tests for Exactly K Types Segment..."<<Color::RESET<<"\n\n";
        for(int i=0;i<totalCount;i++){
            auto tc=cases[i];
            stringstream buffer; streambuf* old=cout.rdbuf(buffer.rdbuf());
            int result=sol.countSubstringsWithKDistinct(tc.s,tc.k);
            cout.rdbuf(old); string logs=buffer.str();
            bool passed=(result==tc.expected);
            if(passed){cout<<Color::GREEN<<"✓ Test "<<i+1<<" Passed"<<Color::RESET<<"\n";passedCount++;}
            else{cout<<Color::RED<<"✗ Test "<<i+1<<" Failed"<<Color::RESET<<"\n";
                 cout<<"     "<<Color::RED<<"Expected: "<<tc.expected<<Color::RESET<<"\n";
                 cout<<"     "<<Color::RED<<"Got: "<<result<<Color::RESET<<"\n";}
            if(!logs.empty()){cout<<Color::YELLOW<<"   Logs:"<<Color::RESET<<"\n";stringstream ls(logs);string l;while(getline(ls,l))cout<<"     "<<l<<"\n";}
        }
        cout<<"\n"; printSummary(passedCount,totalCount);
    }
private:
    void printSummary(int p,int t){
        cout<<Color::BOLD<<"======================================="<<Color::RESET<<"\n";
        if(p==t){cout<<Color::GREEN<<Color::BOLD<<"  ALL TESTS PASSED! ("<<p<<"/"<<t<<")"<<Color::RESET<<"\n";cout<<Color::GREEN<<"  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧"<<Color::RESET<<"\n";}
        else{cout<<Color::RED<<Color::BOLD<<"  TESTS FAILED ("<<p<<"/"<<t<<" passed)"<<Color::RESET<<"\n";cout<<Color::RED<<"  (╯°□°）╯︵ ┻━┻"<<Color::RESET<<"\n";}
        cout<<Color::BOLD<<"======================================="<<Color::RESET<<"\n";
    }
};
int main(){TestRunner r;r.run();return 0;}
