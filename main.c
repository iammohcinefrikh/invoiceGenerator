#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float calculateTVA (float totalHT, float TVARate) {
	float calculation = totalHT * (TVARate / 100);
	return calculation;
}

float calculateTotalTTC (float totalHT, float calculatedTVARate) {
	float calculation = totalHT + calculatedTVARate;
	return calculation;
}

float calculateTotalHT (float itemOnePrice, float itemTwoPrice, float itemThreePrice) {
	float calculation = itemOnePrice + itemTwoPrice + itemThreePrice;
	return calculation;
}

int main(int argc, char *argv[]) {
	char clientName[128], itemOneName[64], itemTwoName[64], itemThreeName[64];
	float itemOnePrice, itemTwoPrice, itemThreePrice, calculatedTVARate, TVARate, totalHT, totalTTC;
	int paymentMethod;
	
	// client name
	printf("######## INVOICE GENERATOR ########\n\n");
	printf("Kindly enter the following required information to generate your invoice:\n\n");
	printf("-- Client Name: ");
	scanf("%s", &clientName);
	// item one details
	printf("-- First Item Name: ");
	scanf("%s", &itemOneName);
	printf("-- First Item Price (in DH): ");
	scanf("%f", &itemOnePrice);
	// item two details
	printf("-- Second Item Name: ");
	scanf("%s", &itemTwoName);
	printf("-- Second Item Price (in DH): ");
	scanf("%f", &itemTwoPrice);
	// item three details
	printf("-- Third Item Name: ");
	scanf("%s", &itemThreeName);
	printf("-- Third Item Price (in DH): ");
	scanf("%f", &itemThreePrice);
	// TVA rate
	printf("-- TVA Rate: ");
	scanf("%f", &TVARate);
	// Payment Method
	printf("-- Payment Method - Press 1 for \"In Person\", or 2 for \"Online\" payment method: ");
	scanf("%d", &paymentMethod);
	
	printf("\n\n############# INVOICE ##############\n\n");
	printf("Billed to: %s\n\n", clientName);
	printf("Items (3):\n");
	printf("-- %s (%.2fDH)\n", itemOneName, itemOnePrice);
	printf("-- %s (%.2fDH)\n", itemTwoName, itemTwoPrice);
	printf("-- %s (%.2fDH)\n\n", itemThreeName, itemThreePrice);
	
	totalHT = calculateTotalHT(itemOnePrice, itemTwoPrice, itemThreePrice);
	calculatedTVARate = calculateTVA(totalHT, TVARate);
	totalTTC = calculateTotalTTC(totalHT, calculatedTVARate);
	printf("Total TTC: %.2fDH\n", totalTTC);
	printf("-- Total HT: %.2fDH\n", totalHT);
	printf("-- Including TVA: %.2fDH (%.2f%c)\n\n", calculatedTVARate, TVARate, 37);
	
	if (paymentMethod == 1) {
		printf("Payment Method: In Person\n\n");
	}
	else {
		printf("Payment Method: Online\n\n");
	}
	printf("####################################\n\n");
	return 0;
}
