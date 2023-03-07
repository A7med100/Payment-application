#include "../STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include "../Card Module/Card.h"
#include "../Terminal Module/Terminal.h"
#include "../Server Module/Server.h"
#include "app.h"


void appStart(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;
	u8 isvalid = initial_state;
	ST_accountsDB_t* reference = NULL;

	getCardHolderName(&cardData);
	getCardExpiryDate(&cardData);
	getCardPAN(&cardData);
//---------------------------------------------------
	getTransactionDate(&termData);
	isvalid=isCardExpired(&cardData,&termData);
	if (isvalid == Ok)
	{
		isvalid = initial_state;
		getTransactionAmount(&termData);
		setMaxAmount(&termData, 10000.0);
		isvalid = isBelowMaxAmount(&termData);
	}
	if (isvalid == Ok)
	{
		isvalid = initial_state;
		isvalid=isValidAccount(&cardData, reference);
	}
	if (isvalid == Ok)
	{
		isAmountAvailable(&termData, reference);
		isvalid = recieveTransactionData(&transData);
		transData.transState = isvalid;
	}
	if (isvalid == Ok)
	{
		saveTransaction(&transData);
	}
}