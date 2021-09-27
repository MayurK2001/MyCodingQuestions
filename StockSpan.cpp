#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> prices){
    vector<int> ans;
    stack<pair<int, int>> s;
    for(auto price: prices){
        int day = 1;
        while(!s.empty() and s.top().first <= price){
            day += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, day));
        ans.push_back(day);
    }
    return ans;
}
int main(){
    vector<int> v = {100, 80,60,70,60,75,85};
    vector<int> ans =  stockSpan(v);
    for(auto answer : ans){
        cout << answer << " ";
    }
return 0;
}