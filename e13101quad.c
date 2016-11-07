#include <stdio.h>
#include <math.h>

int main(){

double a,b,c;
printf("./quad\n");
printf("Enter the coefficients: ");
scanf("%lf %lf %lf",&a,&b,&c);
double d=(b*b)-4*a*c;
if(d>0){
    double x1=(-b+sqrt(d))/2*a;
    double x2=(-b-sqrt(d))/2*a;
    printf("The solutions are %.2lf and %.2lf.\n",x1,x2);
}else{
    if(d==0){
        double x3=-b/(2*a);
        printf("The solutions are %.2lf.\n",x3);
    }
        else{

                double r=4*a*c-(b*b);
            double x4=-b/(2*a);
            double x5=sqrt(r)/(2*a);
            if(x4==0){
                printf("The solutions are %.2lfi and -%.2lfi.\n",x5,x5);
            }else {
                printf("The solutions are %.2lf+%.2lfi and %.2lf-%.2lfi.\n",x4,x5,x4,x5);
        }
    }
}
return 0;
}
