;------------------------------------------------------
;
;	boot.s
;
;------------------------------------------------------

; Multiboot ** magic number **
MBOOT_HEADER_MAGIC equ 0x1BADB002

; 0 4KB alignment
MBOOT_PAGE_ALIGN equ 1 << 0

; 1 tell GRUBMultiboot memory space info
MBOOT_MEM_INFO equ 1 << 1

; define Multiboot symbol
MBOOT_HEADER_FLAGS equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO

; CHECKSUM  should be unsigned 32bit 0
MBOOT_CHECKSUM equ -(MBOOT_HEADER_MAGIC+MBOOT_HEADER_FLAGS)

; -------------------------------------------------------

[BITS 32]
section .text

dd MBOOT_HEADER_MAGIC
dd MBOOT_HEADER_FLAGS
dd MBOOT_CHECKSUM

[GLOBAL start]
[GLOBAL glb_mboot_ptr]
[EXTERN kern_entry]

start:
	cli
	mov esp, STACK_TOP
	mov ebp, 0
	and esp, 0FFFFFFF0H
	mov [glb_mboot_ptr], ebx
	call kern_entry

stop:
	hlt
	jmp stop

; -------------------------------------------------------------

section .bss
stack:
	resb 32768
glb_mboot_ptr:
	resb 4
STACK_TOP equ $-stack-1

