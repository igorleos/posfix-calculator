#!/bin/bash

function compile_parser {
    gcc -Wall -Wextra -std=c11 -c Lista.c -g

    gcc -Wall -Wextra -std=c11 -c Pilha.c -g

    gcc -Wall -Wextra -std=c11 -c PosfixParser.c -g

    gcc -Wall -Wextra -std=c11 -c RunParser.c -g

    gcc Lista.o Pilha.o PosfixParser.o RunParser.o -g
}

function parse {
    gcc -Wall -Wextra -std=c11 -c Lista.c -g

    gcc -Wall -Wextra -std=c11 -c Pilha.c -g

    gcc -Wall -Wextra -std=c11 -c PosfixParser.c -g

    gcc -Wall -Wextra -std=c11 -c RunParser.c -g

    gcc Lista.o Pilha.o PosfixParser.o RunParser.o -g

    echo -e "\n\n\n\n\n\n\n\n====================";

    if [[ "$OSTYPE" == "linux-gnu"* || "$OSTYPE" == "darwin"* ]]
    then
        if [ -z "$1" -a "$1" != " " ]
        then
            ./a.out
        else
            ./a.out "$1"
        fi
    elif [[ "$OSTYPE" == "cygwin" || "$OSTYPE" == "msys" ]]; then
        ./a.exe "$1"
    else
      echo "Sistema nao indentificado, rode manualmente o executavel 'a.out/a.exe'"
    fi
}





