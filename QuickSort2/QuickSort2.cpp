#include <iostream>
using namespace std;

//array of integres to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of movement
int n;
void input() {
	while (true) {
		cout << "masukkan panjang element array :";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\n maksimum panjang array adalah 20" << endl;
	}

	cout << "\n--------------------" << endl;
	cout << "\n Enter array element" << endl;
	cout << "\n--------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

// swap the element at index x with the element at index y
void swap(int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high) {
	int pivot, i, j;
	if (low > high) //langkah 1
		return;
	//partition the list into two parts
	//one containing element less that or equal to pivot
	//outher containing elment greater than pivot
	i = low + 1; //langkah 3
	j = high; //langkah 4
	pivot = arr[low]; //langkah2

	while (i <= j) //langkah 10
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high)) //langkah 5
		{
			i++; //langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) //langkah 7
			j--; //langkah 8
		cmp_count++;
	}
	cmp_count++;
	if (i < j) //langkah 9
		//if greater element is on left on the element
	{
		//swap the element at index i with the element at index j
		swap(i, j);
		mov_count++;
	}
	// sort the list on the left of pivot using quick sort
	q_short(low, j - 1); //langkah 12
	// sort the list on the right of pivot using quick sort
	q_short(j + 1, high); //langkah 13
}

void display() {
	cout << "\n-------------" << endl;
	cout << "\n sorted array" << endl;
	cout << "\n-------------" << endl;
