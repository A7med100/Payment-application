#include "../STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include "../Card Module/Card.h"
#include "Terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter  transaction date \"DD/MM/YYYY\"\n");
	scanf("%s", &termData->transactionDate);
	u8 counter;
	u8 legnth=strlen(termData->transactionDate);
	u8 day = (termData->transactionDate[0] - '0') * 10 + termData->transactionDate[1] - '0';
	//if day not valid
	if (legnth != 10)
	{
		return WRONG_DATE;
	}
	if (day > 31 || day==0)
	{
		return WRONG_DATE;
	}
	//if year less than 2000 or bigger than 2099
	if( termData->transactionDate[6] != '2' || termData->transactionDate[7] != '0')
	{
		return WRONG_DATE;
	}
	if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
	{
		return WRONG_DATE;
	}
	for (counter = 0; counter < 10; counter++)
	{
		if (counter == 2 || counter == 5)
		{
			continue;
		}
		if(termData->transactionDate[counter] <'0' || termData->transactionDate[counter]>'9')
		{
			return WRONG_DATE;
		}
	}
	return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	//comparing Year of Date
	if ((cardData->cardExpirationDate[3] + cardData->cardExpirationDate[4])  < (termData->transactionDate[8] + termData->transactionDate[9]))
	{
		return EXPIRED_CARD;
	}
	else if ((termData->transactionDate[8] + termData->transactionDate[9]) == (cardData->cardExpirationDate[3] + cardData->cardExpirationDate[4]))
	{
		//comparing Month of Date
		if ((cardData->cardExpirationDate[0] + cardData->cardExpirationDate[1]) < (termData->transactionDate[3] + termData->transactionDate[4]))
		{
			return EXPIRED_CARD;
		}
	}
		return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("enter transaction amount\n");
	scanf("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	if (maxAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}

}

ST_cardData_t cardData2 = { {0},{0},"09/23" };
ST_terminalData_t termData;

void getTransactionDateTest(void)
{
	u8 data_Status = getTransactionDate(&termData);
/*
	
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : getTransactionDate\n");
	printf("Test Case %d :\n", counter);

	printf("Input Data : %s\n", termData.transactionDate);
	printf("Actual Result : ");
	if (data_Status == TERMINAL_OK)
	{
		printf("TERMINAL_OK\n");
	}
	else
	{
		printf("WRONG_DATE\n");
	}
	counter++;*/
}

void isCardExpiredTest(void)
{
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : isCardExpired\n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = isCardExpired(&cardData2,&termData);
	printf("Input Data :Transaction Date:%s	 Card Expiry Date:%s\n",termData.transactionDate,cardData2.cardExpirationDate );
	printf("Actual Result : ");
	if (data_Status == TERMINAL_OK)
	{
		printf("TERMINAL_OK\n");
	}
	else
	{
		printf("EXPIRED_CARD\n");
	}
	counter++;
}

void getTransactionAmountTest(void)
{
	u8 data_Status = getTransactionAmount(&termData);
	/*u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : getTransactionAmount\n");
	printf("Test Case %d :\n", counter);

	printf("Input Data : %f\n", termData.transAmount);
	printf("Actual Result : ");
	if (data_Status == TERMINAL_OK)
	{
		printf("TERMINAL_OK\n");
	}
	else
	{
		printf("INVALID_AMOUNT\n");
	}
	counter++;*/
}

void setMaxAmountTest(void)
{
	float max = 0;
	printf("enter max amount 00.0\n");
	scanf("%f", &max);
	u8 data_Status = setMaxAmount(&termData, max);

/*	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : setMaxAmount\n");
	printf("Test Case %d :\n", counter);

	printf("Input Data : %f\n", max);
	printf("Actual Result : ");
	if (data_Status == TERMINAL_OK)
	{
		printf("TERMINAL_OK\n");
	}
	else
	{
		printf("INVALID_MAX_AMOUNT\n");
	}
	counter++;*/
}


void isBelowMaxAmountTest(void)
{
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : isBelowMaxAmount\n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = isBelowMaxAmount(&termData);
	printf("Input Data : %f\n", termData.transAmount);
	printf("Actual Result : ");
	if (data_Status == TERMINAL_OK)
	{
		printf("TERMINAL_OK\n");
	}
	else
	{
		printf("EXCEED_MAX_AMOUNT\n");
	}
	counter++;
}


