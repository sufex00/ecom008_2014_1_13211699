#include "MatrixHe.cpp"
#include <QDebug>
#include<stdio.h>


int main()
{
    MatrixHe matriz;
    matriz.create(3,3);
    matriz.setElementAt(0,0,1);
    matriz.setElementAt(0,1,2);
    matriz.setElementAt(0,2,5);
    matriz.setElementAt(1,0,0);
    matriz.setElementAt(1,1,0);
    matriz.setElementAt(1,2,3);
    matriz.setElementAt(2,0,-1);
    matriz.setElementAt(2,1,0);
    matriz.setElementAt(2,2,-2);
    qDebug() << "matriz.elementAt(0,0)="<< matriz.elementAt(0,0);
    qDebug() << matriz.toString();
    qDebug() <<"determinat:" << matriz.determinant();
    qDebug() <<"transpose" << matriz.transpose()->toString();
    matriz.multiplyBy(2);
    qDebug() << "multiplyBy(2)\n"<<matriz.toString();
    matriz.sub(matriz);
    qDebug()<<"matriz.sub(matriz)" << matriz.toString();

}
