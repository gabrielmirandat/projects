|  - métodos que tem
-> - chama método 
*  - o que faz

main
| -
-> startJVM
	

jvm
| startJVM
| tem um monte de estruturas
* inicia só o leitor exibidor ou a jvm
| carregarClasse_01
	-> 'leitor_eibidor'
	-> 'checker'
| classLinkingVerification
	-> 'checker'
| executeMethod
	-> 'interpreter'
| freeClassData
	-> 'leitor_exibidor'

interpreter
| interpreter
| impĺementação de altos upcodes
* executa as instruções dos opcodes
* inicia func com altas funcoes
| Tconst, Tipush
	-> 'so coisas de pilha da jvm'
| accessField
	-> 'altas funcoes da jvm'
| handleObject
	-> 'tem leitor_exibidor(constPoolInf) e altas jvm'

checker
* valida as estruturas
| isMethodDescriptor
	-> 'leitor_exibidor'
| verifyClassfile
	-> 'leitor_exibidor'

leitor_exibidor
* le e exibe classfile 
| so se chama