#include <cstdio>
#include <string>
#include <cmath>
#include <string.h>

#ifdef _VORONEZH
    #define VoronezhPrintf( code ) printf( code )
#else
    #define VoronezhPrintf( code )
#endif

void Len(double* x, double* y, double* z, double tmp);

void Rot(double* x, double* y, double* z, double tmp, char axis);

int main()
    {
    double x = 0.0;
    double y = 1.0;
    double z = 0.0;

    double tmp = 0.0;
    FILE* Tmp = fopen("input.txt", "r");
    std::string TmpStr = {};
    while (fscanf(Tmp, "%s ", TmpStr.c_str()) == 1 )
        {
        if(!strcmp(TmpStr.c_str(), "len"))
            {
            fscanf(Tmp, " %lf", &tmp);
            Len(&x, &y, &z, tmp);
            } else
            {
            char CharTmp = {};
            fscanf(Tmp, " %c %lf", &CharTmp, &tmp);
            Rot(&x, &y, &z, tmp, CharTmp);
            }
        }
    fclose(Tmp);
    Tmp = fopen("output.txt", "w");
    if(x - 0.001 < 0)
        {
        x+= 0.01;
        }
    if(y - 0.001 < 0)
        {
        y+= 0.01;
        }
    if(z - 0.001 < 0)
        {
        z+= 0.01;
        }
    VoronezhPrintf("Spasibo, chto posmotreli na kod");
    fprintf(Tmp, "%.1lf %.1lf %.1lf", x, y, z);
    fclose(Tmp);
    return 0;
    }

void Len(double* x, double* y, double* z, double tmp)
    {
    double lambda = (sqrt(*x *(*x) + *y * (*y) + *z * (*z)) + tmp)/sqrt(*x *(*x) + *y * (*y) + *z * (*z));
    *x *= lambda;
    *y *= lambda;
    *z *= lambda;
    return;
    }

void Rot(double* x, double* y, double* z, double tmp, char axis)
    {
    switch(axis)
        {
        case ('X'):
            {
            double tmp1 = 0.0;
            double tmp2 = 0.0;
            tmp1 = *y * cos(tmp) - *z * sin(tmp);
            tmp2 = *y * sin(tmp) + *z * cos(tmp);
            *y = tmp1;
            *z = tmp2;
            break;
            }

        case ('Y'):
            {
            double tmp1 = 0.0;
            double tmp2 = 0.0;
            tmp1 = *z * cos(tmp) - *x * sin(tmp);
            tmp2 = *z * sin(tmp) + *x * cos(tmp);
            *z = tmp1;
            *x = tmp2;
            break;
            }

        case ('Z'):
            {
            double tmp1 = 0.0;
            double tmp2 = 0.0;
            tmp1 = *x * cos(tmp) - *y * sin(tmp);
            tmp2 = *x * sin(tmp) + *y * cos(tmp);
            *x = tmp1;
            *y = tmp2;
            break;
            }
        }
        return;
    }

