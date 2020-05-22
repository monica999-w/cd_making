//
// Created by Monica Iliescu on 5/22/2020.
//

#include "best_fit.h"
#include <stdlib.h>

/**
 * best fit
 *
 * @param songSizes
 * @param cdSize
 * @param optimalNumberOfCds
 * @return
 */
int getNumberOfUsedCdsBestFit(const float songSizes[], int numberOfSongs, const float cdSize,
                              const int optimalNumberOfCds) {
    int capacity = optimalNumberOfCds;
    float *cdList = malloc(capacity * sizeof(float)); // remaining capacity for all cd's
    int numberOfUsedCds = 0;

    for (int songIndex = 0; songIndex < numberOfSongs; songIndex++) {
        int cdIndex;

        // Initialize minimum space left and index
        // of best bin
        float min = cdSize + 1;
        int bestCdIndex = 0;

        for (cdIndex = 0; cdIndex < numberOfUsedCds; cdIndex++) {
            if (cdList[cdIndex] >= songSizes[songIndex] && cdList[cdIndex] - songSizes[songIndex] < min) {
                bestCdIndex = cdIndex;
                min = cdList[cdIndex] - songSizes[songIndex];
            }
        }

        if (min == cdSize + 1) {
            if (numberOfUsedCds + 1 > optimalNumberOfCds) {
                realloc(cdList, (numberOfUsedCds * sizeof(int)) + 1);
            }

            cdList[numberOfUsedCds] = cdSize - songSizes[songIndex];
            numberOfUsedCds++;
        } else {
            cdList[bestCdIndex] -= songSizes[songIndex];
        }
    }

    return numberOfUsedCds;
}
