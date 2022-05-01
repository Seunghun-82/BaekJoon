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

vector<char> arr;
int L, C;

void dfs(int len, vector<char> str, vector<bool> visited){
    
    if(len == L){
        
        int a_check = 0;
        int b_check = 0;
        
        for(int i = 0; i < L; i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
               str[i] == 'o' || str[i] == 'u'){
                a_check++;
            }
            else{
                b_check++;
            }
        }
        
        if(a_check >= 1 && b_check >= 2){
            for(int i = 0; i < L; i++){
                cout << str[i];
            }
            cout << "\n";
        }
        
        return;
    }
    
    for(int i = 0; i < C; i++){
        if(visited[i] == false){
            visited[i] = true;
            str.push_back(arr[i]);
            dfs(len + 1, str, visited);
            str.erase(str.begin() + len);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> L >> C;
    
    vector<char> str;
    vector<bool> visited;
    
    for(int i = 0; i < C; i++){
        char tmp;
        cin >> tmp;
        
        arr.push_back(tmp);
        visited.push_back(false);
    }
    
    sort(arr.begin(), arr.end());
    
    dfs(0, str, visited);
    
    return 0;
}