#include<stdio.h>
#include<stdlib.h>

struct data
{
	int number;
	struct data *previous;
	struct data *next;
};
typedef struct data NODE;

NODE *phead = NULL;
NODE *creat(int);
void Link(int);
void Delink(int);
void BackInsert(int,int);
void FrontInsert(int,int);
void ShowLink(NODE *);

int main()
{
	int op,flag = 1;
	int a,b;
	
	while(flag)
	{
		printf("======================================\n");
		printf("1.Link a node\n");
		printf("2.Delete a node\n");
		printf("3.Insert a node(Back a number)\n");
		printf("4.Insert a node(Front a number)\n");
		printf("5.Show this linked list\n");
		printf("6.Quit\n");
		printf("======================================\n");
		printf("What do you want to do? ");
		scanf("%d",&op);
		fflush(stdin);
		
		switch(op)
		{
			case 1:
				printf("Add a number:");
				scanf("%d",&a);
				fflush(stdin);
				Link(a);
				printf("\n********************************\n");
				ShowLink(phead);
				printf("********************************\n");
				break;
			case 2:
				printf("Delete a number:");
				scanf("%d",&a);
				fflush(stdin);
				Delink(a);
				printf("\n********************************\n");
				ShowLink(phead);
				printf("********************************\n");
				break;
			case 3:
				printf("input x,y you can insert a nuber 'y' after x:");
				scanf("%d %d",&a,&b);
				fflush(stdin);
				BackInsert(a,b);
				printf("\n********************************\n");
				ShowLink(phead);
				printf("********************************\n");
				break;
			case 4:
				printf("input x,y you can insert a nuber 'y' before x:");
				scanf("%d %d",&a,&b);
				fflush(stdin);
                FrontInsert(a,b);
                printf("\n********************************\n");
				ShowLink(phead);
				printf("********************************\n");
				break;
			case 5:
				ShowLink(phead);
				break;
			case 6:
				flag = 0;
				break;
			default:
				break;
		}
	}
	return 0;	
}

NODE *creat(int i)
{
	NODE *New;
	New = (struct data*)malloc(sizeof(struct data));
	New -> number = i;
	New -> previous = NULL;
	New -> next = NULL;
	return New;
}

void Link(int i)
{
	NODE *ptr, *temp;
	temp = creat(i);
	
	if(phead == NULL)
	{
		phead = temp;
		temp -> previous = phead;
	}
	else
	{
		ptr = phead;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		ptr -> next = temp;
		temp -> previous = ptr;
	}
}

void Delink(int i)
{
	NODE *ptr;
	ptr = phead;
	
	if(ptr == NULL)
	{
		printf("\n****Empty*****\n");
	}
	else if(ptr -> number == i)
	{
		if(ptr -> next == NULL)
		{
			phead = NULL;
			free(ptr);
			return;
		}
		phead = ptr -> next;
		ptr -> next -> previous = phead;
		free(ptr);
	}
	else
	{
		while(ptr -> number != i && ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		
		if(ptr -> number != i && ptr -> next == NULL)
		{
			printf("\n****Not Found****\n");
		}
		else if(ptr -> number == i && ptr -> next == NULL)
		{
			ptr -> previous -> next = NULL;
			free(ptr);
		}
		else
		{
			ptr -> previous -> next = ptr -> next;
			ptr -> next -> previous = ptr -> previous;
			free(ptr);
		}
	}
}

void BackInsert(int i, int j)
{
	NODE *ptr, *temp;
	ptr = phead;
	temp = creat(j);
	
	if(phead == NULL)
	{
		printf("\n****ERROR, List is empty****\n");
	}
	
	while(ptr -> number != i && ptr -> next != NULL)
	{
		ptr = ptr -> next;
	}
	
	if(ptr -> number != i && ptr -> next == NULL)
	{
		printf("\n****ERROR, Not Found %d****\n",i);
	}
	else if(ptr -> number == i && ptr -> next == NULL)
	{
		temp -> next = ptr -> next;
		ptr -> next = temp;
		temp -> previous = ptr;
	}
	else
	{
		temp -> next = ptr -> next;
		ptr -> next -> previous = temp;
		ptr -> next = temp;
		temp -> previous = ptr;
	}
}

void FrontInsert(int i, int j)
{
	NODE *ptr, *temp;
	temp = creat(j);
	ptr = phead;

	if(phead == NULL)
	{
		printf("\n****ERROR, List is empty****\n");
	}
	else if(ptr -> number == i)
	{	
		phead = temp;
		ptr -> previous = temp;
		temp -> next = ptr;
		temp -> previous = phead;
		return;
	}
	
	while(ptr -> number != i && ptr -> next != NULL)
	{
		ptr = ptr -> next;
	}
	
	if(ptr -> number != i && ptr -> next == NULL)
	{
		printf("\n****ERROR, Not Found %d****\n",i);
	}
	else
	{
		temp -> next = ptr;
		temp -> previous = ptr -> previous;
		ptr -> previous -> next = temp;
		ptr -> previous = temp;
	}
} 

void ShowLink(NODE *ptr)
{
	while(ptr != NULL)
	{
		printf("%p\t| %p,%3d\t| %p\n",ptr->previous, ptr, ptr->number, ptr->next);
		ptr = ptr -> next;
	}
}
