#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../doctest.h"
#include "functions.hpp"

TEST_CASE("abs_val") {
  CHECK(abs_val(1) == 1);
  CHECK(abs_val(-1) == 1);
  CHECK(abs_val(-60) == 60);
  CHECK(abs_val(60) == 60);
  CHECK(abs_val(33) == 33);
  CHECK(abs_val(-33) == 33);
  CHECK(abs_val(14) == 14);
  CHECK(abs_val(0) == 0);
}

TEST_CASE("pow") {
  CHECK(pow(1, 0) == 1);
  CHECK(pow(10, 0) == 1);
  CHECK(pow(100, 0) == 1);
  CHECK(pow(1, 2) == 1);
  CHECK(pow(1, 5) == 1);
  CHECK(pow(1, 10) == 1);
  CHECK(pow(2, 1) == 2);
  CHECK(pow(2, 3) == 8);
  CHECK(pow(2, 5) == 32);
  CHECK(pow(5, 2) == 25);
  CHECK(pow(3, 3) == 27);
}

TEST_CASE("log") {
  CHECK(log(3, 27) == 3);
  CHECK(log(2, 4) == 2);
  CHECK(log(2, 8) == 3);
  CHECK(log(2, 10) == 3);
  CHECK(log(5, 25) == 2);
}

TEST_CASE("chartoint") {
  CHECK(chartoint('0') == 0);
  CHECK(chartoint('1') == 1);
  CHECK(chartoint('2') == 2);
  CHECK(chartoint('3') == 3);
  CHECK(chartoint('4') == 4);
  CHECK(chartoint('5') == 5);
  CHECK(chartoint('6') == 6);
  CHECK(chartoint('7') == 7);
  CHECK(chartoint('8') == 8);
  CHECK(chartoint('9') == 9);
}

TEST_CASE("inttochar") {
  CHECK(inttochar(0) == '0');
  CHECK(inttochar(1) == '1');
  CHECK(inttochar(2) == '2');
  CHECK(inttochar(3) == '3');
  CHECK(inttochar(4) == '4');
  CHECK(inttochar(5) == '5');
  CHECK(inttochar(6) == '6');
  CHECK(inttochar(7) == '7');
  CHECK(inttochar(8) == '8');
  CHECK(inttochar(9) == '9');
}

TEST_CASE("chr") {
  CHECK(chr(43) == '+');
  CHECK(chr(40) == '(');
  CHECK(chr(48) == '0');
  CHECK(chr(122) == 'z');
}

TEST_CASE("ord") {
  CHECK(ord('c') == 99);
  CHECK(ord('O') == 79);
  CHECK(ord('|') == 124);
}

TEST_CASE("max") {
  SUBCASE("Two variables.") {
    CHECK(max(1, 2) == 2);
    CHECK(max(2, 1) == 2);
    CHECK(max(-50, 50) == 50);
    CHECK(max(0, 0) == 0);
  }
  SUBCASE("Three variables.") {
    CHECK(max(1, 2, 3) == 3);
    CHECK(max(3, 2, 1) == 3);
    CHECK(max(1, 1, 1) == 1);
    CHECK(max(0, 4, 0) == 4);
  }
  SUBCASE("Arrays of integers.") {
    int arr1[5] = {-2, -1, 0, 1, 2};
    CHECK(max(arr1, 5) == 2);

    int arr3[7] = {-8, -6, 7, 5, -3, 0, -9};
    CHECK(max(arr3, 7) == 7);

    int arr4[1] = {34982};
    CHECK(max(arr4, 1) == arr4[0]);
  }
}

TEST_CASE("min") {
  SUBCASE("Two variables.") {
    CHECK(min(1, 2) == 1);
    CHECK(min(2, 1) == 1);
    CHECK(min(1, 1) == 1);
    CHECK(min(-20, 20) == -20);
  }
  SUBCASE("Three variables.") {
    CHECK(min(1, 2, 3) == 1);
    CHECK(min(3, 2, 1) == 1);
    CHECK(min(1, 1, 1) == 1);
    CHECK(min(0, 4, 0) == 0);
  }
  SUBCASE("Arrays of variables.") {
    int arr1[5] = {2, 1, 0, -1, -2};
    CHECK(min(arr1, 5) == -2);

    int arr3[7] = {-8, -6, 7, 5, -3, 0, -9};
    CHECK(min(arr3, 7) == -9);

    int arr4[1] = {34982};
    CHECK(min(arr4, 1) == arr4[0]);
  }
}

TEST_CASE("round") {
  SUBCASE("Up") {
    CHECK(round(2.1, 'u') == 3);
    CHECK(round(-4.6, 'u') == -4);
  }
  SUBCASE("Down") {
    CHECK(round(4.6, 'd') == 4);
    CHECK(round(-5.5, 'd') == -6);
  }
}

TEST_CASE("all") {
  bool arr1[1] = {true};
  CHECK(all(arr1, 1));

  bool arr2[1] = {false};
  CHECK(!all(arr2, 1));

  bool arr3[6] = {true, true, true, true, true, false};
  CHECK(!all(arr3, 6));

  bool arr4[6] = {false, true, true, true, true, true};
  CHECK(!all(arr4, 6));
}

TEST_CASE("any") {
  bool arr1[1] = {true};
  CHECK(any(arr1, 1));

  bool arr2[1] = {false};
  CHECK(!any(arr2, 1));

  bool arr3[6] = {false, false, false, false, false, true};
  CHECK(any(arr3, 6));

  bool arr4[6] = {true, false, false, false, false, false};
  CHECK(any(arr4, 6));
}

TEST_CASE("frequency") {
  int arr[10] = {1, 1, 1, 3, 2, 5, 3, 4, 7, 7};
  CHECK(frequency(arr, 10, 1) == 3);
  CHECK(frequency(arr, 10, 3) == 2);
  CHECK(frequency(arr, 10, 4) == 1);
  CHECK(frequency(arr, 10, 6) == 0);
  CHECK(frequency(arr, 10, 7) == 2);

  int arr2[0] = {};
  for (int i = -1; i < 10; ++i) {
    CHECK(frequency(arr2, 0, i) == 0);
  }
}

TEST_CASE("sum") {
  int arr1[1] = {5};
  CHECK(sum(arr1, 1) == 5);

  int arr2[5] = {1, 2, 3, 4, 5};
  CHECK(sum(arr2, 5) == 15);

  int arr3[2] = {2000000000, 2000000000};
  CHECK(sum(arr3, 2) == 4000000000);

  int arr4[2] = {-2000000000, -2000000000};
  CHECK(sum(arr4, 2) == -4000000000);
}

TEST_CASE("index") {
  char str1[] = "this is my string";
  char sub1[] = "ring";
  char sub2[] = "thin";
  char sub3[] = "";

  CHECK(index(str1, sub1) == 13);
  CHECK(index(str1, sub2) == -1);
  CHECK(index(str1, sub3) == 0);
  CHECK(index(str1, str1) == 0);

  char str2[] = "a";
  char sub4[] = "apple";

  CHECK(index(str2, sub4) == -1);
  CHECK(index(str2, str2) == 0);
}

TEST_CASE("is_sorted") {
  int arr1[1] = {80};
  CHECK(is_sorted(arr1, 1));

  int arr2[2] = {5, 4};
  CHECK(is_sorted(arr2, 2));

  int arr3[6] = {1, 1, 3, 3, 5, 5};
  CHECK(is_sorted(arr3, 6));

  int arr4[5] = {1, 2, 3, 4, 3};
  CHECK(!is_sorted(arr4, 5));

  int arr5[5] = {1, 2, 3, 2, 1};
  CHECK(!is_sorted(arr5, 5));
  CHECK(!is_sorted(arr5, 4));
  CHECK(is_sorted(arr5, 3));
}

<<<<<<< HEAD:source/functions.hpp
/** Primality testing.
 * Checks if a given number is prime
 * O(?)
 */
bool prime(int);

TEST_CASE("Checking if a number is prime.") {
=======
TEST_CASE("prime") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
  REQUIRE(prime(2));
  REQUIRE(prime(3));
  REQUIRE_FALSE(prime(4));
  REQUIRE(prime(5));
  REQUIRE_FALSE(prime(6));
  REQUIRE(prime(7));
  REQUIRE_FALSE(prime(8));
  REQUIRE_FALSE(prime(9));
  REQUIRE_FALSE(prime(10));

  REQUIRE_FALSE(prime(66));
  REQUIRE(prime(97));
}

<<<<<<< HEAD:source/functions.hpp
/** Fibonacci numbers
 * Returns the fibonacci number of the given index.
 * O(?)
 */
long fibonacci(int);

TEST_CASE("Fibonacci numbers.") {
=======
TEST_CASE("fibonacci") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
  CHECK(fibonacci(0) == 0);
  CHECK(fibonacci(1) == 1);
  CHECK(fibonacci(2) == 1);
  CHECK(fibonacci(6) == 8);
  CHECK(fibonacci(16) == 987);
}

<<<<<<< HEAD:source/functions.hpp
/** Factorial
 * Returns n!
 * O(?)
 */
long factorial(int);

TEST_CASE("Factorial") {
=======
TEST_CASE("factorial") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
  CHECK(factorial(0) == 1);
  CHECK(factorial(4) == 24);
  CHECK(factorial(8) == 40320);
}

<<<<<<< HEAD:source/functions.hpp
/** String Length
 * Returns the length of the given C-String
 * O(?)
 */
int strlen(char string[]);

TEST_CASE("Testing the string length function") {
=======
TEST_CASE("strlen") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
  CHECK(strlen((char*)"Hello") == 5);
  CHECK(strlen((char*)"Hello World") == 11);
  CHECK(strlen((char*)"1234") == 4);
  CHECK(strlen((char*)"0123456789") == 10);
}

<<<<<<< HEAD:source/functions.hpp
/** String to Int
 * Returns the given string as an integer
 * O(?)
 */
int stringtoint(char string[]);

TEST_CASE("Testing the string to integer function") {
=======
TEST_CASE("stringtoint") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
  CHECK(stringtoint((char*)"0") == 0);
  CHECK(stringtoint((char*)"1") == 1);
  CHECK(stringtoint((char*)"12") == 12);
  CHECK(stringtoint((char*)"123") == 123);
  CHECK(stringtoint((char*)"1234") == 1234);
  CHECK(stringtoint((char*)"10") == 10);
  CHECK(stringtoint((char*)"33") == 33);
  CHECK(stringtoint((char*)"-1") == -1);
  CHECK(stringtoint((char*)"-99") == -99);
}

<<<<<<< HEAD:source/functions.hpp
/** Reverse
 * Reverses the array in-place.
 * O(?)
 */
void reverse(int* arr, int n);
void reverse(char* arr, int n);
void reverse(char* arr);

TEST_CASE("testing reverse functions") {
  SUBCASE("testing reverse function for integers") {
=======
TEST_CASE("reverse") {
  SUBCASE("reverse(int*, int)") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
    int arr1[1] = {1};
    reverse(arr1, 1);
    CHECK(arr1[0] == 1);

    int arr2[3] = {1, 2, 3};
    reverse(arr2, 3);
    for (int i = 0; i < 3; ++i)
      CHECK(arr2[i] == 3 - i);

    int arr3[4] = {1, 2, 3, 4};
    reverse(arr3, 4);
    for (int i = 0; i < 4; ++i)
      CHECK(arr3[i] == 4 - i);

    int arr4[4] = {1, 2, 3, 4};
    int arr5[4] = {1, 2, 3, 4};
    reverse(arr4, 4);
    reverse(arr4, 4);
    for (int i = 0; i < 4; ++i)
      CHECK(arr4[i] == arr5[i]);
  }

<<<<<<< HEAD:source/functions.hpp
  SUBCASE("testing reverse function for strings with length given") {
=======
  SUBCASE("reverse(char*, n)") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
    char arr0[1] = "";
    reverse(arr0, 0);
    CHECK(arr0[0] == '\0');

    char arr1[2] = "I";
    reverse(arr1, 1);
    CHECK(arr1[0] == 'I');

    char arr2[4] = "abc";
    reverse(arr2, 3);
    for (int i = 0; i < 3; ++i)
      CHECK(arr2[i] == 'c' - i);

    char arr3[5] = "abcd";
    reverse(arr3, 4);
    for (int i = 0; i < 4; ++i)
      CHECK(arr3[i] == 'd' - i);

    char arr4[5] = "abcd";
    char arr5[5] = "abcd";
    reverse(arr4, 4);
    reverse(arr4, 4);
    for (int i = 0; i < 4; ++i)
      CHECK(arr4[i] == arr5[i]);
  }

<<<<<<< HEAD:source/functions.hpp
  SUBCASE("testing reverse function for strings without length given") {
=======
  SUBCASE("reverse(char*)") {
>>>>>>> upstream/master:source/Functions/functions.test.cpp
    char arr0[1] = "";
    reverse(arr0);
    CHECK(arr0[0] == '\0');

    char arr1[2] = "I";
    reverse(arr1);
    CHECK(arr1[0] == 'I');

    char arr2[4] = "abc";
    reverse(arr2);
    for (int i = 0; i < 3; ++i)
      CHECK(arr2[i] == 'c' - i);

    char arr3[5] = "abcd";
    reverse(arr3);
    for (int i = 0; i < 4; ++i)
      CHECK(arr3[i] == 'd' - i);

    char arr4[5] = "abcd";
    char arr5[5] = "abcd";
    reverse(arr4);
    reverse(arr4);
    for (int i = 0; i < 4; ++i)
      CHECK(arr4[i] == arr5[i]);

    char arr[] = "12";
    reverse(arr);
    CHECK(arr[0] == '2');
  }
<<<<<<< HEAD
<<<<<<< HEAD:source/functions.hpp
}

#endif
=======
}
>>>>>>> upstream/master:source/Functions/functions.test.cpp
=======
}

TEST_CASE("Binary Search") {
  int n = 100;
  int arr[n];
  for (int i = 0; i < n; ++i)
    arr[i] = 2 * i;
  SUBCASE("Key is present") {
    for (int i = 0; i < n; ++i)
      CHECK_EQ(binsearch(arr, n, 2 * i), i);
  }
  SUBCASE("Key is not preset") {
    for (int i = 0; i < n; ++i)
      CHECK_EQ(binsearch(arr, n, 2 * i + 1), -1);
  }
}

TEST_CASE("Copy") {
  SUBCASE("Array") {
    int A[] = {1, 2, 3, 4, 5};
    int B[10];
    copy(A, B, 5);
    for (int i = 0; i < 5; ++i)
      CHECK_EQ(B[i], A[i]);
  }
}

TEST_CASE("Swap") {
  int a = 5;
  int b = 10;
  swap(&a, &b);
  CHECK_EQ(a, 10);
  CHECK_EQ(b, 5);
}

TEST_CASE("MERGE") {
  int arr1[1] = {1};
  int arr2[2] = {2, 1};
  int arr3[5] = {4, 5, 1, 2, 3};
  int arr4[10] = {23, 41, 54, 64, 92, 28, 35, 40, 81, 82};
  int arr4_sorted[10] = {23, 28, 35, 40, 41, 54, 64, 81, 82, 92};
  int arr5[10] = {1, 1, 2, 3, 3, 1, 2, 2, 2, 3};
  int arr5_sorted[10] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
  int arr6[5] = {1, 3, 2, 4, 5};

  merge(arr1, 1, 1 / 2);
  CHECK(arr1[0] == 1);

  merge(arr2, 2, 2 / 2);
  CHECK(arr2[0] == 1);
  CHECK(arr2[1] == 2);

  merge(arr3, 5, 5 / 2);
  for (int j = 0; j < 5; ++j) {
    CHECK(arr3[j] == j + 1);
  }

  merge(arr4, 10, 10 / 2);
  for (int j = 0; j < 10; ++j) {
    CHECK(arr4[j] == arr4_sorted[j]);
  }

  merge(arr5, 10, 10 / 2);
  for (int j = 0; j < 10; ++j) {
    CHECK(arr5[j] == arr5_sorted[j]);
  }

  merge(arr6, 5, 5 / 2);
  for (int j = 0; j < 5; ++j) {
    CHECK(arr6[j] == j + 1);
  }
}
<<<<<<< HEAD
>>>>>>> upstream/master
=======

TEST_CASE("Partition") {
  int arr1[1] = {1};
  int arr2[2] = {2, 1};
  int arr3[5] = {5, 4, 3, 2, 1};
  int arr4[10] = {23, 41, 54, 64, 92, 28, 35, 40, 81, 82};
  int arr5[10] = {1, 1, 2, 3, 3, 1, 2, 2, 2, 3};

  int p1 = partition(arr1, 0, 0);
  CHECK(p1 == 0);
  CHECK(arr1[0] == 1);

  partition(arr2, 0, 1);
  CHECK(arr2[0] == 1);
  CHECK(arr2[1] == 2);

  int p3 = partition(arr3, 0, 4);
  for (int i = 0; i < p3; ++i) {
    CHECK(arr3[i] <= arr3[p3]);
  }
  for (int i = p3 + 1; i < 5; ++i) {
    CHECK(arr3[i] >= arr3[p3]);
  }

  int p4 = partition(arr4, 0, 9);
  for (int i = 0; i < p4; ++i) {
    CHECK(arr4[i] <= arr4[p4]);
  }
  for (int i = p4 + 1; i < 10; ++i) {
    CHECK(arr4[i] >= arr4[p4]);
  }

  int p5 = partition(arr5, 0, 9);
  for (int i = 0; i < p5; ++i) {
    CHECK(arr5[i] <= arr5[p5]);
  }
  for (int i = p5 + 1; i < 10; ++i) {
    CHECK(arr5[i] >= arr5[p5]);
  }
  int arr6[] = {-665, -207, -85};
  partition(arr6, 0, 2);
  CHECK(arr6[0] == -665);
}
>>>>>>> upstream/master
