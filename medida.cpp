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

#ifndef MEDIDA_C
#define MEDIDA_C

#include"medida.h"
#include<math.h>

/* Função absoluto para doubles */
inline double abs(double x) { return (x<0)?-(x):x; }

medicao::medicao() : medida(0.), erro(0.){}

medicao::medicao(const double a, const double b) : medida(a), erro(b){}

double medicao::media(){
	return medida;
}

double medicao::erro_associado(){
	return erro;
}

/* (a±b) + (c±d) = (a+c) ± (b+d) */
medicao medicao::operator+(const medicao b){
	return medicao(medida + b.medida, erro + b.erro);
}

/* (a±b) - (c±d) = (a-c) ± (b+d) */
medicao medicao::operator-(const medicao b){
	return medicao(medida - b.medida, erro + b.erro);
}

/* (a±b) * (c±d) = (ac+bd) ± |ad+bc| */
medicao medicao::operator*(const medicao b){
	return medicao(medida * b.medida + erro * b.erro,
		abs(medida * b.erro + erro * b.medida));
}

/*  a±b     ac+bd    | ad+bc |      1   (ac+bd)   |   1   (ad+bc)| *
 * ----- = ------- ± |-------| = -------        ± |-------       | *
 *  c±d     c²-d²    | c²-d² |    c²-d²           | c²-d²        | */
medicao medicao::operator/(const medicao b){
	return medicao((medida*b.medida + erro*b.erro) /
		((b.medida+b.erro) * (b.medida-b.erro)),
		abs((medida*b.erro + erro*b.medida) /
       		((b.medida+b.erro) * (b.medida-b.erro))));
}

inline double medicao::operator%(const medicao b){
	return 100. * (b.medida - medida) / b.medida;
}

/* (a±b) + c = (a+c) ± b */
medicao medicao::operator+(const double a){
	return medicao(medida + a, erro);
}

/* (a±b) - c = (a-c) ± b */
medicao medicao::operator-(const double a){
	return medicao(medida - a, erro);
}

/* (a±b) * c = (ac) ± |bc| = (ac) ± b*|c| */
medicao medicao::operator*(const double a){
	return medicao(medida * a, erro * abs(a));
}

/*  a±b     a    | b |    a     b  *
 * ----- = --- ± |---| = --- ± --- *
 *   c      c    | c |    c    |c| */
medicao medicao::operator/(const double a){
	return medicao(medida / a, erro / abs(a));
}

inline double medicao::operator%(const double a){
	return 100. * (a - medida) / a;
}

/* a + (c±d) = (a+c) ± d */
medicao operator+(const double a, const medicao b){
	return medicao(a + b.medida, b.erro);
}

/* a - (c±d) = (a-c) ± d */
medicao operator-(const double a, const medicao b){
	return medicao(a - b.medida, b.erro);
}

/* a * (c±d) = (ac) ± |ad| = (ac) ± |a|*d */
medicao operator*(const double a, const medicao b){
	return medicao(a * b.medida, abs(a) * b.erro);
}

/*   a       a*c     |  a*d  |      a    * c ± |   a   | * d *
 * ----- = ------- ± |-------| = -------       |-------|     *
 *  c±d     c²-d²    | c²-d² |    c²-d²        | c²-d² |     */
medicao operator/(const double a, const medicao b){
	double constante = a / ((b.medida + b.erro) * (b.medida + b.erro));
	return medicao(constante * b.medida, abs(constante) * b.erro);
}

inline double operator%(const double a, const medicao b){
	return 100. * (b.medida - a) / b.medida;
}

/* (a±b) + 1 = (a+1) ± b */
medicao medicao::operator++(){
	medida++;
	return *this;
}

/* (a±b) - 1 = (a-1) ± b */
medicao medicao::operator--(){
	medida--;
	return *this;
}

/* +(a±b) = (a±b) */
medicao medicao::operator+(){
	return *this;
}

/* -(a±b) = (-a) ± b */
medicao medicao::operator-(){
	return medicao(-medida, erro);
}


medicao medicao::operator=(const medicao b){
	medida = b.medida;
	erro = b.erro;
	return *this;
}

/* (a±b) + (c±d) = (a+c) ± (b+d) */
medicao medicao::operator+=(const medicao b){
	medida += b.medida;
	erro += b.erro;
	return *this;
}

/* (a±b) - (c±d) = (a-c) ± (b+d) */
medicao medicao::operator-=(const medicao b){
	medida -= b.medida;
	erro += b.erro;
	return *this;
}

/* (a±b) * (c±d) = (ac+bd) ± |ad+bc| */
medicao medicao::operator*=(const medicao b){
	double c = medida * b.medida + erro * b.erro;
	erro = abs(medida*b.erro + erro*b.medida);
	medida = c;
	return *this;
}

/*  a±b     ac+bd    | ad+bc |      1   (ac+bd)   |   1   (ad+bc)| *
 * ----- = ------- ± |-------| = -------        ± |-------       | *
 *  c±d     c²-d²    | c²-d² |    c²-d²           | c²-d²        | */
medicao medicao::operator/=(const medicao b){
	double constante = 1. / (b.medida*b.medida - b.erro*b.erro);
	double c = constante * (medida * b.medida + erro * b.erro);
	erro = abs(constante * (medida * b.erro + erro * b.medida));
	medida = c;
	return *this;
}


/* (a±b) + c = (a+c) ± b */
medicao medicao::operator+=(const double a){
	medida += a;
	return *this;
}

/* (a±b) - c = (a-c) ± b */
medicao medicao::operator-=(const double a){
	medida -= a;
	return *this;
}

/* (a±b) * c = (ac) ± |bc| = (ac) ± (b*|c|) */
medicao medicao::operator*=(const double a){
	medida *= a;
	erro *= abs(a);
	return *this;
}

/*  a±b     a     | b |    a      b
   ----- = --- ±  |---| = --- ±  ---
     c      c     | c |    c     |c| */
medicao medicao::operator/=(const double a){
	medida /= a;
	erro /= abs(a);
	return *this;
}


medicao pow(const medicao a, const double x){
	medicao aux;
	aux.medida = pow(a.medida + a.erro, x);
	aux.erro = pow(a.medida - a.erro, x);
	aux.medida = (aux.medida + aux.erro)/2.;
	aux.erro = aux.medida - aux.erro;
	return aux;
}

/* a^(x±y) = (a^x/2) * (a^y + 1/(a^y)) ± (a^x/2) * (a^y + 1/(a^y)) */
medicao pow(const double a, const medicao x){
	double aux2 = pow(a, x.erro), aux3 = pow(a, x.medida)/2.;
	return medicao(aux3*(aux2+1./aux2), aux3*(aux2-1./aux2));
}

medicao pow(const medicao a, const medicao x){
	medicao aux;
	aux.medida = pow(a.medida + a.erro, x.medida + x.erro);
	aux.erro = pow(a.medida - a.erro, x.medida - x.erro);
	aux.medida = (aux.medida + aux.erro)/2.;
	aux.erro = aux.medida - aux.erro;
	return aux;
}

medicao sqrt(const medicao a){
	medicao aux;
	aux.medida = sqrt(a.medida + a.erro);
	aux.erro = sqrt(a.medida - a.erro);
	aux.medida = (aux.medida + aux.erro)/2.;
	aux.erro = aux.medida - aux.erro;
	return aux;
}

medicao cbrt(const medicao a){
	medicao aux;
	aux.medida = cbrt(a.medida + a.erro);
	aux.erro = cbrt(a.medida - a.erro);
	aux.medida = (aux.medida + aux.erro)/2.;
	aux.erro = aux.medida - aux.erro;
	return aux;
}


medicao exp(const medicao a){
	double aux2 = exp(a.medida);
	return medicao(aux2*cosh(a.erro), aux2*sinh(a.erro));
}

medicao log(const medicao a){
	medicao aux;
	aux.medida = log(a.medida + a.erro);
	aux.erro = log(a.medida - a.erro);
	aux.medida = (aux.medida + aux.erro)/2.;
	aux.erro = aux.medida - aux.erro;
	return aux;
}

/* sin(a±b) = sin(a) ± |cos(a)| * b ± (1/2)|sin(a)| * b^2 */
medicao sin(const medicao a){
	double medida = sin(a.medida);
	double erro = (abs(cos(a.medida)) - abs(medida) * a.erro / 2.) * a.erro;

	if(medida + erro >= 1. && medida - erro <= -1.)
		return medicao(0., 1.);
	else if(medida + erro >= 1.)
		return medicao((medida - erro + 1.)/2.,
				(1. - medida + erro)/2.);
	else if(medida - erro <= -1.)
		return medicao((medida + erro - 1.)/2.,
				(medida + erro + 1.)/2.);
	/* else */
	return medicao(medida, erro);
}

/* cos(a±b) = cos(a) ± |sin(a)| * b ± (1/2)|cos(a)| * b^2 */
medicao cos(const medicao a){
	double medida = cos(a.medida);
	double erro = (abs(sin(a.medida)) + abs(medida) * a.erro / 2.) * a.erro;

	if(medida + erro >= 1. && medida - erro <= -1.)
		return medicao(0., 1.);
	else if(medida + erro >= 1.)
		return medicao((medida - erro + 1.)/2.,
				(1. - medida + erro)/2.);
	else if(medida - erro <= -1.)
		return medicao((medida + erro - 1.)/2.,
				(medida + erro + 1.)/2.);
	/* else */
	return medicao(medida, erro);
}

/* tan(a±b) = tan(a) ± sec^2(a) * b ± (1/2)sec^2(x)|tg(a)| * b^2 */
medicao tan(const medicao a){
	medicao aux;
	aux.medida = tan(a.medida);
	aux.erro = 1. / cos(a.medida);	// aux.erro = sec(a)
	aux.erro *= aux.erro * (1 + abs(tan(a.medida)) * a.erro / 2.) * a.erro;
	return aux;
}

/* arcsen(a±b) = arcsen(a) ±
 * (1/sqrt(1 - a^2)) * b ± |a/2(sqrt((1 - a^2))^3)| * b^2 =
 * arcsen(a) ± (b/sqrt(1 - a^2)) (1 + |a|b/2(1 - a^2)) */
medicao asin(const medicao a){
	double medida_2 = a.medida * a.medida;
	double erro = a.erro/sqrt(1. - medida_2);
	erro *= 1. + abs(a.medida) * a.erro / (2. - 2. * medida_2);

	return medicao(asin(a.medida), erro);
}

/* arccos(a±b) = arccos(a) ±
 * |-(1/sqrt(1 - a^2)) * b| ± |a/2(sqrt((1 - a^2))^3) * b^2| =
 * arccos(a) ± (b/sqrt(1 - a^2)) (1 + |a|b/2(1 - a^2)) */
medicao acos(const medicao a){
	double medida_2 = a.medida * a.medida;
	double erro = a.erro/sqrt(1. - medida_2);
	erro *= 1. + abs(a.medida) * a.erro / (2. - 2. * medida_2);

	return medicao(acos(a.medida), erro);
}

/* arctg(a±b) = arctg(a) ±
 * |(1/(1 + a^2))| * b ± |(a/(1 + a^2)^2)| * b^2 =
 * arctg(a) ± (b/(1 + a^2)) * (1 + |a|b/(1 + a^2)) */
medicao atan(const medicao a){
	double medida_2 = a.medida * a.medida;
	double erro = a.erro / (1. + medida_2);
	erro *= 1. + abs(a.medida) * a.erro / (1. + medida_2);

	return medicao(atan(a.medida), erro);
}

void medicao::imprime(FILE *fp){
	fprintf(fp,"(%lf ± %lf)", medida, erro);
}

medicao desvio_medio_aboluto(const double* medidas, const unsigned tam){
	double media = 0.;
	for(unsigned i = 0U; i < tam; i++)
		media += *(medidas + i);
	media /= tam;

	double desvios = 0.;
	for(unsigned i = 0U; i< tam; i++)
		desvios += abs(*(medidas + i) - media);
	desvios /= tam;

	return medicao(media, desvios);
}

medicao desvio_padrao(const double* medidas, const unsigned tam){
	double media = 0.;
	for(unsigned i = 0U; i < tam; i++)
		media += *(medidas + i);
	media /= tam;

	double desvios = 0.;
	for(unsigned i = 0U; i< tam; i++){
		double desvio = *(medidas + i) - media;
		desvios += desvio * desvio;
	}

	desvios /= tam - 1U;
	desvios = sqrt(desvios);

	return medicao(media, desvios);
}

medicao desvio_padrao_media(const double* medidas, const unsigned tam){
	double media = 0.;
	for(unsigned i = 0U; i < tam; i++)
		media += *(medidas + i);
	media /= tam;

	double desvios = 0.;
	for(unsigned i = 0U; i< tam; i++){
		double desvio = *(medidas + i) - media;
		desvios += desvio * desvio;
	}

	desvios /= tam * (tam - 1U);
	desvios = sqrt(desvios);

	return medicao(media, desvios);
}

medicao desvio_medio_aboluto_arq(FILE* fp, const unsigned col){
	long pos_arq = ftell(fp);
	unsigned cont_linhas;
	/* Conta a quantidade de \n. A quantidade de linhas é
	 * essa quantidade + 1. */
	for(cont_linhas = 0U; !feof(fp); cont_linhas++){
		fscanf(fp, "%*[\n]");
	}
	cont_linhas++;

	fseek(fp, pos_arq, SEEK_SET);
	double vet_med[cont_linhas];
	for(unsigned i = 0U; i < cont_linhas; i++){
		fscanf(fp, "%lf", vet_med + i);
		fscanf(fp, "%*f");
	}

	return desvio_medio_aboluto(vet_med, cont_linhas);
}

medicao desvio_padrao_arq(FILE* fp, const unsigned col){
	long pos_arq = ftell(fp);
	unsigned cont_linhas;
	/* Conta a quantidade de \n. A quantidade de linhas é
	 * essa quantidade + 1. */
	for(cont_linhas = 0U; !feof(fp); cont_linhas++){
		fscanf(fp, "%*[\n]");
	}
	cont_linhas++;

	fseek(fp, pos_arq, SEEK_SET);
	double vet_med[cont_linhas];
	for(unsigned i = 0U; i < cont_linhas; i++){
		fscanf(fp, "%lf", vet_med + i);
		fscanf(fp, "%*f");
	}

	return desvio_padrao(vet_med, cont_linhas);
}

medicao desvio_padrao_media_arq(FILE* fp, const unsigned col){
	long pos_arq = ftell(fp);
	unsigned cont_linhas;
	/* Conta a quantidade de \n. A quantidade de linhas é
	 * essa quantidade + 1. */
	for(cont_linhas = 0U; !feof(fp); cont_linhas++){
		fscanf(fp, "%*[\n]");
	}
	cont_linhas++;

	fseek(fp, pos_arq, SEEK_SET);
	double vet_med[cont_linhas];
	for(unsigned i = 0U; i < cont_linhas; i++){
		fscanf(fp, "%lf", vet_med + i);
		fscanf(fp, "%*f");
	}

	return desvio_padrao_media(vet_med, cont_linhas);
}

medicao desvio_medio_aboluto_arquivo(const char* nome_arq,
					const unsigned col){
	FILE *fp = fopen(nome_arq, "r");
	medicao res = desvio_medio_aboluto_arq(fp, col);
	fclose(fp);
	return res;
}

medicao desvio_padrao_arquivo(const char* nome_arq,
					const unsigned col){
	FILE *fp = fopen(nome_arq, "r");
	medicao res = desvio_padrao_arq(fp, col);
	fclose(fp);
	return res;
}

medicao desvio_padrao_media_arquivo(const char* nome_arq,
					const unsigned col){
	FILE *fp = fopen(nome_arq, "r");
	medicao res = desvio_padrao_media_arq(fp, col);
	fclose(fp);
	return res;
}

#endif /* MEDIDA_C */
