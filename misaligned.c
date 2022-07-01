#include <stdio.h>
#include <assert.h>
#include "cableColorCode_misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

cableReferenceManual testCable_RefManualData_s[25];

int getColorMap() {
    int majorColors_Index = 0, minorColors_Index = 0, cablePairIndex = 0;
    
    for(majorColors_Index = 0; majorColors_Index < numberOfMajorColors; majorColors_Index++) 
    {
        for(minorColors_Index = 0; minorColors_Index < numberOfMinorColors; minorColors_Index++) 
        {
            testCable_RefManualData_s[cablePairIndex].pairNo = majorColors_Index * 5 + minorColors_Index;
            testCable_RefManualData_s[cablePairIndex].majorColorCode = (enum MajorColor)majorColors_Index;
            testCable_RefManualData_s[cablePairIndex].minorColorCode = (enum MinorColor)minorColors_Index;
            ++cablePairIndex;
        }
    }
    return majorColors_Index * minorColors_Index;
}

void printColorMap()
{
    int majorColors_Index = 0, minorColors_Index = 0;
    for(majorColors_Index = 0; majorColors_Index < numberOfMajorColors; majorColors_Index++) {
        for(minorColors_Index = 0; minorColors_Index < numberOfMinorColors; minorColors_Index++) {
    printf("%d | %s | %s\n", majorColors_Index * 5 + minorColors_Index, majorColor[majorColors_Index], minorColor[minorColors_Index]);
        }
    }
    printf("All is well (maybe!)\n");
}

cableReferenceManual GetColorCodeFromPairNumber(int pairNumber) {
    cableReferenceManual colorCode;
    int zeroBasedPairNumber = pairNumber - 1;
    colorCode.majorColorCode = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorCode.minorColorCode = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorCode;
}

void testMinor_CableColorCode(cableReferenceManual *const cableData)
{
  cableReferenceManual colorCode_Data;
    
  if((cableData->pairNo > 0) && (cableData->pairNo <= 25))
  {
     colorCode_Data = GetColorCodeFromPairNumber(cableData->pairNo);
    
     assert(colorCode_Data.minorColorCode == cableData->minorColorCode); 
  }
  else if(cableData->pairNo == 1)
  {
      assert(cableData->pairNo == 1);
  }
}

int main() {
    int pairCount = getColorMap();
    for(int cablePairIndex = 0; cablePairIndex < pairCount; cablePairIndex++){
        testMinor_CableColorCode(&testCable_RefManualData_s[cablePairIndex]); 
    }
    printColorMap();
    return 0;
}
