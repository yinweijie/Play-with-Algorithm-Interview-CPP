#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"


using namespace std;

template<typename T>
int binarySearch(T data[], int n, int target) {
    int l = 0, r = n;

    // 在[l...r)之间寻找target
    while(l < r) { // l == r的时候[l...r)之间就没有元素了
        int mid = (l + r) / 2;

        if(data[mid] == target) {
            return mid;
        }

        // [l...mid...r)
        if(target > data[mid]) {
            l = mid + 1; // 在[mid + 1, r)之间寻找target
        } else {
            r = mid; // 在[l, mid)之间寻找target
        }
    }

    return -1;
}

int main() {

    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0 ; i < n ; i ++)
        assert(i == binarySearch(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}