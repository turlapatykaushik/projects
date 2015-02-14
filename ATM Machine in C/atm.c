#include<stdio.h>

int main()
{
	int balance=0;
	int pin = 1231;
	int tmpPin;
	int anotherTransaction=1;
	
	printf("Welcome to our bank ATM\n");
	printf("Please enter your four digit pin number:\n");
	scanf("%d",&tmpPin);

	if(pin != tmpPin)
	{
		printf("Invalid pin number\n");
		return 0;
	}
	
	while(anotherTransaction==1)
	{
		int option;
		
		printf("What do you want to do? \n");
		printf("1. Check your balance\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		scanf("%d",&option);

		if(option == 1)//check balance
		{
			printf("Your balance is: $%d \n",balance);
		}
		
		else if(option == 2)//deposit
		{
			int amountDeposit;
			printf("How much money do you want to deposit? $");
			scanf("%d",&amountDeposit);
			if(amountDeposit > 0)
			{
				balance += amountDeposit;
			}
			else
			{
				printf("Invalid deposit amount\n");
			}
		}
		
		else if(option == 3)//withdraw
		{
			int amountWithdraw;
			printf("How much money do you want to withdraw: $");
			scanf("%d", &amountWithdraw);
			if(amountWithdraw <= balance && amountWithdraw % 20 ==0 && amountWithdraw >= 0)
			{
				balance -= amountWithdraw;
			}
			else
			{
				if(amountWithdraw  > balance)
				{
					printf("You dont have enough money \n");
				}
				if(amountWithdraw < 0)
				{
					printf("Invalid amount withdraw\n");
				}
				if(amountWithdraw % 20 != 0)
				{
					printf("You must enter amount which is divisible by 20\n");
				}
				else
				{
					printf("Invalid amount withdraw\n");
				}
			}
		}
		
		else
		{
			printf("Invalid transaction \n");
		}
		
		anotherTransaction =0;
		
		while((anotherTransaction != 1) && (anotherTransaction != 2))
		{
			printf("Do you want to make another Transaction: \n");
			printf("1-Yes 2-No\n");
			scanf("%d",&anotherTransaction);
		}
	}
	
	printf("Thanks for banking with us\n");

	return 0;
}



