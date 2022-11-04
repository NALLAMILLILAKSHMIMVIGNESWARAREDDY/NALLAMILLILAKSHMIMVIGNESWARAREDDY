#include<stdio.h>
int main()
{
int m,mp[10],i,temp,n=0,ms;
char ch='y';
printf("\nEnter the total memory available (in Bytes)--");
scanf("%d",&ms);
temp=ms;
for(i=0;ch=='y';i++,n++)
{
printf("\nEnter memory required for process %d (in Bytes)--",i+1);
scanf("%d",&mp[i]);
if(mp[i]<=temp)
{
printf("\nmemory is allocated for process %d ",i+1);
temp= temp - mp[i];
}
else
{
printf("\nMemory is full");
break;
}
printf("\nDo you want to continue(y/n)--");
scanf(" %c", &ch);
}
printf("\n\nTotal Memory available-- %d",ms);
printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
for(i=0;i<n;i++)
printf("\n \t%d\t\t%d",i+1,mp[i]);
printf("\n\nTotal Memory Allocated is %d",ms-temp);
printf("\nTotal External Fragmentation is %d",temp);
}
