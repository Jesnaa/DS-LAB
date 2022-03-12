#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int len,i=0;
int str1[10],str2[10],str3[10];
int opt,c;
printf("\n Enter the length of the sets: ");
scanf("%d",&len);
printf("\n Enter the bits of first set:\n");
for(i=0;i<len;i++)
{
scanf("%d",&c);
if(c<0 || c>1)
printf("\n Input Error \n Please enter in binary format\n");
else
str1[i]=c;
}
printf("\n Enter the bits of second set:\n");
for(i=0;i<len;i++)
{
scanf("%d",&c);
if(c<0 || c>1)
printf("\n Input Error\n Please enter in binary format\n");
else
str2[i]=c;
}
printf("\n Union of the above set is\n");
for(i=0;i<len;i++)
{
if((str1[i]||str2[i])==1)
printf("1 ");
else
printf("0 ");
}
printf("\n Intersection of the above set is\n");
for(i=0;i<len;i++)
{
printf(str1[i]*str2[i]);
}
printf("\n The set difference of the above 2 sets are:\n");
for(i=0;i<len;i++)
{
str3[i]=!(str2[i]);
str3[i]=str1[i]||str3[i];
printf("%d ",str3[i]);
}
}
