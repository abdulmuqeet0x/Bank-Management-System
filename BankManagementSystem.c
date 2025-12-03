#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100  // Maximum number of accounts allowed


// Global arrays to store account information
int accountNumbers[MAX_ACCOUNTS];
char names[MAX_ACCOUNTS][30];
float balances[MAX_ACCOUNTS];
int totalAccounts = 0;    


// Function prototypes
void addAccount();
void depositMoney();
void withdrawMoney();
void checkBalances();
int findAccount(int accNum);

int main()
{
    int choice;

    do {
        printf("\n===== Welcome to PBL Bank =====\n\n");
        printf("1. Add Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice) ;
        

        // switching choices of user
        switch(choice)
        {
            case 1:
                addAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalances();
                break;
            case 5:
                printf("Thank you for using PBL Bank. Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select only given function choice\n");
                break;
        }

    } while (choice != 5);

    return 0;
}


// Functions Definitions

void addAccount()
{
    if(totalAccounts >= MAX_ACCOUNTS)
    {
        printf("Sorry! Bank is full. Cannot create more accounts.\n");
        return;
    }

    char newName[30];
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", newName);

    for(int i = 0; i < totalAccounts; i++)
    {
        if(strcmp(names[i], newName) == 0)
        {
            printf("This name is already used. Account creation failed. Try with Different name\n");
            return;
        }
    }

    strcpy(names[totalAccounts], newName);

    printf("Enter Initial Deposit: ");
    scanf("%f", &balances[totalAccounts]);

    if(balances[totalAccounts] < 0)
    {
        printf("Initial deposit cannot be negative. Account creation failed.\n");
        return;
    }

    accountNumbers[totalAccounts] = 1000 + totalAccounts;
    printf("Account created successfully! Your Account Number is: %d\n", accountNumbers[totalAccounts]);
    totalAccounts++;  
}


void depositMoney()
{
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum);
    if(index == -1)
    {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid deposit amount.\n");
        return;
    }

    balances[index] += amount;
    printf("Amount deposited successfully! New Balance: %.2f\n", balances[index]);
}


void withdrawMoney()
{
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum);
    if(index == -1)
    {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    else if(amount > balances[index])
    {
        printf("Insufficient balance! Current Balance: %.2f\n", balances[index]);
        return;
    }

    balances[index] -= amount;
    printf("Withdrawal successful! Remaining Balance: %.2f\n", balances[index]);
}


void checkBalances()
{
    int accNum;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum); 
    if(index == -1)
    {
        printf("Account not found!\n");
        return;
    }

    printf("Account Holder Name: %s\n", names[index]);
    printf("Account Number: %d\n", accountNumbers[index]);
    printf("Current Balance: %.2f\n", balances[index]);
}


int findAccount(int accNum)
{
    for(int i = 0; i < totalAccounts; i++)
    {
        if(accountNumbers[i] == accNum)
        {
            return i;
        }
    }
    return -1;
}