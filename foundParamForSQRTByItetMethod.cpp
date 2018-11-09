#include <QCoreApplication>
#include <iostream>
#include <math.h>

int pow(int a, int col);

int main(int argc, char *argv[])
{
    int from = 1000;
    int to = 10000;
    int max = 0;
    int nowCol = 0;
    int minMax = 10;
    int numForMinMax = 1;
    for(int m = 1; m<1000;m++){
        max = 0;
        for(int j = from; j<to; j++) {
            nowCol = pow(j,m);
            if(nowCol>max) {
                max=nowCol;
            }
        }
        if(minMax>max) {
            minMax=max;
            numForMinMax=m;
            std::cout<<"\n"<<"MINMAX = "<<minMax<<" IN "<<m<<std::endl;
        }
        std::cout<<m<<"\t"<<max<<std::endl;
    }
    std::cout<<"\n\n"<<"For sqrt from "<<from<<" to "<< to <<std::endl;
    std::cout<<"Best param for iter method:\nm="<<numForMinMax<<"\ncount iter="<<minMax<<std::endl;
    std::cout<<"formula: \nn=a/"<<numForMinMax<<";"<<std::endl;
    for(int i=0;i<minMax;i++) {
        std::cout<<"n=(n+a/n)/2;"<<std::endl;
    }
    system("PAUSE");
    return 1;
}
int pow(int a,int col) {
    int n=a/col;
    int i;
    for(i = 0; i < 10;++i) {
        n=(n+a/n)/2;
        if(n == static_cast<int>(sqrt(static_cast<double>(a))))
            break;
    }
    return ++i;
}
