//working with linked list
//list.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct NameCode{
  string name;
  string code;
  NameCode* next;
};

void insert_at_tail(NameCode* &head, NameCode* nnamecode);
void delete_list(NameCode* &head);
void display(NameCode* head);
void insert_new(NameCode* &head, NameCode* nnode);
void sort(NameCode* &head);
void insert_by_length(NameCode* &head, NameCode* nnode);

int main()
{
   string filename;
   cout << "Please enter a filename: ";
   cin >> filename;
   ifstream instr(filename.c_str());
   if (!instr.is_open())
   {
      cout << "Failed to open the file.";
      exit(1);
   }

   NameCode* head = NULL;
   string discard;
   getline(instr,discard);
   string nname,ncode;
   while (getline(instr,nname,';'))
   {
      getline(instr,ncode);
      NameCode* nnamecode = new NameCode;
      nnamecode->name = nname;
      nnamecode->code = ncode;
      insert_at_tail(head,nnamecode);
    }

    NameCode* nnode = new NameCode;
    string newname,newcode;
    cout << "Please input a new pair of name and code: ";
    cin >> newname >> newcode;
    nnode->name = newname;
    nnode->code = newcode;
    nnode->next = NULL;
    insert_new(head,nnode);

    sort(head);
    display(head);

    delete_list(head);
    instr.close();
    return 0;
}

void insert_at_tail(NameCode* &head, NameCode* nnamecode)
{
   NameCode* current = head;
   if (current!=NULL)
   {
       while(current->next!=NULL)
       {
         current = current->next;
       }
       nnamecode->next = NULL;
       current->next = nnamecode;
   }
   else
   {
       nnamecode->next=NULL;
       head = nnamecode;
   }
}

void delete_list(NameCode* &head)
{
   NameCode* current;
   while (head!=NULL)
   {
      current = head;
      head = head->next;
      delete current;
   }
   current = NULL;
}

void display(NameCode* head)
{
    NameCode* current=head;
    while (current!=NULL)
    {
        cout << current->name << '\t' << current->code << endl;
        current = current->next;
    }
    cout << endl;
}

void insert_new(NameCode* &head, NameCode* nnode)
{
    NameCode* current=head;
    NameCode* prev = NULL;
    if (head->name > nnode->name)
    {
        nnode->next = head;
        head = nnode;
    }
    else
    {
        while (current!=NULL && current->name < nnode->name)
        {
          prev = current;
          current = current->next;
        }
        nnode->next = current;
        prev->next = nnode;
    }
}

void sort(NameCode* &head)
{
    NameCode* sorted = NULL;
    NameCode* temp=head;
    head = head->next;
    sorted=temp;
    temp->next=NULL;
    while (head!=NULL)
    {
        temp=head;
        head = head->next;
        insert_by_length(sorted,temp);
    }
    head = sorted;
}

void insert_by_length(NameCode* &head, NameCode* nnode)
{
    NameCode* current=head;
    NameCode* prev = NULL;
    if (head->name.length() > nnode->name.length())
    {
        nnode->next = head;
        head = nnode;
    }
    else
    {
        while (current!=NULL && current->name.length() < nnode->name.length())
        {
          prev = current;
          current = current->next;
        }
        if (prev==NULL)
        {
            nnode->next = head;
            head = nnode;
        }
        else
        {
            nnode->next = current;
            prev->next = nnode;
        }
    }
}
