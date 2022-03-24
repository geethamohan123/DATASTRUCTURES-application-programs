#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void display();
void create();
void playing();
void defaultsong();
void previoussong();
void nextsong();
void search();
int c=0,z=0;
struct node
{
	struct node *lp;
	char song[100]; 
	char movie[100];
	struct node *rp;                                                                                                                         
};
struct node *ptr,*start=NULL,*temp,*mohan;
int main()
{
char n,z,i;
int m=1;
printf("a for inserting of songs and movies\n");
printf("2 for display songs with corresponding movie with its songs\n");
printf("3 for playing song \n");
printf("4 for exit\n");
printf("5 for searching\n");
printf("\n");
for(;m;)
{   printf("\n");
	printf("enter your option:");
	scanf("%c",&n);
    switch(n)
    {
	case 'a': scanf("%c",&i);
	         c++;
	         create(); 
			 break;
	case '2':
		    scanf("%c",&i);
	         display();
	         break;
	case '3':scanf("%c",&i);
	         playing();
	         break;
	case '4':exit(0);
	         break; 
	case '5':
	         scanf("%c",&i);
			 search(); 
			 break; 
		 
	          default: 	 scanf("%c",&i);
			            printf("not match your option \n");
   }
}
return 0;
}

void create()
{  	char c;
	temp=(struct node*)malloc(sizeof(struct node));
	scanf("%c",&c);
	printf("enter the movie names:");
	gets(temp->movie);
	printf("enter the song names:");
	gets(temp->song);
	if(start==NULL)
	{
	start=temp;
	start->lp=start;
	start->rp=start;
	}
	else
	    {
	    ptr=start;
	    while(ptr->rp!=start)
	     	{
	     		ptr=ptr->rp;
	     		
			 }
			temp->rp=start;
			temp->lp=ptr;
			ptr->rp=temp;
			start->lp=temp;
		}
}

void display()
{
	printf("\n");
	printf("********all the songs and its movie details**********\n");
	printf("\n");
     struct node *ptr=start;
     while(ptr->rp!=start)
     {
     	printf("%s              -              %s\n",ptr->movie,ptr->song);
     	ptr=ptr->rp;
	 }
	 printf("%s               -            %s\n",ptr->movie,ptr->song);
	 
}

void playing()
{
	char g,v,o=1;
	printf("\n");
	printf("\n");
	printf(" 1  for default song that is middle of the songs\n ");
	printf(" n  for next song playing\n ");
	printf(" p  for previous song playing\n");
	printf(" 2  for exit from the playing songs\n");
    for(;o;)
    {
    printf("enter your playing option:");
	scanf("%c",&g);
	scanf("%c",&v);
	switch(g)
	{
		case '1':   defaultsong();
		              break;
     	case 'n':  nextsong();
		            break;
		case 'p':  previoussong();
		           break;
		case '2':   break;
		           default:
		          printf("not matching\n");		
	}
	if(g=='2')
	    break;	
  }
}

void defaultsong()
{
	float f;
	int k;
    mohan=start;
	ptr=start;
	f=c%2;
	k=c/2;
	if(f==0)
	{
		int p=0;
		while(ptr->rp!=start)
		{
			p++;
			if(p==k)
			    break;
			ptr=ptr->rp;
		}
		mohan=ptr;
		printf("\n");
	   printf("%s   -   %s\n",ptr->movie,ptr->song);
	   printf("\n");
		
	}
	else
	 {
	 	 int p=0,b;
	     b=(c+1)/2;
	      while(ptr->rp!=start)
	      {
		    p++;
			if(p==b)
			    break;
		    ptr=ptr->rp;
	     }
	     mohan=ptr;
	    printf("\n");
	   printf("%s   -   %s\n",ptr->movie,ptr->song);
	   printf("\n");
	     
	 	
	 }
}


void nextsong()
{
	 
	 float f;
	 int k;
if(z<1)
{
	    z++;
    	f=c%2;
    	k=c/2;
	   if(f==0)
	    {
	 	      ptr=start;
	 	      int p=0;
		      while(ptr->rp!=start)
		     {
		      	p++;
			    if(p==k)
			         break;
			     ptr=ptr->rp;
	       	 }
		mohan=ptr;
        }
	else
	 {
	 	 int p=0,b;
	     b=(c+1)/2;
	      while(ptr->rp!=start)
	      {
		    p++;
			if(p==b)
			    break;
		    ptr=ptr->rp;
	     }
	     mohan=ptr;	
	 }
}
     printf("%s   -   %s\n",mohan->movie,mohan->song);
     mohan=mohan->rp;
}


void previoussong()
{
	
	
float ff;
int kk;

if(z<1)
{
	z++;
	ff=c%2;
	kk=c/2;
	if(ff==0)
	{
		int p=0;
		while(ptr->rp!=start)
		{
			p++;                         //these all the if else code is used for the assigning the middle address to the mohan structure 
			if(p==kk)                    //variable and correctl maitain the nextsong and previous song
			    break;
			ptr=ptr->rp;
		}
		mohan=ptr;
    }
    else
	 {
	 	 int p=0,b;
	     b=(c+1)/2;
	     while(ptr->rp!=start)
	    	{
		    	p++;
			    if(p==b)
			       break;
		    	ptr=ptr->rp;
	     	}
	   	mohan=ptr;
	}
}
	 printf("%s   -   %s\n",mohan->movie,mohan->song);  //here this is the only main logic
	 mohan=mohan->lp;
}



void search()
{
	
	int n,t=0;
	int b;
	struct node *son;
	char poo;
	son=(struct node*)malloc(sizeof(struct node));
	char u;
	ptr=start;
	printf(" 0 for searching by the song names\n");
	printf(" 1 for searching by the movie name\n");
	printf("enter your option:");
	scanf("%d",&n);
	switch(n)
	{
	        case 0:
	        	   b=0;
			       printf("enter your song names:");
			       gets(son->song);
			       scanf("%c",&u);
			       ptr=start;
			       while(ptr->rp!=start)
			        {
			          if(strcmp((ptr->song),(son->song))==0)
			            {
			          		printf(" the entered song %s is found\n",ptr->song);
			          		b=1;
			          		break;
						}
			          	
					  }
					if(b==0)
					{
						printf("the entered song %s is not found\n",son->song);
					}
					break;
			case 1:
				    b=0;
				    printf("enter your movie name:");
				    gets(son->movie);
				    scanf("%c",&u);
				    ptr=start;
				     while(ptr->rp!=start)
			        {
			          if(strcmp((ptr->movie),(son->movie))==0)
			            {
			        
			          		printf("the entered movie %s found \n",son->movie);
			          		b=1;
			          		break;
						}
			          	
					  }
					if(b==0)
					{
					         printf("the entered movie %s not found\n",son->movie);
					}
					break;
					default:
						    scanf("%c",&u);
						    printf("not match");
				    
			       
		
	}
    
}

