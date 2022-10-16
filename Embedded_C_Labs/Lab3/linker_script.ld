/**
 ******************************************************************************
 * @file           : Linker Script 
 * @author         : Ahmed Naeem
 * @brief          : Linker Script 
 ******************************************************************************

 */
MEMORY 
{

    flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata*)

        E_TEXT = . ;

    }>flash

    .data :
    {
        S_DATA = . ;
        *(.data*)
        . =  ALIGN(4);
         E_DATA = . ;

    }>sram AT> flash

    .bss : 
    {
        S_bss = . ;
        *(.bss*)
        E_bss = . ;   

    }>sram
}