#include<iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int>q;
int main(){

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(12);
  q.push(23);
  
  while(!q.empty()){
  cout<<q.top();
  q.pop();
  }
}