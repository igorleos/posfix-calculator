#!/bin/bash
function compile {
    gcc -Wall -Wextra -std=c11 -c Lista.c -g

    gcc -Wall -Wextra -std=c11 -c Pilha.c -g

    gcc -Wall -Wextra -std=c11 -c ConvertInfix.c -g


    gcc Lista.o Pilha.o ConvertInfix.o  -g
    


}
#Para executar digite no terminal:
#       source compilar.sh
#       compile
#       run

function run {
    echo -e "\n\n\n\n\n\n\n\n====================";
    # if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    #     ./a.out
    # elif [[ "$OSTYPE" == "darwin"* ]]; then
    #     ./a.out
    # elif [[ "$OSTYPE" == "cygwin" ]]; then
        ./a.exe
    # elif [[ "$OSTYPE" == "msys" ]]; then
        # ./a.exe
    # else
    #   echo "Sistema nao indentificado, rode manualmente o executavel 'a.out/a.exe'"
    # fi
}





