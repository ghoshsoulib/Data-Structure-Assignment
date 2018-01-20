#include<stdio.h>
#include<stdlib.h>

int stack[100],choice,n,top,x,i;
void push();
void pop();
void display();
void empty();
int size();
void Top();
int main()
{
    //clrscr();
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n\t 5.EMPTY\n\t 6. SIZE\n\t 7.EXIT\n\t 8.TOP");
    while(1)
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        case 5:
        {
        	  empty();
        	  break;
        }
        case 6:
        {
            printf("The size of the stack is %d\n",size());
            break;
        }
        case 7:
        {
            return 0;
        }
        case 8:
        {
           Top();
           break;
        }
        
       
        default:
        {
            printf("ENTER PROPER CHOICE");
            break;
        }
        
        }
    }
   return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
       
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
void empty()
{
	if(top == -1) printf("The stack is empty\n");
	else printf("The stack is not empty\n");
}
int size()
{
	
	 return (top+1);
}
void Top()
{
	if(top == -1){
		printf("the stack is empty\n");
		exit(0);
		}
	printf("the top element is %d\n",stack[top]);
}
	

