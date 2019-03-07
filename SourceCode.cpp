#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 62;

void readFile(fstream *file, int numbers[]);
void bubbleSort(int [], int , int&, int&);
void unsortedArrayRead(fstream *file,  int numbers[]);
void unsortedArrayRead2(fstream *file, int numbers[]);
void linearSearch(int rr[], int, int, int&, int&);
void sectionSortSwaps(int[], int, int&, int&);
void binarySearch(int[], int, int, int&, int&);

void readOut(int[], int[], int, int, int, int, int, int, int, int, int);

int main() {
	fstream inputFile;
    fstream testfile;
	fstream newFile;
	inputFile.open("Text.txt");
	testfile.open("Text.txt");
	newFile.open("Text.txt");


	int numbers[SIZE];
	int unsortedArray[SIZE];
	int unsortedArray2[SIZE];
	int cmp = 0;
	int swp = 0;
	int pos = 0;
	int linComp = 0;
	int secSwap = 0;
	int bin = 0;
	int binComp = 0;
	int secComp = 0;

	readFile(&inputFile, numbers);
	
	bubbleSort(numbers, SIZE, cmp, swp);
	unsortedArrayRead(&testfile, unsortedArray);
	unsortedArrayRead(&newFile, unsortedArray2);
	sectionSortSwaps(unsortedArray2, SIZE, secSwap, secComp);
	linearSearch(numbers, SIZE, 976, pos, linComp);
	binarySearch(unsortedArray2, SIZE, 976, bin, binComp);
	readOut(unsortedArray2, numbers, SIZE, cmp, swp, pos, secSwap, binComp, linComp, bin, secComp);
	
	system("pause");
}

void readFile(fstream *file, int numbers[]) {
	for (int i = 0; i < SIZE; i++) {
		*file >> numbers[i];	
	}
}
void bubbleSort(int arr[], int n, int& countComparison, int& countSwap) {
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			countComparison++;
			if (arr[j] > arr[j + 1])
			{
				countSwap++;
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
void unsortedArrayRead(fstream *file, int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		*file >> arr[i];
		
	}
}
void unsortedArrayRead2(fstream *file, int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		*file >> arr[i];

	}
}
void linearSearch(int arr[], int n, int value, int& pos, int& comp) {
	int index = 0;
	int position  =1;
	bool found = false;

	while (index < n && !found)
	{
		comp++;
		if (arr[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	pos = position;
}
void sectionSortSwaps(int arr[], int n, int& secSwap, int& secComp) {
	int startScan, minIndex, minValue;




	for (startScan = 0; startScan < n - 1; startScan++) {
		minIndex = startScan;
		minValue = arr[startScan];

		for (int index = startScan + 1; index < n; index++) {
			secComp++;
			if (arr[index] < minValue) {
				minValue = arr[index];
				minIndex = index;
				secSwap++;			
			}			
		}
		
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
	}
	
}
void binarySearch(int arr[], int n, int value, int& bin, int& cmp)
{
	int first = 0,
		last = SIZE - 1,
		middle,
		position = -1;

	
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		
		if (arr[middle] == value) {
			
			found = true;
			position = middle;
		}
		else if (arr[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
		cmp++; // may be wrong 
	}
	bin = position;

	
}




void readOut(int arr[], int arr2[],int n, int cmp, int swp, int pos, int secSwap, int binComp, int linComp, int bin, int secComp) {

	ofstream outfile;
	outfile.open("physical.txt");

	cout << "Unsorted Array: ";
	outfile << "Unsorted Array: ";

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		outfile << arr[i] << " ";

	}
	cout << "\n" << endl;;
	outfile << "\n" << endl;
	
	cout << "Sorted Array: ";
	outfile << "Sorted Array: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << " ";
		outfile << arr2[i] << " ";
	}
	cout << "\n" << endl;
	outfile << "\n" << endl;

	cout << "Searching:       Key = 976" << "\n" << endl;
	

	cout << "Linear index: " << pos << endl;
	cout << "Linear comparison: " << linComp << endl;
	cout << "Binary index: " << bin << endl;
	cout << "Binary comparison: " << binComp << "\n" << endl;

	cout << "Sorting: " << "\n" << endl;
	cout << "Bubble Sort - Swaps: " << swp << endl;
	cout << "Bubble Sort - Comparison: " << cmp << endl;
	cout << "Selection Sort - Swaps: " << secSwap << endl;
	cout << "Selection Sort - Comparisons: " << secComp << endl;

	outfile << "Searching:       Key = 976" << "\n" << endl;
	outfile << setw(30) << " Index:" <<  setw(30) << "Comparison:" << endl;
	outfile << "Linear " << setw(19) << pos << setw(25) << linComp << endl;
	outfile << "Binary: " << setw(18) << bin << setw(24) << binComp << "\n" << endl;
	outfile << "Sorting: " << "\n" <<  endl;
	outfile << setw(30) << " Swap:" << setw(30) << "Comparison:" << endl;
	outfile << "Bubble Sort: " << setw(15) <<  swp <<   setw(25) << cmp << endl;
	outfile << "Selection Sort :" << setw(12) << secSwap << setw(25) << secComp << endl;
	

}
