#include "testclass.h"

TestClass::TestClass()
{

}
void TestClass::checkCols(){
    Matrix test(0,1);
    QVERIFY(test.getCols() > 0);
}
void TestClass::checkRows(){
    Matrix test(1,0);
    QVERIFY(test.getRows() > 0);
}
void TestClass::checkEqual(){
    Matrix test1(1,1);
    Matrix test2(1,2);
    QVERIFY_EXCEPTION_THROWN(test1+test2, std::exception);
}


