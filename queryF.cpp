void queryF(Database d, int tid)
{
    int count = 0;
    double sum = 0;
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        if (d.TransactionDetails[i].tid == tid)
        {
            cout << d.products[d.TransactionDetails[i].pid].name <<'\t';
            cout << d.products[d.TransactionDetails[i].pid].unitPrice << '\t';
            cout << d.TransactionDetails[i].quantity << '\t';
            cout << d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity
            << endl;
            count++;
            sum += d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity;
        }
    }
    if (count==0)
    {
        cout << "Not found!";
    }
    else
    {
        cout << "Total:" << sum << endl;
    }
}
