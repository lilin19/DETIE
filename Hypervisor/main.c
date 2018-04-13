#include <stdint.h>
#include <msp430.h> 

/**
 * main.c
 */
extern void HyperV();

int main(int x )
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

 HyperV();
 asm("MOV 4(r3), r5");




	/** if ((pc & 0x4c00) == 0x4c00) {
	    uint16_t op = pc & 0x000f;
	    op = (op<<8);
	    op = op ^ 0x4004;
	    uint16_t back = 0x4e00;
	    asm(" MOV r0, R14,  \n\t"
	            " Add #8, R14,  \n\t"
	           // "MOV %1, @2(%0),  \n\t"
	              "BR %0,  \n\t"
	                : :"r"(&op),"r"(back):"R14","R15");
	}

	for (;i < 7;) {}

	return pc;
**/

}
