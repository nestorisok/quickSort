#include <iostream>

using namespace std;


void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void displayArr(int arr[], int arrSize);

int main(void) {

	int myArr[] = { 9, 3, 4, 2, 1, 8 };
	int arrSize = sizeof(myArr) / sizeof(int);
	int mid = myArr[(0 + arrSize - 1) / 2]; // getting middle of array
	// need rand

	int begArr = 0;
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

void quickSort(int arr[], int low, int high) {

	if (low < high) {

		int p = partition(arr, low, high);
		quickSort(arr, low, p);
		quickSort(arr, p + 1, high);


	}


}


int partition(int arr[], int low, int high) {

	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;

	while (true) {
	
		do {
			j--;

			//cout << "i: " << j << " " << " arr: " << arr[j] << "Pivot: " << pivot << endl;
		} while (arr[j] > pivot);

		do {
			i++;
		
			//cout << "i: " << i << " " << " arr: " << arr[i] << "Pivot: " << pivot << endl;
			
		} while (arr[i] < pivot);


		if (i < j) {

			swap(arr[i], arr[j]);

		}
		else {
			return j;
		}

	}

	//return 0; // temp
}