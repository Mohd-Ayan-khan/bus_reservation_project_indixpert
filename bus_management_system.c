#include<stdio.h>

char username[20];
char password[20];
int busnum[10];
int seats[10];
int num=0;
char source_city[10][30]={"jodhpur","jaipur","indore","delhi","mumbai","pali","ajmer","bikaner","pali","nagor"};
char destination[10][30]={"ajmer","udaipur","bikaner","pali","nagor","jodhpur","jaipur","indore","delhi","mumbai"};
int avalible[10];
int tag=0;
int fare[10]={100,150,200,250,300,120,310,190,340,220};
int  login();
int  booking_menu();
int book();
int status();
int cencle();
int route();
int signup();
int payment();



int main()
{
    int choice;
   
    
    while(choice != 2)
 {
    printf("\n#####################################################");
    printf("\n*********** BUS RESERVATION SYSTEM *************");
    printf("\n#####################################################");


    printf("\n****************");
    printf(" \n>> 1 Sign up ");
    printf("\n****************");
    printf(" \n>> 2 login ");
    printf("\n****************");
    printf(" \n>> 3 Exit");
    printf("\n****************");

    printf("\nplese enter your choice ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        signup();
        
        break;

    case 2: 

        login();
        choice=2;
        
        break; 
        
    case 3:
        printf("\n**** Exiting.... ****"); 
        break;    
    
    default: printf("***please Enter valid number**");
        
        break;
    }
} 

return 0;
}

int signup()
{
    printf("Enter User Name :");
    scanf("%s",&username);
    printf("Enter the Password :");
    scanf("%s",&password);

    printf("\n\t**************************************");
    printf("\n\t\t*****Sign Up Complete*****");
    printf("\n\t**************************************\n");
    tag=1;
  return 0;  
}

int login()
{
    
    char user[20];
    char pass[20];
    int usermatch,passmatch;
    int try=0;

    do{
        printf("plese enter username :");
        scanf("%s",&user);
        printf("plese enter password :");
        scanf("%s",&pass);

        usermatch=1;
        passmatch=1;

        for(int i=0; username[i] != '\0' || user[i] != '\0'; i++)
        {
            if(username[i] != user[i])
            {
                usermatch = 0;
                break;
            }
        }

        for(int i=0; password[i] != '\0' || pass[i] != '\0'; i++)
        {
            if(password[i] != pass[i])
            {
                passmatch = 0;
                break;
            }
        }

        if(usermatch == 1 && passmatch == 1)
        {
            printf("\n\t**************************************");
            printf("\n\t\t****login successfully*****");
            printf("\n\t**************************************\n");

            printf("\n\t**************************************");
            printf("\n\t\twelcome %s ",username);
            printf("\n\t**************************************\n");
            
            booking_menu();
            break;
            
        }
        else if(tag==0)
        {
            printf("\n\t**************************************");
            printf("\n\t\t****please sign up*****");
            printf("\n\t**************************************\n");
            main();
        }
        else
        {
            printf("\n\t**************************************");
            printf("\n\t invalid username or password");
            printf("\n\t**************************************\n\n");
            try=1;
        }
        

    }while(try==1);
    return 0;
}


int booking_menu()
{
    int choice;
do{
    printf("\n<<()|()>>********BOOKING MENU*********<<()||()>>");
    printf("\n----------------------");
    printf("\n1. Book a Ticket");
    printf("\n----------------------");
    printf("\n2. Cancel a Tiket");
    printf("\n----------------------");
    printf("\n3. Check Bus Status");
    printf("\n----------------------");
    printf("\n4. Logout");
    printf("\n----------------------");
    printf("\n5. Route detail");
    printf("\n----------------------");
    printf("\n<<()|()>>******************************<<()||()>>\n");

    printf("\nEnter your choice :");
    scanf("%d",&choice);


    switch (choice)
    {
    case 1:

        book();
        break;

     case 2:

        cencle();
        break;   
    
    case 3:

        status();
        break;

    case 4:
        printf("\n\t**************************************");
        printf("\n\t\tThank You for Visiting...");
        printf("\n\t**************************************\n");
        
        break;

    case 5:
        route();
        break;

    default:
        printf("\n\t**************************************");
        printf("\t\tPlease Enter valid number");
        printf("\n\t**************************************\n");
        break;
    }
}while(choice != 4);
return 0;
}


int book()
{
    
    do{
        printf("\nEnter Bus Number Between (1/10): ");
        scanf("%d",&busnum[num]);
        printf("Enter Number of Seats :");
        scanf("%d",&seats[num]);

        if(seats[num] > 50 )
        {
            printf("\n\t**************************************");
            printf("\n\t\tonly 50 seats available");
            printf("\n\t**************************************\n");
        }
        else if(busnum[num] < 1 || busnum[num] > 10)
        {
            printf("\n\t**************************************");
            printf("\n\t\tOnly 1 to 10 Bus available");
            printf("\n\t**************************************\n");
        }
        else{
            avalible[num]=50-seats[num];
            
            payment();
            num++;
            
        }
    }while(seats[num] > 50 && busnum[num]<1 || busnum[num]>10); 
        
        
 return 0;   
}

int cencle()
{
    int cencle;
    int comp;
    int step=0;

    printf("Enter Bus Number :");
    scanf("%d",&comp);

    for(int i=0; i<num; i++ )
    {

        if(busnum[i] == comp)
        {

            printf("How many seats remove :");
            scanf("%d",&cencle);

            if(cencle <= seats[i])
            {
                seats[i] -= cencle;
                avalible[i] += cencle;
            
            printf("\n\t**************************************");
            printf("\n\t\t**Your Seats was Cencled**");
            printf("\n\t**************************************\n");
            step=1; 
            }
        }   
        
    }
    
    if(step==0)
    {
        printf("\n\t**************************************");
        printf("\n\t\tthis bus or Seats not booked");
        printf("\n\t**************************************\n");
    }
   return 0; 
}



int status()
{
    int check;
    int index;
    int tag2=0;
    

    printf("enter bus number :");
    scanf("%d",&check);

    if(num == 0)
    {
        printf("\n\t**************************************");
        printf("\n\t****** No Bus Booked *******");
        printf("\n\t**************************************\n");
    }


    for(int i=0; i<num; i++)
    {
         
        if(check == busnum[i])
        {
            tag2=1;
            index = busnum[i]-1;
            printf("\n**********************************\n");
            printf(" Bus number  :       %d\n ",busnum[i]);
            printf("source city :       %s\n ",source_city[index]);
            printf("destination :       %s\n ",destination[index]);
            printf("total seats :       50\n ");
            printf("avalible    :       %d\n ",avalible[i]);
            printf("fare        :       %d.00\n",fare[index]);
            printf("\n**********************************\n");
            
            break;
        } 
    }
        if(tag2 == 0)
        {
            printf("\n\t**************************************");
            printf("\n\t\t****this bus you not book****");
            printf("\n\t**************************************\n");

        }
    return 0;
}

int route()
{
    printf("---------------------------------------------\n");
    printf("| Bus no.| source city | destination | Amount |\n");
    printf("---------------------------------------------\n");
    

    for(int i=0; i<10; i++)
    {
        printf("|   %-2d   |  %-10s |  %-10s |  Rs.%d|\n",i+1,source_city[i],destination[i],fare[i]);

    }
return 0;    
}

int payment()
{
    int index=0;
    int option;
    int id;

     index = busnum[num] - 1;

    printf("\nyour bus           %d",busnum[num]);
    printf("\nsource city        %s",source_city[index]);
    printf("\ndestination        %s",destination[index]);
    printf("\nbooked seats       %d",seats[num]);
    printf("\nfare               %d",fare[index]);
    printf("\ntotal bill         %d\n",fare[index]*seats[num]);

    printf("\n**********Payment Method*****************");
    printf("\n >> 1 UPI");
     printf("\n**************************************");
    printf("\n >> 2 DEBIT CARD");
     printf("\n**************************************");
    printf("\n >> 3 CREDIT CARD");
     printf("\n**************************************\n");
    
    printf("Enter your choice");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("Enter UPI Number :");
        scanf("%d",&id);

        printf("\n\t**************************************");
        printf("\n\t\t*****Payment sussecfull******");
        printf("\n\t**************************************\n");
        printf("\n\t*****************************************************************************");
        printf("\n\t*****Successfully Booking in Bus %d of %d seats******",busnum[num],seats[num]);
        printf("\n\t***************************************************************************\n");
;
        break;

    case 2 :
        printf("Enter Debit card Number :");
        scanf("%d",&id);

        printf("\n\t**************************************");
        printf("\n\t\t*****Payment sussecfull******");
        printf("\n\t**************************************\n");
        
        break;  
    case 3 : 
        printf("Enter credit card Number :");
        scanf("%d",&id);

        printf("\n\t**************************************");
        printf("\n\t\t*****Payment sussecfull******");
        printf("\n\t**************************************\n");

       
    break;
    
    
    default:printf("\n****Enter valid number******");
        break;
    }


return 0;
}


