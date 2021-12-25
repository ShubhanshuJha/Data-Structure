// Array
#include <stdio.h>
#include <stdlib.h>

#define append(arr1, arr2, n) for (int i = 0; i < n; i++) arr2[i] = arr1[i];
#define addArrAtStart(arr, n) for(int i = 0; i < n; i++) addAtStarting(arr[i]);
#define addArrAtEnd(arr, n) for(int i = 0; i < n; i++) addAtEnd(arr[i]);

int N = 3;
int endIdx = 0;
int *array = NULL;

void addAtEnd(int);
void addAtStarting(int);
int size();
void capacity();
void clear();
void display();
void printDetails();

void searchImpln();
int LinearSearch(int);
int BinarySearch(int, int, int);

void sortImpln();
void ascSort();
void desSort();

int * newArray() {
	int *new = (int *)malloc(N * sizeof(int));
	append(array, new, size());
	free(array);
	return new;
}

void swap(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int main(int argc, char const *argv[]) {
	array = (int *)malloc(N * sizeof(int));
	printf("\tArray\n");
	// int val;
	// do {
	// 	printf("\nEnter the data you want to insert: ");
	// 	scanf("%d", &val);
	// 	addAtEnd(val);
	//  addAtStarting(val);
	// 	printf("\nWant to add another value (1/0): ");
	// 	scanf("%d", &val);
	// } while (val);

	int tempVal1[] = {0, 1, 2, 3, 4, 5};
	addArrAtEnd(tempVal1, 6);
	printDetails();

	int tempVal2[] = {10, 11, 12, 13, 14, 15};
	addArrAtStart(tempVal2, 6);
	printDetails();

	sortImpln();
	searchImpln();

	clear();
	printf("\nArray cleared.");
	printDetails();
	printf("\nProgram Finished.\n");
	return 0;
}

void addAtEnd(int val) {
	if (endIdx == N) {
		// printf("\nSize needs to be changed, %d", N);
		N <<= 1;
		array = newArray();
		// printf("\nSize changed, %d\n", N);
	}
	array[endIdx++] = val;	
}

void addAtStarting(int val) {
	if (endIdx == 0) {
		array[endIdx++] = val;
	} else {
		if (size() == N) {
			// printf("\nSize needs to be changed, %d", N);
			N <<= 1;
			array = newArray();
			// printf("\nSize changed, %d\n", N);
		}
		endIdx++;
		for (int i = size(); i > 0; i--) {
			array[i] = array[i - 1];
		}
		array[0] = val;
	}
}

int size() {
	return endIdx;
}

void capacity() {
	printf("\nCurrent capacity of the Array is %d", N);
	return;
}

void clear() {
	endIdx = 0;
	N = 3;
	free(array);
	array = (int *)malloc(N * sizeof(int));
}

void display() {
	printf("[");
	if (size() == 0) {
		printf("]\n");
	} else {
		printf("%d", array[0]);
		for (int i = 1; i < size(); i++) {
			printf(", %d", array[i]);
		}
		printf("]\n");
	}
}

void printDetails() {
	capacity();
	printf("\nCurrent size of the array: %d", size());
	printf("\nElements in the array: ");
	display();
}

void searchImpln() {
	int key;
	printf("\nEnter the value you want to search in the array: ");
	scanf("%d", &key);

	int choice, resIdx;
	printf("\nSelect searching method:\n1 for LinearSearch\n2 for BinarySearch: ");
	scanf("%d", &choice);
	if (choice == 1) {
		resIdx = LinearSearch(key);
		if (resIdx == -1) {
			printf("Key: %d not found in the array.\n", key);
		} else {
			printf("Key: %d is present in the array at index: %d\n", key, resIdx);
		}
	} else if (choice == 2) {
		resIdx = BinarySearch(key, 0, size());
		if (resIdx == -1) {
			printf("Key: %d not found in the array.\n", key);
		} else {
			printf("Key: %d is present in the array at index: %d\n", key, resIdx);
		}
	} else {
		printf("\nWrong Selection.");
	}
}

int LinearSearch(int key) {
	for (int i = 0; i < size(); ++i) {
		if (array[i] == key)
			return i;
	}
	return -1;
}

int BinarySearch(int key, int i, int j) {
	while (i <= j) {
		int mid = (i + j) >> 1;
		if (array[mid] == key) return mid;
		if (array[mid] < key) {
			i = mid + 1;
		} else {
			j = mid - 1;
		}
	}
	return -1;
}

void sortImpln() {
	int choice;
	printf("\nSelect sorting type:\n1 for Sorting in Ascending Order\n2 for Sorting in Descending Order: ");
	scanf("%d", &choice);
	if (choice == 1) {
		ascSort();
	} else if (choice == 2) {
		desSort();
	} else {
		printf("\nWrong Selection.");
	}
	display();
}

int ascendingOrder(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int descendingOrder(const void * a, const void * b) {
    return ( *(int*)b - *(int*)a);
}

void ascSort() {
	qsort(array, N, sizeof(int), ascendingOrder);
}
void desSort() {
	qsort(array, N, sizeof(int), descendingOrder);
}
