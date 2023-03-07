#include "../STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include "../Card Module/Card.h"
#include "../Terminal Module/Terminal.h"
#include "Server.h"

ST_accountsDB_t accountsDB[255]={ {2000.0, RUNNING, "8989374615436851"} ,{100000.0, BLOCKED, "5807007076043875"},\
								  {27940.0, RUNNING, "8989374615436852"} ,{1098.0, BLOCKED, "5807007076043875"},\
								  {13200.75, RUNNING, "8989374615436852"} ,{40056.0, BLOCKED, "5807007076043875"} };
ST_transaction_t transactionDB[255] = {0};
static u8 g_counter = 0;

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t** accountRefrence)
{
	u8 counter;
	for (counter = 0; counter < 255; counter++)
	{
		u8 flag = strcmp(cardData->primaryAccountNumber, accountsDB[counter].primaryAccountNumber);
		if (flag==0)
		{
			*accountRefrence = &accountsDB[counter];

			return SERVER_OK;
		}
		else
		{
			*accountRefrence = NULL;
		}
	}
	return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence != NULL)
	{
		if (accountRefrence->state == RUNNING)
		{
			return SERVER_OK;
		}
		else
		{
			return BLOCKED_ACCOUNT;
		}
	}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence != NULL)
	{
		if (termData->transAmount > accountRefrence->balance)
		{
			return LOW_BALANCE;
		}
		else
		{
			return SERVER_OK;
		}
	}
}

EN_transState_t recieveTransactionData(ST_transaction_t * transData)
{
	ST_accountsDB_t* accountRefrence = NULL;
	u8 accountstate = 9;
	accountstate=isValidAccount(&transData->cardHolderData, &accountRefrence);
	if (accountstate!= SERVER_OK)
	{
		return FRAUD_CARD;
	}
	else
	{
		u8 ServerState = 9;
		ServerState =isAmountAvailable(&transData->terminalData, accountRefrence);
		if (ServerState ==LOW_BALANCE )
		{
			printf("your balance is %f\n", accountRefrence->balance);
			return DECLINED_INSUFFECIENT_FUND;
		}
		ServerState = isBlockedAccount(accountRefrence);
		if (ServerState == BLOCKED_ACCOUNT)
		{
			return DECLINED_STOLEN_CARD;
		}
		else if (g_counter > 255)
		{
			return INTERNAL_SERVER_ERROR;
		}
		if (accountRefrence != NULL)
		{
			printf("your balance was %f\n", accountRefrence->balance);
			accountRefrence->balance -= transData->terminalData.transAmount;
			printf("your current balance is %f\n", accountRefrence->balance);

		}
		return APPROVED;
	}
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	
	transData->transactionSequenceNumber = g_counter;
	transactionDB[g_counter].cardHolderData = transData->cardHolderData;
	transactionDB[g_counter].terminalData = transData->terminalData;
	transactionDB[g_counter].transState = transData->transState;
	transactionDB[g_counter].transactionSequenceNumber = g_counter;
	g_counter++;
	return SERVER_OK;
}

void listSavedTransactions(void)
{
	u8 counter;
	for (counter = 0; counter <= g_counter-1; counter++)
	{
		printf("#########################\n");
		printf("Transaction Sequence Number: %d\n", counter);
		printf("Transaction Date: %s\n", transactionDB[counter].terminalData.transactionDate);
		printf("Transaction Amount: %f\n", transactionDB[counter].terminalData.transAmount);
		printf("Transaction State:" );
		if (transactionDB[counter].transState == APPROVED)
		{
			printf("APPROVED\n");
		}
		if (transactionDB[counter].transState == FRAUD_CARD)
		{
			printf("FRAUD_CARD\n");
		}
		if (transactionDB[counter].transState == DECLINED_STOLEN_CARD)
		{
			printf("DECLINED_STOLEN_CARD\n");
		}
		if (transactionDB[counter].transState == DECLINED_INSUFFECIENT_FUND)
		{
			printf("DECLINED_INSUFFECIENT_FUND\n");
		}
		if (transactionDB[counter].transState == INTERNAL_SERVER_ERROR)
		{
			printf("INTERNAL_SERVER_ERROR\n");
		}
		printf("Terminal Max Amount: %f\n", transactionDB[counter].terminalData.maxTransAmount);
		printf("Cardholder Name: %s\n", transactionDB[counter].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transactionDB[counter].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", transactionDB[counter].cardHolderData.cardExpirationDate);
		printf("#########################\n");
	}
}/*typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;    float transAmount;
    float maxTransAmount;
    u8 transactionDate[11];
	EN_transState_t transState;
	u32 transactionSequenceNumber;
}ST_transaction_t; */

ST_terminalData_t termData2 = { 5000.0,20000.0,{0} };
ST_cardData_t cardData[5] = {{{0},"5807007076043871",{0}},{{0},"8989374615436852",{0}}, };
ST_transaction_t transaction[4] = { {{"AhmedSalahAbdalazeem","8989374615436851","11/25"},{5000.0,20000.0,"13/11/2024"},APPROVED,0},{{{0},"5807007076043875",{0}},{5000.0,20000.0,{0}},0,0}
,{{{0},"8989374615436852",{0}},{5000.0,20000.0,{0}},0,0} ,{{{0},"8989374615436852",{0}},{5000.0,20000.0,{0}},0,0} };

void recieveTransactionDataTest(void)
{
	u8 static counter = 0;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : recieveTransactionData\n");
	printf("Test Case %d :\n", counter+1);
	u8 data_Status = recieveTransactionData(&transaction[2]);
	printf("Actual Result : ");
	if (data_Status == FRAUD_CARD)
	{
		printf("FRAUD_CARD\n");;
	}
	else if (data_Status == DECLINED_INSUFFECIENT_FUND)
	{
		printf("DECLINED_INSUFFECIENT_FUND\n");
	}
	else if (data_Status == DECLINED_STOLEN_CARD)
	{
		printf("DECLINED_STOLEN_CARD\n");
	}
	else if (data_Status ==  INTERNAL_SERVER_ERROR)
	{
		printf("INTERNAL_SERVER_ERROR\n");
	}
	else
	{
		printf("APPROVED\n");
	}

	counter++;
}
ST_accountsDB_t* reference = NULL;

void isValidAccountTest(void)
{
	u8 static counter = 0;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : isValidAccount\n");
	printf("Test Case %d :\n", counter+1);
	u8 data_Status = isValidAccount(&cardData[counter], &reference);
	printf("Input Data : %s\n",cardData[counter].primaryAccountNumber);
	printf("Actual Result : ");
	if (data_Status == SERVER_OK)
	{
		printf("SERVER_OK\n");
	}
	else
	{
		printf("ACCOUNT_NOT_FOUND\n");
	}
	counter++;
}

void isBlockedAccountTest(void)
{
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name :isBlockedAccount \n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = isBlockedAccount(&accountsDB[counter]);
	printf("Input Data : %s\n", cardData[counter-1].primaryAccountNumber);
	printf("Actual Result : ");
	if (data_Status == SERVER_OK)
	{
		printf("SERVER_OK\n");
	}
	else
	{
		printf("BLOCKED_ACCOUNT\n");
	}
	counter++;
}

void isAmountAvailableTest(void)
{
	u8 static counter = 0;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name :isAmountAvailable \n");
	printf("Test Case %d :\n", counter+1);
	u8 data_Status = isAmountAvailable(&termData2, &accountsDB[counter]);
	printf("Input Data : %f\n", termData2.transAmount);
	printf("Actual Result: ");
	if (data_Status == SERVER_OK)
	{
		printf("SERVER_OK\n");
	}
	else
	{
		printf("LOW_BALANCE\n");
	}
	counter++;
}

void saveTransactionTest(void)
{
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : saveTransaction \n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = saveTransaction(&transaction);
	listSavedTransactions();
	printf("Actual Result : ");

	if (data_Status == SERVER_OK)
	{
		printf("SERVER_OK\n");
	}
	else
	{
		printf("SAVING_FAILED\n");
	}
	counter++;
}

void listSavedTransactionsTest(void)
{
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : listSavedTransactions\n");
	printf("Test Case %d :\n", counter);
	listSavedTransactions();
	counter++;
}



