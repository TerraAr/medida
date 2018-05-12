#include<cmath>
#include<iostream>

#define PI 3.14159265358979323846
#define complexo ponto2d

class medida{
private:
double valor[2];

public:
friend medida operator+(const medida&,const medida&);
friend medida operator-(const medida&,const medida&);
friend medida operator*(const medida&,const medida&);
friend medida operator/(const medida&,const medida&);
friend medida operator-(const medida&);

friend medida operator=(medida&,const medida&);
friend medida operator+=(medida&,const medida&);
friend medida operator-=(medida&,const medida&);
friend medida operator*=(medida&,const medida&);
friend medida operator/=(medida&,const medida&);

friend medida pow(const medida&,const double);

medida(){
valor[0]=0;
valor[1]=0;
}

medida(const double& a,const double& b){
valor[0]=a;
valor[1]=b;
}

void imprime(){
std::cout<<valor[0]<<"±"<<valor[1]<<std::endl;
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

medida operator-(medida& a){
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


medida pow(const medida& a,const double x){
medida aux;
aux.valor[0]=pow(a.valor[0],x);
aux.valor[1]=pow(a.valor[1],x);
return aux;
}
