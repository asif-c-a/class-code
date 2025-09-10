#include <stdio.h>

int push(int stack[], int top)
{
	if(top < 10 - 1)
	{
		int e;
		top++;
		
		printf("Input element to be pushed to stack : ");
		scanf("%d", &e);
		stack[top] = e;
	}else{
		printf("Stack Overflow!\n");
	}

	return top;
}

int pop(int stack[], int top)
{
	if (top == -1)
	{
		printf("Stack Underflow!\n");
	}else{
		printf("The element %d is popped.\n", stack[top]);
		stack[top] = -1;
		top--;
	}

	return top;
}

int peek(int stack[], int top)
{
	printf("The top element in stack is %d.\n", stack[top]);
}

int display(int stack[], int top)
{
	printf("The stack is : [ ");

	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}

	printf("]\n--------------------\n");
}

int main()
{
	int stack[10], ch, top = -1, flag = 1;

	do
	{
		printf("1. Push element\n2. Pop element\n3. Peek stack\n4. Display stack\n5. Exit\n");
		printf("Select option [1/2/3/4/5] : ");
		
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
				top = push(stack, top);
				printf("\n--------------------\n");
				break;
			
			case 2:
				top = pop(stack, top);
				printf("\n--------------------\n");
				break;
			
			case 3:
				peek(stack, top);
				printf("\n--------------------\n");
				break;
			
			case 4:
				display(stack, top);
				break;
			
			case 5:
				flag = 0;
				printf("Exiting...\n");
				break;
				
			default:
				printf("Incorrect choice.\n");
		}

	}while(flag);

	return 0;
}