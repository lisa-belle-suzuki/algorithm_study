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

const long long int INF = 1e9;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

struct Point{
	int x,y;
};

bool vector_finder(std::vector<ll> vec, ll number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

ll factorial(ll N){
    ll ans = 1;
    llRep(i,N){
        ans *= i;
    }
    return ans;
}

ll extended_factorial(ll N){
    ll ans = 1;
    llRep(i,N){
        ans *= i;
        ans %= (ll)(1e9+7);
    }
    return ans;
}

vector<ll> Eratosthenes(ll N){
    bool arr[N+1];
    //initialization
    arr[0] = false;
    arr[1] = false;
	for(ll i = 2; i < N+1; i++){
		arr[i] = true;
	}
    //eratosthenes
	for(ll i = 2; i <= sqrt(N); i++){
		if(arr[i]){
			for(ll j = 0; i * (j + 2) <= N; j++){
				arr[i *(j + 2)] = false;//not prime number
			}
		}
	}
    vector<ll> prime;
    llRep(i,N){
        if (arr[i]==true){
            prime.push_back(i);
        }
    }
    return prime;
}

ll gcd(ll a, ll b){
    ll temp;
	while (a % b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return b;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a,b);
}

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

ll digit__(ll num){
    ll cnt=1;
    while(num > 10){
        cnt ++;
        num /= 10;
    }
    return cnt;
}

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultListNode;
        resultListNode = new ListNode(0);
        ListNode *prevListNode;
        prevListNode = new ListNode(0);
        int sum,carry=0,l1Val, l2Val;

        bool isFirstNode = true;
        while(l1 || l2 || carry>0){
            if (l1){ l1Val = l1->val; }
            else{ l1Val = 0; }

            if (l2){ l2Val = l2->val; }
            else{ l2Val = 0; }

            sum = (l1Val + l2Val + carry) % 10;
            // cout << "sum = " << sum << endl;
            carry = (l1Val + l2Val + carry) / 10;
            // cout << "carry = " << carry << endl;

            ListNode *curListNode = new ListNode(0);
            curListNode->val = sum;
            cout << "curListNode = " << curListNode->val << endl;

            if (!isFirstNode){//not first node
                prevListNode->next = curListNode;
            }else{//first node
                isFirstNode = false;
                resultListNode = curListNode;
            }
            // cout << "ppp "  << endl;
            prevListNode = curListNode;
            // cout << "qqq "  << endl;
            if (l1){
                l1 = l1->next;
            }
            if (l2){
                l2 = l2->next;
            }
        }
        return resultListNode;
    }
};



int main(){

    ListNode l1(2);
    ListNode l1Next(4);
    ListNode l1NextNext(3);
    l1.next = &l1Next;
    l1Next.next = &l1NextNext;

    ListNode l2(5);
    ListNode l2Next(6);
    ListNode l2NextNext(4);
    l2.next = &l2Next;
    l2Next.next = &l2NextNext;

    Solution solution;
    ListNode* testResult = solution.addTwoNumbers(&l1, &l2);
    cout << testResult->val << endl;

    return 0;
}
