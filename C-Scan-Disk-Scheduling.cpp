#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
 struct loc{int arr;}loc[25];
 int n,ds,h;
cout<<"Enter the nos of queue"<<endl;
cin>>n;
cout<<"Enter the block of queue"<<endl;
for(int i=0;i<n;i++){
cin>>loc[i].arr;
}
cout<<"Enter the current head position"<<endl;
cin>>h;
cout<<"Enter the Disk size"<<endl;
cin>>ds;
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;
		left.push_back(0);
		right.push_back(ds-1);
	for (int i = 0; i < n; i++) {
		if (loc[i].arr < h)
			left.push_back(loc[i].arr);
		if (loc[i].arr > h)
			right.push_back(loc[i].arr);
	}
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	for (int i =0; i < right.size(); i++) {
				cur_track = right[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - h);
				seek_count += distance;
				h = cur_track;
			}
         h=0;
   for (int i = 0; i < left.size(); i++) {
				cur_track = left[i];
            seek_sequence.push_back(cur_track);
            distance= abs(cur_track - h);
            seek_count += distance;
				h = cur_track;
			}
	cout << "Total number of seek operations = "
		<<seek_count << endl;
	cout << "Seek Sequence is" << endl;
	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << endl;
	}
}
getch();
}