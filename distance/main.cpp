// Asymptotic complexity O(1).
#include <iostream>
using namespace std;
int main(void) {
    int D, N;
    cout << "Type a distance D and amount N:" << endl;
    cin >> D >> N;

    cout<< "Distance of Wires: " << (float)(D+D*N)/2*N << endl;
    return 0;
}
