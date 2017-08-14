"https://pt.wikipedia.org/wiki/Clang"
Clang é um front-end de um compilador para as linguagens C, C++, Objective-C e Objective-C++ que utiliza 
o LLVM como back-end desde a versão 2.6 do LLVM. Tem como objetivo oferecer um substituto open source ao 
GCC, o conjunto de compiladores da GNU.

"http://clang.llvm.org/get_started.html"
$ cat t.c
#include <stdio.h>
int main(int argc, char **argv) { printf("hello world\n"); }
$ clang t.c
$ ./a.out
hello world

"https://llvm.org/svn/llvm-project/cfe/branches/release_33/www/cxx_status.html"
Clang atualmente implementa todo o padrão ISO C++ 1998 (incluindo os defeitos abordados na padrão ISO C++ 2003)
e é considerado um compilador de qualidade de produção C++.

Por padrão, Clang compila código C++ de acordo com o padrão C++ 98, com muitos recursos C++ 11 aceitos como 
extensões. Você pode usar Clang no modo C++11 com o -std = c++11 opção. Modo C++11 de Clang pode ser usado com
libc++ ou com libstdc do gcc++ , mas os patches são necessários para fazer libstdc++-4.4 trabalho com Clang no 
modo C++11.

"http://clang-analyzer.llvm.org/"
O analisador estático CLang é uma ferramenta de análise de código fonte para encontrar erros em C, C++ e Objective-C, 
sendo totalmente open source.

"http://stackoverflow.com/questions/14072779/how-can-i-run-gcc-clang-for-static-analysis-warnings-only"
Tanto GCC quanto CLang tem a opção -fsyntax-only que faz o compilador apenas checar a sintaxe sem compilar os fontes.


"http://baptiste-wicht.com/posts/2014/04/install-use-clang-static-analyzer-cmake.html"
se esta compilando assim
clang [clang-options] source_file.cpp
você faz análise estática assim
scan-build [scan-build-options] clang [clang-options] source_file.cpp
scan-build funciona substituindo chamadas ao compilador por chamadas ao ccc-analyzer

"https://github.com/scrooloose/syntastic/issues/512"
I found out today that clang has a static analyzer that you can call with clang --analyze which 
tries to find errors not found with -fsyntax-only including:

    array bounds
    unread variables
    memory leaks

full list here

"http://clang-analyzer.llvm.org/available_checks.html"
Exemplos de erros encontrados com clang

// divisão por zero
int main() {
  int z=0;

  int x = 1 / z; // warn

  return 0;
}

Com: gcc clang_test.c -o test, normal
Com: clang-3.8 --analyze clang_test.c -o test
clang_test.c:25:7: warning: Value stored to 'x' during its initialization is never read
  int x = 1 / z; // warn
      ^   ~~~~~
clang_test.c:25:13: warning: Division by zero
  int x = 1 / z; // warn
          ~~^~~
2 warnings generated.


// expressão não inicializada
int main() {
  int x;
  x |= 1; // warn: left expression is unitialized

  return 0;
}

Com: gcc clang_test.c -o test, normal
Com: clang-3.8 --analyze clang_test.c -o test

clang_test.c:24:3: warning: Value stored to 'x' is never read
  x |= 1; // warn: left expression is unitialized
  ^    ~
clang_test.c:24:5: warning: The left expression of the compound assignment is an uninitialized value. The computed value will also be garbage
  x |= 1; // warn: left expression is unitialized
  ~ ^
2 warnings generated.


"http://stackoverflow.com/questions/3455157/example-code-to-trigger-clangs-static-analyser"
TESTADO

11	struct elem {
12	  struct elem *prev;
13	  struct elem *next;
14	};
15
16	#define ELEM_INITIALIZER(NAME) { .prev = &(NAME), .next = &(NAME), }
17
18	struct head {
19	  struct elem header;
20	};
21
22	#define HEAD_INITIALIZER(NAME) { .header = ELEM_INITIALIZER(NAME.header) }
23
24	int main(int argc, char ** argv) {
25  	struct head myhead = HEAD_INITIALIZER(myhead);
26	}

O exemplo contém um erro não detectado nem com -Wall
Implementação de lista encadeada.
A variável myhead não é utilizada no senso comum da aplicação, mas para o compilador ela é sim utilizada
já que dentro do inicializador o endereço de um campo é tomado.

Com: gcc clang_test.c -o test, compila normalmente.
Com: clang-3.8 -fsyntax-only clang_test.c -o test, vai normalmente.
Com: clang-3.8 --analyze clang_test.c -o test
clang_test.c:25:14: warning: Value stored to 'myhead' during its initialization is never read
        struct head myhead = HEAD_INITIALIZER(myhead);
                    ^~~~~~   ~~~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.

"http://doc.qt.io/qtcreator/creator-clang-static-analyzer.html"
TESTADO

1 #include <iostream>

3 namespace n6
  {
    void f(int*) {}

    void useAfterDelete(int* p){
      delete p;
9     f(p); //warn: use after free
    }
  }

  int main()
  {
    using namespace n6;
  
    int* value;
    testUseMiddleArgAfterDelete(value); 
  }

Com: g++ clang_test.cc -o test, compila normalmente
Com: clang++-3.8 --analyze clang_test.cc -o test

clang_test.cc:9:3: warning: Use of memory after it is freed
                f(p); //warn: use after free
                ^~~~
clang_test.cc:18:2: warning: Function call argument is an uninitialized value
        testUseMiddleArgAfterDelete(value);
        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2 warnings generated.

"exemplo proprio"
TESTADO

1 #include <stdio.h>

3 int main()
4 {
5 	int vector[10];
6 	vector[12] = 2;

8 	return 0;
9 }


Com: gcc clang_test.c -o test, compila normalmente
Com: clang-3.8 -fsyntax-only clang_test.c -o test

clang_test.c:6:2: warning: array index 12 is past the end of the array (which contains 10 elements) [-Warray-bounds]
        vector[12] = 2;
        ^      ~~
clang_test.c:5:2: note: array 'vector' declared here
        int vector[10];
        ^
1 warning generated.







