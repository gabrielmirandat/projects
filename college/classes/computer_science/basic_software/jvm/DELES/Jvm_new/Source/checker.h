#include "core.h"

bool isFieldDescriptor(constPoolInf *, uint16_t);
bool isMethodDescriptor(constPoolInf *, uint16_t);
void verifyConstantPool(ClasseDeArquivo *);
void verifyAccessFlags(ClasseDeArquivo *);
void verifyBytecode(attribute_info *, ClasseDeArquivo *);
void verifyClassfile(ClasseDeArquivo *);
void verifySuperFinal(ClasseDeArquivo *, JVM *);
void verifyOverrideMethodFinal(ClasseDeArquivo *, JVM *);
