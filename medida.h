/* Copyright (C) 2018 - 2020 Fernando José Carames Vecino 
 * (fernando.carames@gmail.com).
 ************************************************************************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>
 ************************************************************************
 *
 * Este programa é um software livre; você pode redistribuí-lo e/ou
 * modificá-lo sob os termos da Licença Pública Geral GNU como publicada
 * pela Free Software Foundation; na versão 3 da Licença, ou
 * (a seu critério) qualquer versão posterior.
 *
 * Este programa é distribuído na esperança de que possa ser útil,
 * mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
 * a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
 * Licença Pública Geral GNU para mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
 * com este programa. Se não, veja <http://www.gnu.org/licenses/>
 ************************************************************************
 */

#ifndef MEDIDA_H
#define MEDIDA_H

#include<stdio.h>

#define sec(x) 1/cos(x)
#define csc(x) 1/sin(x)
#define cot(x) 1/tan(x)

#define asec(x) acos(1/x)
#define acsc(x) asin(1/x)
#define acot(x) atan(1/x)

#define ERRO medicao(0., 1.)
#define ERROR(x) medicao(0., x)

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

	/* Verifica se o valor está dentro da faixa de erro */
	bool in(double testar);

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

	/* Funções de saída */
	void print(FILE *fp = stdout);
	void println(FILE *fp = stdout);
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
