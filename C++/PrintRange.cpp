#include <iostream>

using namespace std;

//Prints the elements in range of iterators
template <typename It>
void PrintRange(It range_begin, It range_end){
    for(auto it = range_begin;it!=range_end;it++){
        cout<<*it<<" ";
    }
    cout<<endl;  
}