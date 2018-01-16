void loadProducts(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
   if (!instr.is_open())
   {
      cout << "Failed to open the file.";
      exit(1);
    }

    string discard;
    getline(instr,discard);
    d.numberOfProducts = atoi(discard.c_str());

    d.products = new Product[d.numberOfProducts];

    int count=0;
    while (getline(instr,discard,','))
    {
        d.products[count].pid = atoi(discard.c_str());
        instr >> d.products[count].unitPrice;
        instr.ignore();
        getline(instr,d.products[count].category,',');
        getline(instr,d.products[count].name);
        count++;
    }
    instr.close();
}

void queryA(Database d)
{
    for (int i=0; i<d.numberOfProducts; i++)
    {
        cout << d.products[i].pid << "\t";
        cout << d.products[i].unitPrice << "\t";
        cout << d.products[i].category << "\t";
        cout << d.products[i].name << "|" << endl;
    }
}
