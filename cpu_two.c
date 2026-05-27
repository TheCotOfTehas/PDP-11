#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#define MEMSIZE (1024 * 64)

typedef unsigned char byte ; // 8 bit
typedef unsigned short  word ;// 16 bit
typedef word address ; // 64 Kb


void b_write (address adr, byte val); // - пишем значение (байт) val по адресу adr;
byte b_read (address adr); // - читаем байт по адресу adr и возвращаем его;
void w_write (address adr, word val); // - пишем значение (слово) val по адресу adr;
word w_read (address adr); // - читаем слово по адресу adr и возвращаем его;

byte mem_b[MEMSIZE];
word mem_w[MEMSIZE];

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

// Запись слова val по адресу adr
void w_write (address adr, word val)
{
    // проверка, что адрес слова четный
    assert((adr & 1) == 0);
    mem_w[adr] = val;
}

// Возвращает слово по адресу adr
word w_read (address adr)
{
    return adr % 2 == 0 ? mem_w[adr] : (byte)(mem_w[adr - 1] >> 8);
}

void b_write (address adr, byte val)
{
    mem_b[adr] = val;
}
byte b_read (address adr)
{
    return mem_b[adr];
}