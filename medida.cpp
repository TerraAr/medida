#include<cmath>
#include<stdio.h>

#define PI M_PI
#define NEPHER M_E

#define sec(x) 1/cos(x)
#define csc(x) 1/sin(x)
#define cot(x) 1/tan(x)

#define asec(x) acos(1/x)
#define acsc(x) asin(1/x)
#define acot(x) atan(1/x)

double abs(double x) {return (x<0)?-(x):x;}

class medida{
private:
double valor[2];

public:
medida operator+(const medida&);
medida operator-(const medida&);
medida operator*(const medida&);
medida operator/(const medida&);
double operator%(const medida&);

medida operator++();
medida operator--();
medida operator-();

medida operator=(const medida&);
medida operator+=(const medida&);
medida operator-=(const medida&);
medida operator*=(const medida&);
medida operator/=(const medida&);

template <class T> T operator=(const medida&);
template <class T> friend T operator+=(T&,const medida&);
template <class T> friend T operator-=(T&,const medida&);
template <class T> friend T operator*=(T&,const medida&);
template <class T> friend T operator/=(T&,const medida&);

friend medida pow(const medida&,const double);
friend medida sqrt(const medida&);
friend medida cbrt(const medida&);

friend medida sin(const medida&);
friend medida cos(const medida&);
friend medida tan(const medida&);

friend medida asin(const medida&);
friend medida acos(const medida&);
friend medida atan(const medida&);

friend double erro(const medida&,const medida&);

medida(const double& a=0,const double& b=0){
valor[0]=a;
valor[1]=b;
}

double medicao() {return *valor;}
double erro() {return *(valor+1);}

void imprime(){
printf("%lf±%lf\n",valor[0],valor[1]);
}
};

medida medida::operator+(const medida& b){
medida aux;
aux.valor[0]=valor[0]+b.valor[0];
aux.valor[1]=valor[1]+b.valor[1];
return aux;
}

medida medida::operator-(const medida& b){
medida aux;
aux.valor[0]=valor[0]-b.valor[0];
aux.valor[1]=valor[1]+b.valor[1];
return aux;
}

medida medida::operator*(const medida& b){
medida aux;
aux.valor[0]=valor[0]*b.valor[0]+valor[1]*b.valor[1];
aux.valor[1]=valor[0]*b.valor[1]+valor[1]*b.valor[0];
return aux;
}

medida medida::operator/(const medida& b){
medida aux;
aux.valor[0]=(valor[0]*b.valor[0] + valor[1]*b.valor[1]) / ((b.valor[0]+b.valor[1]) * (b.valor[0]-b.valor[1]));
aux.valor[1]=(valor[0]*b.valor[1] + valor[1]*b.valor[0]) / ((b.valor[0]+b.valor[1]) * (b.valor[0]-b.valor[1]));
return aux;
}

double medida::operator%(const medida& b){
double aux;
aux=100.*(b.valor[0]-valor[0])/b.valor[0];
return aux;
}


medida medida::operator++(){
valor[0]++;
return *this;
}

medida medida::operator--(){
valor[0]--;
return *this;
}

medida medida::operator-(){
medida aux;
aux.valor[0]=-valor[0];
aux.valor[1]=valor[1];
return aux;
}


medida medida::operator=(const medida& b){
valor[0]=b.valor[0];
valor[1]=b.valor[1];
return *this;
}

medida medida::operator+=(const medida& b){
valor[0]+=b.valor[0];
valor[1]+=b.valor[1];
return *this;
}

medida medida::operator-=(const medida& b){
valor[0]-=b.valor[0];
valor[1]+=b.valor[1];
return *this;
}

medida medida::operator*=(const medida& b){
double c=valor[0]*b.valor[0] + valor[1]*b.valor[1];
valor[1]=valor[0]*b.valor[1] + valor[1]*b.valor[0];
valor[0]=c;
return *this;
}

medida medida::operator/=(const medida& b){
double c=(valor[0]*b.valor[0] + valor[1]*b.valor[1]) / ((b.valor[0]+b.valor[1]) * (b.valor[0]-b.valor[1]));
valor[1]=(valor[0]*b.valor[1] + valor[1]*b.valor[0]) / ((b.valor[0]+b.valor[1]) * (b.valor[0]-b.valor[1]));
valor[0]=c;
return *this;
}


template <class T> T operator+=(T& a,const medida& b){
a+=(T)b.valor[0];
return a;
}

template <class T> T operator-=(T& a,const medida& b){
a-=(T)b.valor[0];
return a;
}

template <class T> T operator*=(T& a,const medida& b){
a*=(T)b.valor[0];
return a;
}

template <class T> T operator/=(T& a,const medida& b){
a/=(T)b.valor[0];
return a;
}


medida pow(const medida& a,const double x){
medida aux;
aux.valor[0]=pow(a.valor[0]+a.valor[1],x);
aux.valor[1]=pow(a.valor[0]-a.valor[1],x);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}

medida sqrt(const medida& a){
medida aux;
aux.valor[0]=sqrt(a.valor[0]+a.valor[1]);
aux.valor[1]=sqrt(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}

medida cbrt(const medida& a){
medida aux;
aux.valor[0]=cbrt(a.valor[0]+a.valor[1]);
aux.valor[1]=cbrt(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}

medida sin(const medida& a){
medida aux;
aux.valor[0]=(abs(a.valor[0]-PI/2)<a.valor[1])?1:sin(a.valor[0]+a.valor[1]);
aux.valor[1]=(abs(a.valor[0]+PI/2)<a.valor[1])?-1:sin(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida cos(const medida& a){
medida aux;
aux.valor[0]=(abs(a.valor[0])<a.valor[1])?1:cos(a.valor[0]+a.valor[1]);
aux.valor[1]=(abs(a.valor[0]+PI)<a.valor[1])?-1:cos(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida tan(const medida& a){
medida aux;
if(abs(a.valor[0]-PI/2)<a.valor[1] || abs(a.valor[0]+PI/2)<a.valor[1]) return aux;

aux.valor[0]=tan(a.valor[0]+a.valor[1]);
aux.valor[1]=tan(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}


medida asin(const medida& a){
medida aux;
aux.valor[0]=asin(a.valor[0]+a.valor[1]);
aux.valor[1]=asin(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida acos(const medida& a){
medida aux;
aux.valor[0]=acos(a.valor[0]+a.valor[1]);
aux.valor[1]=acos(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida atan(const medida& a){
medida aux;
aux.valor[0]=atan(a.valor[0]+a.valor[1]);
aux.valor[1]=atan(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}

double erro(const medida& a,const medida& b){
return 100*(a.valor[0]-b.valor[0])/a.valor[0];
}
