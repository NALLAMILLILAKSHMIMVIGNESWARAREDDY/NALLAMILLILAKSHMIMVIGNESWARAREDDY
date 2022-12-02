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
/*Enter the total memory available (in Bytes)--1000

Enter memory required for process 1 (in Bytes)--128

memory is allocated for process 1
Do you want to continue(y/n)--y

Enter memory required for process 2 (in Bytes)--256

memory is allocated for process 2
Do you want to continue(y/n)--y

Enter memory required for process 3 (in Bytes)--64

memory is allocated for process 3
Do you want to continue(y/n)--y

Enter memory required for process 4 (in Bytes)--512

memory is allocated for process 4
Do you want to continue(y/n)--y

Enter memory required for process 5 (in Bytes)--1024

Memory is full

Total Memory available-- 1000

        PROCESS          MEMORY ALLOCATED
        1               128
        2               256
        3               64
        4               512

*/
