#include<algorithm>
#include<string.h>
#include<fstream>
#include<iostream>
#include<time.h>
using std::swap;
using std::partition;
using std::ofstream;
using std::cout;
using std::endl;

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}


int RPartition(int a[], int p, int r) {
	int i = rand() % r + 1;
	swap(a[i], a[r]);
	return partition(a, p, r);
}


int RSelect(int a[], int p, int r, int i)
{
	if (p == r)
		return a[p];
	int q = RPartition(a, p, r);
	int k = q - p + 1;
	if (i == k)
		return a[q];
	else if (i < k)
		return RSelect(a, p, q - 1, i);
	else return RSelect(a, q + 1, r, i - k);
}

int main() {

	srand(time(NULL));
	ofstream out("Project_Data.txt");

	const int n = 10;
	int A[n];
	for (int i = 0; i < n; i++)
		A[i] = rand();

	time_t start_time = time(NULL);
	time_t current_time = time(NULL);
	double count = 0;

	while (current_time - start_time < 1)
	{
		RSelect(A, 0, n - 1, rand() % n + 1);
		current_time = time(NULL);
		count++;
	}

	out << "Array Size: " << n << " T(n): " << 1 / count
		<< " T(n)/n: " << (1 / count) / n << endl;
}
