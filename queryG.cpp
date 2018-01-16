void queryG(Database d, int tid)
{
    int count = 0;
    double sum = 0;
    double* arr = new double[d.numberOfTran_details];
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        if (d.TransactionDetails[i].tid == tid)
        {
            arr[i]= d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity;
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
        double biggest;
        int index;
        for (int i=0; i<count; i++)
        {
            biggest=0;
            index = 0;
            for (int j=0; j<d.numberOfTran_details; j++)
            {
              if(arr[j]>biggest)
              {
                index=j;
                biggest=arr[j];
              }
            }
            cout << d.products[d.TransactionDetails[index].pid].name <<'\t';
            cout << d.products[d.TransactionDetails[index].pid].unitPrice << '\t';
            cout << d.TransactionDetails[index].quantity << '\t';
            cout << arr[index] << endl;
            arr[index]=0;
        }
        cout << "Total:" << sum << endl;
    }
    delete []arr;
    arr = 0;
}
