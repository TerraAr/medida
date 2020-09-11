# medida
 Protótipo de biblioteca para operação com medidas reais (com erro).
 Atualmente abrange as operações básicas (`+`, `-`, `*`, `/` e `%`),
 potenciação, radiciação e as trigonométricas.  

## Operadores

  Foram construídos todos os operadores binários e unários para os
  quais foram encontrados significado, tais como `+` (adição),
  `-` (subtração), `*` (multiplicação), `/` (divisão), `%` (erro), `++`
  (soma 1) e `--` (subtrai 1).  

 - `+`

 - `-`

 - `*`

 - `/`

 - `%`

 - `+`

 - `-`

 - `++`

 - `--`

 - `+=`

 - `-=`

 - `\=`

 - `/=`

---

## Funções matemáticas

  Foram criadas sobrecargas para as funções da
  biblioteca math para que estas trabalhem
  corretamente com medidas que tenham um erro
  atrelado. Foi utilizada a Teoria do Desvio
  Máximo para as sobrecargas das funções
  trigonométricas, tanto as diretas quanto as
  inversas, e trabalhou-se com o desenvolvimento
  pela faixa de erro\* para as demais.  

 - `pow(medida, medida)`

 - `pow(medida, double)`

 - `pow(double, medida)`

 - `sqrt(medida)`

 - `cbrt(medida)`

 - `exp(medida)`

 - `log(medida)`

 - `sin(medida)`

 - `cos(medida)`

 - `tan(medida)`

 - `asin(medida)`

 - `acos(medida)`

 - `atan(medida)`

 \* Desenvolvimento pela faixa de erro: f(x±dx) = (MAX + MIN)/2 ± (MAX - MIN)/2
 com as possíveis simplificações para cada função, de acordo com suas
 propriedades.  

---

## Funções de entrada

---

## Funções de saída

 - `imprime(FILE*)`
  Função que faz a saída da variável no formato `(medicao±erro)` através
  do ponteiro especificado. Caso não seja enviado ponteiro, a saída é
  feita pelo `stdout`.  
