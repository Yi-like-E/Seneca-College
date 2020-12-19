//================================================================
// Name:           YiHsun Lee
// Section:        NTT
//================================================================

struct Product
{
	int id;
	int category;
	double price;
	int soldby;
};

struct StockRecord
{
	struct Product product;
	char name[21];
	double quantity;
	double numsold; //how many products were sold 
};

struct SalesRecord
{
	struct StockRecord stock;
};


int readStockItems(struct StockRecord record[], const int entries, const int stock);

void centreText(int num, char symbol, char string[]);

void printStockReport(struct StockRecord sales[], int num);

int readSale(struct StockRecord stock[], int numStock, struct SalesRecord sales[]);

double printSalesReport(struct StockRecord stock[], struct SalesRecord items[], int num);

void getTopSellers(struct StockRecord stock[], int numStock, struct SalesRecord topsellers[], int num, int catnum);

void printTopSellers(struct StockRecord stock[], struct SalesRecord topsellers[], int num, int catnum);

// Print category names
void printCategory(int cat_num);

// Find the corresponding index in StockRecord struct via entered ID
int findId(struct StockRecord record[], int id, int numStock);

// Check if the quantity in stock for the purchased item is enough
double saleQuantity(struct StockRecord record[], double quantity, int IDindex);

// Assign values into the SalesRecord struct to display 
void assignSalesStruct(int id, struct StockRecord record[], struct SalesRecord sales[], int index, double soldquantity);

// Update quantity in StockRecord struct 
void updateStock(struct SalesRecord sales[], struct StockRecord stock[], int idPosition, double quantity);

// print banner for top 3 sellers in different category 
void topsellerbanner(int catnum);

// sort the items by number of sold items for topseller struct
void sort(struct SalesRecord seller[], int num);