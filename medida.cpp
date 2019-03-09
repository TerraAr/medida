#include<stdio.h>
#include<math.h>

#define PI M_PI
#define NEPHER M_E

#define sec(x) 1/cos(x)
#define csc(x) 1/sin(x)
#define cot(x) 1/tan(x)

#define asec(x) acos(1/x)
#define acsc(x) asin(1/x)
#define acot(x) atan(1/x)

inline double abs(double x) {return (x<0)?-(x):x;}

class medida{
public:
double medicao,erro;

medida operator+(const medida);
medida operator-(const medida);
medida operator*(const medida);
medida operator/(const medida);
inline double operator%(const medida);

medida operator+(const double);
medida operator-(const double);
medida operator*(const double);
medida operator/(const double);
inline double operator%(const double);

friend medida operator+(const double,const medida);
friend medida operator-(const double,const medida);
friend medida operator*(const double,const medida);
friend medida operator/(const double,const medida);
friend double operator%(const double,const medida);

medida operator++();
medida operator--();
medida operator+();
medida operator-();

medida operator=(const medida);
medida operator+=(const medida);
medida operator-=(const medida);
medida operator*=(const medida);
medida operator/=(const medida);

medida operator+=(const double);
medida operator-=(const double);
medida operator*=(const double);
medida operator/=(const double);

friend medida pow(const medida,const double);
friend medida pow(const double,const medida);
friend medida pow(const medida,const medida);
friend medida sqrt(const medida);
friend medida cbrt(const medida);

friend medida exp(const medida);
friend medida log(const medida);

friend medida sin(const medida);
friend medida cos(const medida);
friend medida tan(const medida);

friend medida asin(const medida);
friend medida acos(const medida);
friend medida atan(const medida);

medida(const double a=0,const double b=0){
medicao=a;
erro=b;
}

void imprime(FILE *fp=stdout){
fprintf(fp,"(%lf±%lf)",medicao,erro);
}
};



medida medida::operator+(const medida b){
return medida(medicao+b.medicao, erro+b.erro);
}

medida medida::operator-(const medida b){
return medida(medicao-b.medicao, erro+b.erro);
}

medida medida::operator*(const medida b){
return medida(medicao*b.medicao+erro*b.erro, abs(medicao*b.erro+erro*b.medicao));
}

medida medida::operator/(const medida b){
return medida((medicao*b.medicao + erro*b.erro) / ((b.medicao+b.erro) * (b.medicao-b.erro)),
abs((medicao*b.erro + erro*b.medicao) / ((b.medicao+b.erro) * (b.medicao-b.erro))));
}

inline double medida::operator%(const medida b){
return 100.*(b.medicao-medicao)/b.medicao;
}


medida medida::operator+(const double a){
return medida(medicao+a, erro);
}

medida medida::operator-(const double a){
return medida(medicao-a, erro);
}

medida medida::operator*(const double a){
return medida(medicao*a, erro*abs(a));
}

medida medida::operator/(const double a){
return medida(medicao/a, erro/abs(a));
}

inline double medida::operator%(const double a){
return 100.*(a-medicao)/a;
}


medida operator+(const double a,const medida b){
return medida(a+b.medicao, b.erro);
}

medida operator-(const double a,const medida b){
return medida(a-b.medicao, b.erro);
}

medida operator*(const double a,const medida b){
return medida(a*b.medicao, abs(a)*b.erro);
}

medida operator/(const double a,const medida b){
double constante=a/((b.medicao+b.erro)*(b.medicao+b.erro));
return medida(constante*b.medicao, abs(constante)*b.erro);
}

inline double operator%(const double a,const medida b){
return 100.*(b.medicao-a)/b.medicao;
}


medida medida::operator++(){
medicao++;
return *this;
}

medida medida::operator--(){
medicao--;
return *this;
}

medida medida::operator+(){
return *this;
}

medida medida::operator-(){
return medida(-medicao,erro);
}


medida medida::operator=(const medida b){
medicao=b.medicao;
erro=b.erro;
return *this;
}

medida medida::operator+=(const medida b){
medicao+=b.medicao;
erro+=b.erro;
return *this;
}

medida medida::operator-=(const medida b){
medicao-=b.medicao;
erro+=b.erro;
return *this;
}

medida medida::operator*=(const medida b){
double c=medicao*b.medicao + erro*b.erro;
erro=abs(medicao*b.erro + erro*b.medicao);
medicao=c;
return *this;
}

medida medida::operator/=(const medida b){
double c=(medicao*b.medicao + erro*b.erro) / ((b.medicao+b.erro) * (b.medicao-b.erro));
erro=abs((medicao*b.erro + erro*b.medicao) / ((b.medicao+b.erro) * (b.medicao-b.erro)));
medicao=c;
return *this;
}


medida medida::operator+=(const double a){
medicao+=a;
return *this;
}

medida medida::operator-=(const double a){
medicao-=a;
return *this;
}

medida medida::operator*=(const double a){
medicao*=a;
erro*=abs(a);
return *this;
}

medida medida::operator/=(const double a){
medicao/=a;
erro/=abs(a);
return *this;
}


medida pow(const medida a,const double x){
medida aux;
aux.medicao=pow(a.medicao+a.erro,x);
aux.erro=pow(a.medicao-a.erro,x);
aux.medicao=(aux.medicao+aux.erro)/2;
aux.erro=aux.medicao-aux.erro;
return aux;
}

medida pow(const double a,const medida x){
double aux2=pow(a,x.erro),aux3=pow(a,x.medicao);
return medida(aux3*(aux2+1./aux2)/2., aux3*(aux2-1./aux2)/2.);
}

medida pow(const medida a,const medida x){
medida aux;
aux.medicao=pow(a.medicao+a.erro,x.medicao+x.erro);
aux.erro=pow(a.medicao-a.erro,x.medicao-x.erro);
aux.medicao=(aux.medicao+aux.erro)/2.;
aux.erro=aux.medicao-aux.erro;
return aux;
}

medida sqrt(const medida a){
medida aux;
aux.medicao=sqrt(a.medicao+a.erro);
aux.erro=sqrt(a.medicao-a.erro);
aux.medicao=(aux.medicao+aux.erro)/2.;
aux.erro=aux.medicao-aux.erro;
return aux;
}

medida cbrt(const medida a){
medida aux;
aux.medicao=cbrt(a.medicao+a.erro);
aux.erro=cbrt(a.medicao-a.erro);
aux.medicao=(aux.medicao+aux.erro)/2.;
aux.erro=aux.medicao-aux.erro;
return aux;
}


medida exp(const medida a){
double aux2=exp(a.medicao);
return medida(aux2*cosh(a.erro),aux2*sinh(a.erro));
}

medida log(const medida a){
medida aux;
aux.medicao=log(a.medicao+a.erro);
aux.erro=log(a.medicao-a.erro);
aux.medicao=(aux.medicao+aux.erro)/2.;
aux.erro=aux.medicao-aux.erro;
return aux;
}


medida sin(const medida a){
return medida(sin(a.medicao), abs(cos(a.medicao)*a.erro));
}

medida cos(const medida a){
return medida(cos(a.medicao), abs(sin(a.medicao)*a.erro));
}

medida tan(const medida a){
medida aux;
aux.medicao=tan(a.medicao);
aux.erro=1./cos(a.medicao);
aux.erro*=aux.erro*a.erro;
return aux;
}


medida asin(const medida a){
return medida(asin(a.medicao), a.erro/sqrt(1.-a.medicao*a.medicao));
}

medida acos(const medida a){
return medida(acos(a.medicao), a.erro/sqrt(1.-a.medicao*a.medicao));
}

medida atan(const medida a){
return medida(atan(a.medicao), a.erro/(1.+a.medicao*a.medicao));
}

#undef PI
#undef NEPHER
