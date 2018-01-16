void queryD(Database d, string searchName)
 {
     int count;
     string newname = to_lowercase(searchName);
     for (int i=0; i<d.numberOfProducts; i++)
     {
         string nproduct = to_lowercase(d.products[i].name);
         if (nproduct.find(newname) != string::npos)
         {
             count = 0;
             for (int j=0; j<d.numberOfTran_details; j++)
             {
                 if (d.TransactionDetails[j].pid==d.products[i].pid)
                 {
                    count += d.TransactionDetails[j].quantity;
                 }
             }
              cout << d.products[i].name << " " << count << endl;
         }
     }

 }

string to_lowercase(string s)
 {
     int j=s.length();
     for (int i=0; i<j; i++)
     {
         if (s.at(i) <= 90)
            s.at(i) += 32;
     }
     return s;
 }
