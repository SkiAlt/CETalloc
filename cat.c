#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define A1SEATS 8 //maximim number of seats 
#define B2SEATS 8 //for reservations in clgs
#define GMSEATS 9 //for different categories
typedef struct Student
{
	int uid;
	char name[20];
	int rank;
	char cat[2];
	char clg[10];//in database this should hold NULL
	struct Student *lptr, *rptr;
}node;
typedef struct College
{
	char name[20];
	node* pupils[25];//clg list will have student nodes assigned to them.
}college;

//fn for inputs
/*clg allocating(college c1, A1, B2, GM)
{
	count variables
	return c1;
}
*/
node* generatePQueue(node* catlist,node* studentlist,char ch)
{
	while(studentlist)
	{
		if(studentlist->cat[0]==ch)
		{
			node* new1=malloc(sizeof(node));
			new1->lptr=new1->rptr=NULL;
			strcpy((new1->name),(studentlist->name));
			new1->rank=studentlist->rank;
			strcpy((new1->cat),(studentlist->cat));
			new1->uid=studentlist->uid;
			
			if(!catlist)
			{	
				catlist=new1;
				goto TRAVERSE;
			}
			//first node edge case
			if(catlist->rank > new1->rank) //insert front
			{	
				catlist->lptr=new1;
				new1->rptr=catlist;
				catlist=new1;
				goto TRAVERSE;
			}
			node *temp=catlist;
			while(temp->rptr && ((temp->rptr)->rank)<new1->rank)//asscending priority
				temp=temp->rptr; //find spot
			//appedning
			new1->rptr=temp->rptr;
			if(temp->rptr) //to avoid segufault
				(temp->rtpr)->lptr=new1;
			temp->rptr=new1;
			new1->lptr=temp;
		}
TRAVERSE:	studentlist=studentlist->rptr;
	}
	return catlist;
}

void main()
{
	node* studentlist; //to dynamically create and store students info.
	node* A1, *B2, *GM;
	college rv, bsm, jss, msr, rns, pes;
	A1=generatePQueue(A1,studentlist, 'A');
	B2=generatePQueue(B2,studentlist, 'B');
	GM=generatePQueue(GM,studentlist, 'G');

}
