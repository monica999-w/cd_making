#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "best_fit.h"
#include "firs_fit.h"

#define DEFAULT_CD_SIZE 10;

int main(int argc, char **argv) {

    float songSizes[] = {5, 2, 4, 7, 1, 3, 8, 3.5, 6.7, 4, 5.6, 2.1};

    float cdSize = DEFAULT_CD_SIZE;
    int optimalNumberOfCds;
    int numberOfSongs = sizeof(songSizes) / sizeof(songSizes[0]);
    double totalSongsCapacity = 0;

    for (int i = 0; i < numberOfSongs; i++) {
        totalSongsCapacity += songSizes[i];
    }

    optimalNumberOfCds = ceil(totalSongsCapacity / cdSize);

    printf("Number of used cd using first fit alg %d \n",
           getNumberOfUsedCdsFirstFit(songSizes, numberOfSongs, cdSize, optimalNumberOfCds));

    printf("Number of used cd using best fit alg %d \n ",
           getNumberOfUsedCdsBestFit(songSizes, numberOfSongs, cdSize, optimalNumberOfCds));


    return 0;
}