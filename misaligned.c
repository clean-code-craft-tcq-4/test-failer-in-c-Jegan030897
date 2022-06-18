#include <stdio.h>
#include <assert.h>
#include "cableColorCode_misaligned.h"

cableReferenceManual testCable_RefManualData_s[25];

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
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

void testCableColorCode(cableReferenceManual *const cabelData)
{
  int cablePairIndex = 0;
  cableReferenceManual colorCode_Data;
  
  for(cablePairIndex = 0; cablePairIndex < MAX_CABLE_COLOR_PAIR; cablePairIndex++)
  {
    if((cabelData[cablePairIndex]->pairNo > 0) && (cabelData[cablePairIndex]->pairNo <= MAX_CABLE_COLOR_PAIR))
    {
      colorCode_Data = GetColorCodeFromPairNumber(cabelData[cablePairIndex]->pairNo);
      
      assert(colorCode_Data.minorColorCode == cabelData[cablePairIndex]->minorColorCode);
    }
  }
  
}

int main() {
    int result = printColorMap();
    assert(result == 24);
    testCableColorCode(testCable_RefManualData_s);
    printf("All is well (maybe!)\n");
    return 0;
}
