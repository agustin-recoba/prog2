TEST_DIR="./test"

correctAmount=0
incorrectAmount=0
for TEST_INPUT_NAME in ./test/*.in; do
  TEST_NAME="$(echo "$TEST_INPUT_NAME" | cut -d"/" -f3 | cut -d "." -f1)";  # for example: "mapping"
	TEST_OUTPUT_FILE="${TEST_DIR}/${TEST_NAME}.sal";                   # for example: "./test/mapping.sal"
	TEST_EXPECTED_OUTPUT_FILE="${TEST_DIR}/${TEST_NAME}.out";          # for example: "./test/mapping.out"
	./principal < "$TEST_INPUT_NAME" > "$TEST_OUTPUT_FILE";

	output="."$(echo "$fileName" | cut -d "." -f2)".out"
	diff=$(diff -y --suppress-common-lines "$TEST_EXPECTED_OUTPUT_FILE" "$TEST_OUTPUT_FILE");

	if [ -z "$diff" ]
	then
		echo "✅ $TEST_NAME OK!"
		((correctAmount+=1))
	fi

	if [ -n "$diff" ] 
	then
	  echo -e "\n"
		echo "❌ $TEST_NAME MAL!"
		echo "Mostrando salida esperada (izquierda) y salida obtenida (derecha):"
		echo "$diff"
		echo ""
		((incorrectAmount+=1))
	fi
done

echo ""
echo "Tests aprobados: $correctAmount"
echo "Tests reprobados: $incorrectAmount"