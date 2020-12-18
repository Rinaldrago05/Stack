#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int top;
	int* arr;
}*s=NULL;

struct stack* initialise_structure()
{
	s=(struct stack*)calloc(1,sizeof(struct stack));
	s->top=-1;
	
	return s;
}

int* initialise_array()
{
	return s->arr=(int*)calloc(1,sizeof(int));
}

int* reallocate(int val)
{
	return (s->arr=(int*)realloc(s->arr,((s->top+val)*sizeof(int))));
}

//1
struct stack* push(int val)
{
	if(s->top==-1 && !initialise_array())
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;	
	}
		
	if(s->top!=-1 && !reallocate(2))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;
	}
	
	s->top++;
	s->arr[s->top]=val;
	
	return s;
	
}

//2
struct stack* pop(int* val)
{
	if(s->top==-1)
	{
		printf("\n\nError: The stack is empty.");
		return NULL;
	}
	
	*val=s->arr[s->top];
	
	if(!reallocate(0))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;
	}
	
	s->top--;
	
	if(s->top==-1)
	s->arr=NULL;
	
	return s;
}

//3
struct stack* top(int* val)
{
	if(s->top==-1)
	{
		printf("\n\nError: The stack is empty.");
		return NULL;
	}
	
	*val=s->arr[s->top];
	
	return s;
}

//4
int size()
{	
	if(s->top==-1)
	printf("\n\nError: The stack is empty.");
	
	return (s->top)+1;	
} 

//5
int* empty()
{
	return s->arr;
}

//6
struct stack* display()
{
	if(s->top==-1)
	{
		printf("\n\nError: The stack is empty.");
		return NULL;
	}
	
	int i;
	printf("\n\n");
	for(i=0;i<=s->top;i++)
	printf("%d ",s->arr[i]);
	
	return s;
}

void free_all()
{
	free(s->arr);
	free(s);
}

void menu()
{
	printf(" MENU:\n-------\n");
	printf("\n1) Push.");
	printf("\n2) Pop.");
	printf("\n3) Top.");
	printf("\n4) Size.");
	printf("\n5) Empty.");
	printf("\n6) Display.");
	printf("\n7) Re-display the menu.");
	printf("\n0) Exit.");
}

int main()
{
	if(!(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return 0;
	}
	
	menu();
	
	printf("\n\n");
	int i,ch,val;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be pushed: ");
						scanf("%d",&val);
						if(push(val))
						printf("\n\nMessage: Successfully pushed the value '%d' inside the stack.",val);
						break;
			
			case 2: 	if(pop(&val))						
						printf("\n\nMessage: The item successfully popped out of the stack is: %d",val);
						break;
			
			case 3:		if(top(&val))
						printf("\n\nMessage: The item pointed present at the top of the stack is: '%d'",val);
						break;
			
			case 4:		printf("\n\nMessage: The number of elements present in the stack is: '%d'",size());
						break;
						
			case 5:		if(!empty())
						printf("\n\nMessage: The stack is empty.");
						else
						printf("\n\nMessage: The stack is not empty.");
						break;
			
			case 6:		printf("\n\nMessage: Displaying the whole stack.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole stack.");
						break;
				
			case 7:		printf("\n\nMessage: Re-displaying the menu.\n\n");
						menu();
						break;
			
			default:	printf("\n\nError: Wrong choice.");
						break;
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	free_all();
	
	printf("\n\nMessage: Program successfully exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\n");
}
