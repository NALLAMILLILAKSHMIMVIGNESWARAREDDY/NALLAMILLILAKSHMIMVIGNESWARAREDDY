#include<stdio.h>
void main()
{
int a[50],c[10],i,j,k,ps,nop,npf=0,nps=0;
printf("\n\t Enter no of pages :");
scanf("%d",&nop);
printf("\n\tEnter pages :");
for(i=0;i<nop;i++)
{
scanf("%d",&a[i]);
}
printf("\n\tEnter no of pages frames :");
scanf("%d",&ps);
for(i=0;i<nop;i++)
{
for(k=0;c[k]!=a[i]&&k<nps;k++);
if(k==nps)
{
npf++;
if(nps==ps)
for(k=0;k<nps-1;k++)
{
c[k]=c[k+1];
}
c[k]=a[i];
if(nps<ps)
{
nps++;
}
}
else
{
for(j=k;j<nps-1;j++)
{
c[j]=c[j+1];
}
c[j]=a[i];
}
printf("\n");
for(k=0;k<nps;k++)
printf("  %d",c[k]);
}
printf(" \n\tNo of page faults occured are %d",npf);
}

/*[21MH1A0542@localhost ~]$ vi lru.c
[21MH1A0542@localhost ~]$ cc lru.c
[21MH1A0542@localhost ~]$ ./a.out

         Enter no of pages :7

        Enter pages :12
14
74
78
73
65
85

        Enter no of pages frames :7

  12
  12  14
  12  14  74
  12  14  74  78
  12  14  74  78  73
  12  14  74  78  73  65
  12  14  74  78  73  65  85
        No of page faults occured are 7*/
