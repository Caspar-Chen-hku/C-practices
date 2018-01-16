struct Product{
 int pid;
 double unitPrice;
 string category;
 string name;
};

struct Transaction{
 int tid;
 string datetime;
 string place;
};

struct TransactionDetail{
 int tid;
 int pid;
 int quantity;
};

 struct Database{
  Product* products;
  int numberOfProducts;
  Transaction* transactions;
  int numberOfTransactions;
  TransactionDetail* TransactionDetails;
  int numberOfTran_details;
};
