#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
int data;
struct node *next;
}*front=NULL;
struct node *rear=NULL;
struct node *newnode;
void create_node()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("\n enter a value for the node: ");
scanf("%d",&newnode->data);
}
void main()
{
int opt;
do
{
printf("\n SELECT A CHOICE\n");
printf("\n1. ENQUEUE\n");
printf("\n2. DEQUEUE\n");
printf("\n3. DISPLAY\n");
printf("\n4. EXIT\n");
scanf("%d",&opt);
switch(opt)
{
case 1: enqueue();
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("\n Invalid Choice\n");
} }
while(opt!=4);
}
void enqueue()
{
create_node();
if(front==NULL && rear==NULL)
{
front=newnode;
rear=newnode;
newnode->next=front;
}
else
{
struct node *temp=front;
while(temp->next!=front)
temp=temp->next;
newnode->next=temp->next;
temp->next=newnode;
rear=newnode;
}
display();
}
void dequeue()
{
if(front==NULL&&rear==NULL)
printf("\n QUEUE IS empty\n");
else
{
if(front->next==front)
{
printf("\n the node %d has been deleted",front->data);
front=NULL;
rear=NULL;
}
else
{
struct node *temp=front;
struct node *temp1=front;
while(temp->next!=front)
temp=temp->next;
temp->next=front->next;
front=front->next;
printf("\n the node %d has been deleted\n",temp1->data);
free(temp1);
}
display();
} }
void display()
{
if(front==NULL)
printf("\n the CIRCULAR QUEUE IS empty...!!!\n");
else
{
struct node *temp=front;
while(temp->next!=front)
{
printf("%d\t",temp->data);
temp=temp->next;
}
printf("%d\t",temp->data);
}
