Universal Turing Machine (UTM)
=========================

This is a simple implementation of the Universal Turing Machine. An input sample can be seen at tm.in.

This work is developed in the Theory of Computation's class.

Federal University of Santa Maria

Authors:

tengel@inf.ufsm.br

voliveira@inf.ufsm.br



DESCRIÇÃO (PT-BR):
A entrada começa com 4 números indicando o número de estados, o número de símbolos no alfabeto de entrada, o número de símbolos no alfabeto de fita e o número de transições, respectivamente. 
Após todas as transições segue uma linha com um dos seguintes caracteres: 
-R (reconhecedora de Linguagens)
-P (processadora de funções)
Na sequência segue o número, n, de casos de testes. Nas seguintes n linhas, seguem os testes. A saída para essa entrada deve ser como no exemplo (tm.out). 
Isto é, para cada caso de teste, a máquina deve imprimir no arquivo de saída, aceita ou rejeita, no caso de máquina reconhecedora de linguagens. No caso de máquina processadora de funções, 
a máquina deve imprimir, o conteúdo final da fita para cada caso de teste. Um em cada linha do arquivo de saída.


DESCRIÇÃO (EN):
The input begins with 4 numbers indicating the number of states, the number of symbols of the input alphabet, 
the number of symbol of the tape alphabet, and the number of transitions, respectively.
After the transitions, follows on char:
-R (languages recognizer)
-P (function processor)
In the sequence, follows a number of test cases.
The output must be given as in the example (tm.out)
That is, for each test case, the machine must press in the output file "accept" or "reject", in the case 
of the language recognizer. In the function processor, the machine must press the final content of the tape.
