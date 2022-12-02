#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main(int argc, char **argv)
{
FILE *fp,*fp1;
int n,count=0;
char buf;
fp=fopen(argv[1],"r");
fp1=fopen(argv[2],"w");
while(!feof(fp))
{
buf=fgetc(fp);
fputc(buf,fp1);
}
fclose(fp);
fclose(fp1);
return (0);

}
/*[21MH1A0542@localhost ~]$ vi copying.c
[21MH1A0542@localhost ~]$ cc copying.c
[21MH1A0542@localhost ~]$ ./a.out
Segmentation fault (core dumped)
[21MH1A0542@localhost ~]$ ./a.out  1 3
[21MH1A0542@localhost ~]$ cat 1
okjwvheoivhoifev
[21MH1A0542@localhost ~]$ cat 3
okjwvheoivhoifev
/*
