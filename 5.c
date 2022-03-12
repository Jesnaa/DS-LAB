#include<stdio.h>
#include<stdlib.h>
int count=0;
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search_key();
void traverse_list();
struct node
{
int data;
struct node *prev;
struct node *next;
}*head=NULL;
void main()
{
int opt,item;
do
{
printf("\n SELECT A VALID OPTION FROM THE MENU\n");
printf("\n1. INSERTION AT BEGINNING\n");
printf("\n2. INSERTION AT END\n");
printf("\n3. INSERTION AT A GIVEN POSITION\n");
printf("\n4. DELETION AT BEGINNING\n");
printf("\n5. DELETION AT END\n");
printf("\n6. DELETION AT A PARTICULAR POSITION\n");
printf("\n7. SEARCH FOR AN ITEM\n");
printf("\n8. DISPLAY LIST\n");
printf("\n9. EXIT\n");
scanf("%d",&opt);
switch(opt)
{
case 1: insert_begin();
break;
case 2: insert_end();
break;
case 3: insert_pos();
break;
case 4: delete_begin();
break;
case 5: delete_end();
break;
case 6: delete_pos();
break;
case 7: search_key();
break;
case 8: traverse_list();
break;
case 9: exit(0);
default: printf("\n Invalid Option\n");
} }
while(opt!=9);
}
void insert_begin()
{
int item;
printf("\n enter a value: ");
scanf("%d",&item);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=item;
if(head==NULL)
{
head=newnode;
newnode->prev=NULL;
newnode->next=NULL;
count++;
}
else
{
struct node *temp=head;
temp->prev=newnode;
newnode->prev=NULL;
newnode->next=temp;
head=newnode;
count++;
}
printf("\n the items in the list are:\n");
traverse_list();
}
void insert_end()
{
int item;
printf("\n enter a value: ");
scanf("%d",&item);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=item;
if(head==NULL)
{
head=newnode;
newnode->prev=NULL;
newnode->next=NULL;
count++;
}
else
{
struct node *temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
newnode->prev=temp;
newnode->next=NULL;
count++;
}
printf("\n the items in the list are\n");
traverse_list();
}
void insert_pos()
{
int item,pos,i=1;
struct node *temp=head;
printf("\n enter a value: ");
scanf("%d",&item);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=item;
printf("\n Enter the position to which the new node is to be inserted: ");
scanf("%d",&pos);
if(pos>count)
{
printf("\n invalid position\n");
}
while(temp->next!=NULL&&i!=pos-1)
{
temp=temp->next;
i++;
}
if(i==pos-1)
{
newnode->next=temp->next;
temp->next=newnode;
newnode->prev=temp;
count++;
}
else
{
if(pos==count)
{
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
newnode->next=NULL;
newnode->prev=temp;
count++;
}
else
printf("\n POSITION not found in list\n");
}
printf("\n the items in the list are\n");
traverse_list();
}
void delete_begin()
{
struct node *temp=head;
if(head==NULL)
printf("\n doubly linked list is empty\n");
else
{
if(temp->next==NULL)
{
temp->prev=NULL;
head=NULL;
printf("\n the item %d has been deleted\n",temp->data);
free(temp);
count--;
traverse_list();
}
else
{
head=temp->next;
temp->next->prev=NULL;
temp->prev=NULL;
temp->next=NULL;
printf("\n the item %d has been deleted from beginning\n",temp->data);
free(temp);
count--;
printf("\n the items in the list are\n");
traverse_list();
} } }
void delete_end()
{
struct node *temp=head;
if(head==NULL)
printf("\n doubly linked list is empty\n");
else if(temp->next==NULL)
{
printf("\n the item %d has been deleted\n",temp->data);
temp->prev=NULL;
temp->next=NULL;
head=NULL;
free(temp);
count--;
printf("\n the items in the list are\n");
traverse_list();
}
else
{
while(temp->next!=NULL)
temp=temp->next;
temp->prev->next=NULL;
temp->prev=NULL;
printf("\n the item %d has been deleted from end\n",temp->data);
free(temp);
count--;
printf("\n the items in the list are\n");
traverse_list();
} }
void delete_pos()
{
int pos,i=1;
struct node *temp=head;
if(head==NULL)
printf("\n the doubly linked list is empty\n");
else
{
printf("\n enter the position of node to be deleted: ");
scanf("%d",&pos);
if(pos>count)
printf("\n position is not within the list\n");
else
{
while(temp->next!=NULL&&pos!=i)
{
temp=temp->next;
i++;
}
temp->prev->next=temp->next;
temp->prev=NULL;
temp->next=NULL;
printf("\n the item %d has been deleted",temp->data);
free(temp);
count--;
printf("\n the items in the doubly linked list are\n");
traverse_list();
} } }
void traverse_list()
{
struct node *temp=head;
if(head==NULL)
printf("\n list is empty\n");
else
{
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
} } v
oid search_key()
{
int item;
printf("\n enter an item to be searched: \n");
scanf("%d",&item);
struct node *temp=head;
while(temp->data!=item&&temp->next!=NULL)
temp=temp->next;
if(temp->data==item)
printf("\n the item %d found in the list",item);
else
printf("\n the item %d not found in the list\n",item);
}
