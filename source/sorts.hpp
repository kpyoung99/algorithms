#ifndef __SORTS__
#define __SORTS__

#include "doctest/doctest/doctest.h"

typedef void (*sort_fn)(int*, int);

void bubble_sort(int* arr, int n);

void insertion_sort(int* arr, int n);

void selection_sort(int* arr, int n);

sort_fn sorts[] = {bubble_sort, insertion_sort, selection_sort};
char names[][20] = {"Bubble sort", "Insertion sort", "Selection sort"};

TEST_CASE("Sorting Functions.") {
  int arr1[1] = {1};
  int arr2[2] = {2, 1};
  int arr3[5] = {5, 4, 3, 2, 1};
  int arr4[10] = {92, 64, 54, 41, 23, 35, 82, 28, 81, 40};
  int arr4_sorted[10] = {23, 28, 35, 40, 41, 54, 64, 81, 82, 92};
  int arr5[10] = {3, 1, 3, 2, 1, 3, 2, 2, 1, 2};
  int arr5_sorted[10] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

  for (int i = 0; i < sizeof(sorts) / sizeof(sort_fn); ++i) {
    SUBCASE(names[i]) {
      sorts[i](arr1, 1);
      CHECK(arr1[0] == 1);

      sorts[i](arr2, 2);
      CHECK(arr2[0] == 1);
      CHECK(arr2[1] == 2);

      sorts[i](arr3, 5);
      for (int j = 0; j < 5; ++j) {
        CHECK(arr3[j] == j + 1);
      }

      sorts[i](arr4, 10);
      for (int j = 0; j < 10; ++j) {
        CHECK(arr4[j] == arr4_sorted[j]);
      }

      sorts[i](arr5, 10);
      for (int j = 0; j < 10; ++j) {
        CHECK(arr5[j] == arr5_sorted[j]);
      }
    }
  }
}

#endif