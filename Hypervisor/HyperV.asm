;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------

.extern HyperV2,main,hyperV_core, justif, enter

.global HyperV, Test, reg_set, set1, set2, comp, compare, enter

.data
;-------------------------------------------------------------------------------

.text                           ; Assemble into program memory.



;-------------------------------------------------------------------------------

HyperV:
            mov.w   R12,   reg_set
            mov.w   #reg_set,   R12
            mov.w   R1,   2(R12)
            mov.w   R2,   4(R12)
            mov.w   R3,   6(R12)
            mov.w   R4,   8(R12)
            mov.w   R5,   10(R12)
            mov.w   R6,   12(R12)
            mov.w   R7,   14(R12)
            mov.w   R8,   16(R12)
            mov.w   R9,   18(R12)
            mov.w   R10,  20(R12)
            mov.w   R11,  22(R12)
            mov.w   R13,  26(R12)
            mov.w   R14,  28(R12)
            mov.w   R15,  30(R12)
            mov.w   reg_set, R12
            mov.w   R12, 24(R12)

            call    #hyperV2;

set1:
            mov.w #reg_set, R12
            mov.w 2(R12), R1
            mov.w 4(R12), R2
            mov.w 6(R12), R3

            mov.w 10(R12), R5
            mov.w 12(R12), R6
            mov.w 14(R12), R7
            mov.w 16(R12), R8
            mov.w 18(R12), R9
            mov.w 20(R12), R10
            mov.w 22(R12), R11
            mov.w 26(R12), R13
            mov.w 28(R12), R14
            mov.w 30(R12), R15
            mov.w 24(R12), R12
            add.w  #2,  0(SP)
            ret
set2:
            mov.w #reg_set, R12
            mov.w 2(R12), R1
            mov.w 4(R12), R2
            mov.w 6(R12), R3

            mov.w 10(R12), R5
            mov.w 12(R12), R6
            mov.w 14(R12), R7
            mov.w 16(R12), R8
            mov.w 18(R12), R9
            mov.w 20(R12), R10
            mov.w 22(R12), R11
            mov.w 26(R12), R13
            mov.w 28(R12), R14
            mov.w 30(R12), R15
            mov.w 24(R12), R12
            add.w  #4,  0(SP)
            push   @R12
            ret

compare:   calla #comp
           mov.w  R4, R12
           calla #justif
           ret



            ;


