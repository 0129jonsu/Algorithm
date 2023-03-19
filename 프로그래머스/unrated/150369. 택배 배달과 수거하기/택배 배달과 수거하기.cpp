#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<int> d;
    stack<int> p;
    
    for(int i = 0; i < n; i++){
        d.push(deliveries[i]);
        p.push(pickups[i]);
    }
    
    while(!d.empty() && d.top() == 0) d.pop();
    while(!p.empty() && p.top() == 0) p.pop();
    
    while(!d.empty() || !p.empty()){
        answer += max(d.size(), p.size()) * 2;
        int tmp = 0;
        while(!d.empty() && tmp <= cap){
            if(d.top() <= cap - tmp) {
                tmp += d.top();
                d.pop();
            }
            else {
                d.top() -= (cap-tmp);
                break;
            }
        }
        tmp = 0;
        while(!p.empty() && tmp <= cap){
            if(p.top() <= cap - tmp){
                tmp += p.top();
                p.pop();
            }
            else {
                p.top() -= (cap-tmp);
                break;
            }
        }
    }
    
    return answer;
}