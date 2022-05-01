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
    
    int N, M;
    bool disable[10] = {false, };
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int tempt;
        cin >> tempt;
        disable[tempt] = true;
    }
    
    int min_v;
    if(N > 100){
        min_v = N - 100;
    }
    else{
        min_v = 100 - N;
    }
    
    for(int i = 0; i < 1000000; i++){
        int store = i;
        int len = 0;
        bool check = true;
        if(store == 0){
            len = 1;
            if(disable[0] == true){
                check = false;
            }
        }
        else{
            while(store != 0){
                int tmp = store % 10;
                store = store / 10;
                if(disable[tmp] == true){
                    check = false;
                    break;
                }
                len++;
            }
        }
        
        if(check == false){
            continue;
        }
        
        int need;
        
        if(i < N){
            need = len + N - i;
        }
        else{
            need = len + i - N;
        }
        
        min_v = min(need, min_v);
        
    }
    
    cout << min_v << "\n";
    
}