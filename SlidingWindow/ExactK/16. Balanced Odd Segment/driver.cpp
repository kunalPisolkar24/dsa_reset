#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;
struct Color { static const string RED, GREEN, YELLOW, RESET, BOLD; };
const string Color::RED="\033[31m", Color::GREEN="\033[32m", Color::YELLOW="\033[33m", Color::RESET="\033[0m", Color::BOLD="\033[1m";
struct TestCase { vector<int> nums; int k; int expected; };
class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            {{1,1,2,1,1}, 3, 2}, {{2,4,6}, 1, 0}, {{1,2,3,4,5}, 2, 4},
            {{2,2,2,1,1}, 2, 4}, {{1,3,5,7}, 2, 3}, {{1,1,1,1,1}, 1, 5},
            {{2,4,6,8}, 0, 10}, {{1}, 1, 1}, {{2}, 0, 1}, {{1,2,1,2,1}, 3, 1},
            {{3,5,7,2,4}, 1, 5}, {{1,2,3,4,5,6}, 3, 2}, {{2,1,2,1,2}, 2, 4},
            {{1,1,1}, 2, 2}, {{5,10,15,20}, 1, 6}
        };
        Solution sol; int passedCount=0, totalCount=cases.size();
        cout<<Color::BOLD<<"Running "<<totalCount<<" Tests for Balanced Odd Segment..."<<Color::RESET<<"\n\n";
        for(int i=0;i<totalCount;i++){
            auto tc=cases[i];
            stringstream buffer; streambuf* old=cout.rdbuf(buffer.rdbuf());
            int result=sol.countSubarraysWithKOdds(tc.nums,tc.k);
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
