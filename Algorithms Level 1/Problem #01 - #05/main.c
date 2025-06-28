#include <stdio.h>
#include <setjmp.h>

// extern olarak tanımlı hata mesajı ve fonksiyonlar
extern jmp_buf ex_buf;
extern char* ex_message;
void ParaCek(int);
void ParaYatir(int);

int main(void) {
    if (setjmp(ex_buf) == 0) {
        // try
        ParaCek(100);
        ParaYatir(-1);
    } else {
        // catch
        printf("%s\n", ex_message);
    }
    return 0;
}
