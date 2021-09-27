#include<bits/stdc++.h>
using namespace std;
int arrMan(int n, vector<vector<int>> v){
vector<int> ans;
long long arr[v.size()][n];
for(int i = 0;  i < v.size() ; i ++){
    for(int j = 0 ; j < n ; j ++){
        arr[i][j] = 0;
    }
}
for(int i = 0 ; i < v.size(); i ++){
        for(int j = i ; j < v.size() ; j ++){
            int a = v[i][0];
            int b = v[i][1];
            int K = v[i][2];
            for(int k = a-1 ; k <= b-1 ; k ++){
                arr[j][k] += K;
            }
        }
}
long long maxx = INT_MIN;
for(int i = 0;  i < v.size() ; i ++){
    for(int j = 0 ; j < n ; j ++){
        if(arr[i][j] > maxx){
            maxx = arr[i][j];
        }
    }
}
// for(int i = 0;  i < v.size() ; i ++){
//     for(int j = 0 ; j < n ; j ++){
//        cout << arr[i][j] << " ";
//     }
//     cout << endl;
// }
return maxx;
}
int main(){
    vector<int> v1 = {2,6,8};
    vector<int> v2 = {3,5,7};
    vector<int> v3 = {1,8,1};
    vector<int> v4 = {5,9,15};
    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    cout << arrMan(10, v);
return 0;
}