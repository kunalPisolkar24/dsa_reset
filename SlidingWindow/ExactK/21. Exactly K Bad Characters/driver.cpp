#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;
struct Color { static const string RED, GREEN, YELLOW, RESET, BOLD; };
const string Color::RED="\033[31m", Color::GREEN="\033[32m", Color::YELLOW="\033[33m", Color::RESET="\033[0m", Color::BOLD="\033[1m";
struct TestCase { string s; vector<char> bad; int k; int expected; };
class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            {"abcde", {'b','d'}, 2, 4}, {"aaa", {'b'}, 1, 0}, {"abab", {'a'}, 1, 6},
            {"abcabc", {'a','b'}, 2, 7}, {"xyz", {'x','y','z'}, 1, 3},
            {"hello", {'l'}, 2, 6}, {"aabb", {'a'}, 1, 4}, {"test", {'t'}, 1, 6},
            {"abcde", {'a'}, 0, 10}, {"aaaa", {'a'}, 2, 3}, {"abcde", {'z'}, 0, 15},
            {"bbbb", {'b'}, 1, 4}, {"abcdef", {'b','d','f'}, 2, 6},
            {"aabbc", {'a','b'}, 3, 3}, {"xyzxy", {'x'}, 2, 2}
        };
        Solution sol; int passedCount=0, totalCount=cases.size();
        cout<<Color::BOLD<<"Running "<<totalCount<<" Tests for Exactly K Bad Characters..."<<Color::RESET<<"\n\n";
        for(int i=0;i<totalCount;i++){
            auto tc=cases[i];
            stringstream buffer; streambuf* old=cout.rdbuf(buffer.rdbuf());
            int result=sol.countSubstringsWithKBad(tc.s,tc.bad,tc.k);
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
