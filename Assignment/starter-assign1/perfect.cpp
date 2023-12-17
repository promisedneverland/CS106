/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "console.h"
#include <iostream>
#include "SimpleTest.h"
#include "perfect.h"
#include <cmath>
using namespace std;

/* The divisorSum function takes one argument `n` and calculates the
 * sum of proper divisors of `n` excluding itself. To find divisors
 * a loop iterates over all numbers from 1 to n-1, testing for a
 * zero remainder from the division using the modulus operator %
 *
 * Note: the C++ long type is a variant of int that allows for a
 * larger range of values. For all intents and purposes, you can
 * treat it like you would an int.
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* The isPerfect function takes one argument `n` and returns a boolean
 * (true/false) value indicating whether or not `n` is perfect.
 * A perfect number is a non-zero positive number whose sum
 * of its proper divisors is equal to itself.
 */
bool isPerfect(long n) {
    return (n != 0) && (n == divisorSum(n));
}

/* The findPerfects function takes one argument `stop` and performs
 * an exhaustive search for perfect numbers over the range 1 to `stop`.
 * Each perfect number found is printed to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    // for(int i = 1; i <10; i++){
    //     cout << i << "th" << findNthPerfectEuclid(i) << endl;
    // }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
long smarterSum(long n) {
    /* TODO: Fill in this function. */
    long total = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i == n / i) {
                total += i;
             } else {
                total += (i + n / i);
            }
        }
    }
    return total - n;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
bool isPerfectSmarter(long n) {
    /* TODO: Fill in this function. */
    return smarterSum(n) == n;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void findPerfectsSmarter(long stop) {
     /* TODO: Fill in this function. */
    for (long num = 1; num < stop; num++) {
        if (isPerfectSmarter(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
long findNthPerfectEuclid(long n) {
    /* TODO: Fill in this function. */
    int found = 0;
    long current_perfect = 0;
    for(int k = 1; found < n; k++) {
        long m = pow(2, k) - 1;
        if(smarterSum(m) == 1) {
            found++;
            current_perfect = m * pow(2, k - 1);
        }
    }
    return current_perfect;
}


/* * * * * * Test Cases * * * * * */

// TODO: add your STUDENT_TEST test cases here!

/*
 * Here is sample test demonstrating how to use a loop to set the input sizes
 * for a sequence of time trials.
 */
//STUDENT_TEST("Multiple time trials of findPerfects on increasing input sizes") {
//    int smallest = 1000, largest = 8000;
//    for (int size = smallest; size <= largest; size *= 2) {
//        TIME_OPERATION(size, findPerfects(size));
//    }
//}


/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Confirm divisorSum of small inputs") {
    EXPECT_EQUAL(divisorSum(1), 0);
    EXPECT_EQUAL(divisorSum(6), 6);
    EXPECT_EQUAL(divisorSum(12), 16);
}

PROVIDED_TEST("Confirm 6 and 28 are perfect") {
    EXPECT(isPerfect(6));
    EXPECT(isPerfect(28));
}

PROVIDED_TEST("Confirm 12 and 98765 are not perfect") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}

PROVIDED_TEST("Confirm 6 and 28 are perfect") {
    EXPECT_EQUAL(isPerfect(6), isPerfectSmarter(6));
    EXPECT_EQUAL(isPerfect(8), isPerfectSmarter(8));
    EXPECT_EQUAL(isPerfect(98765), isPerfectSmarter(98765));
    EXPECT_EQUAL(isPerfect(28), isPerfectSmarter(28));
}

PROVIDED_TEST("Confirm 12 and 98765 are not perfect") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}
PROVIDED_TEST("Test oddballs: 0 and 1 are not perfect") {
    EXPECT(!isPerfect(0));
    EXPECT(!isPerfect(1));
}

PROVIDED_TEST("Confirm 33550336 is perfect") {
    EXPECT(isPerfect(33550336));
}

STUDENT_TEST("Confirm 33550336 is perfect") {
    EXPECT(!isPerfect(-33550336));
}
STUDENT_TEST("Confirm 33550336 is perfect") {
    EXPECT(!isPerfect(-3));
}

STUDENT_TEST("test smart sum") {
    EXPECT_EQUAL(smarterSum(25), divisorSum(25));
}

STUDENT_TEST("test smart sum2") {
    EXPECT_EQUAL(smarterSum(253), divisorSum(253));
}
PROVIDED_TEST("Time trial of findPerfects on input size 1000") {
    TIME_OPERATION(1000, findPerfects(1000));
}

STUDENT_TEST("Time trial of findPerfects on input size 10000") {
    TIME_OPERATION(10000, findPerfects(10000));
}

STUDENT_TEST("Time trial of findPerfects on input size 100000") {
    TIME_OPERATION(100000, findPerfects(100000));
}


STUDENT_TEST("Time trial of findPerfects on input size 200000") {
    TIME_OPERATION(200000, findPerfects(200000));
}


STUDENT_TEST("Time trial of findPerfects on input size 1000") {
    TIME_OPERATION(1000, findPerfectsSmarter(1000));
}

STUDENT_TEST("Time trial of findPerfects on input size 10000") {
    TIME_OPERATION(10000, findPerfectsSmarter(10000));
}

STUDENT_TEST("Time trial of findPerfects on input size 100000") {
    TIME_OPERATION(100000, findPerfectsSmarter(100000));
}


STUDENT_TEST("Time trial of findPerfects on input size 200000") {
    TIME_OPERATION(200000, findPerfectsSmarter(200000));
}
