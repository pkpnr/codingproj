/*
    CODE COURTESY OF ACA, BANAAG, AND PANER
    
    DO NOT REDISTRIBUTE PROGRAM UNLESS 
    WITH CONSENT FROM THE OWNERS             */

#include <stdio.h>
#include <string.h>

//function declarations
void getRecs();
void findRec();
void printRecs();

//global variable
int add;

//declaring Date structure
struct Date
{
    int mm;
    int dd;
    int yyyy;
};

//declaring Rec structure for storing information
struct Rec
{
    int num_Client;
    char Name[100];
    char Address[100];
    char cell_Number[100];
    float prev_Bal;
    float curr_Bal;
    float CashOnHand;
    struct Date paydate;
};

//global unsized array declaration
struct Rec client[] = {};

//main function
int main()
{
    //declaring local variables
    int option, i;
    
    //main menu
    printf("------------------------------------------\n");
    printf("-----JBR CUSTOMER BILLING SYSTEMS INC.----\n");
    printf("------------------------------------------\n\n\n");
    printf("1.\tAdd an account.\n");
    printf("2.\tSearch for an existing account.\n");
    printf("3.\tExit program.\n");
    
    //executes do-while loop/asks for input until user chooses options 1, 2, & 3  
    do
    {
        printf("\nSelect an option: ");
        scanf("%d", &option); 
        getchar(); //to prevent character eating of the first letter of any string when printing
    } while (option <= 0 || option > 3);
    
    //transaction choices 1, 2, & 3
    switch (option)
    {
    case 1: //add accounts
        printf("\nHow many new accounts would you like to add?\n");
        printf("Please enter number of accounts: ");
        scanf("%d", &add); //asks input for number of accounts
        getchar(); 
        
        //for loop executes until desired additions of accounts is reached
        for (i = 0; i < add; i++)
        {
            getRecs(i); //storing records of information

            client[i].curr_Bal = client[i].prev_Bal - client[i].CashOnHand; //updated or new balance after payment
        }

        main(); //returns to main menu
        break; // terminates the case

    case 2:
        printf("\nIn what method would you like to search for an account?\n");
        printf("\n1.\tSearch by Client Name\n");
        printf("2.\tSearch by Account Number\n");
        printf("3.\tBack to Main Menu\n");

        findRec(client, add); //access stored accounts

        main();
        break;

    case 3: //exit program
        printf("\nTHANK YOU FOR USING OUR BILLING SYSTEM.\n");
        return 0; //terminating statement
        break;
    }
}

void getRecs(int i) //stores records
{
    printf("\n\nNOTE: All inputs must be in UPPERCASE LETTERS.\n");
    printf("ACCOUNT NUMBERS must start from 1, 2, 3, 4, so on and so forth.\n");
    
    printf("\nAccount Number: "); //current bug: for every input, client number must start at 1 and so on until it is equal with the desired numer of account additions CLIENT NUMBER DOES NOT INCREASE BY 1 WITHOUT USER INPUT
    scanf("%d", &client[i].num_Client);
    getchar();

    printf("Full Name:\t");
    fgets(client[i].Name, 100, stdin);

    printf("Address:\t");
    fgets(client[i].Address, 100, stdin);

    printf("Phone Number:\t");
    fgets(client[i].cell_Number, 100, stdin);

    printf("\nAccount Balance: PHP ");
    scanf("%f", &client[i].prev_Bal);
    getchar();

    printf("Amount To Pay: -PHP ");
    scanf("%f", &client[i].CashOnHand);
    getchar();

    printf("Date Paid (mm/dd/yyyy): "); //1ST ATTEMPT: asks for input from one line to the next, 2ND ATTEMPT: asks multiple inputs on one line but date separator ('/') must be included
    scanf("%d/%d/%d", &client[i].paydate.mm, &client[i].paydate.dd, &client[i].paydate.yyyy);
    getchar();
    
    printf("\n\nACCOUNT SAVED.");
    printf("\n\n================================================\n\n");

    
    return;
}

void findRec(struct Rec *clientele, int size) //receives struct array "client" and size "add"
{
    int k, l, m = 1;
    int search; 
    char name[100]; //for searching the account name

    do // executes loop until user chooses 1 and 2 
    {
        printf("\nSelect an option: ");
        scanf("%d", &search);
        getchar();
    } while (search != 1 && search != 2 && search != 3);

    switch (search) //search acct option 1 and 2
    {
    case 1:
        do //loop continues if user wishes to search again after mistake committed
        {
            printf("\n\nNOTE: All inputs must be in UPPERCASE LETTERS.\n");
            
            printf("\nEnter client's name:\t");
            fgets(name, 100, stdin); //asks client name for searching

            for (k = 0; k < add; k++)
            {
                if (strstr(name, clientele[k].Name)) //if entered name matches with names of stored records
                {
                    printRecs(&clientele[k]);
                    m = 0; //determines if user entered correctly
                    break;
                }
            }

            if (m != 0) //asks for redo if account is not found
            {
                printf("\nAccount not found.\n");
                printf("\nTry again? (9 - Yes / 0 - No)\n");
                scanf("%d", &search);
                getchar();
            }
        } while (search == 9);
        break;

    case 2:
        do
        {
            printf("      ACCOUNT NUMBERS must start with '1'.\n");
                    
            printf("\nEnter account number: ");
            scanf("%d", &l);
            getchar();

            if (l <= 0 || l > size) //if entered client number is less than or equal to zero or way beyond the number of desired account additions (this is also part of the "client number" bug, still needs a fix)
            {
                printf("\nClient number not found.\n");
                printf("\nTry again? (9 - Yes / 0 - No)\n");
                scanf("%d", &search);
                getchar();
                
            }
            else
            {
                printRecs(&clientele[l - 1]); // prints records if entered client number matches with stored client n1umber
                break;
            }
        } while (search == 9);
        break;
    case 3:
    main();
    break;
    }
    return;
}

void printRecs(struct Rec *clients) // prints records
{
    printf("\n\n============ CUSTOMER'S INFORMATION ============");
    printf("\n\n    Account Number: \t %d\n", clients->num_Client);
    printf("         Full Name: \t %s", clients->Name);
    printf("           Address: \t %s", clients->Address);
    printf("      Phone Number: \t %s\n\n", clients->cell_Number);
    printf("  PREVIOUS BALANCE: \t PHP %.2f\n", clients->prev_Bal);
    printf("       AMOUNT PAID: \t-PHP %.2f\n", clients->CashOnHand);
    printf("   UPDATED BALANCE: \t PHP %.2f\n", clients->curr_Bal);
    printf("         DATE PAID: \t %d/%d/%d\n\n", clients->paydate.mm, clients->paydate.dd, clients->paydate.yyyy);

    printf("\nTHANK YOU FOR USING OUR BILLING SYSTEM!\n\n\n");
    printf("================================================\n\n");
    return;
}


/*
    CODE COURTESY OF ACA, BANAAG, AND PANER
    
    DO NOT REDISTRIBUTE PROGRAM UNLESS 
    WITH CONSENT FROM THE OWNERS              */
    


