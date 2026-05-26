#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned char byte ; // 8 bit
typedef unsigned short  word ;// 16 bit
typedef word address ; // 64 Kb

void b_write (address adr, byte val); // - пишем значение (байт) val по адресу adr;
byte b_read (address adr); // - читаем байт по адресу adr и возвращаем его;
void w_write (address adr, word val); // - пишем значение (слово) val по адресу adr;
word w_read (address adr); // - читаем слово по адресу adr и возвращаем его;

int main() 
{
    return 0;
}