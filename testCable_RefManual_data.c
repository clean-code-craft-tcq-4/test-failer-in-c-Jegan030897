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
