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
    
    vector<int> que;
    
    while(N--){
        string tmp;
        cin >> tmp;
        if(tmp == "push"){
            int num;
            cin >> num;
            que.push_back(num);
        }
        else if(tmp == "front"){
            if(que.empty()){
                cout << "-1\n";
            }
            else{
                cout << que.front() << "\n";
            }
        }
        else if(tmp == "back"){
            if(que.empty()){
                cout << "-1\n";
            }
            else{
                cout << que.back() << "\n";
            }
        }
        else if(tmp == "size"){
            cout << que.size() << "\n";
        }
        else if(tmp == "pop"){
            if(que.empty()){
                cout << "-1\n";
            }
            else{
                cout << que.front() << "\n";
                que.erase(que.begin());
            }
        }
        else{
            cout << que.empty() << "\n";
        }
    }
    
}