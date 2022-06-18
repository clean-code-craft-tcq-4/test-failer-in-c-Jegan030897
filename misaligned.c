#include <stdio.h>
#include <assert.h>
#include "cableColorCode_misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

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

void testMinor_CableColorCode(cableReferenceManual *const cableData)
{
  cableReferenceManual colorCode_Data;
    
  if((cableData->pairNo > 0) && (cableData->pairNo <= 25))
  {
     colorCode_Data = GetColorCodeFromPairNumber(cableData->pairNo);
     //assert(colorCode_Data.majorColorCode == cableData->majorColorCode); 
     //assert(colorCode_Data.minorColorCode == cableData->minorColorCode); 
  }
  else if(cableData->pairNo == 0)
  {
      assert(cableData->pairNo == 1);
  }
}

int main() {
    int cablePairIndex = 0;
    int result = printColorMap();
    //assert(result == 24);
    
    for(cablePairIndex = 0; cablePairIndex < result; cablePairIndex++)
    {
        testMinor_CableColorCode(&testCable_RefManualData_s[cablePairIndex]); 
    }
    printf("All is well (maybe!)\n");
    return 0;
}
