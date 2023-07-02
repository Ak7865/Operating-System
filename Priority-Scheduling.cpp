#include<iostream>
#include<conio.h>
using namespace std;

int main(){

int n,i,j,t;

struct p{
int at;
int id;
int rt;
int prt;
int bt;
int tat;
int ct;
int wt;
}p[25];



cout<<"How many process?"<<endl;
cin>>n;
for(i=0;i<n;i++){
cout<<"Enter the Process Id & Arrival time & Busrt Time & Priority for process"<<endl;
cin>>p[i].id>>p[i].at>>p[i].bt>>p[i].prt;
}
cout<<"\t\t"<<"After Priority Done"<<endl;
cout<<"n\t"<<"Process Id"<<"\t\t"<<"Arrival"<<"\t\t"<<"Burst Time"<<"\t"<<"Priority"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].prt<<endl;
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(p[i].prt<p[j].prt){


t=p[i].id;
p[i].id=p[j].id;
p[j].id=t;

t=p[i].prt;
p[i].prt=p[j].prt;
p[j].prt=t;

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
p[i].wt=0;
for(i=0;i<n;i++){
p[i].wt=p[i].tat-p[i].bt;
}
p[0].rt=0;
for(i=1;i<=n;i++){
p[i].rt=p[i-1].ct-p[i].at;
}
cout<<"\t\t"<<"Before Priority Done"<<endl;
cout<<"\n\t"<<"Process Id"<<"\t"<<"Arrival"<<"\t\t"<<"Burst Time"<<"\t"<<"CT"<<"\t\t"<<"TAT"<<"\t\t"<<"WT"<<"\t\t"<<"Priority"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].prt<<endl;
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