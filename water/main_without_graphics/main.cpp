#include <iostream>
#include <stdio.h>
using namespace std;

int num_scan( void ) {
	int num = 0, proof = 0;
	do {
		proof = scanf("%d", &num);
		if(proof == 1) break;
		printf("Incorrect input, try again");
		fflush(stdin);
	} while (1);
	return num;
}

///return max number from integer array
int findMax(int  n, int a[]) {
	int max = a[0];
	for(int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main(void) {
	cout << "Type the size of the array: ";
	int N;
	N = num_scan();
	int a[N];
	cout << "\nType the elements: ";
	for(int i = 0; i < N; i++)
		a[i] = num_scan();

	int max = findMax(N, a);

	cout << "\nArray: ";
	for(int i = 0; i < N; i++)
		cout << a[i] << ", ";

	int water = 0, water_units = 0;
	for(int j = 0; j < max; j++) {
		for(int i = 0; i < N; i++) {
			//there is ground
		GROUND:
			if (a[i] > 0) {
				water_units = 0;
				// count units of water
				for(int z = i+1; z < N; z++) {
					//find water
					if(a[z] == 0)
						water_units++;
					//find second ground
					else {
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

	cout << "\nWater Unit = " << water << endl;

	return 0;
}
