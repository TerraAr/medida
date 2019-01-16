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

void imprime(){
printf("%lf±%lf",medicao,erro);
}
};

medida medida::operator+(const medida b){
medida aux;
aux.medicao=medicao+b.medicao;
aux.erro=erro+b.erro;
return aux;
}

medida medida::operator-(const medida b){
medida aux;
aux.medicao=medicao-b.medicao;
aux.erro=medicao+b.erro;
return aux;
}

medida medida::operator*(const medida b){
medida aux;
aux.medicao=medicao*b.medicao+erro*b.erro;
aux.erro=abs(medicao*b.erro+erro*b.medicao);
return aux;
}

medida medida::operator/(const medida b){
medida aux;
aux.medicao=(medicao*b.medicao + erro*b.erro) / ((b.medicao+b.erro) * (b.medicao-b.erro));
aux.erro=abs((medicao*b.erro + erro*b.medicao) / ((b.medicao+b.erro) * (b.medicao-b.erro)));
return aux;
}

inline double medida::operator%(const medida b){
return 100.*(b.medicao-medicao)/b.medicao;
}


medida medida::operator+(const double a){
medida aux;
aux.medicao=medicao+a;
aux.erro=erro;
return aux;
}

medida medida::operator-(const double a){
medida aux;
aux.medicao=medicao-a;
aux.erro=erro;
return aux;
}

medida medida::operator*(const double a){
medida aux;
aux.medicao=medicao*a;
aux.erro=erro*abs(a);
return aux;
}

medida medida::operator/(const double a){
medida aux;
aux.medicao=medicao/a;
aux.erro=erro/abs(a);
return aux;
}

inline double medida::operator%(const double a){
return 100.*(a-medicao)/a;
}


medida operator+(const double a,const medida b){
medida aux;
aux.medicao=a+b.medicao;
aux.erro=b.erro;
return aux;
}

medida operator-(const double a,const medida b){
medida aux;
aux.medicao=a-b.medicao;
aux.erro=b.erro;
return aux;
}

medida operator*(const double a,const medida b){
medida aux;
aux.medicao=a*b.medicao;
aux.erro=abs(a)*b.erro;
return aux;
}

medida operator/(const double a,const medida b){
double constante=a/((b.medicao+b.erro)*(b.medicao+b.erro));
medida aux;
aux.medicao=constante*b.medicao;
aux.erro=abs(constante)*b.erro;
return aux;
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
medida aux;
aux.medicao=-medicao;
aux.erro=erro;
return aux;
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
medida aux;
double aux2=pow(a,x.erro),aux3=pow(a,x.medicao);
aux.medicao=aux3*(aux2+1./aux2)/2.;
aux.erro=aux3*(aux2-1./aux2)/2.;
return aux;
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
medida aux(aux2*cosh(a.erro),aux2*sinh(a.erro));
return aux;
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
medida aux;
aux.medicao=sin(a.medicao);
aux.erro=abs(cos(a.medicao)*a.erro);
return aux;
}

medida cos(const medida a){
medida aux;
aux.medicao=cos(a.medicao);
aux.erro=abs(sin(a.medicao)*a.erro);
return aux;
}

medida tan(const medida a){
medida aux;
aux.medicao=tan(a.medicao);
aux.erro=1./cos(a.medicao);
aux.erro*=aux.erro*a.erro;
return aux;
}


medida asin(const medida a){
medida aux;
aux.medicao=asin(a.medicao);
aux.erro=a.erro/sqrt(1.-a.medicao*a.medicao);
return aux;
}

medida acos(const medida a){
medida aux;
aux.medicao=acos(a.medicao);
aux.erro=a.erro/sqrt(1.-a.medicao*a.medicao);
return aux;
}

medida atan(const medida a){
medida aux;
aux.medicao=atan(a.medicao);
aux.erro=a.erro/(1.+a.medicao*a.medicao);
return aux;
}
