#include<stdio.h>
#include<string.h>
void main()
{
char p[10][5];
int et[10],wt[10],timer,count,pt[25],rt,i,j,totwt=0,n,found=0,m,tat[10],ttt=0;
float avgwt;
printf("Enter the no of process:\n");
scanf("%d",&n);
printf("Enter time slice:\n");
scanf("%d",&timer);
for(i=0;i<n;i++)
{
printf("Enter the process name:\n");
scanf("%s",&p[i]);
printf("Enter the process time:\n");
scanf("%d",&pt[i]);
}
m=n;
wt[0]=0;
i=0;
do
{
if (pt[i]>timer)
{
rt=pt[i]-timer;
strcpy(p[n],p[i]);
pt[n]=rt;
et[i]=timer;
n++;
}
else
{
et[i]=pt[i];
}
i++;
wt[i]=wt[i-1]+et[i-1];
}
while(i<n);
count=0;
for(i=0;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(strcmp(p[i],p[j])==0)
{
count++;
found=j;
}
if(found!=0)
{
{
wt[i]=wt[found]-(count*timer);
count=0;
found=0;
}
}
}
for(i=0;i<m;i++)
{
totwt+=wt[i];
tat[i]=wt[i]+pt[i];
ttt=ttt+tat[i];
}
avgwt=(float)totwt/m;
printf("pname \t ptime \t wtime \tturnaroundtime\n");
for(i=0;i<m;i++)
{
printf("\n %s \t %d \t %d \t\t %d",p[i],pt[i],wt[i],tat[i]);
}
printf("\n Total Waiting time: %d \n",totwt);
printf("\n Avgwaiting time: %f",avgwt);
printf("\n Total turnaround time: %d",ttt);
printf("\n Avg turnaround time: %f",(float)ttt/m);
}
