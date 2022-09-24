#include <QCoreApplication>
#include "matrix.h"
#include <QDebug>
#include "testclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestClass, argc, argv);
    Matrix test1(1,1), test2(4,3), test3(4,3);
    //test1+test2;
    return a.exec();
}
