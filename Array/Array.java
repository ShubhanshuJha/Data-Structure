import static java.lang.System.*;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Array {

	final static Scanner input = new Scanner(in);
	static int N = 3;
	static int endIdx = 0;
	static int[] array;
	static final int DEF_VAL = Integer.MAX_VALUE;

	final static int[] newArray() {
		int[] newArr = new int[N];
		int i = 0, j = array.length, k = 0;
		while(i < j) {
			newArr[k++] = array[i++];
		}
		while(k < N){
			newArr[k++] = DEF_VAL;
		}
		return newArr;
	}

	public static void main(String[] args) {
		array = new int[N];
	   	out.println("\tArray");
		// int val;
		// do {
		// 	out.print("\nEnter the data you want to insert: ");
		// 	val = input.nextInt();
		// 	addAtEnd(val);
		// 	addAtStarting(val);
		// 	out.print("\nWant to add another value (1/0): ");
		// 	val = input.nextInt();
		// } while (val == 1);

		int[] tempVal1 = {0, 1, 2, 3, 4, 5};
		addArrAtEnd(tempVal1, 6);
		printDetails();

		int[] tempVal2 = {10, 11, 12, 13, 14, 15};
		addArrAtStart(tempVal2, 6);
		printDetails();

		sortImpln();
		searchImpln();

		clear();
		out.printf("\nArray cleared.");
		printDetails();
		out.printf("\nProgram Finished.\n");
	}

	static void addArrAtStart(int[] temp, int n) {
		if (endIdx == 0) {
			for (int i = n - 1; i >= 0; i--)
				addAtEnd(temp[i]);
		} else {
			while (endIdx + n >= N) {
				N <<= 1;
				array = newArray();
			}
			for (int i = 0; i < endIdx; i++)
				array[i + n] = array[i];
			int k = 0;
			for (int i = n - 1; i >= 0; i--)
				array[k++] = temp[i];
			endIdx += n;
		}
	}

	static void addArrAtEnd(int[] temp, int n) {
		for(int i = 0; i < n; i++)
			addAtEnd(temp[i]);
	}

	static void appendArr() {
		out.print("Enter the array elements: ");
		int[] temp = Arrays.stream(input.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	   	int j = 0, k = temp.length;
	   	while(j < k) {
	   		addAtEnd(temp[j]);
	   	}
	}
	static void display() {
		out.print("[");
		if (size() == 0)
			out.println("]");
		else {
			out.print(array[0] == DEF_VAL ? " " : array[0]);
			for (int i = 1; i < endIdx; i++){
				out.print(", " + (array[i] == DEF_VAL ? " " : array[i]));
			}
			out.println("]");
		}
	}

	static void addAtEnd(int val) {
		if (endIdx == N) {
			N <<= 1;
			array = newArray();
		}
		array[endIdx++] = val;	
	}

	static void addAtStarting(int val) {
		if (endIdx == 0) {
			array[endIdx++] = val;
		} else {
			if (endIdx++ == N) {
				N <<= 1;
				array = newArray();
			}
			for (int i = size(); i > 0; i--) {
				array[i] = array[i - 1];
			}
			array[0] = val;
		}
	}

	static int size() {
		return endIdx;
	}

	static void capacity() {
		out.printf("\nCurrent capacity of the Array is %d", N);
	}

	static void clear() {
		endIdx = 0;
		N = 3;
		array = new int[3];
		for(int i = 0; i < 3; i++)
			array[i] = DEF_VAL;
	}

	static void printDetails() {
		capacity();
		out.printf("\nCurrent size of the array: %d", size());
		out.printf("\nElements in the array: ");
		display();
	}

	static void searchImpln() {
		out.printf("\nEnter the value you want to search in the array: ");
		int key = input.nextInt();

		int resIdx;
		out.printf("\nSelect searching method:\n1 for LinearSearch\n2 for BinarySearch: ");
		int choice = input.nextInt();
		if (choice == 1 || choice == 2) {
			resIdx = choice == 1 ? LinearSearch(key) : BinarySearch(key, 0, size());
			if (resIdx == -1) {
				out.printf("Key: %d not found in the array.\n", key);
			} else {
				out.printf("Key: %d is present in the array at index: %d\n", key, resIdx);
			}
		} else {
			out.printf("\nWrong Selection.");
		}
	}

	static int LinearSearch(int key) {
		for (int i = 0; i < N; ++i) {
			if (array[i] == key)
				return i;
		}
		return -1;
	}

	static int BinarySearch(int key, int i, int j) {
		if (array[0] > array[1]) {
			while (i <= j) {
				int mid = (i + j) >> 1;
				if (array[mid] == key) return mid;
				if (array[mid] < key) {
					j = mid - 1;
				} else {
					i = mid + 1;
				}
			}
		} else {
			while (i <= j) {
				int mid = (i + j) >> 1;
				if (array[mid] == key) return mid;
				if (array[mid] < key) {
					i = mid + 1;
				} else {
					j = mid - 1;
				}
			}
		}
		return -1;
	}

	static void sortImpln() {
		out.print("\nSelect sorting type:\n1 for Sorting in Ascending Order\n2 for Sorting in Descending Order: ");
		int choice = input.nextInt();
		if (choice == 1) {
			ascSort();
		} else if (choice == 2) {
			desSort();
		} else {
			out.print("\nWrong Selection.");
		}
		display();
	}

	static void ascSort() {
		Arrays.sort(array);
	}

	static void desSort() {
		Integer[] arr = new Integer[N];
		for (int j = 0; j < N; j++) {
			arr[j] = array[j];
		}
		Arrays.sort(arr, Collections.reverseOrder());
		int i = 0;
		while (i < arr.length && arr[i] == DEF_VAL) i++;
		int st = i, k = 0;
		for (; k < endIdx; k++) {
			array[k] = arr[st++];
		}
		while (i < arr.length) {
			array[k++] = arr[i++];
		}
	}
}
