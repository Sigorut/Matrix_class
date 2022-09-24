#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <QObject>
#include <QTest>
#include "matrix.h"
class TestClass : public QObject
{
    Q_OBJECT

public:
    TestClass();

private slots:

    void checkRows();
    void checkCols();
    void checkEqual();
};

#endif // TESTCLASS_H
