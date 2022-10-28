include<stdio.h>
int main()
{
int ms, bs, nob, ef,n, mp[10],tif=0;
int i,p=0;
printf("Enter the total memory available(in bytes)--");
scanf("%d"&ms);
printf("Enter the block size (in bytes)--");
scanf("%d", &bs);
nob=ms/bs;
ef=ms - nob*bs;
printf("\nEnter the no of processes -- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter memory required for process %d (in Bytes)-- ",i+1);
scanf("%d",&mp[i]);
}
printf("\nNo. Of Blocks available in memory -- %d",nob);
printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
for(i=0;i<n && p<nob;i++)
{
printf("\n %d\t\t%d,i+1,mp[i]);
if(mp[i]>bs)
printf("\t\tNO\t\t---");
else
{
printf("\t\tYES\t%d",bs-mp[i]);
tif=tif+bs-mp[i];
p++;
}
}
if(i<n)
printf("\nmemory is full,Remaining process cannot be accomdated");
printf("\n\nTotal internal fragment is %d",tif);
printf("Total external fragmentation is %d",ef);
}
