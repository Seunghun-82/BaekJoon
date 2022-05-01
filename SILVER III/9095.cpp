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

int dfs(int N){
    if(N == 0){
        return 1;
    }
    else if( N < 0){
        return -1;
    }
    else{
        int return_val[3];
        
        return_val[0] = dfs(N - 1);
        return_val[1] = dfs(N - 2);
        return_val[2] = dfs(N - 3);
        
        bool check[3] = {false};
        
        if(return_val[0] > 0){
            check[0] = true;
        }
        if(return_val[1] > 0){
            check[1] = true;
        }
        if(return_val[2] > 0){
            check[2] = true;
        }
        
        int sum = 0;
        
        for(int i = 0; i < 3; i++){
            if(check[i]){
                sum += return_val[i];
            }
        }
        
        return sum;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;
        
        int return_val = dfs(N);
        
        cout << return_val << "\n";
        
    }
}