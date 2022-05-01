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

struct cmp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

struct Fireball{
    int y;
    int x;
    int m;
    int s;
    int d;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K;;
    
    cin >> N >> M >> K;
    
    vector<Fireball> arr;
    
    for(int i = 0 ; i < M ; i++){
        int tmp_r, tmp_c, tmp_m, tmp_s, tmp_d;
        cin >> tmp_r >> tmp_c >> tmp_m >> tmp_s >> tmp_d;
        Fireball tmp = {tmp_r - 1, tmp_c - 1, tmp_m, tmp_s, tmp_d};
        arr.push_back(tmp);
    }
    
    while(K--){
        
        vector<int> table[N][N];
        
        auto size = arr.size();
        for(auto i = 0; i < size; i++){
            if(arr[i].d == 0){
                arr[i].y -= arr[i].s;
            }
            else if(arr[i].d == 1){
                arr[i].y -= arr[i].s;
                arr[i].x += arr[i].s;
            }
            else if(arr[i].d == 2){
                arr[i].x += arr[i].s;
            }
            else if(arr[i].d == 3){
                arr[i].y += arr[i].s;
                arr[i].x += arr[i].s;
            }
            else if(arr[i].d == 4){
                arr[i].y += arr[i].s;
            }
            else if(arr[i].d == 5){
                arr[i].y += arr[i].s;
                arr[i].x -= arr[i].s;
            }
            else if(arr[i].d ==6){
                arr[i].x -= arr[i].s;
            }
            else{
                arr[i].x -= arr[i].s;
                arr[i].y -= arr[i].s;
            }
            
            while(arr[i].x < 0){
                arr[i].x += N;
            }
            while(arr[i].x >= N){
                arr[i].x -= N;
            }
            while(arr[i].y < 0){
                arr[i].y += N;
            }
            while(arr[i].y >= N){
                arr[i].y -= N;
            }
            
            table[arr[i].y][arr[i].x].push_back(i);
            
        }
        
        vector<int> del;
        vector<Fireball> add;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                auto tmp_size = table[i][j].size();
                if(tmp_size >= 2){
                    
                    int mass = 0;
                    int speed = 0;
                    
                    bool odd_num = true;
                    bool even_num = true;
                    
                    for(int k = 0; k < tmp_size; k++){
                        mass += arr[table[i][j][k]].m;
                        speed += arr[table[i][j][k]].s;
                        if(arr[table[i][j][k]].d % 2 == 1){
                            even_num = false;
                        }
                        else{
                            odd_num = false;
                        }
                        del.push_back(table[i][j][k]);
                    }
                    
                    mass = mass / 5;
                    speed = speed / tmp_size;
                    bool check_direction = (odd_num || even_num);
                    if(mass != 0){
                        for(int k = 0; k < 4; k++){
                            if(check_direction == true){
                                Fireball tmp = {i, j, mass, speed, k * 2};
                                add.push_back(tmp);
                            }
                            else{
                                Fireball tmp = {i, j, mass, speed, k * 2 + 1};
                                add.push_back(tmp);
                            }
                        }
                    }
                }
            }
        }
        
        
        sort(del.begin(), del.end());
        
        auto del_size = del.size();
        
        for(auto i = 0; i < del_size ; i++){
            arr.erase(arr.begin() + del[del_size - 1 - i]);
        }
        
        auto add_size = add.size();
        
        for(int i = 0; i <add_size; i++){
            arr.push_back(add[i]);
        }
        
    }
    
    int sum_mass = 0;
    auto arr_size = arr.size();
    
    for(auto i = 0; i < arr_size; i++){
        sum_mass += arr[i].m;
    }
    
    cout << sum_mass << "\n";
    
}