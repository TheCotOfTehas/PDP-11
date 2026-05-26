#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//Основные команды их бы в отдельный файл запихнуть
void HLT();
void ADD(uint8_t *, uint8_t *);
void SUB(uint8_t *, uint8_t *);
void MOV(uint8_t *, uint8_t );
void IR();

//Команды обёртки для масива функций CPU
void wrap_ADD(void);
void wrap_SUB(void);
void wrap_MOV(void);

void readerCommand(void);
bool stop = false; //влаг для остановки программы
uint8_t ram[4]; 
void (*cpu[5])(void);

int main() 
{
    cpu[0] = HLT;
    cpu[1] = wrap_ADD;
    cpu[2] = wrap_SUB;
    cpu[3] = wrap_MOV;
    cpu[4] = IR;

    while (!stop)
        readerCommand();
    
    return 0;
}



void readerCommand(void)
{
    int command;
    scanf("%d", &command);
    if (command >= 0 && command < 5)
        cpu[command]();
    else
        printf("Выход За диапазонн комманд\n");
}

void HLT()
{
    stop = true;
}

void IR()
{
    for (size_t i = 0; i < 4; i++)
        printf("%d ", ram[i]); 

    printf("\n");
}

void ADD(uint8_t * a, uint8_t * b)
{
    *a =  *a + *b;  
}

void wrap_ADD(void)
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
    a -= 5;
    b -= 5;
    ADD(&ram[a], &ram[b]);
}

void SUB(uint8_t * a, uint8_t * b)
{
    *a =  *a - *b;  
}

void wrap_SUB(void)
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
    a -= 5;
    b -= 5;
    SUB(&ram[a], &ram[b]);
}

void MOV(uint8_t * a, uint8_t b)
{
    *a = b;
}

void wrap_MOV(void)
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
    a -= 5;
    MOV(&ram[a], b);
}