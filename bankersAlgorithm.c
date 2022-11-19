// Bankers Algorithm
// Nathaniel Capeta
// 11.19.22

#include <stdio.h>

    int n, m;
    n = 5; // Number of processes
    m = 3; // Number of resources

    // Allocation matrix
    int alloc[5][3] = { { 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };

    // Max of matrix
    int max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } };

    // Resources Available
    int avail[3] = { 3, 3, 2 };

    