#ifndef IRRemoteCodes_h
#define IRRemoteCodes_h

/*
1     BA45FF00 69
2     B946FF00 70
3     B847FF00 71
4     BB44FF00 68
5     BF40FF00 64
6     BC43FF00 67
7     F807FF00 7
8     EA15FF00 21
9     F609FF00 9
*     E916FF00 22
0     E619FF00 25     
#     F20DFF00 13
UP    E718FF00 24
DOWN  AD52FF00 82
LEFT  F708FF00 8
RIGHT A55AFF00 90
OK    E31CFF00 28
*/

enum IRRemoteCodes {
  ONE = 69,
  TWO = 70,
  THREE = 71,
  FOUR = 68,
  FIVE = 64,
  SIX = 67,
  SEVEN = 7,
  EIGHT = 21,
  NINE = 9,
  ASTERISK = 22,
  ZERO = 25,
  HASH = 13,
  UP = 24,
  DOWN = 82,
  LEFT = 8,
  RIGHT = 90,
  OK = 28
};

#endif
