#include "stdio.h"

#define MAX_CABLE_COLOR_PAIR  25

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

struct cableReferenceManual
{
  int pairNo;
  enum MajorColor majorColorCode;
  enum MinorColor minorColorCode;
};

void testCableColorCode(cableReferenceManual const cabelData);
cableReferenceManual GetColorCodeFromPairNumber(int pairNumber);
int GetPairNumberFromColorCode(const cableReferenceManual* colorCode);
