# medida
 Protótipo de biblioteca para operação com medidas reais (com erro).
 Atualmente abrange as operações básicas (`+`, `-`, `*`, `/` e `%`),
 potenciação, radiciação e as trigonométricas.  

 Foram criadas sobrecargas para os operadores e
 as funções da biblioteca math para que estas
 trabalhem corretamente com medidas que tenham um
 erro atrelado. Foi utilizada o método do cálculo
 diferencial da Teoria do Desvio Padrão com
 truncamento após o segundo termo para as
 sobrecargas das funções trigonométricas, tanto
 as diretas quanto as inversas, e trabalhou-se
 com o método das faixas de erro da Teoria do
 Desvio Máximo para as demais.  

 **Teoria do Desvio Padrão**
 Toma-se a série de Taylor da função e trunca-se
 no *n*-ésimo termo da série, de modo que temos
 o resultado da operação sendo f(a±b) = f(a) ±
 f'(a) \* b + (1/2)f''(a) \* b ^ 2.

 **Teoria do Desvio Máximo**
 Toma-se os extremos que o resultado da operação
 pode tomar, sendo o resultado a média dos dois
 valores e o erro d diferença entre os extremos
 e a média.

## Operadores

  Foram construídos todos os operadores binários
  e unários para os quais foram encontrados
  significado, tais como `+` (adição), `-`
  (subtração), `*` (multiplicação), `/`
  (divisão), `%` (erro), `++` (soma 1) e `--`
  (subtrai 1).  

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

---

## Funções de Entrada

 - `medicao desvio_medio_aboluto(const double*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio médio absoluto
 das medidas.

 - `medicao desvio_padrao(const double*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão das
 medidas.

 - `medicao desvio_padrao_media(const double*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão da média
 das medidas.

 - `medicao desvio_medio_aboluto_arq(FILE*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio médio absoluto
 das medidas da coluna especificada do arquivo enviado.

 - `medicao desvio_padrao_arq(FILE*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão das
 medidas da coluna especificada do arquivo enviado.

 - `medicao desvio_padrao_media_arq(FILE*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão da média
 das medidas da coluna especificada do arquivo enviado.

 - `medicao desvio_medio_aboluto_arquivo(const char*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio médio absoluto
 das medidas da coluna especificada do arquivo com o nome enviado.

 - `medicao desvio_padrao_arquivo(const char*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão das
 medidas da coluna especificada do arquivo com o nome enviado.

 - `medicao desvio_padrao_media_arquivo(const char*, const unsigned)`

 Cria uma variável `medicao` usando como erro o desvio padrão da média
 das medidas da coluna especificada do arquivo com o nome enviado.

---

## Funções de saída

 - `imprime(FILE*)`

  Função que faz a saída da variável no formato `(medicao±erro)` através
  do ponteiro especificado. Caso não seja enviado ponteiro, a saída é
  feita pelo `stdout`.  
