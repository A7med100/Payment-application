#include "../STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include "Card.h"

cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	u8 counter;
	printf("Enter card Holder Name\n");
	scanf("%s", cardData->cardHolderName);
	//If the cardholder name is less than 20 characters or more than 24 will return a WRONG_NAME error
	u8 legnth = strlen(cardData->cardHolderName);
	if (legnth < 19 || legnth > 24)
	{
		return WRONG_NAME;
	}
	for (counter = 0; counter < legnth; counter++)
	{
		if (cardData->cardHolderName[counter] < 'A' || cardData->cardHolderName[counter]>'z')
		{
			return WRONG_NAME;
		}
	}
	return CARD_OK;
}

cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	u8 month = (cardData->cardExpirationDate[0] - '0') * 10 + cardData->cardExpirationDate[1] - '0';
	
	u8 counter;

	printf("Enter card expiry date \"MM / YY\"\n");
	scanf(" %s", cardData->cardExpirationDate);
	u8 num = strlen(cardData->cardExpirationDate);
	if (num != 5 || cardData->cardExpirationDate[2] != '/')//checking cardExpirationDate format
	{
		return WRONG_EXP_DATE;
	}
	else if ( month > 12 ||  month == 0)
	{
		return WRONG_EXP_DATE;
	}
	
	for (counter = 0; counter < 5; counter++)
	{
		if (counter == 2)
		{
			continue;
		}
		if (cardData->cardExpirationDate[counter] < '0' || cardData->cardExpirationDate[counter]>'9')
		{
			return WRONG_EXP_DATE;
		}
	}
	return CARD_OK;
}

cardError_t getCardPAN(ST_cardData_t* cardData)
{
	u8 counter;

	printf("Enter Primary Account Number\n");
	scanf("%s", &cardData->primaryAccountNumber);

	u8 num = strlen(cardData->primaryAccountNumber);
	if (num < 16 || num >19)
	{
		return WRONG_PAN;
	}
	for (counter = 0; counter < num; counter++)
	{
		if (cardData->primaryAccountNumber[counter] > '9' || cardData->primaryAccountNumber[counter] < '0')
		{
			return WRONG_PAN;
		}
	}
	return CARD_OK;
}


void getCardHolderNameTest(void)
{
	u8 static counter = 1;
	ST_cardData_t person;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : getCardHolderName\n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = getCardHolderName(&person);
	printf("Input Data : %s\n", person.cardHolderName);
	printf("Actual Result : ");
	if (data_Status == 0)
	{
		printf("CARD_OK\n");
	}
	else
	{
		printf("WRONG_NAME\n");
	}
	counter++;
}


void getCardExpiryDateTest(void)
{
	ST_cardData_t person;

	u8 data_Status = getCardExpiryDate(&person);
/*
	u8 static counter = 1;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : getCardExpiryDate\n");
	printf("Test Case %d :\n", counter);

	printf("Input Data : %s\n", person.cardExpirationDate);
	printf("Actual Result : ");
	if (data_Status == 0)
	{
		printf("CARD_OK\n");
	}
	else
	{
		printf("WRONG_EXP_DATE\n");
	}
	counter++;*/
}


void getCardPANTest(void)
{
	u8 static counter = 1;
	ST_cardData_t person;
	printf("Tester Name :Ahmed Salah\n");
	printf("Function Name : getCardPAN\n");
	printf("Test Case %d :\n", counter);
	u8 data_Status = getCardPAN(&person);
	printf("Input Data : %s\n", person.primaryAccountNumber);
	printf("Actual Result : ");
	if (data_Status == 0)
	{
		printf("CARD_OK\n");
	}
	else
	{
		printf("WRONG_PAN\n");
	}
	counter++;
}
