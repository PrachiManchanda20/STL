#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
  unordered_map<int , string> mp;

  mp[101] = "abc";
  mp[102] = "bcd";
  mp[103] = "qwerty";

  mp.insert({1002 , "120dsjds"});
  mp.insert({1003 , "3423de"});
  mp.insert({10043 , "j34s"});

  for( auto i = mp.begin(); i != mp.end(); i++){  //iterator based 
    cout << i->first <<"\n";
  }

  mp.erase(102);


  for(auto x :mp ){ //range based 
    cout<< " 1st value: "<< x.first;
  }

}