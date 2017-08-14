'objetivo'

- implementar resolvedor de expressões (com notação polonesa reversa) baseado em máquina de pilha
- parâmetros entram por notação infixada (polonesa normal) com ou sem parêntesis

nota 
- conversão notação infixa para posfixa
- corretude 
- 4 operações em aritmética estendida
- passagem de parâmetros
- documentação (descrever armazenamento dos números, dependência de arquitetura, descrição, ..)


'notação polonesa (prefixada ou  prefix notation)'
+ 3 4
"vai andando na esquerda até achar o padrão operador operando operando p/ resolver"
((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1))

pseudocodigo
// pode ser da esquerda pra direita, muda um pouquinho
Scan the given prefix expression from right to left
for each symbol
 {
  if operand then
    push onto stack
  if operator then
   {
    operand1=pop stack
    operand2=pop stack
    compute operand1 operator operand2
    push result onto stack
   }
 }
return top of stack as result

'notação infixa (normal conhecida)'
3+4

'notação polonesa reversa (posfixada ou pofix notation)'
3 4 +
5 1 2 + 4 * + 3 -

pseudocodigo
While there are input tokens left
    Read the next token from input.
    If the token is a value
        Push it onto the stack.
    Otherwise, the token is an operator (operator here includes both operators and functions).
        It is already known that the operator takes n arguments.
        If there are fewer than n values on the stack
            (Error) The user has not input sufficient values in the expression.
        Else, Pop the top n values from the stack.
        Evaluate the operator, with the values as arguments.
        Push the returned results, if any, back onto the stack.
If there is only one value in the stack
    That value is the result of the calculation.
Otherwise, there are more values in the stack
    (Error) The user input has too many values.


http://www.paulgriffiths.net/program/c/calc1.php
programa de auxilio: http://www.c4learn.com/data-structure/c-program-convert-infix-expression-to-postfix-using-stack/

Não tem parêntesis e nem regras de precedência em notação posfixa

"converting infix to postfix"
The first thing we do in our calculator therefore, is to convert the input infix expression 
into a postfix expression. We do this in the following steps:

    xCreate a stack data structure to temporarily store operators;
    xRead through the infix expression one token at a time from left to right;
    xOutput an operand as soon as we come to one (operands always appear in the same order, whether we are 
    	using an infix, a postfix, or a prefix expression);
    When we come to an operator, if it has a higher precedence than the operator currently on the top of 
    	the stack, then add it to the stack;
    If the operator has a lower precedence than the operator on top of the stack, then remove operators 
    	from the stack one at a time until we run out, or until we come to an operator with a higher precedence.
    When we run out of input, output any remaining operators still in the stack

Evaluation
"evaluation"
Once we have our postfix expression, evaluating it is fairly simple:

    Create a stack, this time to hold the operands;
    Read through the input from left to right;
    If we find an operand, add it to the stack;
    If we find an operator, remove the last two operands from the stack, perform the operation, and add the value
    	back to the stack;
    At the end of the input, the one remaining value on the stack is the result of our expression.

EXEMPLO
"infixo"   (3 + 4) * 4 / 2	//14
"posfixo"  3 4 + 4 * 2 /
		   
		   (10 + 4) * 4 / 2	//28
		   10 4 + 4 * 2 /





http://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
implementação infixo para posfixo em python


Create an empty stack called opstack for keeping operators. Create an empty list for output.
Convert the input infix string to a list by using the string method split.
Scan the token list from left to right.
    If the token is an operand, append it to the end of the output list.
    If the token is a left parenthesis, push it on the opstack.
    If the token is a right parenthesis, pop the opstack until the corresponding left parenthesis is removed. Append each operator to the end of the output list.
    If the token is an operator, *, /, +, or -, push it on the opstack. However, first remove any operators already on the opstack that have higher or equal precedence and append them to the output list.
When the input expression has been completely processed, check the opstack. Any operators still on the stack can be removed and appended to the end of the output list.

for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixList.append(token)
        elif token == '(':
            opStack.push(token)
        elif token == ')':
            topToken = opStack.pop()
            while topToken != '(':
                postfixList.append(topToken)
                topToken = opStack.pop()
        else:
            while (not opStack.isEmpty()) and (prec[opStack.peek()] >= prec[token]):
                  postfixList.append(opStack.pop())
            opStack.push(token)

    while not opStack.isEmpty():
        postfixList.append(opStack.pop())
    return " ".join(postfixList)

evaluacao


Create an empty stack called operandStack.
Convert the string to a list by using the string method split.
Scan the token list from left to right.
    If the token is an operand, convert it from a string to an integer and push the value onto the operandStack.
    If the token is an operator, *, /, +, or -, it will need two operands. Pop the operandStack twice. The first pop 
    	is the second operand and the second pop is the first operand. Perform the arithmetic operation. Push the 
    	result back on the operandStack.
When the input expression has been completely processed, the result is on the stack. Pop the operandStack and return the value.

operandStack = Stack()
    tokenList = postfixExpr.split()

    for token in tokenList:
        if token in "0123456789":
            operandStack.push(int(token))
        else:
            operand2 = operandStack.pop()
            operand1 = operandStack.pop()
            result = doMath(token,operand1,operand2)
            operandStack.push(result)
    return operandStack.pop()
