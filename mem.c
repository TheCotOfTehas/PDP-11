#include "mem.h"

word mem_w[MEMSIZE];


// - пишем значение (слово) val по адресу adr;
void w_write (address adr, word val)
{
    
    // проверка, что адрес слова четный
    assert((adr & 1) == 0);
    byte last = (byte)(val & 0xFF);
    byte first = (byte)(val >> 8);

    mem_w[adr] = last;
    mem_w[adr - 1] = first;
}

// - читаем слово по адресу adr и возвращаем его;
word w_read (address adr)
{
    word last = (word)(mem_w[adr + 1] << 8);
    word first = mem_w[adr];
    word result = first | last;


    return result;
}

//пишем значение (байт) val по адресу adr;
void b_write (address adr, byte val)
{
    mem_w[adr] = val;
}

// - читаем байт по адресу adr и возвращаем его;
byte b_read (address adr)
{
    return mem_w[adr];
}