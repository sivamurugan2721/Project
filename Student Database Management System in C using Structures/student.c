#include<stdio.h>
#include<string.h>

typedef struct student{
	int roll;
	char name[20];
	float marks;

}ST;

void student_roll(ST*);  

void student_marks(ST*);

void student_name(ST*);

int main()
{
	char op;

	ST s[6] ={ {3,"Oviya", 98.7}, {1, "Reji",100}, {2, "Uma",76.9}, {9, "Rocky",99}, {7, "Siva",80}, {8,"Hukesh",67.9} };
       	
	ST *p=s;

	printf("Enter the option R/N/M \n");

	scanf("%c",&op); 

	if((op=='R')||(op=='r'))

		student_roll(p); 

	else if ((op=='N')||(op='n'))

		student_name(p);

	else if((op='M') || (op=='m'))

		student_marks(p);
	else 
		printf("INVALID OPTION\n");
}
void student_roll(ST*s)
{
	int i,j;
	ST temp;
	for(i=0;i<6;i++)
	{

		for(j=0;j<6-1;j++) 
		{
			if(s[j].roll < s[j+1].roll) 
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		for(i=0;1<6;i++) 
			printf("%d %s %f\n",s[i].roll,s[i].name,s[i].marks);
		}
	}
}	
void student_marks(ST*s) 
{
	int i,j;
	ST temp;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6-1;j++) 
		{
			if(s[j].marks < s[j+1].marks) 
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}

			for(i=0;1<6;i++) 
				printf("%d %s %f\n",s[i].roll,s[i].name,s[i].marks);
		}
	}
}
void student_name(ST*s) 
{
	int i,j;
	ST temp;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6-1;j++) 
		{	 
			int n=strcmp(s[1].name,s[j+1].name); 
			if(n>0) 
			{
				temp=s[j];
				for(i=0;i<6;i++)
					printf("%d %s %f\n",s[i].roll,s[i].name,s[1].marks);
			}
		}
	}
}
