#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack[MAX],top=-1,item;
void push();
void pop();
void palindrome();
void display();

void main()
{
int choice;
while(1)
{
Printf("―------- STACK OPERATIONS ------\n―");
printf("1.push\n 2.pop\n 3.palindrome\n 4.display\n 5.exit\n");
printf("enter choice");
scanf("%d",&choice);
switch(choice)
{
case 1:push();
break;
case 2:pop();
break;
case3:palindrome();
break;
case 4:display();
break;
case 5:exit(0);
break;
default:printf("invalidchoice\n");
break;
}
}
}

void push() {
if(top==MAX-1)
printf("stackoverflow");
else {
printf("enter the item to be pushed\n");
scanf("%d",&item);
top=top+1;
stack[top]=item; }}


void pop() {
if(top==-1)
printf("stackunderflow");
else {
item=stack[top];
top=top-1;
printf("deleted item is %d",item);
 }
 }

void display() {
int i;
if(top==-1)
printf("stack is empty");
else {
    printf("stack items are:");
for(i=top;i>=0;i--)
printf("%d\t",stack[i]);
}}


void palindrome()
{
int num[10],i=0,k,flag=1;
k=top;
while(k!=-1)
num[i++]=stack[k--];
for(i=0;i<=top;i++)
{
if(num[i]==stack[i])
continue;
else
flag=0;
}
if(top==-1)
printf("stack is empty");
else
{
if(flag)
printf("palindrome");
else
printf("not a palindrome");
}
}