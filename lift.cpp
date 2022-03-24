
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	struct node *lp;
	int a;
	struct node *rp;
};
struct node *ptr,*start=NULL,*temp;
int main()
{
	int i,z=1,m,l=1,p=1;
	for(i=1;i<=10;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->a=i;
		if(start==NULL)
		{
			start=temp;
			start->lp=NULL;
			start->rp=NULL;
		}
		else
		{
			ptr=start;
			while(ptr->rp!=NULL)
			{
				ptr=ptr->rp;
			}
			ptr->rp=temp;
			temp->lp=ptr;
			temp->rp=NULL;
		}
	}
/*	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->a);
		ptr=ptr->rp;
	}*/
	                                                //upto here I created ten nodes and assigning data to the corresponding nodes
	                                                
	                                                
	                                                

for(;p;)
{


        printf("enter the floor number:");
        scanf("%d",&m);
        if(l==1)
        {
	         l++;
             ptr=start;
             while(ptr!=NULL)
             {
  	             if(ptr->a==m)
  	                {
	  
  		               printf("%d floor is successfully reached\n",m);
  		                start=ptr;
  	                 }
                 	ptr=ptr->rp;
              }
             for(i=1;i<=10;i++)
             {
               	if(i==m)
  	               {                                                   //this code is for the first entered  floor
  	             	continue;
	               }
	            printf("%d for %dfloor\n",i,i);
             }
         }
         else if(l==2)                                    //from here onwards this code is for the second entered floors
         {
            ptr=start;
            if(m>(ptr->a))
            {
	             while(ptr!=NULL)
              	{
		            if(ptr->a==m)
		             {
		                   printf("%d floor is successfully reached\n",m);
		                    start=ptr;
	                  }
	                  ptr=ptr->rp;
               	}
                for(i=1;i<=10;i++)
                {
  	               if(i==m)
  	               {
  		              continue;
	                }
	                printf("%d for %dfloor\n",i,i);
                }	
            }
            else
           {
             ptr=start;
             if(m<(ptr->a))
             {
	
	           while(ptr!=NULL)
	           {
		               if(ptr->a==m)
	                 	{
		                   printf("%d floor is successfully reached\n",m);
	  	                    start=ptr;
	                    }
	                   ptr=ptr->lp;
	           }
               for(i=1;i<=10;i++)
               {
              	   if(i==m)
                 	{
  		               continue;
	                 }
	                 printf("%d for %dfloor\n",i,i);
                }		
              }
           }
         }
}
return 0;
}
