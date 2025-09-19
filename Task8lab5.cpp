#include <iostream>
using namespace std;

int maxFlags=0;
bool columns[4]={0};
bool diagonal1[7]={0}; 
bool diagonal2[7]={0}; 

void placeFlag(int row, int count) {
    if(row==4) {
        if(count>maxFlags)
            maxFlags = count;
        return;
    }

    for (int col=0; col<4; col++) {
        int d1= row-col+3;
        int d2= row+col;

        if ((!columns[col]) && (!diagonal1[d1]) && (!diagonal2[d2])) {
            columns[col]= diagonal1[d1]= diagonal2[d2] = 1;
            placeFlag(row+1, count+1);
            columns[col]= diagonal1[d1]= diagonal2[d2]=0;
        }
    }

    placeFlag(row+1, count);
}

int main() {
    placeFlag(0, 0);
    cout << "Max number of flags that can be placed: "<<maxFlags<<endl;
    return 0;
}
