;makes adjustments to load 0x7c00 addsress (i.e. boot sector address)
[org 0x7c00]

[bits 16] ; initialize(produces) 16 bit opcodes for further instructions to execute

;BOOT LOADER

;Memory offset to which kernel will be loaded
mov bx , 0x1000
;Bios read sector function
mov ah , 0x02
;No. of sectors to read 
mov al , 30
;select cylinder 0 from harddisk
mov ch , 0x00
;select head 0 from hard disk
mov dh , 0x00
;start reading from second selector( Sector just after boot sector)
mov cl , 0x02

;Bios Interrupt relating to disk functions
int 0x13


;SWITCH TO PROTECTED MODE
; turns interrupts switch off
cli
;load GDT and describe GDT
lgdt [GDT_DESC] ;loads GDT

;switch to protected mode
mov eax, cr0
or eax , 0x1
mov cr0, eax

;Jump to 32 bit code and forces CPU to flush cache memory contents
jmp CODE_SEG:INIT_PM

[bits 32]

INIT_PM:
mov ax , DATA_SEG
mov ds , ax
mov ss , ax
mov es , ax
mov fs , ax
mov gs , ax

;update stack segment
mov ebp , 0x90000
mov esp , ebp

call 0x1000
jmp $

GDT_BEGIN:

;The mandatory null descriptor
GDT_NULL_DESC:
     dd 0x0
     dd 0x0

GDT_CODE_SEG:
     dw 0xffff
     dw 0x0
     db 0x0
     db 10011010b
     db 11001111b
     db 0x0

GDT_DATA_SEG:
     dw 0xffff
     dw 0x0
     db 0x0
     db 10010010b
     db 11001111b
     db 0x0

GDT_END:

GDT_DESC:
     dw GDT_END - GDT_BEGIN - 1
     dd GDT_BEGIN

CODE_SEG equ GDT_CODE_SEG - GDT_BEGIN
DATA_SEG equ GDT_DATA_SEG - GDT_BEGIN

times 510-($-$$) db 0
dw 0xaa55