#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Page {
    public:
        int id;
        string path;
        int counter;
        Page(int id, string path) {
            this->id = id;
            this->path = path;
            counter = 0;
        };
        friend bool operator<(const Page & a, const Page & b);
};

vector<Page> pages;

// Please implement the following function
bool operator<(const Page & a, const Page & b) {
    if (a.counter<b.counter) return true;
    else if (a.counter>b.counter) return false;
    else{
        return (a.path<b.path);
    }

};

class User {
    public:
        int id;
        vector<string> visits;
        User(int id) {
            this->id = id;
        };
        void add_visit(int page_id) {
            Page p(page_id, "");
            vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
            if(iter->id == page_id)
                visits.push_back(iter->path);
        };
        int size() const {
            return visits.size();
        };
        void print_visits() {
            sort(visits.begin(), visits.end());
            vector<string>::iterator iter;
            for(iter = visits.begin(); iter != visits.end(); iter++) {
                cout << "- " << *iter << endl;
            }
        }
        friend bool operator<(const User & a, const User & b);
};

vector<User> users;

// Please implement the following function
bool operator<(const User & a, const User & b) {
if (a.size()<b.size()) return true;
else if (a.size()>b.size()) return false;
else return (a.id<b.id);
};



// Please implement the following function
void add_page(const Page& p) {
pages.push_back(p);
}

// Please implement the following function
bool cmp_page_count(const Page & a, const Page & b) {
return (a.counter<b.counter);
}

// Please implement the following function
void print_pages(int number) {
sort(pages.begin(), pages.end(),cmp_page_count);
vector<Page>::iterator iter;
for(iter = pages.begin(); iter != pages.begin()+number; iter++) {
    cout << (*iter).counter << ":" << (*iter).path << endl;
            }
}

// Please implement the following function
void add_user(User u) {
    users.push_back(u);

}

// Please implement the following function
void add_visit(int page_id) {
vector<Page>::iterator iter;
    for(iter = pages.begin(); iter != pages.end(); iter++) {
    if ((*iter).id==page_id){ (*iter).counter++;
    }
            }
vector<User>::iterator iter2=users.end()-1;
iter2->add_visit(page_id);

}

// Please implement the following function
void print_users(int number) {
sort(users.begin(), users.end());
vector<User>::iterator iter;
for(iter = users.begin(); iter != users.begin()+number; iter++) {
    cout << (*iter).size() << ":" << (*iter).id << endl;
    (*iter).print_visits();
            }
}

int main() {

        string type;
        while(cin >> type) {
        if(type == "USER") {
          int user_id;
          cin >> user_id;
          User u(user_id);
          add_user(u);
        } else if(type == "PAGE") {
          int page_id;
          string page_path;
          cin >> page_id;
          cin >> page_path;
          Page p(page_id, page_path);
          add_page(p);
        } else if(type == "VISIT") {
          int page_id;
          cin >> page_id;
          Page p(page_id, "");
          vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
          if(iter->id == p.id) {
            iter->counter++;
          }
          add_visit(p.id);
        }
    }
    sort(pages.begin(), pages.end(), cmp_page_count);
    cout << "*** 5 most popular pages ***" << endl;
    print_pages(5);
    sort(pages.begin(), pages.end());

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    print_users(5);
        return 0;
}
