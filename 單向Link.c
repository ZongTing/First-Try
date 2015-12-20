#include<stdio.h>
#include<stdlib.h>

struct data
{
	int number;
	struct data *next;
};
typedef struct data NODE;

NODE *phead = NULL;
NODE *creat(int);
void link(int);
void delink(int);
void insert(int,int);
void showlink(NODE*);

int main()
{
	int op,flag=1,a,b;
	
	do
	{
		printf("\n'L':Link a node.\n'I':Insert a node.\n'D':Delete a node.\n'P':Print this linked list.\nwhat do you want to do?");
        scanf(" %c",&op);
		
		switch(op)
		{
			case 'l':
			case 'L':
				printf("you can add a nuber to this link:");
				scanf("%d",&a);
				link(a);
				printf("\n==================================================\n");
				showlink(phead);
				printf("==================================================\n");
				break;
				
			case 'i':
			case 'I':
				printf("input x,y you can insert a nuber 'y' after x:");
				scanf("%d%d",&a,&b);
				insert(a,b);
				printf("\n==================================================\n");
				showlink(phead);
				printf("==================================================\n");
				break;
				
			case 'd':
			case 'D':
				printf("delete a nuber from this link:");
				scanf("%d",&a);
				delink(a);
				printf("\n==================================================\n");
				showlink(phead);
				printf("==================================================\n");
				break;
				
			case 'p':
			case 'P':
				printf("\n==================================================\n");
				printf("==================================================\n");
				break;
				
			default:
				flag = 0;
				break;	
		}
		
	}while(flag);
	
	system("PAUSE");
	return 0;
}

NODE *creat(int i)
{
	NODE *New;
	New = (struct data*)malloc(sizeof(struct data));
	New -> number = i;
	New -> next = NULL;
	return New;
}

void link(int i)
{
	NODE *ptr,*temp;
	temp = creat(i);
	
	if(phead == NULL)
	{
		phead = temp;
	}
	else
	{
		ptr = phead;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		ptr -> next = temp;
		
	}
}

void delink(int i)
{
	NODE *ptr, *temp;
	ptr = phead;
	temp = phead -> next;
	
	if(ptr -> number == i)
	{
		phead = ptr -> next;
		free(ptr);
	}
	else
	{
		while((temp -> number != i) && (temp -> next != NULL))
		{
			ptr = ptr -> next;
			temp = temp -> next;
		}
		ptr -> next = temp -> next;
		free(temp);
	}
	
}

void insert(int i,int j)
{
	NODE *ptr, *temp;
	temp = creat(j);
	ptr = phead;
	
	while((ptr -> number != i) && (ptr -> next != NULL))
	{
		ptr = ptr -> next;
	}
	temp -> next = ptr -> next;
	ptr -> next = temp;
}

void showlink(NODE *ptr)
{
	while(ptr != NULL)
	{
		printf("%p\t| %d\t| %p\n",ptr,ptr->number,ptr->next);
		ptr = ptr->next;
	}	
}
