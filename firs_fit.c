//
// Created by Monica Iliescu on 5/22/2020.
//

#include "firs_fit.h"
#include <stdlib.h>

/**
 * first fit
 *
 * @param songSizes
 * @param cdSize
 * @param optimalNumberOfCds
 * @return
 */
int getNumberOfUsedCdsFirstFit(const float songSizes[], int numberOfSongs, const float cdSize,
                               const int optimalNumberOfCds) {
    int capacity = optimalNumberOfCds;
    float *cdList = malloc(capacity * sizeof(float)); // remaining capacity for all cd's
    int numberOfUsedCds = 0;

    for (int songIndex = 0; songIndex < numberOfSongs; songIndex++) {
        int cdIndex;
        for (cdIndex = 0; cdIndex < numberOfUsedCds; cdIndex++) {
            if (cdList[cdIndex] >= songSizes[songIndex]) {
                cdList[cdIndex] = cdList[cdIndex] - songSizes[songIndex];
                break;
            }
        }

        // If song can't fit the existing cd's we use another one
        if (cdIndex == numberOfUsedCds) {
            if (numberOfUsedCds + 1 > optimalNumberOfCds) {
                realloc(cdList, (numberOfUsedCds * sizeof(int)) + 1);
            }

            cdList[cdIndex] = cdSize - songSizes[songIndex];
            numberOfUsedCds++;
        }
    }

    return numberOfUsedCds;
}


