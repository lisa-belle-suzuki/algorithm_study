#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int resultFromStr(string Str){
        std::map<char, int> romanCharToInt;
        romanCharToInt['I'] = 1;
        romanCharToInt['V'] = 5;
        romanCharToInt['X'] = 10;
        romanCharToInt['L'] = 50;
        romanCharToInt['C'] = 100;
        romanCharToInt['D'] = 500;
        romanCharToInt['M'] = 1000;

        vector<int > intList;
        vector<int > BorderIdxList;
        for (int i=0; i<Str.length(); i++){
            int romanInt = romanCharToInt[Str[i]];
            if (i!=0 && (intList.back() > romanInt)){
                BorderIdxList.push_back(i);
            }
            intList.push_back(romanInt);
        }
        BorderIdxList.push_back(Str.length());

        // // (TODO) delete
        // cout << "intList:" << endl;
        // for (int i=0; i<intList.size(); i++){
        //     cout << intList[i] << " " << endl;
        // }

        // // (TODO) delete
        // cout << "BorderIdxList:" << endl;
        // for (int i=0; i<BorderIdxList.size(); i++){
        //     cout << BorderIdxList[i] << " " << endl;
        // }

        int sum = 0;
        int prevIdx = 0;
        for (int j=0; j<BorderIdxList.size(); j++){
            int curIdx = BorderIdxList[j];
            // cout << "prevIdx = " << prevIdx << endl;
            // cout << "curIdx = " << curIdx << endl;
            if (curIdx - prevIdx == 1){
                // cout << "a" << endl;
                sum += intList[prevIdx];
            }else if (curIdx - prevIdx == 2){
                // cout << "b" << endl;
                if (intList[prevIdx]==intList[prevIdx+1]){
                    // cout << "b1" << endl;
                    sum += intList[prevIdx];
                    sum += intList[prevIdx+1];
                }else{
                    // cout << "b2" << endl;
                    sum += (intList[prevIdx+1]-intList[prevIdx]);
                }
            }else{
                // cout << "c" << endl;
                sum += intList[prevIdx];
                sum += intList[prevIdx+1];
                sum += intList[prevIdx+2];
            }
            // cout << "sum = " << sum << endl;

            prevIdx = curIdx;
        }
        return sum;
    }


    int romanToInt(string s) {
        return resultFromStr(s);
    }
};

void testFunc(string testStr){
    Solution solution;
    cout << testStr  << ": "<< solution.romanToInt(testStr) << endl;
    return;
}

int main(){
    testFunc("III");
    testFunc("IV");
    testFunc("V");
    testFunc("VII");
    testFunc("VIII");
    testFunc("IX");
    testFunc("X");
    testFunc("LVIII");
    testFunc("MCMXCIV");

}
