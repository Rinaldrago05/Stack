#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;	
}*head=NULL,*tail=NULL;

//-1
struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

//0
void free_all()
{
	struct Node* ptr=head;
	while(ptr)
	{
		head=head->next;
		free(ptr);
		ptr=head;
	}
	
	head=tail=NULL;
}

//1
struct Node** push(int data)
{
	struct Node* nd=create_new_node();
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(head)
	tail->next=nd;
	
	else
	head=nd;
	
	tail=nd;
	
	nd->data=data;
	nd->next=NULL;
	
	return &head;
}


//2
struct Node** pop(int* val)
{
	if(!head)
	{
		printf("\n\nERROR: The stack is empty.");
		return NULL;
	}
	
	if(!head->next)
	{
	
		head=head->next;
		
		*val=tail->data;
		
		free(tail);
		tail=head;
		
		return &head;
	}
	
	struct Node *ptr=head;
	
	while(ptr->next->next)
	ptr=ptr->next;
	
	*val=ptr->next->data;
	
	free(ptr->next);
	ptr->next=NULL;
	
	tail=ptr;
	
	return &head;
}

//3
struct Node** top(int* val)
{
	if(!head)
	{
		printf("\n\nError: The stack is empty.");
		return NULL;
	}
	
	*val=tail->data;
	
	return &head;
}

//4
int size()
{
	if(!head)
	return 0;
	
	struct Node* ptr=head->next;
	int cnt=1;
	
	while(ptr)
	{
		cnt++;
		ptr=ptr->next;
	}
	
	return cnt;
}

//5
struct Node* empty()
{
	return head;
}

//6
struct Node** display()
{
	if(!head)
	{
		printf("\n\nERROR: The stack is empty.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	printf("\n\n");
	
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	return &head;
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
