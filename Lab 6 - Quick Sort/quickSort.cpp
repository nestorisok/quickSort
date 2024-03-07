#include <iostream>

using namespace std;


void quickSort(int arr[], int p, int right);
int partition(int arr[], int low, int high);
void displayArr(int arr[], int arrSize);

int main(void) {

	int myArr[] = { 9, 3, 4, 2, 1, 8 };
	int arrSize = sizeof(myArr) / sizeof(int);

	int begArr = myArr[0];
	int endArr = arrSize - 1;

	displayArr(myArr, arrSize);

	quickSort(myArr, begArr, endArr);

	displayArr(myArr, arrSize);







	return 0;
}


void displayArr(int arr[], int arrSize) {

	cout << "\n";

	for (int i = 0; i < arrSize; i++) {

		cout << arr[i] << " ";
	}

}

void quickSort(int arr[], int p, int right) {

	if (p < right) {

		int p = partition(arr, p, right);
		quickSort(arr, p, right);
		quickSort(arr, p + 1, right);


	}


}


int partition(int arr[], int low, int high) {

	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;

	while (i < pivot && j > pivot) {

		while (arr[j] >= pivot) {
			j--;
		}
		while (arr[i] <= pivot) {
			i++;
		}
		if (i < j) {
			swap(arr[i], arr[j]);

		}
		else {
			return j;
		}

	}


	//return 0; // temp
}