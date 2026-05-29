#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define MEMSIZE (1024 * 64)

typedef unsigned char byte;
typedef unsigned short word;
typedef word address;

void w_write(address adr, word val);
word w_read(address adr);
void b_write(address adr, byte val);
byte b_read(address adr);

#endif