#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

/*    First Element Sort    */
void quickSortBeg(int arr[], int low, int high);
int partitionBeg(int arr[], int low, int high);

/*    Middle Element Sort    */
void quickSortMid(int arr[], int low, int high);
int partitionMid(int arr[], int low, int high);


/*    Random Element Sort    */
void quickSortRand(int arr[], int low, int high);
int partitionRand(int arr[], int low, int high);


void displayArr(int arr[], int arrSize);

int main(void) {

	int myFirstArr[] = { 9, 3, 4, 2, 1, 8 };
	int arrSize = sizeof(myFirstArr) / sizeof(int);

	int begArr = 0;
	int endArr = arrSize - 1;

	cout << "\n1st Element is pivot: ";

	displayArr(myFirstArr, arrSize);

	auto frontTimeBeg = high_resolution_clock::now();
	quickSortBeg(myFirstArr, begArr, endArr);
	auto frontTimeEnd = high_resolution_clock::now();
	auto frontDuration = duration_cast<nanoseconds>(frontTimeEnd - frontTimeBeg);

	displayArr(myFirstArr, arrSize);

	cout << "\nIt took " << frontDuration.count() << " nanoseconds" << endl;




	int mySecArr[] = { 9, 3, 4, 2, 1, 8 };
	int secSize = sizeof(mySecArr) / sizeof(int);
	int endSec = secSize - 1;

	cout << "\nMiddle Element is pivot: ";

	displayArr(mySecArr, secSize);

	auto midTimeBeg = high_resolution_clock::now();
	quickSortMid(mySecArr, begArr, endSec);
	auto midTimeEnd = high_resolution_clock::now();
	auto midDuration = duration_cast<nanoseconds>(midTimeEnd - midTimeBeg);

	displayArr(mySecArr, secSize);
	cout << "\nIt took " << midDuration.count() << " nanoseconds" << endl;





	int myThArr[] = { 9, 3, 4, 2, 1, 8 };
	int thSize = sizeof(myThArr) / sizeof(int);
	int endTh = thSize - 1;

	cout << "\nRand Element is pivot: ";

	displayArr(myThArr, thSize);

	auto randTimeBeg = high_resolution_clock::now();
	quickSortRand(myThArr, begArr, endTh);
	auto randTimeEnd = high_resolution_clock::now();
	auto randDuration = duration_cast<nanoseconds>(randTimeEnd - randTimeBeg);

	displayArr(myThArr, thSize);
	cout << "\nIt took " << randDuration.count() << " nanoseconds" << endl;


	return 0;
}


void displayArr(int arr[], int arrSize) {

	cout << "\n";

	for (int i = 0; i < arrSize; i++) {

		cout << arr[i] << " ";
	}

}

void quickSortBeg(int arr[], int low, int high) {

	if (low < high) {

		int p = partitionBeg(arr, low, high);
		quickSortBeg(arr, low, p);
		quickSortBeg(arr, p + 1, high);


	}


}


int partitionBeg(int arr[], int low, int high) {

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
}







void quickSortMid(int arr[], int low, int high) {

	if (low < high) {

		int p = partitionMid(arr, low, high);
		quickSortMid(arr, low, p);
		quickSortMid(arr, p + 1, high);


	}


}


int partitionMid(int arr[], int low, int high) {

	int pivot = arr[(low + high) / 2];
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
}






void quickSortRand(int arr[], int low, int high) {

	if (low < high) {

		int p = partitionRand(arr, low, high);
		quickSortRand(arr, low, p);
		quickSortRand(arr, p + 1, high);


	}


}


int partitionRand(int arr[], int low, int high) {
	
	int pivot = arr[rand() % (low + high)];
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
}