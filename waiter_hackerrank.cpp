#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

bool is_prime(long num){
    long n = sqrt(num);
    for(int i=3; i<=n; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n, q, i, num, prime_count = 4;
    vector<long> prime_num;
    stack<long> a0, stak;
    
    cin >> n >> q;
    
    vector< stack<long> > A, B;
    
    prime_num.push_back(2);
    prime_num.push_back(3);
    prime_num.push_back(5);
    prime_num.push_back(7);
    
    num = 11;
    
    while(prime_count <= q){
        if(is_prime(num)){
            prime_num.push_back(num);
            prime_count++;
        }
        num += 2;
    }
    
    for(i=0; i<n; i++){
        cin >> num;
        a0.push(num);
    }
    
    A.push_back(a0);
    // B.push_back(stak);
    
    // while(!a0.empty()){
    //     num = a0.top();
    //     a0.pop();
    //     if(num%prime_num[0] == 0){
    //         B[0].push(num);
    //     }
    //     else{
    //         A[0].push(num);
    //     }
    // }
    
    for(i=0; i<q; i++){
        A.push_back(stak);
        B.push_back(stak);
        while(!A[i].empty()){
            num = A[i].top();
            A[i].pop();
            if(num%prime_num[i] == 0){
                B[i].push(num);
            }
            else{
                A[i+1].push(num);
            }  
        }
    }
    
    for(auto itr = B.begin(); itr != B.end(); itr++){
        while(!(*itr).empty()){
            cout << (*itr).top() << endl;
            (*itr).pop();
        }
    }
    
    auto itr = A.end();
    itr--;
    
    while(!(*itr).empty()){
        cout << (*itr).top() << endl;
        (*itr).pop();
    }
    
    return 0;
}
