#include<stdio.h>
int main()
{
int i,j,n,ref_str[50],frame[10],no,k,avail,fcount=0;
printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
printf("\n ENTER THE PAGE NUMBER :\n");
for(i=1;i<=n;i++)
scanf("%d",&ref_str[i]);
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&no);
for(i=0;i<=no;i++)
frame[i]=-1;
j=0;
printf("\n ref string \t page frames \tHit/fault\n");
for(i=1;i<=n;i++)
{
printf("%d\t\t",ref_str[i]);
avail=0;
for(k=0;k<no;k++)
if(frame[k]==ref_str[i])
{
avail=1;
for(k=0;k<no;k++)
printf("%d\t",frame[k]);
printf("H");
}
if(avail==0)
{
frame[j]=ref_str[i];
j=(j+1)%no;
fcount++;
for(k=0;k<no;k++)
printf("%d\t",frame[k]);
printf("F");
}
printf("\n");
}
printf("Page Fault is %d",fcount);
return 0;
}
/*
 ENTER THE NUMBER OF PAGES:
7

 ENTER THE PAGE NUMBER :
24
43
55
65
76
76
45

 ENTER THE NUMBER OF FRAMES :5

 ref string      page frames    Hit/fault
24              24      -1      -1      -1      -1      F
43              24      43      -1      -1      -1      F
55              24      43      55      -1      -1      F
65              24      43      55      65      -1      F
76              24      43      55      65      76      F
76              24      43      55      65      76      H
45              45      43      55      65      76      F
Page Fault is 6*/
