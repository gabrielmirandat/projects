//g++ -std=c++11 trab_v3.cpp -o trab3
//endereco maximo = (256*4) - 1 = 1023

#include <iostream>
#include<cstdint>

#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif

using namespace std;

int lb(uint32_t, uint16_t);
int16_t lh(uint32_t, uint16_t);
int32_t lw(uint32_t, uint16_t);
void sb(uint32_t, uint16_t, int);
void sh(uint32_t, uint16_t, int16_t);
void sw(uint32_t, uint16_t, int32_t);
