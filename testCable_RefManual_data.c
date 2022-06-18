#include "cableColorCode_misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

cableReferenceManual GetColorCodeFromPairNumber(int pairNumber) {
    cableReferenceManual colorCode;
    int zeroBasedPairNumber = pairNumber - 1;
    colorCode.majorColorCode = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorCode.minorColorCode = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorCode;
}

int GetPairNumberFromColorCode(const cableReferenceManual* colorCode) {
    return colorCode->majorColorCode * numberOfMinorColors + colorCode->minorColorCode + 1;
}
