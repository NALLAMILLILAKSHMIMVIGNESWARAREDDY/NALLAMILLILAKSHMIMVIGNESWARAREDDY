#include<stdio.h>
main()
{
int n,m[20],i,j,sb[20],s[20],b[20][20],x;
printf("\nEnter no. of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
printf("\nEnter starting block and size of file%d:",i+1);
scanf("%d%d",&sb[i],&s[i]);
printf("\nEnter blocks occupied by file%d:",i+1);
scanf("%d",&m[i]);
printf("\nenter blocks of file%d:",i+1);
for(j=0;j<m[i];j++)
scanf("%d",&b[i][j]);
 }
printf("\nFile\t index\tlength\n");
for(i=0;i<n;i++)
 {
printf("%d\t%d\t%d\n",i+1,sb[i],m[i]);
 }
printf("\nEnter file name:");
scanf("%d",&x);
printf("\nfile name is:%d\n",x);
i=x-1;
printf("Index is:%d",sb[i]);
printf("\nBlock occupied are:");
for(j=0;j<m[i];j++)
printf("%3d\n",b[i][j]);
}
