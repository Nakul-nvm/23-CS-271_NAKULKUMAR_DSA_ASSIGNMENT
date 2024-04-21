#include <stdio.h>

int findFloor(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid, floor = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return arr[mid];
        } else if (arr[mid] < key) {
            floor = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return floor;
}

int findCeil(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid, ceil = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return arr[mid];
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            ceil = arr[mid];
            high = mid - 1;
        }
    }

    return ceil;
}

int findPeak(int arr[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
            return arr[mid]; // Found peak element
        } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1; // Search left side
        } else {
            low = mid + 1; // Search right side
        }
    }

    return -1; // Peak not found
}

int findMinimum(int arr[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        if (arr[low] <= arr[high]) {
            return arr[low]; // Array is already sorted
        }

        mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return arr[mid]; // Found minimum element
        } else if (arr[mid] <= arr[high]) {
            high = mid - 1; // Search left side
        } else if (arr[mid] >= arr[low]) {
            low = mid + 1; // Search right side
        }
    }

    return -1; // Minimum not found
}

int main() {
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int floor = findFloor(arr, n, key);
    int ceil = findCeil(arr, n, key);
    int peak = findPeak(arr, n);
    int min = findMinimum(arr, n);

    printf("Floor of %d: %d\n", key, floor);
    printf("Ceiling of %d: %d\n", key, ceil);
    printf("Peak element: %d\n", peak);
    printf("Minimum element: %d\n", min);

    return 0;
}
