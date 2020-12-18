#include<stdio.h>
#include<stdlib.h>

struct Node
{
	char data;
	struct Node* next;	
}*head=NULL,*tail=NULL;

struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

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

struct Node** push(char data)
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

struct Node** pop(char* val)
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

struct Node* empty()
{
	return head;
}

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
		printf("%c",ptr->data);
		ptr=ptr->next;
	}
	
	return &head;
}

void input_stack(char str[])
{
	int i=0;
	
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
}

void reverse_string(char str[])
{
	int i,cnt=size();
	char ch;
	
	if(!empty())
	{
		printf("\n\nError: The string is empty.");
		return;
	}
	
	for(i=0;i<cnt;i++)
	{
		pop(&ch);
		str[i]=ch;
	}
	
	str[i]='\0';
}

int main()
{ 
	char str[50];
	
	printf("Enter the string:\n");
	
	fflush(stdin);
	scanf("%[^\n]%*c",str); 
	
	input_stack(str);	
	
	char ch;
	
	reverse_string(str);
	
	printf("\n\nThe reversed string is:\n%s",str);
	
	free_all();
}
