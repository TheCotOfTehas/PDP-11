#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "mem.c"

int main() 
{
    address a;
    byte b0, b1, bres;
    word w, wres;

    //пишем байт, читаем байт
    fprintf(stderr, "Пишем и читаем байт по чётному адресу\n");
    a = 0;
    b0 = 0x12;
    b_write(a, b0);
    bres = b_read(a); 
    //ту полезно написать отладочную печать a, b0 ,bres
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    assert(b0 == bres);
    //анологично стоит проверить чтение и запись по нечетному адресу
    

    //пишем 2 байта, читаем 1 слово
    fprintf(stderr, "Пишем 2 байта, читаем слово\n");
    a = 4; // другой аддрес
    w = 0xa1b2;
    //little-endian, младшие разряды по меньшему адресу
    b0 = 0xb2;
    b1 = 0xa1;
    b_write(a, b0);
    b_write(a+1, b1);
    wres = w_read(a);
    //тут полезно написать отладочную печать a, w, wres
    fprintf(stderr, "a=%06o b1=%02hhx bo=%02hhx wres=%04x\n", a, b1, b0, wres);
    assert(w == wres);

    int adr = 2;
    word w2 = 'A';

    w_write(adr, w2);
    word w_res = w_read(adr);
    printf("%c == %c ответ %s\n", (char)w2, (char)w_res, w2 == w_res ? "Правда" : "Лож");

    return 0;
}