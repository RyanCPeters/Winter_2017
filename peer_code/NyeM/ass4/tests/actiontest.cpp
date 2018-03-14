#include "displayinventory.h"
#include "displaytransactionhistory.h"
#include "returnmovie.h"
#include "borrowmovie.h"

int main() {
	BorrowMovie* bm = new BorrowMovie();
	ReturnMovie* rm = new ReturnMovie();
	DisplayInventory* di = new DisplayInventory();
	DisplayTransactionHistory* dth = new DisplayTransactionHistory();

	delete bm;
	delete rm;
	delete di;
	delete dth;

	return 0;
}