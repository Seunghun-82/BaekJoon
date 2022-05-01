//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<long long int, int> a, pair<long long int, int> b) {
    return a.first < b.first;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    long long int result = 0;
    
    int len = 1;
    int num = 9;
    
    while(N){
        if(N >= num){
            result += (num * len);
            N = N - num;
            len++;
            num = num * 10;
        }
        else{
            result += (N * len);
            break;
        }
    }
    
    cout << result << "\n";
}