 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
bool authenticate() {
    char passcode[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter passcode for your BANKONTHEGO account(Attempts left: %d): ", attempts);
        scanf("%s", passcode);


        if (strcmp(passcode, "cse103") == 0) {
            return true;
        } else {
            printf("Incorrect passcode. %d attempts left.\n", attempts - 1);
            attempts--;
        }
    }

    printf("Maximum number of attempts reached. Access denied.\n");
    return false;
}

struct Account {
    int accountNumber;
    char accountHolder[50];
    double balance;
    int NID;
    char pin[5];
};

void printTitle() {
    printf("  ____          _   _ _  ______  _   _ _______ _    _ ______ _____  ____  \n");
    printf(" |  _ \\   /\\   | \\ | | |/ / __ \\| \\ | |__   __| |  | |  ____/ ____|/ __ \\ \n");
    printf(" | |_) | /  \\  |  \\| | ' | |  | |  \\| |  | |  | |__| | |__ | |  __| |  | |\n");
    printf(" |  _ < / /\\ \\ | . ` |  <| |  | | . ` |  | |  |  __  |  __|| | |_ | |  | |\n");
    printf(" | |_) / ____ \\| |\\  | . | |__| | |\\  |  | |  | |  | | |___| |__| | |__| |\n");
    printf(" |____/_/    \\_|_| \\_|_|\\_\\____/|_| \\_|  |_|  |_|  |_|______\\_____ |\\____/ \n");
    printf("***********************************************************************************\n");
    printf("***********************************************************************************\n");
}


void createAccount(struct Account **accounts, int *numAccounts) {
    printf("///////////////////////////    CREATE ACCOUNT   ///////////////////////////////////\n");
    printf("...................................................................................\n");
    if (*numAccounts < 10) {
        struct Account newAccount;

        printf("Enter account number: ");
        if (scanf("%d", &newAccount.accountNumber) != 1 || newAccount.accountNumber <= 0) {
            printf("Invalid account number. Please enter a positive integer.\n");
            getch();
            return;
        }

        int i;// Duplicate checking
        for ( i = 0; i < *numAccounts; i++) {
            if ((*accounts)[i].accountNumber == newAccount.accountNumber) {
                printf("An account with the same account number already exists.\n");
                getch();
                return;
            }
        }

        while (getchar() != '\n');  // Prevents errors if space or enter is entered

        printf("Enter account holder name: ");
        fgets(newAccount.accountHolder, sizeof(newAccount.accountHolder), stdin);
        newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = '\0';  // Removes problem with space and enter while naming user

        char pw[4];
        int x;
        printf("Enter PIN: ");
        for (x = 0; x < 4; x++)
        {
        // accepts the hidden password using the getch() function
        pw[x] = getch();
        printf("*"); // print the input chartered in the form of *
        }
        pw[x] = '\0';
        printf( "\n" );
        strcpy(newAccount.pin,pw);
        getch();




        printf("\nEnter initial balance: ");
        if (scanf("%lf", &newAccount.balance) != 1 || newAccount.balance < 0) {
            printf("Invalid initial balance. Please enter a non-negative amount.\n");
            getch();
            return;
        }

        (*accounts)[*numAccounts] = newAccount;
        (*numAccounts)++;

        printf("Account created successfully!\n");
        getch();
    } else {
        printf("Maximum account limit reached.\n");
        getch();
    }
}



void deposit(struct Account *accounts, int numAccounts, int accountNumber, double amount) {
    if (amount <= 0) {
        printf("Invalid deposit amount. Please enter a positive amount.\n");
        getch();
        return;
    }
int i;
    for ( i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful. Updated balance: %.2lf\n", accounts[i].balance);
            getch();
            return;
        }
    }
    printf("Account not found. Feel free to make a new account!\n");
}

void withdraw(struct Account *accounts, int numAccounts, int accountNumber, double amount) {

    if (amount <= 0) {
        printf("Invalid withdrawal amount. Please enter a positive amount.\n");
        getch();
        return;
    }
int i;
    for ( i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. Updated balance: %.2lf\n", accounts[i].balance);
                getch();
            } else {
                printf("Insufficient balance.\n");
                getch();
            }
            getch();
            return;
        }
    }
    printf("Account not found. Feel free to make a new account!\n");
    getch();
}


bool login(struct Account *accounts, int numAccounts, int accountNumber)
{
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
       char pw[4];
        int x;
        printf("Enter PIN: ");
        for (x = 0; x < 4; x++)
        {
        // accepts the hidden password using the getch() function
        pw[x] = getch();
        printf("*"); // print the input chartered in the form of *
        }
        pw[x] = '\0';
        printf( "\n" );
        getch();

        if(strcmp(accounts[i].pin,pw) == 0)
        {
            printf("login successful......");
            getch();
            return true;
        }
        else
        {
            printf("Wrong PIN");
            getch();
            return false;
        }

    }
    else{
        printf("Account not found. Feel free to make a new account!\n");
        getch();
        return false;}
    getch();
return;
}}
bool verification(struct Account *accounts, int numAccounts, int accountNumber)
{
int i;
    for ( i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
       char pw[4];
        int x;
        printf("Enter PIN: ");
        for (x = 0; x < 4; x++)
        {
        // accepts the hidden password using the getch() function
        pw[x] = getch();
        printf("*"); // print the input chartered in the form of *
        }
        pw[x] = '\0';
        printf( "\n" );
        getch();

        if(strcmp(accounts[i].pin,pw) == 0)
        {
            return true;
        }
        else
        {
            printf("Invalid Details");
            getch();
            return false;
        }

        }
        else{
        printf("INCORRECT DETAILS");
         getch();
        return false;
        }
        }
        getch();
        return;
}

void checkBalance(struct Account *accounts, int numAccounts, int accountNumber) {
int i;
    for ( i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Account Balance: %.2lf\n", accounts[i].balance);
            getch();
            return;
        }
    }
    printf("Account not found. Feel free to make a new account!\n");
    getch();
}

void transfer(struct Account *accounts, int numAccounts, int fromAccount, int toAccount, double amount) {
    if (amount <= 0) {
        printf("Invalid transfer amount. Please enter a positive amount.\n");
        return;
    }

    double transferAmount = amount + (amount * 0.018);  // 1.8 percent charge
    int i,j;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == fromAccount) {
            if (accounts[i].balance >= transferAmount) {
                for (j = 0; j < numAccounts; j++) {
                    if (accounts[j].accountNumber == toAccount) {
                        accounts[i].balance -= transferAmount;
                        accounts[j].balance += amount;
                        printf("Transfer successful. Updated balance: %.2lf\n", accounts[i].balance);
                        getch();
                        return;
                    }
                }
                printf("Receiver account not found.\n");
                getch();
            } else {
                printf("Insufficient balance for transfer.\n");
                getch();
            }
            return;
        }
    }
    printf("Sender account not found.\n");
    getch();
    return;
}

int main() {
    struct Account *accounts = malloc(10 * sizeof(struct Account));
    int numAccounts = 0;

    if (!authenticate()){
        return 0;
    }
    int select;
    do{
    system("cls");
    printTitle();
    printf("\nWelcome to BankOnTheGo's mobile banking interface! How can we help you today:\n\n");
    printf("1.Create Account\n");
    printf("2.Login\n");
    printf("3.EXIT\n");
    scanf("%d",&select);

    switch(select)
    {
        case 1: {
                system("cls");
                printTitle();
                createAccount(&accounts, &numAccounts);
                break;}
        case 2: {system("cls");
                printTitle();
                printf("///////////////////////////        LOGIN       ///////////////////////////////////\n");
                printf("...................................................................................\n");
                int accNum;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                if(login(accounts, numAccounts, accNum))
                {
            int choice;
    do {
        system("cls");
        printTitle();
        printf("\nWelcome to BankOnTheGo's mobile banking interface! How can we help you today:\n\n");
        printf("1. Transfer Balance\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Check Balance\n");
        printf("5. Logout\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
             case 1: {
                 system("cls");
                 printTitle();
                 printf("///////////////////////////       TRANSFER       ///////////////////////////////////\n");
                 printf("...................................................................................\n");
                int fromAccNum, toAccNum;
                double amount;
                printf("Enter sender account number: ");
                scanf("%d", &fromAccNum);
                if(verification(accounts, numAccounts, fromAccNum)){
                printf("Enter receiver account number: ");
                scanf("%d", &toAccNum);
                printf("Enter amount to transfer: ");
                scanf("%lf", &amount);
                transfer(accounts, numAccounts, fromAccNum, toAccNum, amount);}
                break;
            }
            case 2: {
                system("cls");
                printTitle();
                printf("///////////////////////////      DEPOSIT       ///////////////////////////////////\n");
                printf("...................................................................................\n");
                int accNum;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                if(verification(accounts, numAccounts, accNum))
                {
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(accounts, numAccounts, accNum, amount);}
                break;

            }
            case 3: {
                system("cls");
                printTitle();
                printf("///////////////////////////       WITHDRAW     ///////////////////////////////////\n");
                printf("...................................................................................\n");
                int accNum;
                double amount;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                if(verification(accounts, numAccounts, accNum)){
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(accounts, numAccounts, accNum, amount);}
                break;
            }
            case 4: {
                system("cls");
                printTitle();
                int accNum;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                printf("///////////////////////////    CHECK BALANCE   ///////////////////////////////////\n");
                printf("...................................................................................\n");
                if(verification(accounts, numAccounts, accNum)){
                checkBalance(accounts, numAccounts, accNum);}
                break;
            }
            case 5:
                system("cls");
                printTitle();
                printf("Thank you for visiting our bank!.\n");
                getch();
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
                break;}
    }
                }



    }while(select!=3);
    free(accounts);

    return 0;
}
