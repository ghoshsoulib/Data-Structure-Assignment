#include <stdio.h>
#include<stdlib.h>

 

#define MAX 100

// making global declaration of some variables

int queue_array[MAX];

int rear = - 1;

int front = - 1;

// main function begins

int main()

{

    int choice;

    while (1)

    {
    	
    	// displaying the choice

        printf("1.En-queue\n");

        printf("2.De-queue \n");

        printf("3.Display  \n");

        printf("4.Quit \n");
        
        printf("5.Empty \n");
        
        printf("6. Size \n");

        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:

            insert();

            break;

            case 2:

            delete();

            break;

            case 3:

            display();

            break;

            case 4:

            exit(1);
            
            case 5:
            
            empty();
            
            break;
            
            case 6:
            
            size();
            
            break;

            default:

            printf("Wrong choice \n");

        } /*End of switch*/

    } /*End of while*/
    return 0;

} /*End of main()*/



void insert()

{

    int add_item;

    if (rear == MAX - 1)

    printf("Queue Overflow \n");

    else

    {

        if (front == - 1)

        /*If queue is initially empty */

        front = 0;

        printf("Enter the data in queue : ");

        scanf("%d", &add_item);

        rear = rear + 1;

        queue_array[rear] = add_item;

    }

} /*End of insert()*/

 

void delete()

{

    if (front == - 1 || front > rear)

    {

        printf("Queue Underflow \n");

        

    }

    else

    {

        printf("Element deleted from queue is : %d\n", queue_array[front]);

        front = front + 1;

    }

} /*End of delete() */

void display()

{

    int i;

    if (front == - 1)

        printf("Queue is empty \n");

    else

    {

        printf("Queue is : \n");

        for (i = front; i <= rear; i++)

            printf("%d ", queue_array[i]);

        printf("\n");

    }

}

void empty()
{
	 if (front == - 1 || front > rear) printf("the queue is empty\n");
	else printf("the queue is not empty\n");
}


void size()
{
	if (front == - 1 || front > rear) {
		printf("the size is zero\n");
		}
		
	
	else printf("the size of the queue is %d\n",(rear - front + 1));
}

