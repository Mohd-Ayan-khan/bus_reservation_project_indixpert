#include<stdio.h>

char username[20];
char password[20];
int busnum[5];
int seats[5];
int num=0;
char source_city[5][30]={"jodhpur","jaipur","indore","delhi","mumbai"};
char destination[5][30]={"ajmer","udaipur","bikaner","pali","nagor"};
int total_seat[5];
int avalible[5];
void login();
void booking_menu();
void book();
void status();
void cencle();
void route();
void signup();


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

void signup()
{
    printf("Enter User Name :");
    scanf("%s",&username);
    printf("Enter the Password :");
    scanf("%s",&password);

}

void login()
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
        else
        {
            printf("\n\t**************************************");
            printf("\n\t invalid username or password");
            printf("\n\t**************************************\n\n");
            try=1;
        }

    }while(try==1);
}


void booking_menu()
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
}


void book()
{
    
    do{
        printf("\nEnter Bus Number Between (1/5): ");
        scanf("%d",&busnum[num]);
        printf("Enter Number of Seats :");
        scanf("%d",&seats[num]);

        if(seats[num] > 50 )
        {
            printf("\n\t**************************************");
            printf("\n\t\tonly 50 seats available");
            printf("\n\t**************************************\n");
        }
        else{
            avalible[num]=50-seats[num];
            printf("\n\t*****************************************************************************");
            printf("\n\t*****Successfully Booking in Bus %d of %d seats******",busnum[num],seats[num]);
            printf("\n\t***************************************************************************\n");
            num++;
        }
    }while(seats[num] > 50); 
        
        
    
}

void cencle()
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
    
}



void status()
{
    int check;
    int index;
    int fare[5]={100,150,200,250,300};

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
        if(check != busnum[i] )
        {
            printf("\n\t**************************************");
            printf("\n\t\t****this bus you not book****");
            printf("\n\t**************************************\n\n");

        }   
        if(check == busnum[i])
        {
            index = busnum[i]-1;
            printf("\n**********************************\n");
            printf(" Bus number  :       %d\n ",busnum[i]);
            printf("source city :       %s\n ",source_city[index]);
            printf("destination :       %s\n ",destination[index]);
            printf("total seats :       50\n ");
            printf("avalible    :       %d\n ",avalible[i]);
            printf("fare        :       %d.00\n",fare[index]);
            printf("\n**********************************\n");
   

            
        }
        
    }
    
}

void route()
{
    for(int i=0; i<5; i++)
    {
        printf("\n%d %-10s  -  %-10s\n",i+1,source_city[i],destination[i]);

    }
    
}





