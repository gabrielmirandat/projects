// validador de estruturas
#include "jvm.h"

bool isFieldDescriptor(constant_pool_info *, uint16_t);
bool isMethodDescriptor(constant_pool_info *, uint16_t);
void verifyConstantPool(ClassFile *);
void verifyAccessFlags(ClassFile *);
void verifyBytecode(attribute_info *, ClassFile *);
void verifyClassfile(ClassFile *);
void verifySuperFinal(ClassFile *, JVM *);
void verifyOverrideMethodFinal(ClassFile *, JVM *);
