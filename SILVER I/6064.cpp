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
    int T;
    
    cin >> T;
    
    while(T--){
        int M, N, X, Y;
        
        cin >> M >> N >> X >> Y;
        
        int year = 1;
        bool check = false;
        
        while(X <= M * N && Y <= M * N){
            if(X > Y){
                Y += N;
            }
            else if(X < Y){
                X += M;
            }
            else{
                check = true;
                break;
            }
        }
        
        if(check == false){
            cout << -1 << "\n";
        }
        else{
            cout << X << "\n";
        }
        
        
    }
    
}