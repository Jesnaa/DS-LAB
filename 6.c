#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *l;
struct node *r;
}*root=NULL,*temp=NULL,*t1,*t2;
void insert();
void create();
void search(struct node *t);
void search1(struct node *t,int data);
void inorder(struct node *t);
void delete();
void delete1();
int smallest(struct node *t);
int largest(struct node *t);
int flag = 1;
int main()
{
int ch;
printf("\nOPERATIONS ---");
printf("\n1 - Insert an element into tree\n");
printf("2 - Inorder Traversal\n");
printf("3 - Delete a node \n");
printf("4 - Exit\n");
do
{
printf("\nEnter your choice : ");
scanf("%d", &ch);
switch (ch)
{
case 1:
insert();
break;
case 2:inorder(root);
break;
case 3:delete();
break;
case 6:printf("\nInvalid option\n");
exit(0);
default :
printf("Wrong choice, Please enter correct choice ");
break;
}
}while(ch<4);
}
void insert()
{
create();
if (root == NULL)
root = temp;
else
search(root);
}
void create()
{
int data;
printf("Enter data of node to be inserted : ");
scanf("%d", &data);
temp = (struct node *)malloc(1*sizeof(struct node));
temp->data = data;
temp->l = temp->r = NULL;
}
void search(struct node *t)
{
if ((temp->data > t->data) && (t->r != NULL))
search(t->r);
else if ((temp->data> t->data) && (t->r == NULL))
t->r = temp;
else if ((temp->data< t->data) && (t->l != NULL))
search(t->l);
else if ((temp->data < t->data) && (t->l == NULL))
t->l = temp;
}
void inorder(struct node *t)
{
if (root == NULL)
{
printf("No elements in a tree to display");
return;
}
if (t->l != NULL)
inorder(t->l);
printf("%d ->", t->data);
if (t->r != NULL)
inorder(t->r);
}
void delete()
{
int data;
if (root == NULL)
{
printf("No elements in a tree to delete");
return;
}
printf("Enter the data to be deleted : ");
scanf("%d", &data);
t1 = root;
t2 = root;
search1(root, data);
}
void search1(struct node *t, int data)
{
if ((data>t->data))
{
t1 = t;
search1(t->r, data);
}
else if ((data < t->data))
{
t1 = t;
search1(t->l, data);
}
else if ((data==t->data))
{
delete1(t);
} }
void delete1(struct node *t)
{
int k;
if ((t->l == NULL) && (t->r == NULL))
{
if (t1->l == t)
{
t1->l = NULL;
}
else
{
t1->r = NULL;
} t
= NULL;
free(t);
return;
}
else if ((t->r == NULL))
{
if (t1 == t)
{
root = t->l;
t1 = root;
}
else if (t1->l == t)
{
t1->l = t->l;
}
else
{
t1->r = t->l;
} t
= NULL;
free(t);
return;
}
else if (t->l == NULL)
{
if (t1 == t)
{
root = t->r;
t1 = root;
}
else if (t1->r == t)
t1->r = t->r;
else
t1->l = t->r;
t == NULL;
free(t);
return;
}
else if ((t->l != NULL) && (t->r != NULL))
{
t2 = root;
if (t->r != NULL)
{
k = smallest(t->r);
flag = 1;
}
else
{
k =largest(t->l);
flag = 2;
}
search1(root, k);
t->data = k;
} }
int smallest(struct node *t)
{
t2 = t;
if (t->l != NULL)
{
t2 = t;
return(smallest(t->l));
}
else
return (t->data);
}
int largest(struct node *t)
{
if (t->r != NULL)
{
t2 = t;
return(largest(t->r));
}
else
return(t->data);
}
