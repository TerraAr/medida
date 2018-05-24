#include<cmath>
#include<stdio.h>

#define PI M_PI

class medida{
private:
double valor[2];

public:
friend medida operator+(const medida&,const medida&);
friend medida operator-(const medida&,const medida&);
friend medida operator*(const medida&,const medida&);
friend medida operator/(const medida&,const medida&);

friend medida operator++(medida&);
friend medida operator--(medida&);
friend medida operator-(const medida&);

friend medida operator=(medida&,const medida&);
friend medida operator+=(medida&,const medida&);
friend medida operator-=(medida&,const medida&);
friend medida operator*=(medida&,const medida&);
friend medida operator/=(medida&,const medida&);

template <class T> friend medida operator+(const medida&,const T&);
template <class T> friend medida operator-(const medida&,const T&);
template <class T> friend medida operator*(const medida&,const T&);
template <class T> friend medida operator/(const medida&,const T&);

template <class T> friend medida operator+(const T&,const medida&);
template <class T> friend medida operator-(const T&,const medida&);
template <class T> friend medida operator*(const T&,const medida&);
template <class T> friend medida operator/(const T&,const medida&);

template <class T> friend medida operator=(medida&,const T&);
template <class T> friend medida operator+=(medida&,const T&);
template <class T> friend medida operator-=(medida&,const T&);
template <class T> friend medida operator*=(medida&,const T&);
template <class T> friend medida operator/=(medida&,const T&);

template <class T> friend T operator=(T&,const medida&);
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

medida(){
valor[0]=0;
valor[1]=0;
}

medida(const double& a,const double& b){
valor[0]=a;
valor[1]=b;
}

void imprime(){
printf("%lf±%lf\n",valor[0],valor[1]);
}
};

medida operator+(const medida& a,const medida& b){
medida aux;
aux.valor[0]=a.valor[0]+b.valor[0];
aux.valor[1]=a.valor[1]+b.valor[1];
return aux;
}

medida operator-(const medida& a,const medida& b){
medida aux;
aux.valor[0]=a.valor[0]-b.valor[0];
aux.valor[1]=a.valor[1]+b.valor[1];
return aux;
}

medida operator*(const medida& a,const medida& b){
medida aux;
aux.valor[0]=(a.valor[0]+a.valor[1])*(b.valor[0]+b.valor[1]);
aux.valor[1]=(a.valor[0]-a.valor[1])*(b.valor[0]-b.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}

medida operator/(const medida& a,const medida& b){
medida aux;
aux.valor[0]=(a.valor[0]+a.valor[1])/(b.valor[0]-b.valor[1]);
aux.valor[1]=(a.valor[0]-a.valor[1])/(b.valor[0]+b.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=aux.valor[0]-aux.valor[1];
return aux;
}


medida operator++(medida& a){
a.medida[0]++
return a;
}

medida operator--(medida& a){
a.medida[0]--;
return a;
}

medida operator-(const medida& a){
medida aux;
aux.valor[0]=-a.valor[0];
aux.valor[1]=a.valor[1];
return aux;
}


medida operator=(medida& a,const medida& b){
a.valor[0]=b.valor[0];
a.valor[1]=b.valor[1];
return a;
}

medida operator+=(medida& a,const medida& b){
a.valor[0]+=b.valor[0];
a.valor[1]+=b.valor[1];
return a;
}

medida operator-=(medida& a,const medida& b){
a.valor[0]-=b.valor[0];
a.valor[1]+=b.valor[1];
return a;
}

medida operator*=(medida& a,const medida& b){
double c=(a.valor[0]+a.valor[1])*(b.valor[0]+b.valor[1]);
a.valor[1]=(a.valor[0]-a.valor[1])*(b.valor[0]-b.valor[1]);
a.valor[0]=(c+a.valor[1])/2;
a.valor[1]=a.valor[0]-a.valor[1];
return a;
}

medida operator/=(medida& a,const medida& b){
double c=(a.valor[0]+a.valor[1])/(b.valor[0]-b.valor[1]);
a.valor[1]=(a.valor[0]-a.valor[1])/(b.valor[0]+b.valor[1]);
a.valor[0]=(c+a.valor[1])/2;
a.valor[1]=a.valor[0]-a.valor[1];
return a;
}


template <class T> medida operator+(const medida& a,const T& b){
medida aux;
aux.valor[0]=a.valor[0]+(double)b;
aux.valor[1]=a.valor[1];
return aux;
}

template <class T> medida operator-(const medida& a,const T& b){
medida aux;
aux.valor[0]=a.valor[0]-(double)b;
aux.valor[1]=a.valor[1];
return aux;
}

template <class T> medida operator*(const medida& a,const T& b){
medida aux;
aux.valor[0]=a.valor[0]*(double)b;
aux.valor[1]=a.valor[1];
return aux;
}

template <class T> medida operator/(const medida& a,const T& b){
medida aux;
aux.valor[0]=a.valor[0]/(double)b;
aux.valor[1]=a.valor[1];
return aux;
}


template <class T> medida operator+(const T& a,const medida& b){
medida aux;
aux.valor[0]=b.valor[0]+(double)a;
aux.valor[1]=b.valor[1];
return aux;
}

template <class T> medida operator-(const T& a,const medida& b){
medida aux;
aux.valor[0]=b.valor[0]-(double)a;
aux.valor[1]=b.valor[1];
return aux;
}

template <class T> medida operator*(const T& a,const medida& b){
medida aux;
aux.valor[0]=b.valor[0]*(double)a;
aux.valor[1]=b.valor[1];
return aux;
}

template <class T> medida operator/(const T& a,const medida& b){
medida aux;
aux.valor[0]=b.valor[0]/(double)a;
aux.valor[1]=b.valor[1];
return aux;
}


template <class T> medida operator=(medida& a,const T& b){
a.valor[0]=(double)b;
a.valor[1]=0;
return a;
}

template <class T> medida operator+=(medida& a,const T& b){
a.valor[0]+=(double)b;
return a;
}

template <class T> medida operator-=(medida& a,const T& b){
a.valor[0]-=(double)b;
return a;
}

template <class T> medida operator*=(medida& a,const T& b){
a.valor[0]*=(double)b;
return a;
}

template <class T> medida operator/=(medida& a,const T& b){
a.valor[0]/=(double)b;
return a;
}


template <class T> T operator=(T& a,const medida& b){
a=(T)b.valor[0];
return a;
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
aux.valor[0]=pow(a.valor[0],x);
aux.valor[1]=pow(a.valor[1],x);
return aux;
}

medida sqrt(const medida& a){
medida aux;
aux.valor[0]=sqrt(a.valor[0]+a.valor[1]);
aux.valor[1]=sqrt(a.valor[0]1a.valor[1]);
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
aux.valor[0]=sin(a.valor[0]+a.valor[1]);
aux.valor[1]=sin(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida cos(const medida& a){
medida aux;
aux.valor[0]=cos(a.valor[0]+a.valor[1]);
aux.valor[1]=cos(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
return aux;
}

medida tan(const medida& a){
if(abs(a.valor[0]-PI)<a.valor[1]) return 0;
medida aux;
aux.valor[0]=tan(a.valor[0]+a.valor[1]);
aux.valor[1]=tan(a.valor[0]-a.valor[1]);
aux.valor[0]=(aux.valor[0]+aux.valor[1])/2;
aux.valor[1]=abs(aux.valor[0]-aux.valor[1]);
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
