#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct student
{
	int exno;
	int marks;
};

int hash(int exno)
{
	return exno%SIZE;
}

int insert(struct student s[],struct student p)
{
	int index,i,flag=0;
	index=hash(p.exno);
	if(s[index].exno==-1)
	{
		s[index].exno=p.exno;
		s[index].marks=p.marks;
	}
	else if(s[index].exno==p.exno)
		{
			return -1;
		}
	else
	{
		for(i=index+1;i<SIZE;i++)
		{
			if(s[i].exno==-1)
			{
				s[i].exno=p.exno;
				s[i].marks=p.marks;
				flag++;
				break;
			}
			
		}
		if(flag==0)
		{
			for(i=0;i<index;i++)
			{
				if(s[i].exno==-1)
				{
					s[i].exno=p.exno;
					s[i].marks=p.marks;
					flag++;
					break;
				}
			}
		}
	}
	if(flag==0)
	{
		return -2;
	}
	return 0;
}

int search(struct student s[],struct student p)
{
	int index,i,flag=0;
	index=hash(p.exno);
	if(s[index].exno==-1)
	{
		return -1;
	}	
	else if(s[index].exno==p.exno)
	{
		return index;
	}
	else
	{
		for(i=index+1;i<SIZE;i++)
		{
			if(s[i].exno==p.exno)
			{
				flag++;
				return i;
			}
		}
		if(flag==0)
		{
			for(i=0;i<index;i++)
			{
				if(s[i].exno==p.exno)
				{
					flag++;
					return i;
				}
				
			}
		}
		else if(flag==0)
		{
			return -1;
		}
		 
	}
}
int main()
{
	int i,x,ch,a;
	struct student p;
	struct student s[SIZE];
	for(i=0;i<SIZE;i++)
	{
		s[i].exno=-1;
	}
	while(1)
	{
		printf("\n1.Register exam number\n2.Search Exam number\n3.Exit\nEnter you choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the exam no : ");
			scanf("%d",&p.exno);
			printf("Enter the marks : ");
			scanf("%d",&p.marks);
			x=insert(s,p);
			if(x==-1)
			{
				printf("Duplicate exam number\n");
			}
			else if(x==-2)
			{
				printf("No space left\n");
			}
			else
			{
				printf("Exam number %d registered successfully\n",p.exno);
			}	
		}
		else if(ch==2)
		{
			printf("Enter the exam number to be searched:");
			scanf("%d",&p.exno);
			a=search(s,p);
			if(a==-1)
			{
				printf("Exam number not found\n");
			}
			else
			{
				printf("Exam number %d found at %d with marks %d",p.exno,a,s[a].marks);
			}
		}
		else if(ch==3)
		{
			printf("Hashing operations completed successfully\n");
			break;
		}
		else
		{
			printf("Invalid choice\n");
		}
		printf("\nThe hash table is:\n");
		for(i=0;i<SIZE;i++)
		{
			printf("index=%d-> %d\n",i,s[i].exno);
		}
	}
}
