#include<iostream>
#include<conio.h>
using namespace std;

int main(){

int n,i,j,t;
struct p{
int id;
int rt;
int at;
int bt;
int tat;
int ct;
int wt;
}p[25];



cout<<"How many process?"<<endl;
cin>>n;
cout<<"Enter the Process Id, Arrival Time & Busrt Time for process"<<endl;
for(i=0;i<n;i++){
cout<<"Enter the Process Id, Arrival Time & Burst Time for process"<<endl;
cin>>p[i].id>>p[i].at>>p[i].bt;

}
cout<<"Snapshot is given below"<<"\n"<<endl;
cout<<"Process no"<<"\t"<<"AT"<<"\t"<<"BT"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<endl;
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(p[i].at<p[j].at){


t=p[i].id;
p[i].id=p[j].id;
p[j].id=t;

t=p[i].at;
p[i].at=p[j].at;
p[j].at=t;

}
}
}
p[0].ct=p[0].at+p[0].bt;
for(i=1;i<=n;i++){
p[i].ct=p[i-1].ct+p[i].bt;
}
for(i=0;i<n;i++){
p[i].tat=p[i].ct-p[i].at;
}
for(i=0;i<n;i++){
p[i].wt=p[i].tat-p[i].bt;
}
p[0].rt=0;
for(i=1;i<=n;i++){
p[i].rt=p[i-1].ct-p[i].at;
}
cout<<"Before FSFC is complete"<<endl;
cout<<"Process no"<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<"\t"<<"RT"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<endl;
}
int ttat=0, twt=0;

for(i=0;i<n;i++){

ttat=ttat+p[i].tat;
twt=twt+p[i].wt;
}
float atat;
float awt;
atat=(float)ttat/(float) n;
awt=(float)twt/(float)n;
cout<<"\n"<<"\n"<<"Average Turn Around Time is= "<<atat;
cout<<"\n"<<"\n"<<"Average Waiting Time is= "<<awt;

getch();
}


