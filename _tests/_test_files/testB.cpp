#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"


using namespace std;
bool  double_equal(const double& lhs, const double& rhs){
        double n=lhs-rhs;
        // cout<<n<<"\n";
        if (n<0)
        n*=-1;
        if (0.001>n)
          return true;
        return false;
}
bool test_rpn (bool debug =false){
  // Queue <Token*> p;
  // p.push (new Integer (3));
  // p.push (new Integer (5));
  // p.push (new Operator ("*"));
  //   // RPN rpn (p);
  // // cout<<rpn ()<<"\n";

  // p.push (new Integer (2));
  // // p.push (new Integer (8));
  // // p.push (new Operator ("*"));
  // p.push (new Operator ("+"));
  // //   p.push (new Integer (9));
  // // p.push (new Integer (8));
  // //   p.push (new Integer (4));
  // // p.push (new Integer (8));
  // p.push (new Integer (-1));
  // p.push (new Operator ("*"));
  // RPN rpn (p);
  // cout<<rpn ()<<"\n";
  // if (rpn()!=-17.00){
  //   cout<<"FATAL FAILURE EXPECTED -17, BUT FOUND "<< rpn()<<"\n";
  //   return false;
  // }
  Queue <Token*> q;

  q.push (new Integer (3));
  q.push (new Integer (4));
  q.push (new Operator ("*"));
  q.push (new Integer (5));
  q.push (new Integer (6));
  q.push (new Operator ("*"));
  q.push (new Operator ("+"));
  q.push (new Integer (7));
  q.push (new Integer (8));
  q.push (new Operator ("*"));
  q.push (new Operator ("-"));
  q.push (new Integer (9));
  q.push (new Operator ("+"));

  RPN erpn (q);
  cout<<erpn ()<<"\n";
  if (erpn()!=-5.00){
    cout<<"FATAL FAILURE EXPECTED 5, BUT FOUND "<< erpn()<<"\n";
    return false;
  }
  Queue <Token*> a;
  a.push (new Integer (20));
  a.push (new Integer (4));
  a.push (new Operator ("/"));
  a.push (new Integer (3));
  a.push (new Operator ("*"));
  a.push (new Integer (7));
  a.push (new Integer (2));
  a.push (new Operator ("/"));
  a.push (new Operator ("-"));
  a.push (new Integer (5));
  a.push (new Operator ("+"));
  erpn.set_input(a);
  cout<<erpn ()<<"\n";
  if (erpn()!=16.50){
    cout<<"FATAL FAILURE EXPECTED 16.5, BUT FOUND "<< erpn()<<"\n";
    return false;
  }

  Queue<Token*> inputQueue;
inputQueue.push(new Integer(10));
inputQueue.push(new Integer(5));
inputQueue.push(new Operator("*"));
inputQueue.push(new Integer(3));
inputQueue.push(new Integer(2));
inputQueue.push(new Operator("/"));
inputQueue.push(new Operator("+"));
inputQueue.push(new Integer(8));
inputQueue.push(new Integer(4));
inputQueue.push(new Operator("/"));
inputQueue.push(new Operator("-"));
inputQueue.push(new Integer(6));
inputQueue.push(new Operator("+"));

erpn.set_input(inputQueue);
cout << erpn() << "\n";
if (erpn() != 55.5) {
    cout << "FATAL FAILURE EXPECTED 55.5, BUT FOUND " << erpn() << "\n";
    return false;
}
Queue<Token*> myQueue;
myQueue.push(new Integer(5));
myQueue.push(new Integer(2));
myQueue.push(new Integer(3));
myQueue.push(new Operator("*"));
myQueue.push(new Operator("+"));
myQueue.push(new Integer(8));
myQueue.push(new Operator("/"));
myQueue.push(new Integer(4));
myQueue.push(new Operator("+"));
myQueue.push(new Integer(7));
myQueue.push(new Integer(2));
myQueue.push(new Operator("*"));
myQueue.push(new Operator("-"));

erpn.set_input(myQueue);
cout << erpn() << "\n";
if (erpn() != -8.625) {
    cout << "FATAL FAILURE EXPECTED -8.625, BUT FOUND " << erpn() << "\n";
    return false;
}

cout<<"================================================================\n";
Queue<Token*> largeQueue;
largeQueue.push(new Integer("3"));
largeQueue.push(new Integer("5"));
largeQueue.push(new Operator("+"));
largeQueue.push(new Integer("8"));
largeQueue.push(new Operator("-"));
largeQueue.push(new Integer("2"));
largeQueue.push(new Integer("3"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("6"));
largeQueue.push(new Operator("/"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("4"));
largeQueue.push(new Integer("2"));
largeQueue.push(new Operator("+"));
largeQueue.push(new Integer("1"));
largeQueue.push(new Integer("7"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("9"));
largeQueue.push(new Operator("-"));
largeQueue.push(new Integer("3"));
largeQueue.push(new Operator("/"));
largeQueue.push(new Integer("2"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("6"));
largeQueue.push(new Integer("5"));
largeQueue.push(new Operator("+"));
largeQueue.push(new Integer("3"));
largeQueue.push(new Operator("-"));
largeQueue.push(new Integer("4"));
largeQueue.push(new Operator("/"));
largeQueue.push(new Integer("2"));
largeQueue.push(new Operator("+"));
largeQueue.push(new Integer("8"));
largeQueue.push(new Integer("7"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("4"));
largeQueue.push(new Operator("-"));
largeQueue.push(new Integer("1"));
largeQueue.push(new Integer("3"));
largeQueue.push(new Operator("*"));
largeQueue.push(new Integer("6"));
largeQueue.push(new Operator("/"));
largeQueue.push(new Operator("*"));

erpn.set_input(largeQueue);
cout << erpn() << "\n";
if (erpn() != 26) {
    cout << "FATAL FAILURE EXPECTED 26, BUT FOUND " << erpn() << "\n";
    return false;
}


  return true;
}

bool test_shunting_yard (bool debug = false){
  Queue <Token*> p;
  p.push (new Integer (3));
  p.push (new Operator ("*"));
  p.push (new Integer (5));
    // RPN rpn (p);
  // cout<<rpn ()<<"\n";
  p.push (new Operator ("+"));
  p.push (new Integer (2));
  // p.push (new Integer (8));
  // p.push (new Operator ("*"));
  ShuntingYard test (p);

  // p.push (new Integer (-1));
  // p.push (new Operator ("*"));
  RPN rpn (test.postfix());
  cout<<rpn ()<<"\n";
    cout<<test.postfix ()<<"\n";

  double res = rpn();
  if (res!=17.00){
    cout<<"FATAL FAILURE EXPECTED 17, BUT FOUND "<< res<<"\n";
    return false;
  }
  Queue <Token*> expressionQueue;
  expressionQueue.push(new Integer(4));
  expressionQueue.push(new Operator("+"));
  expressionQueue.push(new Integer(6));
  expressionQueue.push(new Operator("*"));
  expressionQueue.push(new Integer(2));
  expressionQueue.push(new Operator("+"));
  expressionQueue.push(new Function("x"));
  test.infix (expressionQueue);
  rpn.set_input (test.postfix());
  cout<<test.postfix ()<<"\n";
  double change_me = rpn (3);
  cout<<change_me<<"\n";
  if (!(double_equal(change_me, 19.00))){
    cout<<"FATAL FAILURE EXPECTED 19, BUT FOUND "<< change_me<<"\n";
    return false;
  }
  Queue <Token*> myExpressionQueue;
  myExpressionQueue.push(new Integer(8));
  myExpressionQueue.push(new Operator("/"));
  myExpressionQueue.push(new Integer(2));
  myExpressionQueue.push(new Operator("-"));
  myExpressionQueue.push(new Integer(3));
  myExpressionQueue.push(new Operator("+"));
  myExpressionQueue.push(new Function("x"));
  test.infix(myExpressionQueue);
  rpn.set_input(test.postfix());
  
  cout << test.postfix() << "\n";
  
  double myResult = rpn(5);
  
  cout << myResult << "\n";
  
  if (!(double_equal(myResult, 6.00))){
    cout << "FATAL FAILURE EXPECTED 6, BUT FOUND " << myResult << "\n";
    return false;
  }
  Queue <Token*> newset;
  newset.push(new Integer(4));
  newset.push(new Operator("+"));
  newset.push(new Integer(2));
  newset.push(new Operator("-"));
  newset.push(new Integer(3));
  newset.push(new Operator("+"));
  newset.push(new Function("x"));
  newset.push(new Operator("-"));
  newset.push (new LeftParen());
  newset.push (new LeftParen());
  newset.push(new Integer(9));
  newset.push(new Operator("+"));
  newset.push(new Integer(9));
  newset.push(new Operator("*"));
  newset.push(new Integer(5));
  newset.push (new RightParen());
  newset.push(new Operator("/"));
  newset.push (new LeftParen());
  newset.push(new Integer(2));
  newset.push(new Operator("*"));
  newset.push(new Integer(3));
  newset.push(new Operator("-"));
  newset.push(new Integer(5));
  newset.push(new Operator("+"));
  newset.push(new Function("x"));
  newset.push (new RightParen());
  newset.push (new RightParen());

  test.infix(newset);
  rpn.set_input(test.postfix());
  cout<<"=================RESULT=======================\n";
  cout << test.postfix() << "\n";
  cout<<"========================RPN=====================\n";
  double ans = rpn(5);
  
  cout << ans << "\n";
  
  if (!(double_equal(ans, -1))){
    cout << "FATAL FAILURE EXPECTED -1, BUT FOUND " << ans << "\n";
    return false;
  }
  return true;
}

bool test_rpn_with_functions (bool debug =false){
  Queue<Token*> postfixQueue;
  postfixQueue.push(new Integer(3));
  postfixQueue.push(new Function("X"));
  postfixQueue.push(new Operator("*"));
  RPN rpn (postfixQueue);
  cout<<rpn(2)<<"\n";
  if (rpn(2)!=6){
    cout << "FATAL FAILURE EXPECTED 6, BUT FOUND " << rpn(2) << "\n";
    return false;
  }
  Queue<Token*> newque;
  newque.push(new Integer(7));
  newque.push(new Function("X"));
  newque.push(new Operator("-"));
  rpn.set_input (newque);
  cout<<rpn(5)<<"\n";
  if (rpn(5)!=2){
    cout << "FATAL FAILURE EXPECTED 6, BUT FOUND " << rpn(5) << "\n";
    return false;
  }

Queue<Token*> expressionQueue;
expressionQueue.push(new Integer(4));
expressionQueue.push(new Function("X"));
expressionQueue.push(new Operator("*"));
expressionQueue.push(new Integer(3));
expressionQueue.push(new Operator("+"));
expressionQueue.push(new Integer(7));
expressionQueue.push(new Operator("*"));
expressionQueue.push(new Function("X"));
expressionQueue.push(new Operator("-"));
expressionQueue.push(new Integer(2));
expressionQueue.push(new Operator("/"));
expressionQueue.push(new Integer(3));
expressionQueue.push(new Operator("*"));
expressionQueue.push(new Integer(2));
expressionQueue.push(new Operator("-"));

rpn.set_input(expressionQueue);
double result = rpn(4);
  cout<<result<<"\n";
if (result != 191.5) {
    cout << "FATAL FAILURE EXPECTED 191.5, BUT FOUND " << rpn(4) << "\n";
    return false;
}

Queue<Token*> newExpressionQueue;
newExpressionQueue.push(new Integer(5));
newExpressionQueue.push(new Function("X"));
newExpressionQueue.push(new Operator("*"));
newExpressionQueue.push(new Integer(3));
newExpressionQueue.push(new Operator("+"));
newExpressionQueue.push(new Integer(2));
newExpressionQueue.push(new Function("X"));
newExpressionQueue.push(new Operator("+"));
newExpressionQueue.push(new Integer(7));
newExpressionQueue.push(new Operator("*"));
newExpressionQueue.push(new Integer(4));
newExpressionQueue.push(new Operator("/"));
newExpressionQueue.push(new Integer(2));
newExpressionQueue.push(new Operator("-"));
newExpressionQueue.push(new Function("X"));
newExpressionQueue.push(new Operator("*"));
rpn.set_input(newExpressionQueue);
double neresult = rpn(3);
cout<<neresult<<"\n";
if (neresult != 20.25) {
    cout << "FATAL FAILURE EXPECTED 680, BUT FOUND " << neresult << "\n";
    return false;
}

Queue<Token*> largerExpressionQueue;
largerExpressionQueue.push(new Integer(5));
largerExpressionQueue.push(new Function("X"));
largerExpressionQueue.push(new Operator("*"));
largerExpressionQueue.push(new Integer(3));
largerExpressionQueue.push(new Operator("+"));
largerExpressionQueue.push(new Integer(2));
largerExpressionQueue.push(new Function("X"));
largerExpressionQueue.push(new Operator("+"));
largerExpressionQueue.push(new Integer(7));
largerExpressionQueue.push(new Operator("*"));
largerExpressionQueue.push(new Integer(4));
largerExpressionQueue.push(new Operator("/"));
largerExpressionQueue.push(new Integer(2));
largerExpressionQueue.push(new Operator("-"));
largerExpressionQueue.push(new Function("X"));
largerExpressionQueue.push(new Operator("*"));
largerExpressionQueue.push(new Integer(8));
largerExpressionQueue.push(new Operator("+"));
largerExpressionQueue.push(new Integer(6));
largerExpressionQueue.push(new Operator("/"));
largerExpressionQueue.push(new Integer(2));
largerExpressionQueue.push(new Operator("-"));
largerExpressionQueue.push(new Integer(3));
largerExpressionQueue.push(new Operator("+"));
rpn.set_input(largerExpressionQueue);
double resultant = rpn(3);
cout<< resultant<<"\n";
if (resultant !=5.708333333333333  ) {
    cout << "FATAL FAILURE EXPECTED: 5.708333333333333 , BUT FOUND " << resultant << "\n";
    return false;
}

Queue<Token*> okayQueue;
okayQueue.push(new Integer(5));
okayQueue.push(new Function("x"));
okayQueue.push(new Operator("*"));
okayQueue.push(new Integer(3));
okayQueue.push(new Operator("+"));
okayQueue.push(new Integer(2));
okayQueue.push(new Function("x"));
okayQueue.push(new Operator("+"));
okayQueue.push(new Integer(7));
okayQueue.push(new Operator("*"));
okayQueue.push(new Integer(4));
okayQueue.push(new Operator("/"));
okayQueue.push(new Integer(2));
okayQueue.push(new Operator("-"));
okayQueue.push(new Function("x"));
okayQueue.push(new Operator("*"));
okayQueue.push(new Integer(8));
okayQueue.push(new Operator("+"));
okayQueue.push(new Integer(6));
okayQueue.push(new Operator("/"));
okayQueue.push(new Integer(2));
okayQueue.push(new Operator("-"));
okayQueue.push(new Integer(3));
okayQueue.push(new Operator("+"));
okayQueue.push(new Integer(9));
okayQueue.push(new Function("x"));
okayQueue.push(new Operator("/"));
okayQueue.push(new Integer(2));
okayQueue.push(new Operator("*"));
okayQueue.push(new Integer(4));
okayQueue.push(new Operator("+"));
rpn.set_input(okayQueue);
double bruh = rpn(3);
cout<< bruh<<"\n";
if (!double_equal (bruh,10.00)) {
    cout << "FATAL FAILURE EXPECTED: 10 , BUT FOUND " << bruh << "\n";
    return false;
}
  return true;

}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}


TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

// TEST(TEST_RPN, TestRpn) {
  
//   //EXPECT_EQ(0, <your individual test functions are called here>);

//   EXPECT_EQ(1, test_rpn(false));
// }


TEST(TEST_SHUNTING_YARD, TestYard) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shunting_yard(false));
}



// TEST(TEST_RPN_FUNCTION, TestFunction) {
  
//   //EXPECT_EQ(0, <your individual test functions are called here>);

//   EXPECT_EQ(1, test_rpn_with_functions(false));
// }



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

