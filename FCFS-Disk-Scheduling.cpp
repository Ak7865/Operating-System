#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main(){

struct loc{
int arr;
}loc[25];
int n,h;
cout<<"Enter nos of Queue"<<endl;
cin>>n;
cout<<"Enter the block nos of Queue"<<endl;
for(int i=0;i<n;i++){
cin>>loc[i].arr;
}
cout<<"Enter the current head position"<<endl;
cin>>h;
int seek_count = 0;
    int distance, cur_track;
    for (int i = 0; i < n; i++) {
        cur_track = loc[i].arr;
        distance = abs(cur_track - h);
        seek_count += distance;
        h = cur_track;
    }

    cout << "Total number of head  movement = "<< seek_count << endl;
    cout << "Queue Sequence is" << endl;

    for (int i = 0; i < n; i++) {
        cout << loc[i].arr << endl;
    }
getch();
}