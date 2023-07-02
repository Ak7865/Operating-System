#include<iostream>
#include<conio.h>
using namespace std;


int main(){
//clrscr();
int n,i,j,t,pid;
struct p{
int id;

int rt;
int bt;
int tat;
int ct;
int wt;
}p[25];



cout<<"How many process?"<<endl;
cin>>n;

cout<<"Enter the Process Id & Busrt Time for process"<<endl;
for(i=0;i<n;i++){
cout<<"Enter the Process Id & Burst Time for process"<<endl;
cin>>p[i].id>>p[i].bt;

}

cout<<"Snapshot is given below"<<"\n"<<endl;
cout<<"Process no"<<"\t"<<"BT"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t"<<p[i].bt<<endl;
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(p[i].bt<p[j].bt){
t=p[i].bt;
p[i].bt=p[j].bt;
p[j].bt=t;

t=p[i].id;
p[i].id=p[j].id;
p[j].id=t;



}
}
}
p[0].ct=0+p[0].bt;
for(i=1;i<=n;i++){
p[i].ct=p[i-1].ct+p[i].bt;
}
for(i=0;i<n;i++){
p[i].tat=p[i].ct-0;
}
p[i].wt=0;
for(i=0;i<n;i++){
p[i].wt=p[i].tat-p[i].bt;
}
p[0].rt=0;
for(i=0;i<n;i++){
p[i].rt=p[i-1].ct-0;
}

cout<<"Before FSFC is complete"<<endl;
cout<<"Process no"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<"\t"<<"RT"<<endl;
for(i=0;i<n;i++){
cout<<"\t"<<p[i].id<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<endl;
}
int ttat=0, twt=0;

for(i=0;i<n;i++){

ttat=ttat+p[i].tat;
twt=twt+p[i+1].wt;
}
float atat;
float awt;
atat=(float)ttat/(float) n;
awt=(float)twt/(float)n;
cout<<"\n"<<"\n"<<"Average Turn Around Time is= "<<atat;
cout<<"\n"<<"\n"<<"Average Waiting Time is= "<<awt;
getch();
}
