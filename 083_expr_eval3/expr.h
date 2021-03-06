#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Expression
{
 public:
  virtual long evaluate() const = 0;  //abstract method
  virtual string toString() const = 0;
  virtual ~Expression() {}
};

class NumExpression : public Expression
{
 protected:
  long num;

 public:
  virtual long evaluate() const { return num; }
  explicit NumExpression(long x) : num(x){};
  virtual string toString() const {
    stringstream ss;
    ss << num;
    return ss.str();
  }
  virtual ~NumExpression(){};
};

class OpExpression : public Expression
{
 protected:
  char ch;
  string left;
  string right;
  long leftNum;
  long rightNum;

 public:
  OpExpression(char ch, Expression * lhs, Expression * rhs) :
      ch(ch),
      left(lhs->toString()),
      right(rhs->toString()),
      leftNum(lhs->evaluate()),
      rightNum(rhs->evaluate()) {
    delete lhs;
    delete rhs;
  };
  virtual string toString() const {
    stringstream ss;
    ss << "(" << left << " " << ch << " " << right << ")";
    return ss.str();
  }

  ~OpExpression() {}
};

class PlusExpression : public OpExpression
{
 public:
  PlusExpression(Expression * lhs, Expression * rhs) : OpExpression('+', lhs, rhs){};
  virtual long evaluate() const { return leftNum + rightNum; }
  virtual ~PlusExpression(){};
};

class MinusExpression : public OpExpression
{
 public:
  MinusExpression(Expression * lhs, Expression * rhs) : OpExpression('-', lhs, rhs){};
  virtual long evaluate() const { return leftNum - rightNum; }
  virtual ~MinusExpression(){};
};

class TimesExpression : public OpExpression
{
 public:
  TimesExpression(Expression * lhs, Expression * rhs) : OpExpression('*', lhs, rhs){};
  virtual long evaluate() const { return leftNum * rightNum; }
  virtual ~TimesExpression(){};
};

class DivExpression : public OpExpression
{
 public:
  DivExpression(Expression * lhs, Expression * rhs) :
      OpExpression('/', lhs, rhs){

      };
  virtual long evaluate() const { return leftNum / rightNum; }
  virtual ~DivExpression(){};
};
