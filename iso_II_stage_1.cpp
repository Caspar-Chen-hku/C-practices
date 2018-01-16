// ENGG1111A/B   2015-2016
// Lab 11
// iso_ll.cpp
//
// This program is from Lab 11. It reads ISO3166 names from the ISO3166
// text file and stores them with their codes in a linked list
//
// The input file is assumed to be valid and there is no error checking.
// This version reads field by field from the input file.

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct NCNode
{
      string name;
      string code;
      NCNode* next;
};

// the next two functions can require the head pointer to change and
// there are two ways to handle that. We can return the new pointer and
// the caller must assign the returned value to head, as shown for insert_at_head().
// Or we can change head via a reference parameter as shown for insert_at_tail().
// In the functions below, these two approaches have been mixed relative to the
// notes to give you more practice.


NCNode* insert_at_head(NCNode* head, NCNode* pNode); // returns new head
void insert_at_tail(NCNode* &head, NCNode* pNode);   // changes head by reference

void display_list(NCNode* head);                     // traverse and display

NCNode* find_prev(NCNode* head, string content);     // finds node, prev, ahead of insertion point
void insert(NCNode* prev, NCNode* pNode);            // inserts following prev
void insert_in_order(NCNode* &head, NCNode* pNode);  // inserts at head or within list as necessary

NCNode* remove_at_head(NCNode* &head);               // used by insertion sort
void sort_by_name_length(NCNode* &head);             // insertion sort

void delete_list(NCNode* &head);                      //changes head by reference

int main()
{
   NCNode* head = NULL;

   string name;
   string code;
   string discard;

   ifstream instream("ISO3166.txt");
   if (!instream.is_open())
   {
      cout << "Failed to open input file" << endl;
      exit(1);
   }

   int count = 0;

   //Skip header
   getline(instream, discard);

   //Exract name/code pairs until EOF
   while (getline(instream, name, ';'))
   {
      getline(instream, code);
      NCNode* pNode = new NCNode;
      pNode->name = name;
      pNode->code = code;
      pNode->next = NULL;
      head = insert_at_head(head, pNode);
      ++count;
   }
   cout << "\nThere are " << count << " names" << endl;

   display_list(head);

   delete_list(head);
   instream.close();

   return 0;
}

NCNode* insert_at_head(NCNode* head, NCNode* pNode)
{
   pNode->next = head;
   return pNode;
}

void display_list(NCNode* head)
{
   NCNode* current = head;
   cout << "\nCode" << '\t' << "Name" << endl;
   while(current != NULL)
   {
      cout << current->code << '\t' << current->name << endl;
      current = current->next;
   }
   cout << endl;
}

void delete_list(NCNode* &head)
{
   NCNode* current = head;
   while (current != NULL)
   {
      NCNode* temp = current;
      current = current->next;
      delete temp;
   }
   head = NULL;
}
