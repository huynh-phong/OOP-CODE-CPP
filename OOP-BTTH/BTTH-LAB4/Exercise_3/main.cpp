#include "CTime.h"
#include <iostream>
using namespace std;

int main(){
    CTime t;
    cin>>t;
    cout<<"\nThoi gian hien tai la: "<<t;
    cout<<"\nCong 500 giay: "<<t+500;
    cout<<"\nTru 100 giay: "<<t-100;
    cout<<"\nThoi gian khi ++: "<<++t;
    cout<<"\nThoi gian khi --: "<<--t;
    return 0;
}