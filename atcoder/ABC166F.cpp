#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nums[3];
char answer[100002];
string S[100002];

ll alphabet2num(char alphabet){
    if (alphabet=='A') return 0;
    if (alphabet=='B') return 1;
    if (alphabet=='C') return 2;
    else return -1;
}

char num2alphabet(ll num){
    if (num==0) return 'A';
    if (num==1) return 'B';
    if (num==2) return 'C';
    else return 'X';
}


bool isCharIncludedInStr(char c, string s){
    for(int i=0; i<s.size(); i++){
        if (c==s[i]) return true;
    }
    return false;
}


int main(){
    ll N, l, r;
    string s;
    cin >> N >> nums[0] >> nums[1] >> nums[2];
    for(int i=0; i<N; i++){
        cin >> S[i];
    }


    ll sum = nums[0] + nums[1] + nums[2];
    if (sum == 0){
        cout << "No" << endl;
        return 0;
    }
    else if (sum==1){
        for(ll i=0; i<N; i++){
            s = S[i];
            l = alphabet2num(s[0]);
            r = alphabet2num(s[1]);
            if (max(nums[l], nums[r])<=0){
                cout << "No"<< endl;
                return 0;
            }
            if (nums[l] < nums[r]){
                answer[i] = num2alphabet(l);
                nums[l] ++;
                nums[r] --;
            }else{
                answer[i] = num2alphabet(r);
                nums[l] --;
                nums[r] ++;
            }
        }
        cout << "Yes" << endl;
        for(ll i=0; i<N; i++){
            cout << answer[i] << endl;
        }
        return 0;
    }else{
        for(ll i=0; i<N; i++){
            s = S[i];
            l = alphabet2num(s[0]);
            r = alphabet2num(s[1]);

            if (nums[l]==0 && nums[r]==0){
                cout << "No" << endl;
                return 0;
            }
            if (nums[l]==0 && nums[r]>0){
                answer[i] = num2alphabet(l);
                nums[l] ++;
                nums[r] --;
            }else if (nums[l]>0 && nums[r]==0){
                answer[i] = num2alphabet(r);
                nums[l] --;
                nums[r] ++;
            }else if (sum==2 && nums[l]==1 && nums[r]==1 && i!=N-1 && S[i]!=S[i+1]){
                if (isCharIncludedInStr(s[1], S[i+1])){
                    answer[i] = num2alphabet(r);
                    nums[l] --;
                    nums[r] ++;
                }else{
                    answer[i] = num2alphabet(l);
                    nums[l] ++;
                    nums[r] --;
                }
            }else{
                if (nums[l] > nums[r]){
                    answer[i] = num2alphabet(r);
                    nums[l] --;
                    nums[r] ++;
                }else{
                    answer[i] = num2alphabet(l);
                    nums[l] ++;
                    nums[r] --;
                }
            }
        }

        cout << "Yes" << endl;
        for(ll i=0; i<N; i++){
            cout << answer[i] << endl;
        }
    }

    return 0;
}