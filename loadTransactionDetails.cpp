void loadTran_details(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    getline(instr,discard);
    d.numberOfTran_details = atoi(discard.c_str());

    d.TransactionDetails = new TransactionDetail[d.numberOfTran_details];
    while (getline(instr,discard,' '))
    {
        d.TransactionDetails[count].tid = atoi(discard.c_str());
        getline(instr,discard,' ');
        d.TransactionDetails[count].pid = atoi(discard.c_str());
        getline(instr,discard);
        d.TransactionDetails[count].quantity = atoi(discard.c_str());
        count++;
    }
    instr.close();
}

void queryC(Database d)
{
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        cout << d.TransactionDetails[i].tid << "\t";
        cout << d.TransactionDetails[i].pid << "\t";
        cout << d.TransactionDetails[i].quantity << endl;
    }
}
