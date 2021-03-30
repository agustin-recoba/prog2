#!/bin/bash

TEST_DIR="./test"

RUNNABLE="./principal"

if [ "$1" == "--valgrind" ]
then
  RUNNABLE="timeout --preserve-status 4 valgrind --error-exitcode=52 -q --leak-check=full $RUNNABLE"
fi

if ! [ -d "$TEST_DIR" ]
then
  echo "❌ No pudo encontrarse el directorio './test'. Terminando script."
  exit
fi

if ! [[ -f "./principal" ]]
then
  echo "❌ No pudo encontrarse el ejecutable './principal'. Terminando script."
  exit
fi

if ! [[ -x "./principal" ]]
then
  echo "❌ './principal' no es un archivo ejecutable. Terminando script."
  exit
fi

correctAmount=0
incorrectAmount=0

for TEST_INPUT_NAME in ./test/*.in; do
  TEST_NAME="$(echo "$TEST_INPUT_NAME" | cut -d"/" -f3 | cut -d "." -f1)"   # for example: "mapping"
  TEST_OUTPUT_FILE="${TEST_DIR}/${TEST_NAME}.sal"                           # for example: "./test/mapping.sal"
  TEST_EXPECTED_OUTPUT_FILE="${TEST_DIR}/${TEST_NAME}.out"                  # for example: "./test/mapping.out"

  $RUNNABLE < "$TEST_INPUT_NAME" > "$TEST_OUTPUT_FILE"
  
  exitcode="$?"
  if [ "$exitcode" -eq 52 ]
  then
    echo "❌ $TEST_NAME MAL!"
    echo "❌ Posible error con el manejo de memoria encontrado mientras ejecutamos el test \"$TEST_INPUT_NAME\"! (leer output de valgrind)"
    exit
  elif [ "$exitcode" -ne 0 ]
  then
    echo "❌ $TEST_NAME MAL!"
    echo "❌ El programa terminó con el exit code $exitcode mientras ejecutaba el test \"$TEST_INPUT_NAME\""
    exit
  fi

  output="."$(echo "$fileName" | cut -d "." -f2)".out"
  diff=$(diff -y --suppress-common-lines "$TEST_EXPECTED_OUTPUT_FILE" "$TEST_OUTPUT_FILE")

  if [ -z "$diff" ]
  then
    echo "✅ $TEST_NAME OK!"
    ((correctAmount+=1))
  fi

  if [ -n "$diff" ]
  then
    echo -e "\n"
    echo "❌ $TEST_NAME MAL!"
    ((incorrectAmount+=1))
    echo "Mostrando salida esperada (izquierda) y salida obtenida (derecha):"
    echo "$diff"
    echo ""
  fi

done

echo ""

if [ "$1" == "--valgrind" ]
then
  echo "❗ Test de memoria con valgrind realizado."  
else
  echo "❗ Para realizar el test de memoria con valgrind, ejecuta el script de la siguiente manera:"
  echo "❗ './tester.sh --valgrind'"
fi

echo ""
echo "Tests aprobados: $correctAmount"
echo "Tests reprobados: $incorrectAmount"
echo ""
echo "Autor: github.com/pragmare ✨"