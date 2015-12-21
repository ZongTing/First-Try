#include<stdio.h> 
#include<stdlib.h>

struct data
{
	int number;
	struct data *left;
	struct data *right;
};
typedef struct data NODE;

NODE *creat(int);
NODE *phead = NULL;
void Insert(int);
void Inorder(NODE *);
void Preorder(NODE *);
void Postorder(NODE *);

int main()
{
	int num;
	FILE *inptr;
	
	inptr = fopen("Node.txt","r");
	
	while((fscanf(inptr,"%d",&num)) != EOF)
	{
		printf("¥HÅª¤J%d\n",num);
		Insert(num);
	} 
	
	printf("\n¤¤§Ç°lÂÜ:\n");
	Inorder(phead);
	printf("\n«e§Ç°lÂÜ:\n");
	Preorder(phead);
	printf("\n«á§Ç°lÂÜ:\n");
	Postorder(phead);
	
	fclose(inptr);
	return 0;
}

NODE *creat(int i)
{
	NODE *New;
	New = (struct data*)malloc(sizeof(struct data));
	New -> number = i;
	New -> left = NULL;
	New -> right = NULL;
	return New; 
}

void Insert(int i)
{
	NODE *ptr, *temp;
	temp = creat(i);
	ptr = phead;
	int flag = 1;
	
	if(ptr == NULL)
	{
		phead = temp;
	}
	else
	{
		while(flag)
		{
			if(i < ptr -> number)
			{
				if(ptr -> left == NULL)
				{
					ptr -> left = temp;
					flag = 0;
				}
				else
				{
					ptr = ptr -> left;
				}
			}
			else if(i > ptr -> number)
			{
				if(ptr -> right == NULL)
				{
					ptr -> right = temp;
					flag = 0;
				}
				else
				{
					ptr = ptr -> right;
				}
			}
			else
			{
				printf("*****ERROR,­«½Æ!!*****\n");
				break;
			}
		}
	}
	
}

void Inorder(NODE *ptr)
{
	if(ptr != NULL)
    {
	  	Inorder(ptr->left);			//¨«³X¥ª¤l¾ð 
	  	printf("%d ",ptr->number);	//¨«³X¦C¦L¾ð®Ú 
	  	Inorder(ptr->right);		//¨«³X¥k¤l¾ð 
	}
}

void Preorder(NODE *ptr)
{
	if(ptr != NULL)
	{
		printf("%d ",ptr->number);
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
}

void Postorder(NODE *ptr)
{
	if(ptr != NULL)
	{
		Postorder(ptr->left);
		Postorder(ptr->right);
		printf("%d ",ptr->number);
	}
}
