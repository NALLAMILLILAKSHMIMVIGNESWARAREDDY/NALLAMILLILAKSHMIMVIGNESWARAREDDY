#include<stdio.h>
main()
{
int n,m[20],i,j,sb[20],s[20],b[20][20],x;
printf("\nenter no.of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n enter starting block and size of file %d:",i+1);
scanf("%d%d",&sb[i],&s[i]);
printf("\n enter blocks occupied by file %d:",i+1);
scanf("%d",&m[i]);
printf("\n enter blocks of file%d:",i+1);
for(j=0;j<m[i];j++)
scanf("%d",&b[i][j]);
}
printf("\n file\t index\t length \n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\n",i+1,sb[i],m[i]);
}
printf("\n enter file name :");
scanf("%d",&x);
printf("file name is:%d\n",x);
i=x-1;
printf("index is:%d",sb[i]);
printf("\n block occupied are:");
for(j=0;j<m[i];j++)
printf("%3d\n",b[i][j]);
}
