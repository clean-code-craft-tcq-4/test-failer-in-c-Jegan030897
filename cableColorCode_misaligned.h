#include "stdio.h"

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE}

struct cableReferenceManual
{
  int pairNo;
  enum MajorColor majorColorCode;
  enum MinorColor minorColorCode;
};
