#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

bool succeed(){
       int a[10];
       srand (time(NULL));
       for (int i=0; i<10; i){
           a[i] = (int) rand()%20;
           srand (time(NULL));
       }
       int max_prior=a[0];
       for (int i=1; i<4; i++){
           if (a[i]>max_prior) max_prior=a[i];
       }
       int max_total=max_prior;
       int index_max=3;
       for (int i=4; i<10; i++){
           if (a[i]>max_total) {
               max_total=a[i];
               index_max=i;
           }
       }
       if (index_max==3) return false;
       for (int i=4; i<10; i++){
           if (a[i]>max_prior){
               if (a[i]==max_total) return true;
               return false;
           }
       }
       return false;
}

   int main()
   {
       /*int success = 0;
       for (int i=0; i<5; i++){
           if (succeed()) success++;
       }
       cout << success*1.0/5.0 << endl;*/
       cout << succeed() << endl;

    return 0;
    }
