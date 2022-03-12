#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[20],b[20],c[40];
int n,i,j,temp,m;
printf("\n Enter the size of array 1: ");
scanf("%d",&n);
printf("\n Enter %d elements into the array 1:\n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n Enter the size of array 2:\n");
scanf("%d",&m);
printf("\n Enter %d elements into the array 2: \n",m);
for(i=0;i<m;i++)
scanf("%d",&b[i]);
printf("\n The array 1 contains :\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n The array 2 contains:\n ");
for(i=0;i<m;i++)
printf("%d\t",b[i]);
printf("\n");
for(i=0;i<n;i++)
c[i]=a[i];
printf("%d\t",i);
for(i=n;i<(m+n);i++)
c[i]=b[i-n];
printf("\n THE merged array in unsorted form\n");
for(i=0;i<(m+n);i++)
printf("%d\t",c[i]);
for(i=0;i<(m+n);i++)
{
for(j=0;j<(m+n)-i;j++)
{
if(c[j]>c[j+1])
{
temp=c[j];
c[j]=c[j+1];
c[j+1]=temp;
} } }
printf("\n Sorted merged array is\n");
for(i=0;i<(m+n);i++)
printf("%d\t",c[i]);
}
