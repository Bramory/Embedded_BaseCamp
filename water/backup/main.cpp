#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>
#include <string>
#include <list>
using namespace std;

//return element from [a ... b]
//template <typename T>
int randFromRange (int min, int max){
    return rand() % (max-min+1) + min;
}

//return max number from integer array
int findMax(int  n, int a[]){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if (a[i] > max)
            max = a[i];
    }
    return max;
}


int main()
{
    srand(time(0));
    int N = randFromRange(3, 6);
    int a[N];

    for(int i = 0; i < N; i++)
        a[i] = randFromRange(0, 5);

    for(int i = 0; i < N; i++)
      cout << a[i] << " ";


    int max = findMax(N, a);
    cout << "\nMAX = " << max << endl;

    int water = 0, water_units = 0;
    for(int j = 0; j < max; j++){
        for(int i = 0; i < N; i++){
            //there is ground
            GROUND:
            if (a[i] > 0){
                water_units = 0;
                // count units of water
                for(int z = i+1; z < N; z++){
                    //find water
                    if(a[z] == 0)
                        water_units++;
                //find second ground
                    else{
                        water+=water_units;
                        i++;
                        goto GROUND;
                    }
                }
            }
        }
            for(int m = 0; m < N; m++)
                if (a[m] > 0)
                    a[m]--;
    }

    cout << "\nN = " << N << endl;
    cout << "\nWater Unit = " << water << endl;

    system("pause");
    return 0;
}
