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

vector<char> table[10];

vector<int> result;

bool dfs(int len, int N, vector<int> arr){
    
    if(len == N){
        
        bool check = true;
        
        for(int i = 0; i < len; i++){
            int sum = 0;
            
            for(int j = 0; j < len - i; j++){
                sum += arr[i + j];
                if(table[i][j] == '-'){
                    if(sum >= 0){
                        check = false;
                        break;
                    }
                }
                else if(table[i][j] == '+'){
                    if(sum <= 0){
                        check = false;
                        break;
                    }
                }
                else{
                    if(sum != 0){
                        check = false;
                        break;
                    }
                }
            }
            
            if(check == false){
                break;
            }
        }
        
        if(check){
            for(int i = 0; i < arr.size(); i++){
                result.push_back(arr[i]);
            }
            
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(table[len][0] == '+'){
            
            bool check = true;
            
            for(int i = 0; i < len; i++){
                int sum = 0;
                
                for(int j = 0; j < len - i; j++){
                    sum += arr[i + j];
                    if(table[i][j] == '-'){
                        if(sum >= 0){
                            check = false;
                            break;
                        }
                    }
                    else if(table[i][j] == '+'){
                        if(sum <= 0){
                            check = false;
                            break;
                        }
                    }
                    else{
                        if(sum != 0){
                            check = false;
                            break;
                        }
                    }
                }
                
                if(check == false){
                    break;
                }
            }
            
            if(check == true){
                for(int i = 1; i <= 10; i++){
                    arr.push_back(i);
                    bool ret = dfs(len + 1, N, arr);
                    if(ret){
                        return true;
                    }
                    else{
                        arr.erase(arr.begin() + len);
                    }
                    
                }
            }
            
        }
        else if(table[len][0] == '-'){
            bool check = true;
            
            for(int i = 0; i < len; i++){
                int sum = 0;
                
                for(int j = 0; j < len - i; j++){
                    sum += arr[i + j];
                    if(table[i][j] == '-'){
                        if(sum >= 0){
                            check = false;
                            break;
                        }
                    }
                    else if(table[i][j] == '+'){
                        if(sum <= 0){
                            check = false;
                            break;
                        }
                    }
                    else{
                        if(sum != 0){
                            check = false;
                            break;
                        }
                    }
                }
                
                if(check == false){
                    break;
                }
            }
            
            if(check == true){
                for(int i = -10; i <= -1; i++){
                    arr.push_back(i);
                    bool ret = dfs(len + 1, N, arr);
                    if(ret){
                        return true;
                    }
                    else{
                        arr.erase(arr.begin() + len);
                    }
                }
            }
        }
        else{
            bool check = true;
            
            for(int i = 0; i < len; i++){
                int sum = 0;
                
                for(int j = 0; j < len - i; j++){
                    sum += arr[i + j];
                    if(table[i][j] == '-'){
                        if(sum >= 0){
                            check = false;
                            break;
                        }
                    }
                    else if(table[i][j] == '+'){
                        if(sum <= 0){
                            check = false;
                            break;
                        }
                    }
                    else{
                        if(sum != 0){
                            check = false;
                            break;
                        }
                    }
                }
                
                if(check == false){
                    break;
                }
            }
            
            if(check == true){
                for(int i = 0; i <= 0; i++){
                    arr.push_back(i);
                    bool ret = dfs(len + 1, N, arr);
                    if(ret){
                        return true;
                    }
                    else{
                        arr.erase(arr.begin() + len);
                    }
                }
            }
        }
    }
    
    return false;
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i; j++){
            char tmp;
            cin >> tmp;
            table[i].push_back(tmp);
        }
    }
    
    vector<int> arr;
    
    bool check = dfs(0, N, arr);
    
    if(check){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}