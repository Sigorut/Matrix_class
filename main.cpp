#include <QCoreApplication>
#include "matrix.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Matrix test1(0,1), test2(4,3), test3(4,3);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            test1[i][j] = i+1;
            test2[i][j] = i+1;
        }
    }
    test1.printmat();
    test2.printmat();
    //qDebug() << test3.toString();
    //test3.transp().printmat();
    test3 = test2 * test1;
    test3.printmat();

    return a.exec();
}
