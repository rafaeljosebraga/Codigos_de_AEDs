gcc -Wall -pedantic -g polinomio.c -o compilado
mkdir meu_saidas
for((s=1;s<7;s++)) do
echo Caso $s:;
./compilado<ins/$s.in>meu_saidas/$s.out
diff meu_saidas/$s.out ins/$s.out
done;
