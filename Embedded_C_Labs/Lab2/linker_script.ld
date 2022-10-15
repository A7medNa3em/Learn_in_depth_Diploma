


MEMORY 
{

    flash : ORIGIN = 0x08000000, LENGTH = 128K
    sram :  ORIGIN = 0x20000000, LENGTH = 20K
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
         E_DATA = . ;

    }>sram AT> flash

    .bss : 
    {
        S_bss = . ;
        *(.bss*)
        E_bss = . ;

        . = . + 0x1000 ;

        _stack_top = . ;

    }>sram
}