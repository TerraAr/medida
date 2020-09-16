#ifndef MEDIDA_H
#define MEDIDA_H

#include<stdio.h>

#define sec(x) 1/cos(x)
#define csc(x) 1/sin(x)
#define cot(x) 1/tan(x)

#define asec(x) acos(1/x)
#define acsc(x) asin(1/x)
#define acot(x) atan(1/x)

class medicao{
	private:
	double medida, erro;

	public:
	/* Constructor */
	medicao();
	medicao(const double a, const double b);

	/* Retorna cada um dos valores */
	double media();
	double erro_associado();

	/* Operadores aritméticos básicos com outro membro da mesma classe */
	medicao operator+(const medicao) __attribute__((const));
	medicao operator-(const medicao) __attribute__((const));
	medicao operator*(const medicao) __attribute__((const));
	medicao operator/(const medicao) __attribute__((const));
	inline double operator%(const medicao)
		__attribute__((always_inline));

	/* Operadores aritméticos básicos com números exatos à direita */
	inline medicao operator+(const double)
		__attribute__((always_inline));
	inline medicao operator-(const double)
		__attribute__((always_inline));
	medicao operator*(const double);
	medicao operator/(const double);
	inline double operator%(const double)
		__attribute__((always_inline));

	/* Operadores aritméticos básicos com números exatos à esquerda */
	friend medicao operator+(const double, const medicao)
		__attribute__((const));
	friend medicao operator-(const double, const medicao)
		__attribute__((const));
	friend medicao operator*(const double, const medicao)
		__attribute__((const));
	friend medicao operator/(const double, const medicao)
		__attribute__((const));
	friend inline double operator%(const double, const medicao)
		__attribute__((always_inline));

	/* Operadores unários */
	inline medicao operator+()
		__attribute__((const)) __attribute__((always_inline));
	inline medicao operator-()
		__attribute__((const)) __attribute__((always_inline));
	inline medicao operator++() __attribute__((always_inline));
	inline medicao operator--() __attribute__((always_inline));

	/* Operadores de atribuição com outros membros da mesma classe */
	medicao operator=(const medicao);
	medicao operator+=(const medicao);
	medicao operator-=(const medicao);
	medicao operator*=(const medicao);
	medicao operator/=(const medicao);

	/* Operadores de atribuição com números exatos */
	medicao operator+=(const double);
	medicao operator-=(const double);
	medicao operator*=(const double);
	medicao operator/=(const double);

	/* Funções de exponenciação e radiciação */
	friend medicao pow(const medicao, const double);
	friend medicao pow(const double, const medicao);
	friend medicao pow(const medicao, const medicao);
	friend medicao sqrt(const medicao);
	friend medicao cbrt(const medicao);

	/* Exponenciação e logaritmo */
	friend medicao exp(const medicao);
	friend medicao log(const medicao);

	/* Funções trigonométricas diretas */
	friend medicao sin(const medicao);
	friend medicao cos(const medicao);
	friend medicao tan(const medicao);

	/* Funções trigonométricas inversas */
	friend medicao asin(const medicao);
	friend medicao acos(const medicao);
	friend medicao atan(const medicao);

	/* Função de saída */
	void imprime(FILE *fp = stdout);
};

medicao desvio_medio_aboluto(const double* medidas, const unsigned tam);
medicao desvio_padrao(const double* medidas, const unsigned tam);
medicao desvio_padrao_media(const double* medidas, const unsigned tam);

medicao desvio_medio_aboluto_arq(FILE* fp, const unsigned col);
medicao desvio_padrao_arq(FILE* fp, const unsigned col);
medicao desvio_padrao_media_arq(FILE* fp, const unsigned col);

medicao desvio_medio_aboluto_arquivo(const char* nome_arq, const unsigned col);
medicao desvio_padrao_arquivo(const char* nome_arq, const unsigned col);
medicao desvio_padrao_media_arquivo(const char* nome_arq, const unsigned col);

#endif /* MEDIDA_H */
