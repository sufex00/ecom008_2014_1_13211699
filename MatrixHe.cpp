#include<MatrixADT.h>
#include<QDebug>

class MatrixHe : public MatrixADT{
        int columns;
        int rows;
        double **matrix;
public:
        MatrixHe()
        {
            this->columns=0;
            this->rows=0;
        }
        void create(int columns, int rows)
        {
            this->columns=columns;
            this->rows=rows;
            matrix=new double *[columns];
            for (int i = 0 ; i < columns ; i++)
                  matrix[i] = new double[rows];
        }
        void setElementAt(int column, int row, double value)
        {
            this->matrix[column][row]=value;
        }
        double elementAt(int column, int row) const
        {
            return this->matrix[column][row];
        }
        void sub(const MatrixADT & other)
        {
            for(int i=0; i<this->columns;i++)
            {
                for(int j=0; j<this->rows; j++)
                {
                    this->matrix[i][j]-=other.elementAt(i,j);
                }
            }
        }
        MatrixHe* transpose()
        {
            MatrixHe *aux= new MatrixHe();
            aux->create(this->columns,this->rows);
            for(int i=0; i<this->columns;i++)
            {
                for(int j=0; j<this->rows; j++)
                {
                    aux->setElementAt(j,i,this->matrix[i][j]);
                }
            }
            return aux;

        }

        double determinant()
        {
            if(this->columns!=this->rows)
            {
                qDebug() << "Operação invalida!!!!!";
                return 1;
            }
            else
            {
               if(this->columns==2)
               {
                   return this->matrix[0][0]*this->matrix[1][1]-this->matrix[0][1]*this->matrix[1][0];
               }
               double sum=0;
               double multiply;
               for(int loop=0; loop<this->columns; loop++)
               {
                   multiply=1;
                   for(int x=0; x<this->columns; x++)
                   {
                       int y = (loop + x) % this->columns;
                       multiply*=this->matrix[x][y];
                   }
                   sum+=multiply;
               }
               for(int loop=0; loop<this->columns; loop++)
               {
                   multiply=1;
                   for(int x=0 ; x<this->columns; x++)
                   {
                       int y=(this->columns-1)-x-loop;
                       if(y<0)y+=this->columns;
                       multiply*=this->matrix[x][y];
                   }
                   sum-=multiply;

               }
               return sum;
            }
        }

        void multiplyBy(double k){
            for(int i=0; i<this->columns;i++)
            {
                for(int j=0; j<this->rows; j++)
                {
                    this->matrix[i][j]=this->matrix[i][j]*k;
                }
            }
        }

        QString toString()
        {
            QString matrix;
            for(int i=0; i<this->columns;i++)
            {
                matrix=matrix+"\n";

                for(int j=0; j<this->rows; j++)
                {
                    matrix=matrix+" ";
                    matrix=matrix+QString::number(this->elementAt(i,j));
                }
            }
            return matrix;
        }
};
