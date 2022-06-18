#include <stdio.h>
#include <assert.h>
#include "cableColorCode_misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

cableReferenceManual testCable_RefManualData_s[25];

int printColorMap() {
    int i = 0, j = 0, cablePairIndex = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            testCable_RefManualData_s[cablePairIndex].pairNo = i * 5 + j;
            testCable_RefManualData_s[cablePairIndex].majorColorCode = (enum MajorColor)i;
            testCable_RefManualData_s[cablePairIndex].minorColorCode = (enum MinorColor)i;
            ++cablePairIndex;
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

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

void testCableColorCode(cableReferenceManual *const cabelData)
{
  cableReferenceManual colorCode_Data;
    
  if((cabelData->pairNo > 0) && (cabelData->pairNo <= 25))
  {
     colorCode_Data = GetColorCodeFromPairNumber(cabelData->pairNo);
      
     assert(colorCode_Data.minorColorCode == cabelData->minorColorCode);  
  }
}

int main() {
    int cablePairIndex = 0;
    int result = printColorMap();
    assert(result == 24);
    
    for(cablePairIndex = 0; cablePairIndex < 25; cablePairIndex++)
    {
        testCableColorCode(&testCable_RefManualData_s[cablePairIndex]);
    }
    printf("All is well (maybe!)\n");
    return 0;
}
