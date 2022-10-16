
/**
 ******************************************************************************
 * @file           : startup.c
 * @author         : Ahmed Naeem
 * @brief          : Startup code
 ******************************************************************************

 */

#include <stdint.h>

extern void main();

void _reset_handler();

extern uint32_t S_DATA;
extern uint32_t E_DATA;
extern uint32_t E_TEXT;
extern uint32_t E_bss;
extern uint32_t S_bss;

/* uninilized array of size 1024 byteslocated in bss section in ram used for stacktop*/
static uint32_t stack_top[256];

/* Vectors Symbols*/
void NMI_Handler(void) __attribute__((weak, alias("Default_handler")));
;
void H_Fault_Handler(void) __attribute__((weak, alias("Default_handler")));
;
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_handler")));
;
void Bus_Fault_Handler(void) __attribute__((weak, alias("Default_handler")));
;
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_handler")));
;

/* Defualt handeler >> alias*/
void Default_handler()
{
    _reset_handler();
}

/*.vector section as array of pointers to functions*/
void (*const g_pvectors[])() __attribute__((section(".vectors"))) =
    {
        /*Stack pointer*/
        (void (*)())((uint32_t)stack_top + sizeof(stack_top)),
        &_reset_handler,
        &NMI_Handler,
        &MM_Fault_Handler,
        &Bus_Fault_Handler,
        &Usage_Fault_Handler};

/* reset handler call main*/
void _reset_handler()
{
    /* Copy .data section from Flash to RAM*/
    unsigned int _DATA_size = (unsigned char *)&E_DATA - (unsigned char *)&S_DATA;
    unsigned char *P_src = (unsigned char *)&E_TEXT;
    unsigned char *P_dst = (unsigned char *)&S_DATA;
    int i = 0;
    for (i = 0; i < _DATA_size; i++)
    {
        *((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
    }

    /* init .bss section in RAM by 0*/
    unsigned int _bss_size = (unsigned char *)&E_bss - (unsigned char *)&S_bss;
    P_dst = (unsigned char *)&S_bss;

    for (i = 0; i < _DATA_size; i++)
    {
        *((unsigned char *)P_dst++) = (unsigned char)0;
    }

    /* Jump to main*/
    main();
}