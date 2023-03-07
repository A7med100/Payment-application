#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>
#include "App/app.h"
#include "Card Module/Card.h"
#include "Terminal Module/Terminal.h"
#include "Server Module/Server.h"


void main(void)
{
	/*//------------- isCardExpiredTest---------------------------------
	getCardExpiryDateTest();
	getTransactionDateTest();
	printf("case Card:is Expired\n ");
	isCardExpiredTest();
	printf("Expected Result :EXPIRED_CARD \n\n");

	//-------------isBelowMaxAmountTest ---------------------------------
	setMaxAmountTest();
	getTransactionAmountTest();
	printf("case TransactionAmount:more tan MaxAmount\n ");
	isBelowMaxAmountTest();
	printf("Expected Result :EXCEED_MAX_AMOUNT \n\n");

	///--------Transaction stae test-----------------------------------------
	printf("case Transaction:more than balance \n ");
	recieveTransactionDataTest();
	printf("Expected Result :DECLINED_INSUFFECIENT_FUND \n\n");

	printf("case card: is stolen \n ");
	recieveTransactionDataTest();
	printf("Expected Result :DECLINED_STOLEN_CARD \n\n");

	printf("case Transaction:is valid\n ");
	recieveTransactionDataTest();
	printf("Expected Result :APPROVED \n\n");

	

	
		printf("case Transaction:is valid\n ");
	recieveTransactionDataTest();
	printf("Expected Result :APPROVED \n\n");

	printf("case TransactionAmount:more tan MaxAmount\n ");
	setMaxAmountTest();
	getTransactionAmountTest();
	isBelowMaxAmountTest();
	printf("Expected Result :EXCEED_MAX_AMOUNT \n\n");

	printf("case TransactionAmount:is not valid \n ");
	getTransactionAmountTest();
	isAmountAvailableTest();
	
	//------------ - getCardHolderNameTest--------------------------------
	
	printf("case name:less than 19\n ");
	getCardHolderNameTest();
	printf("Expected Result :WRONG_NAME \n\n");

	printf("case name:more than 24 \n");
	getCardHolderNameTest();
	printf("Expected Result :WRONG_NAME \n\n");

	printf("case name: include non alphabetic characters \n");
	getCardHolderNameTest();
	printf("Expected Result : WRONG_NAME \n\n");

	printf("case name: is valid \n");
	getCardHolderNameTest();
	printf("Expected Result :CARD_OK \n");
	//-------------getCardExpiryDateTest-------------------------------- - 
	printf("case Date:less than 5\n ");
	getCardExpiryDateTest();
	printf("Expected Result :WRONG_EXP_DATE \n\n");

	printf("case Date:more tan 5\n ");
	getCardExpiryDateTest();
	printf("Expected Result :WRONG_EXP_DATE \n\n");

	printf("case Date:has wrong format\n ");
	getCardExpiryDateTest();
	printf("Expected Result :WRONG_EXP_DATE \n\n");

	printf("case Date:is valid\n ");
	getCardExpiryDateTest();
	printf("Expected Result :CARD_OK \n\n");
	//-------------getCardPANTest---------------------------------
	printf("case PAN:less than 16\n ");
	getCardPANTest();
	printf("Expected Result :WRONG_PAN \n\n");

	printf("case PAN:more tan 19\n ");
	getCardPANTest();
	printf("Expected Result :WRONG_PAN \n\n");

	printf("case PAN:Non Numeric\n ");
	getCardPANTest();
	printf("Expected Result :WRONG_PAN \n\n");

	printf("case PAN:is valid\n ");
	getCardPANTest();
	printf("Expected Result :CARD_OK \n\n");

//-------------------------------------TERMINAL MODULE----------------------------
	//-------------getTransactionDateTest ------------------------
	printf("case Date:less than 10\n ");
	getTransactionDateTest();
	printf("Expected Result :WRONG_DATE \n\n");

	printf("case Date:more tan 10\n ");
	getTransactionDateTest();
	printf("Expected Result :WRONG_DATE \n\n");

	printf("case Date: has wrong format\n ");
	getTransactionDateTest();
	printf("Expected Result :WRONG_DATE \n\n");

	printf("case Date:is valid\n ");
	getTransactionDateTest();
	printf("Expected Result :TERMINAL_OK \n\n");
	
	 ///------------- isCardExpiredTest---------------------------------
	//getCardExpiryDateTest();

	getTransactionDateTest();

	printf("case Card:is Expired\n ");
	isCardExpiredTest();
	printf("Expected Result :EXPIRED_CARD \n\n");
	
	getTransactionDateTest();

	printf("case Card:has more than year before expiry date \n ");
	isCardExpiredTest();
	printf("Expected Result :TERMINAL_OK \n\n");

	getTransactionDateTest();

	printf("case Card:has more than Month before expiry date \n ");
	isCardExpiredTest();
	printf("Expected Result :TERMINAL_OK \n\n");

	//-------------getTransactionAmountTest ---------------------------------
	printf("case TransactionAmount:less than 0\n ");
	getTransactionAmountTest();
	printf("Expected Result :INVALID_AMOUNT \n\n");

	printf("case TransactionAmount:equal 0\n ");
	getTransactionAmountTest();
	printf("Expected Result :INVALID_AMOUNT \n\n");

	printf("case TransactionAmount:is valid\n ");
	getTransactionAmountTest();
	printf("Expected Result :TERMINAL_OK \n\n");


	//-------------setMaxAmountTest ---------------------------------
	printf("case MaxAmount:less than 0\n ");
	setMaxAmountTest();
	printf("Expected Result :INVALID_MAX_AMOUNT \n\n");
	
	printf("case MaxAmount:equal 0 \n ");
	setMaxAmountTest();
	printf("Expected Result :INVALID_MAX_AMOUNT \n\n");
	
	printf("case MaxAmount:is valid\n ");
	setMaxAmountTest();
	printf("Expected Result :TERMINAL_OK \n\n");
//-------------isBelowMaxAmountTest ---------------------------------
	
	setMaxAmountTest();
	getTransactionAmountTest();

	printf("case TransactionAmount:more tan MaxAmount\n ");
	isBelowMaxAmountTest();
	printf("Expected Result :EXCEED_MAX_AMOUNT \n\n");

	getTransactionAmountTest();
	printf("case TransactionAmount:is  valid\n ");
	isBelowMaxAmountTest();
	printf("Expected Result :TERMINAL_OK \n\n");

//-------------------------------------Server MODULE----------------------------
*/
	///-------------isValidAccountTest ---------------------------------
	printf("case Card:is not valid\n ");
	isValidAccountTest();
	printf("Expected Result :ACCOUNT_NOT_FOUND \n\n");

	printf("case Card:is valid\n ");
	isValidAccountTest();
	printf("Expected Result :SERVER_OK \n\n");
	/*
	///------------- recieveTransactionDataTest---------------------------------
	printf("case Card:not found \n ");
	recieveTransactionDataTest();
	printf("Expected Result :FRAUD_CARD \n\n");

	printf("case Transaction:more than balance \n ");
	recieveTransactionDataTest();
	printf("Expected Result :DECLINED_INSUFFECIENT_FUND \n\n");

	printf("case card: is stolen \n ");
	recieveTransactionDataTest();
	printf("Expected Result :DECLINED_STOLEN_CARD \n\n");

	printf("case Transaction:is valid\n ");
	recieveTransactionDataTest();
	printf("Expected Result :APPROVED \n\n");

	//-------------isBlockedAccountTest ---------------------------------
	printf("case Account:is not valid \n ");
	isBlockedAccountTest();
	printf("Expected Result :BLOCKED_ACCOUNT \n\n");

	printf("case Account:is valid\n ");
	isBlockedAccountTest();
	printf("Expected Result :SERVER_OK \n\n");
	//-------------isAmountAvailableTest ---------------------------------
	printf("case TransactionAmount:is not valid \n ");
	isAmountAvailableTest();
	printf("Expected Result :LOW_BALANCE \n\n");
  
	printf("case TransactionAmount:is valid\n ");
	isAmountAvailableTest();
	printf("Expected Result :SERVER_OK \n\n");

	////-------------saveTransactionTest ---------------------------------
	//printf("case :less tan \n ");
	saveTransactionTest();
	printf("Expected Result :SERVER_OK \n\n");
	*/


}