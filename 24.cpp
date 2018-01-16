#include <iostream>
using namespace std;
int m,n,p,q;

bool yes(int a,int b,int c){
    if (q/(m+p)*n==24) return true;
    else if((m-n)*p/q==24) return true;
else if (a==0){
    if (b==0){
        if (c==0){
            return((m+n+p+q)==24);
        }
        else if(c==1){
            return((m+n+p-q)==24);
        }
        else if(c==2){
            return((m+n+p*q)==24||((m+n+p)*q)==24||(m+(n+p)*q)==24);
        }
        else if(c==3){
            return((m+n+p/q)==24||((m+n+p)/q)==24||(m+(n+p)/q)==24);
        }
    }
    else if(b==1){
        if (c==0){
            return((m+n-p+q)==24);
        }
    }
    else if(b==2){
        if (c==0){
            return((m+n*p+q)==24||((m+n)*(p+q))==24);
        }
        else if(c==1){
            return((m+n*p-q)==24||((m+n)*(p-q))==24);
        }
        else if(c==2){
            return((m+n*p*q)==24||((m+n)*p*q)==24);
        }
        else if(c==3){
            return((m+n*p/q)==24||((m+n)*p/q)==24);
        }
    }
    else if (b==3){
       if (c==0){
            return((m+n/p+q)==24||((m+n)/(p+q))==24);
        }
        else if(c==1){
            return((m+n/p-q)==24);
        }
        else if(c==2){
            return((m+n/p*q)==24||((m+n)/p*q)==24);
        }
        else if(c==3){
            return((m+n/p/q)==24||((m+n)/p/q)==24);
        }
    }
}
    else if (a==1){
    if (b==0){
        if (c==0){
            return ((m-n+p+q)==24);
        }
        else if(c==1){
             return ((m-n+p-q)==24);
        }
        else if(c==2){
             return ((m-n+p*q)==24||((m-n+p)*q)==24);
        }
        else if(c==3){
             return ((m-n+p/q)==24);
        }
    }
}
else if(a==2){
    if (b==0){
        if (c==0){
            return ((m*n+p+q)==24||(m*(n+p+q))==24);
        }
        else if(c==1){
             return ((m*n+p-q)==24||(m*(n+p-q))==24);
        }
        else if(c==2){
             return ((m*n+p*q)==24||(m*(n+p)*q)==24);
        }
        else if(c==3){
             return ((m*n+p/q)==24||(m*(n+p)/q)==24);
        }
    }
    else if(b==1){
        if (c==0){
            return ((m*n-p+q)==24||(m*(n-p+q))==24);
        }
        else if(c==1){
             return ((m*n-p-q)==24||(m*(n-p-q))==24);
        }
        else if(c==2){
             return ((m*n-p*q)==24||(m*(n-p)*q)==24);
        }
        else if(c==3){
             return ((m*n-p/q)==24);
        }
    }
    else if(b==2){
        if (c==0){
            return ((m*n*p+q)==24||(m*n*(p+q))==24);
        }
        else if(c==1){
             return ((m*n*p-q)==24||(m*n*(p-q))==24);
        }
        else if(c==2){
             return ((m*n*p*q)==24);
        }
        else if(c==3){
             return ((m*n*p/q)==24);
        }
    }
    else if(b==3){
        if (c==0){
            return ((m*n/p+q)==24||(m*n/(p+q))==24);
        }
        else if(c==1){
             return ((m*n/p-q)==24);
        }
        else if(c==2){
             return ((m*n/p*q)==24);
        }
        else if(c==3){
             return ((m*n/p/q)==24);
        }
    }
}
else if(a==3){
     if (b==0){
        if (c==0){
            return ((m/n+p+q)==24);
        }
        else if(c==2){
             return ((m/n+p*q)==24||(m/(n+p)*q)==24);
        }
        else if(c==3){
             return ((m/n+p/q)==24);
        }
    }
    else if(b==2){
        if (c==0){
            return ((m/n*p+q)==24||(m/n*(p+q))==24);
        }
        else if(c==1){
             return ((m/n*p-q)==24||(m/n*(p-q))==24);
        }
        else if(c==2){
             return ((m/n*p*q)==24);
        }
        else if(c==3){
             return ((m/n*p/q)==24);
        }
    }
    else if(b==3){
        if(c==2){
             return ((m/n/p*q)==24);
        }
    }
}
return false;
}

int main(){
    cin>>m>>n>>p>>q;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<4; k++){
                if (yes(i,j,k)){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}