/*
project title:movie ticket booking system
author name: syed.uzma yasmin
date of project creation :15.05.2023
*/
#include<stdio.h>
#include<stdlib.h>

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
	

}b;

int seat = 60 ;

void insert_details();//for inserting movie details
void find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old records of users,booked tickets

void main()
{

	int ch;
 	do{
	printf("\n********************************************************************");
	printf("\n");	
	printf("\t WELCOME TO MOVIE TICKET BOOKING ");
	printf("\n");
	printf("\n********************************************************************");
	
	printf("\nPress <1> Insert Movie");
 	printf("\nPress <2> Find Movie ");
	printf("\nPress <3> Book Ticket");
	printf("\nPress <4> View All Transactions");
   	printf("\nPress <5> Exit ");

   	printf("\nEnter your Choice :");
   	scanf("%d",&ch); 	

   	switch (ch)
   	{
    	case 1 :
    		insert_details();
   		    break;
   		case 2:
    		find();
   		    break;

	    case 3:
	        book_ticket();
		    break;
		
		case 4:
		    old_record();
		    break;

    	case 5:
    		exit(5);
    		break;

    	default:
    		printf("ERROR !");
    		break;
   	}
 }while(ch!=0);

	


}


void insert_details()
{
	
	FILE *fp;
	struct book b;
	printf("Enter movie code : ");	
	scanf("%s",b.code);
	printf("Enter  name : ");	
	scanf("%s",b.name);
	printf("Enter Date: ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:");	
	scanf("%d",&b.cost);
	
	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record inserted Sucessfully");
	}
		printf("\n");
	fclose(fp);
}
void find() //find details
{
	struct book b;
	FILE *fp;
	
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket :%d",b.cost);
				break;
			}
		}
		
	}

	fclose(fp);
}
//for ticket booking 
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];

	
	char ch; //used in display all movies
	char movie_code[20]; //for searching

	// disply all moives by default for movie code
	fp = fopen("data.txt","r");
 	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	
	//display ends
	printf("\n For Book ticket Choose Movie(Enter Movie Code First Later Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}
		
	}
	printf("\n* Fill Details  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	
	
	total_amount = b.cost * total_seat;
	
	printf("\n ***** ENJOY MOVIE ****\n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	
	
	ufp=fopen("oldTransaction.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Sucessfully to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}

void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);


}
