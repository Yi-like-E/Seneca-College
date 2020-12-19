//================================================================
// Name:           YiHsun Lee
// Section:        NTT
//================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stock.h"

#define MAX_STOCK_ENTRIES 100 
#define MAX_ITEMS_IN_SALE 50

int readStockItems(struct StockRecord record[], const int entries, const int stock)
{
	int i, count = 0, flag = 1;

	for (i = 0; i < entries && flag; i++)
	{

		scanf("%lf,%d,%lf,%d,%20[^\n]", &record[i].quantity, &record[i].product.category, &record[i].product.price, &record[i].product.soldby, record[i].name);

		record[i].product.id = i + 1;  // assign id # for each product  

		if (strlen(record[i].name) == 0) // when input is 0, breaks the for loop
		{
			flag = 0;
		}

		if ((record[i].product.category < 1 || record[i].product.category > 7) && flag)  // check if the category number is in the range (1-7)
		{
			printf("Invalid category - enter a number between 1 and 7: ");
			scanf("%d,%lf,%d,%20[^\n]", &record[i].product.category, &record[i].product.price, &record[i].product.soldby, record[i].name);

		}

		if (record[i].product.soldby != 1 && record[i].product.soldby != 0 && flag)   // check if the input number for soldbyweight/kg is either 1 or 0
		{
			printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
			scanf("%d,%20[^\n]", &record[i].product.soldby, record[i].name);
		}
		if (flag)
		{
			count = i + 1;  //number of stock items
		}
	}
	return count;
}

void centreText(int num, char symbol, char string[])
{
	int charnum, len, i;

	len = strlen(string);

	if (len == 0)
	{
		for (i = 0; i < num; i++)
		{
			printf("%c", symbol);
		}

		printf("\n");
	}
	else if (len % 2 == 0)
	{
		charnum = ((num - len) / 2);

		for (i = 0; i < charnum; i++)
		{
			printf("%c", symbol);
		}
			
		printf("%s", string);

		for (i = 0; i < charnum; i++)
		{
			printf("%c", symbol);
		}
	}
	else
	{
		charnum = ((num - len) / 2);

		for (i = 0; i < charnum; i++)
		{
			printf("%c", symbol);
		}

		printf("%s", string);

		for (i = 0; i < charnum + 1; i++)
		{
			printf("%c", symbol);
		}
	}
	printf("\n");
}

void printStockReport(struct StockRecord stock[], int num)
{
	int i;

	printf("  ID                        Product        Category   Price Quantity\n");

	for (i = 0; i < num; i++)
	{
		printf("%4d %30s", stock[i].product.id, stock[i].name);

		printCategory(stock[i].product.category);

		printf("%8.2lf %8.0lf\n", stock[i].product.price, stock[i].quantity);

	}
}

int readSale(struct StockRecord stock[], int numStock, struct SalesRecord sales[])
{
	int idPosition, i, flag = 1, numSaleItems;
	double numSold, numSoldtotal = 0;

	for (i = 0; i < MAX_ITEMS_IN_SALE && flag; i++)
	{
		printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
		scanf("%d,%lf", &sales[i].stock.product.id, &sales[i].stock.numsold);

		if (sales[i].stock.product.id == 0 || sales[i].stock.numsold == 0)
		{
			sales[i].stock.numsold = 0;
			flag = 0;
		}

		if (sales[i].stock.product.id > numStock && flag)
		{
			printf("Invalid Product - Enter a number between 0 and %d: ", numStock);
			scanf("%d,%lf", &sales[i].stock.product.id, &sales[i].stock.numsold);
		}

		if ((sales[i].stock.numsold < 0.10 || sales[i].stock.numsold > 100.00) && flag)
		{
			printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
			scanf("%d,%lf", &sales[i].stock.product.id, &sales[i].stock.numsold);

		}

		if (flag)
		{
			idPosition = findId(stock, sales[i].stock.product.id, numStock);
			numSold = saleQuantity(stock, sales[i].stock.numsold, idPosition);	// if the purchase quantity is more than the stock, return the stock quantity
			assignSalesStruct(idPosition, stock, sales, i, numSold);  // put product information into SalesRecord Struct
			updateStock(sales, stock, idPosition, sales[i].stock.numsold);  // Update quantity and number of product sold in StockRecord struct 
		}
	}

	numSaleItems = i - 1;

	return numSaleItems;
}

double printSalesReport(struct StockRecord stock[], struct SalesRecord sales[], int num)
{
	int i;
	double total = 0.0, tax = 0.0;

	printf("\n");
	centreText(70, '*', " Seneca Groceries ");
	centreText(70, '=', "");

	for (i = 0; i < num; i++)
	{
		printf("%30s %8.2lf %7.2lf\n", sales[i].stock.name, sales[i].stock.product.price, sales[i].stock.numsold * sales[i].stock.product.price);
		total += (sales[i].stock.numsold * sales[i].stock.product.price);

		if (sales[i].stock.product.category == 6 || sales[i].stock.product.category == 7)
		{
			tax += (sales[i].stock.product.price * 0.13);
		}
	}

	printf("Purchase Total %32.2lf\n", total);
	printf("Tax %43.2lf\n", tax);
	printf("Total %41.2lf\n", total + tax);
	printf("Thank you for shopping at Seneca!\n\n");

	return total;
}

void getTopSellers(struct StockRecord stock[], int numStock, struct SalesRecord top[], int topthree, int catnum)
{
	int i, j = 0;

	struct SalesRecord temp[MAX_ITEMS_IN_SALE] = { 0 };

	for (i = 0; i < numStock; i++)
	{
		if (stock[i].product.category == catnum + 1)
		{
			if (stock[i].numsold > 0)
			{
				strcpy(temp[j].stock.name, stock[i].name);
				temp[j].stock.numsold = stock[i].numsold;
				j++;
			}
		}
	}

	sort(temp, j + 1);

	for (i = 0; i < topthree; i++)
	{
		//if (temp[i].stock.numsold == 0)
		if(strlen(temp[i].stock.name) == 0)
		{
			strcpy(top[i].stock.name, "<none>");
			top[i].stock.numsold = 0.00;
		}
		else
		{
			top[i] = temp[i];
		}
	}
}

void printTopSellers(struct StockRecord stock[], struct SalesRecord top[], int num, int catnum)
{
	int i;

	topsellerbanner(catnum + 1);
	printf("Rank                       Product   Sales\n");

	for (i = 0; i < num; i++)
	{
		printf("%4d%30s%8.2lf\n", i + 1, top[i].stock.name, top[i].stock.numsold);
	}
}

void printCategory(int cat_num)
{
	char cat1[20] = "produce";
	char cat2[20] = "bakery";
	char cat3[20] = "meat";
	char cat4[20] = "dairy";
	char cat5[20] = "baking";
	char cat6[20] = "house wares";
	char cat7[20] = "miscellaneous";

	switch (cat_num)
	{
	default:
		break;
	case 1:
		printf("%16s", cat1);
		break;
	case 2:
		printf("%16s", cat2);
		break;
	case 3:
		printf("%16s", cat3);
		break;
	case 4:
		printf("%16s", cat4);
		break;
	case 5:
		printf("%16s", cat5);
		break;
	case 6:
		printf("%16s", cat6);
		break;
	case 7:
		printf("%16s", cat7);
		break;
	}
}

int findId(struct StockRecord record[], int id, int numStock)
{
	int i, index = -1;

	for (i = 0; i < numStock; i++)
	{
		if (record[i].product.id == id)
		{
			index = i;
		}
	}

	return index;
}

double saleQuantity(struct StockRecord record[], double quantity, int IDindex)
{

	if (quantity > record[IDindex].quantity)
	{
		quantity = record[IDindex].quantity;
	}
	
	return quantity;
}

void assignSalesStruct(int id, struct StockRecord record[], struct SalesRecord sales[], int index, double soldquantity)
{
	sales[index].stock.product.category = record[id].product.category;
	sales[index].stock.product.price = record[id].product.price;
	sales[index].stock.product.soldby = record[id].product.soldby;
	strcpy(sales[index].stock.name, record[id].name);
	sales[index].stock.numsold = soldquantity;
}

void updateStock(struct SalesRecord sales[], struct StockRecord stock[], int idPosition, double quantity)
{
	double numItems;

	numItems = saleQuantity(stock, quantity, idPosition);

	stock[idPosition].quantity -= numItems;

	stock[idPosition].numsold = numItems;  
}

void topsellerbanner(int catnum)
{
	switch (catnum)
	{
	default:
		break;
	case 1:
		centreText(50, '-', " Top 3 sellers in produce ");
		break;
	case 2:
		centreText(50, '-', " Top 3 sellers in bakery ");
		break;
	case 3:
		centreText(50, '-', " Top 3 sellers in meat ");
		break;
	case 4:
		centreText(50, '-', " Top 3 sellers in dairy ");
		break;
	case 5:
		centreText(50, '-', " Top 3 sellers in baking ");
		break;
	case 6:
		centreText(50, '-', " Top 2 sellers in house wares ");
		break;
	case 7:
		centreText(50, '-', " Top 2 sellers in miscellaneous ");
		break;
	}
}

void sort(struct SalesRecord seller[], int num)
{
	int i, j;

	struct SalesRecord temp;

	for (i = num - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if(seller[j].stock.numsold < seller[j+1].stock.numsold)
			{
				temp = seller[j];
				seller[j] = seller[j + 1];
				seller[j + 1] = temp;
			}
		}
	}
}