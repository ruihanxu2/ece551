#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Expression
{
 public:
  virtual string toString() const = 0;
  virtual ~Expression() {}
};

class NumExpression : public Expression
{
 private:
  long num;

 public:
  explicit NumExpression(long x) : num(x){};
  virtual string toString() const {
    stringstream ss;
    ss << num;
    return ss.str();
  }
  virtual ~NumExpression(){};
};

class PlusExpression : public Expression
{
 private:
  string left;
  string right;

 public:
  PlusExpression(Expression * lhs, Expression * rhs) :
      left(lhs->toString()),
      right(rhs->toString()) {
    delete lhs;
    delete rhs;
  };
  virtual string toString() const {
    stringstream ss;
    ss << "(" << left << " + " << right << ")";
    return ss.str();
  }
  virtual ~PlusExpression() {}
};
