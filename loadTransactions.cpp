void loadTransactions(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    string add;
    getline(instr,discard);
    d.noOfTransactions = atoi(discard.c_str());

    d.transactions = new Transaction[d.noOfTransactions];
    while (getline(instr,discard,' '))
    {
        d.transactions[count].tid = atoi(discard.c_str());
        getline(instr,discard,' ');
        getline(instr,add,' ');
        d.transactions[count].datetime = discard + '\t' + add;
        getline(instr,d.transactions[count].place);
        count++;
    }
    instr.close();
}

void queryB(Database d)
{
    for (int i=0; i<d.noOfTransactions; i++)
    {
        cout << d.transactions[i].tid << "\t";
        cout << d.transactions[i].datetime << "\t";
        cout << d.transactions[i].place << "|" << endl;
    }
}
