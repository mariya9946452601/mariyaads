#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main()
{
int opt,data,found;
//working the for loop infinitely
for(;;)
{
printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt){
case 1:
printf("Enter the element to insert:");
scanf("%d",&data);
sp=push(sp,data);
break;
case 2:
if(sp==NULL){
printf("stack is empty!\n");}
else{
sp=pop(sp,&data);
printf("Popped element is:%d\n",data);}
break;
case 3:
display(sp);
break;
case 4:
printf("Enter the element to be searched:");
scanf("%d",&data);
found=search(sp,data);
if(found!=0)
printf("The element is %d present.\n",data);
else
printf("%d is not found\n",data);
break;
case 5:
exit(0);
break;}}return 0;}
//function to push an element in the singly linked list.
struct node *push(struct node *sp,int data){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;}
//function to pop an element in the singly linked list.
struct node *pop(struct node *sp,int *x){
struct node *temp;
if(sp!=NULL){
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);}
return sp;}
//function to display an element in the singly linked list.
void display(struct node *sp){
if(sp==NULL){
printf("stack is empty!\n");
return;}
printf("stack elements are:\n");
while(sp!=NULL){
printf("%d\n",sp->data);
sp=sp->next;}}
//function to search an element in the singly linked list.
int search(struct node *sp,int data){
while(sp!=NULL){
if(sp->data==data)
return 1;
sp=sp->next;}
return 0;
}

