#!/bin/bash

function link_files {
    gcc -Wall -Wextra -std=c11 -c Lista.c -g

    gcc -Wall -Wextra -std=c11 -c Pilha.c -g

    gcc -Wall -Wextra -std=c11 -c PosfixParser.c -g

    gcc -Wall -Wextra -std=c11 -c PosfixCalculator.c -g

    gcc -Wall -Wextra -std=c11 -c RunParser.c -g

    gcc -Wall -Wextra -std=c11 -c RunCalculator.c -g
}

function compile_parser {
    gcc Lista.o Pilha.o PosfixParser.o RunParser.o -g
}

function compile_calculator {
    gcc Lista.o Pilha.o PosfixCalculator.o RunCalculator.o -g
}

function run_code {

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

function parse {
    link_files
    compile_parser
    run_code "$1"
}

function calculate {
    link_files
    compile_calculator
    run_code "$1"
}




