#include "library.h"

#define INTERPRETADOR   "gcc -o interpretador interpretador.c"
#define ACRESCENTA      "gcc -o acrescenta acrescenta.c"
#define APAGA           "gcc -o apaga apaga.c"
#define CONTA           "gcc -o conta conta.c"
#define INFORMA         "gcc -o informa informa.c"
#define LISTA           "gcc -o lista lista.c"
#define MOSTRA          "gcc -o mostra mostra.c"

int main(int argc, char const *argv[])
{
    system(INTERPRETADOR);
    system(ACRESCENTA);
    system(APAGA);
    system(CONTA);
    system(INFORMA);
    system(LISTA);
    system(MOSTRA);

    return 0;
}
