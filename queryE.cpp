void queryE(Database d, string place, int YYYY)
 {
    int arr[12] = {};
    for (int i=0; i< 12; i++)
    {
        int year = atoi(d.transactions[i].datetime.substr(0,4).c_str());
        if (d.transactions[i].place == place && year == YYYY)
        {
            int month = atoi(d.transactions[i].datetime.substr(5,2).c_str());
            arr[month-1] ++;
        }
    }
    for (int j=0; j< 12; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
 }
