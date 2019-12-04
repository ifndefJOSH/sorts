import java.util.Random;
//import java.io.*;


class Main
{
    public static void main(String[] args) {
        int[] array1 = new int[10];
        System.out.println("Java Implementation of certain sorting algorithms: ");

        /* Upward Bubblesort */
        System.out.println("Simple upward bubblesort: ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        upBubbleSort(array1);
        System.out.println("Sorted array: ");
        printArray(array1);

        /* Downward Bubblesort */
        System.out.println("Simple Downward bubblesort (or leadsort): ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        downBubbleSort(array1);
        System.out.println("Sorted array: ");
        printArray(array1);

        /* Minimum Selection sort */
        System.out.println("Simple min Selection sort: ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        minSelectionSort(array1);
        System.out.println("Sorted array: ");
        printArray(array1);

        /* Maximum Selection sort */
        System.out.println("Simple max Selection sort: ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        maxSelectionSort(array1);
        System.out.println("Sorted array: ");
        printArray(array1);

        /* First element as pivot Quicksort */
        System.out.println("First element as pivot quicksort: ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        firstQuickSort(array1, 0, 9);
        System.out.println("Sorted array: ");
        printArray(array1);

        /* Last element as pivot Quicksort */
        System.out.println("Last element as pivot quicksort: ");
        generateRandomList(array1, 10);
        System.out.println("Unsorted array: ");
        printArray(array1);
        lastQuickSort(array1, 0, 9);
        System.out.println("Sorted array: ");
        printArray(array1);
    }
    /* 
    Description: generates a random list of size integers
    */
    public static void generateRandomList(int[] list, int size){
        Random random = new Random();
        for (int i = 0; i < size; i++){
            /* Add random number to array */
            list[i] = random.nextInt() % 10;
        }
    }
    /*
    Description: swaps array values at i and j
    */
    public static void swap(int[] pArray, int i, int j) {
        int tmp = pArray[i];
        pArray[i] = pArray[j];
        pArray[j] = tmp;
    }
    /*
    Description: prints the array
    */
    public static void printArray(int[] pArray) {
        for (int i = 0; i < pArray.length; i++) {
            System.out.print(pArray[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
    /*
    Description: Does a simple upward bubble sort
    */
    public static void upBubbleSort(int[] pArray){
        int len = pArray.length;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - 1; j++) {
                if (pArray[j] > pArray[j + 1]) {
                    swap(pArray, j, j + 1);
                }
            }
        }
    }
    /*
    Description: Does a simple downward bubble (lead) sort
    */
    public static void downBubbleSort(int[] pArray) {
        int len = pArray.length;
        for (int i = 0; i < len; i++) {
            for (int j = len - 1; j > i; j--) {
                if (pArray[j] < pArray[j - 1]) {
                    swap(pArray, j, j - 1);
                }
            }
        }
    }
    /*
    Description: does a simple (min) Selection sort. Finds the smallest
    value in the remaining list and places it at the beginning.
    */
    public static void minSelectionSort(int[] pArray) {
        int len = pArray.length;
        for (int i = 0; i < len; i++) {
            int minIndex = i;
            for (int j = i; j < len; j++) {
                if (pArray[j] < pArray[i]) {
                    minIndex = j;
                }
            }
            swap(pArray, minIndex, i);
        }
    }
    /*
    Description: does a simple (max) Selection sort. Finds the largest
    value in the remaining list and places it at the end.
    */
    public static void maxSelectionSort(int[] pArray) {
        int len = pArray.length;
        for (int i = len - 1; i >= 0; i--) {
            int maxIndex = i;
            for (int j = 0; j < i; j++) {
                if (pArray[j] > pArray[maxIndex]) {
                    maxIndex = j;
                }
            }
            swap(pArray, maxIndex, i);
        }
    }
    /*
    Description: does a quicksort, but always selects the first element as
    the pivot
    */
    public static void firstQuickSort(int[] pArray, int min, int max) {
        if (min >= max) {
            return;
        }
        int pIndex = min;
        int sIndex = min + 1;
        for (int i = min + 1; i <= max; i++) {
            if (pArray[i] < pArray[pIndex]) {
                swap(pArray, sIndex, i);
                sIndex++;
            }
        }
        swap(pArray, sIndex - 1, pIndex);
        pIndex = sIndex - 1;
        firstQuickSort(pArray, min, pIndex - 1);
        firstQuickSort(pArray, pIndex + 1, max);
    }
    /*
    Description: does a quicksort, but always selects the last element as
    the pivot 
    */
    public static void lastQuickSort(int[] pArray, int min, int max) {
        if (min >= max) {
            return;
        }
        int pIndex = max;
        int sIndex = max - 1;
        for (int i = sIndex; i >= min; i--) {
            if (pArray[i] > pArray[pIndex]) {
                swap(pArray, sIndex, i);
                sIndex--;
            }
        }
        swap(pArray, sIndex + 1, pIndex);
        pIndex = sIndex + 1;
        lastQuickSort(pArray, min, pIndex - 1);
        lastQuickSort(pArray, pIndex + 1, max);
    }
};