#include <stdio.h>
#include <stdlib.h>

int a[20],b[20],c[20],i,m,n;



void set_union(int a[],int b[],int m){

printf("after Union operation\n");
for( i=0;i<m;i++){
    c[i]=a[i]||b[i];
    printf("%d\t",c[i]);
}
return;

}

void set_intersection(int a[],int b[],int m){

printf("after intersection operation\n");
for(i=0;i<m;i++){
    c[i]=a[i]&&b[i];
    printf("%d\t",c[i]);
}
return;

}

void set_difference(int a[],int b[],int m){

printf("after Difference operation\n");
for( i=0;i<m;i++){
    c[i]=!b[i]&&a[i];
    printf("%d\t",c[i]);
}
return;

}


void main(){

int m,n,p;
printf("enter the size of 1st set\n");
scanf("%d",&m);
printf("enter the zeros and ones based on condition\n");
for(i=0;i<m;i++){
    main:
    scanf("%d",&p);
    if (p==0 || p==1){
        a[i]=p;
    }
    else{
        printf("set only accept 0's and 1's please enter a valid number");
        goto main;
    }

}

printf("enter the size of 2nd set\n");
scanf("%d",&n);
printf("enter the zeros and ones based on condition\n");
for(i=0;i<n;i++){
    main2:
    scanf("%d",&p);
    if (p==0 || p==1){
        b[i]=p;
    }
    else{
        printf("set only accept 0's and 1's please enter a valid number");
        goto main2;
    }

}



while(1){
    int x;
    printf("\n---------------------SET MENU-----------------------\n");
    printf("1. Union\n 2. Intersection\n 3. Difference\n 0. exit\n enter the option below\n");
    scanf("%d",&x);
    switch(x){

    case 1: if(m==n)
                set_union(a,b,m);
            else
                printf("union perform only same size of array\n");
                exit(1);
            break;
    case 2: if(m==n)
                set_intersection(a,b,m);
            else
                printf("intersection perform only same size of array\n");
                exit(1);
            break;
    case 3: if(m==n)
                set_difference(a,b,m);
            else
                printf("difference perform only same size of array\n");
                exit(1);
            break;
    case 0:exit(1);
    default: printf("invalid option\n");


    }

}

}
