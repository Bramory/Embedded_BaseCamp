#include <iostream>
#include <stdlib.h>
using namespace std;

struct retdata {
	int min, 
		max,
		avg;
};

int super_func(int *arr, unsigned int len, struct retdata *ret) {
	unsigned int cnt;
	ret->min = ret->max = *arr;
	ret->avg = 0;
	for (cnt = 0; cnt < len; cnt++) {
		if (arr[cnt] < ret->min)
			ret->min = arr[cnt];
			
		else if (arr[cnt] > ret->max)
			ret->max = arr[cnt];

		ret->avg += arr[cnt];
	}
	ret->avg /= len;
	return 0;
}

int main (void) {
	const int N = 4;
	int *a = (int*) malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		a[i] = i;
	}
	struct retdata *data = (struct retdata *) malloc (sizeof(struct retdata));

	cout << super_func ( a, N, data ) << endl;
	cout << "\nMax: " << data->max;
	cout << "\nMin: " << data->min;
	cout << "\nAvg: " << data->avg;
	cout << "\n0x01 | 0x00: " << (0x01 | 0x00);
	return 0;
}
