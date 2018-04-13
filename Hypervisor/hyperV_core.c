/*
 * hyperV_core.c
 *
 *  Created on: 9 Nov 2017
 *      Author: tg
 */

#include <msp430.h>
#include <stdint.h>

volatile uint16_t reg_set[16];
volatile uint16_t *oldPC;
volatile uint16_t *c;

uint16_t ad;
uint16_t op;
extern void set1();
extern void set2();
extern void compare();
uint16_t ex[3];
uint16_t comp[4];

void hyperV2(){

    c = reg_set[1]; //stack pointer
    oldPC = *c;    //return address of function call

    //the instruction in the return address
    ad = *oldPC; //for addressing mode
    op = *oldPC; //for op code

    ex[0] = *oldPC;  //for translation

    ad=ad>>4;

    op = op>>8;

if(op == 0x0042){
        if((ad & 0x0003)==0x0001){
            //for instruction emulation
                            ex[0] = ex[0]<<8;
                            ex[0] = ex[0] & 0x0F00;
                            ex[0] = ex[0]|0x4014;
                            ex[1] = *(oldPC+1);
                            ex[2] = 0x0110;

                            // for pre-verification
                            comp[0] = (ex[0]&0x0F00)|0x4004;
                            comp[1] = 0X5034;
                            comp[2] = ex[1];
                            comp[3] = 0x0110;



                            asm( "CALLA #compare  \n\t" //call pre-verification
                                    "MOV %0, R12  \n\t"
                                    "CALLA R12 \n\t"    //call emulation function
                                    "CALLA #set2 \n\t "  //call return stub
                                        ::"r"(&ex):"R12"
                                    );
                        }

        if((ad & 0x0003)==0x0002){

                    ex[0] = ex[0]<<8;
                    ex[0] = ex[0] & 0x0F00;
                    ex[0] = ex[0]|0x4024;
                    ex[1] = 0x0110;
                    comp[0] = (ex[0]&0x0F00)|0x4004;
                    comp[3] = 0x0110;
                    asm(    "CALLA #compare  \n\t"
                            "MOV %0, R12  \n\t"
                            "CALLA R12 \n\t"
                            "CALLA #set1 \n\t "::"r"(&ex):"R12"
                            );
                }

        if((ad & 0x0003)==0x0003){
                            ex[0] = ex[0]<<8;
                            ex[0] = ex[0] & 0x0F00;
                            ex[0] = ex[0]|0x4034;
                            ex[2] = 0x0110;
                            comp[0] = (ex[0]&0x0F00)|0x4004;
                            comp[1] = 0x0110;
                            asm( "CALLA #compare  \n\t"
                                  "MOV %0, R12  \n\t"
                                 "CALLA R12 \n\t "
                                "CALLA #set1 \n\t "::"r"(&ex):"R12"
                                    );
                        }

}

if(op == 0x0043){
    if((ad & 0x0003)==0x0001){

                              ex[0] = ex[0] & 0x000F;
                              ex[0] = ex[0]|0x4480;
                              ex[1] = *(oldPC+1) ;
                              ex[2] = 0x0110;

                              comp[0] = ex[0]<<8;
                              comp[0] = (comp[0]&0x0F00)|0x4004;
                              comp[1] = 0X5034;
                              comp[2] = ex[1];
                              comp[3] = 0x0110;

                              asm( "CALLA #compare  \n\t"
                                   "MOV %0, R4 \n\t"
                                    "MOV %1, R12  \n\t"
                                  "CALLA R12 \n\t "
                                  "CALLA #set2 \n\t "::"r"(reg_set[4]),"r"(&ex):"R12"
                                      );
                          }

}


if(op == 0x0012){
    if((ad & 0x0008)==0x0000){

                              ex[0] = ex[0] & 0x000F;
                              ex[0] = ex[0]|0x1210;
                              ex[1] = *(oldPC+1) ;
                              ex[2] = 0x0110;

                              comp[0] = ex[0]<<8;
                              comp[0] = (comp[0]&0x0F00)|0x4004;
                              comp[1] = 0X5034;
                              comp[2] = ex[1];
                              comp[3] = 0x0110;

                              asm( "CALLA #compare  \n\t"
                                   "MOV %0, R4 \n\t"
                                    "MOV %1, R12  \n\t"
                                  "CALLA R12 \n\t "
                                  "CALLA #set2 \n\t "::"r"(reg_set[4]),"r"(&ex):"R12"
                                      );
                          }

}


if(op == 0x0041){
    if((ad & 0x0008)==0x0008){

                              ex[0] = ex[0] & 0x000F;
                              ex[0] = ex[0]|0x1290;
                              ex[1] = *(oldPC+1) ;
                              ex[2] = 0x0110;

                              comp[0] = ex[0]<<8;
                              comp[0] = (comp[0]&0x0F00)|0x4004;
                              comp[1] = 0X5034;
                              comp[2] = ex[1];
                              comp[3] = 0x0110;

                              asm( "CALLA #compare  \n\t"
                                   "MOV %0, R4 \n\t"
                                    "MOV %1, R12  \n\t"
                                  "CALLA R12 \n\t "
                                  "CALLA #set2 \n\t "::"r"(reg_set[4]),"r"(&ex):"R12"
                                      );
                          }

}



    }

void justif(uint16_t t){
    if(t>0){
    }
}










