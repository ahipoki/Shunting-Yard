#include <iostream>
#include <cstring>
#include <functional>
#include <math.h>
#include <deque>

class Token{
 public:
  enum class Type{
    Unknown,
      Number,
      Operator,
      LeftParen,
      RightParen,
      };
  Token(Type t, const char* s, int prec = 
}
