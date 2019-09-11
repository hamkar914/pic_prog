/*
 * Written by hkarlsson914@gmail.com, August 2019 for project PUD-1 
 * "Pretty Useless Device 1". A small project built around the PIC16F1829 
 * microcontroller for my own education and blinking a few LEDs and explore
 * concepts such as interrupts, use of timers etcetera. Written using 
 * MPLAB X IDE v5.25, XC8 compiler (v2.05) and using Pickit3 for 
 * transfer to chip.  
 */


// PIC16F1829 Configuration Bit Settings

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection INTOSC = internal 
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select
#pragma config CP = OFF         // Flash Program Memory Code Protection 
#pragma config CPD = OFF        // Data Memory Code Protection
#pragma config BOREN = OFF      // Brown-out Reset Enable 
#pragma config CLKOUTEN = OFF   // Clock Out Enable 
#pragma config IESO = OFF       // Internal/External Switchover 
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable 

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection 
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable 
#pragma config BORV = LO        // Brown-out Reset Voltage Selection 
#pragma config LVP = OFF        // Low-Voltage Programming Enable 

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include <pic16f1829.h>

#define _XTAL_FREQ 16000000


// Flag variables
int prg = 1;
int run_prg = 0;
int btn_pushed = 0;
int ok_to_run = 0;


void start_flash() 
{
    /* Function to blink all LEDs at startup
     *  to see that system is awake */
    
    PORTC = 0b00000000;
    
    PORTC = 0b00100000;
    __delay_ms(200);
        
    PORTC = 0b00010000;
    __delay_ms(200);
        
    PORTC = 0b00001000;
    __delay_ms(00);
       
    PORTC = 0b01000000;
    __delay_ms(200);
    
    PORTC = 0b10000000;
    __delay_ms(200);
        
    PORTC = 0b10000000;
    __delay_ms(200);
        
    PORTC = 0b01000000;
    __delay_ms(200);
        
    PORTC = 0b00001000;
    __delay_ms(200);
        
    PORTC = 0b00010000;
    __delay_ms(200);
        
    PORTC = 0b00100000;
    __delay_ms(200);

}

/**************************************************************
* "Programs" or functions that blink my LEDs in different ways
***************************************************************/

void prg_one() 
{
    // blink LEDs different durations
    
    PORTC = 0b00000000;
    
    int iter = 0;
    
    while (iter < 4)    
    {
        PORTC = 0b00100000;
        __delay_ms(1000);
        
        PORTC = 0b00010000;
        __delay_ms(2000);
        
        PORTC = 0b00001000;
        __delay_ms(3000);
        
        PORTC = 0b01000000;
        __delay_ms(4000);
    
        PORTC = 0b10000000;
        __delay_ms(5000);
        
        iter++;
    }
    
    PORTC = 0b00000000;  
}


void prg_two() 
{
    // one way round round round...
    
    int secs = 0;
    
    PORTC = 0b00000000;

    while (secs < 120) 
    {
         PORTC = 0b00100000;
        __delay_ms(100);
        
         PORTC = 0b00010000;
        __delay_ms(100);
        
         PORTC = 0b00001000;
        __delay_ms(100);
        
         PORTC = 0b01000000;
        __delay_ms(100);
    
        PORTC = 0b10000000;
        __delay_ms(100);

        secs++;
     }
    
    PORTC = 0b00000000;
}


void prg_three() 
{
    // count to 30 in binary two times
    
    int iter = 0;
    
    PORTC = 0b00000000;
    
    while(iter < 2)
    {
        PORTC = 0b00100000;
        __delay_ms(1000);

        PORTC = 0b00010000;
        __delay_ms(1000);

        PORTC = 0b00110000;
        __delay_ms(1000);

        PORTC = 0b00001000;
        __delay_ms(1000);

        PORTC = 0b00101000;
        __delay_ms(1000);

        PORTC = 0b00011000;
        __delay_ms(1000);

        PORTC = 0b00111000;
        __delay_ms(1000);

        PORTC = 0b01000000;
        __delay_ms(1000);

        PORTC = 0b01100000;
        __delay_ms(1000);

        PORTC = 0b01010000;
        __delay_ms(1000);

        PORTC = 0b01110000;
        __delay_ms(1000);

        PORTC = 0b01001000;
        __delay_ms(1000);

        PORTC = 0b01101000;
        __delay_ms(1000);
 
        PORTC = 0b01011000;
        __delay_ms(1000);

        PORTC = 0b01111000;
        __delay_ms(1000);

        PORTC = 0b10000000;
        __delay_ms(1000);

        PORTC = 0b10100000;
        __delay_ms(1000);

        PORTC = 0b10010000;
        __delay_ms(1000);

        PORTC = 0b10110000;
        __delay_ms(1000);

        PORTC = 0b10001000;
        __delay_ms(1000);

        PORTC = 0b10101000;
        __delay_ms(1000);

        PORTC = 0b10011000;
        __delay_ms(1000);

        PORTC = 0b10111000;
        __delay_ms(1000);

        PORTC = 0b11000000;
        __delay_ms(1000);

        PORTC = 0b11100000;
        __delay_ms(1000);

        PORTC = 0b11010000;
        __delay_ms(1000);

        PORTC = 0b11110000;
        __delay_ms(1000);

        PORTC = 0b11001000;
        __delay_ms(1000);

        PORTC = 0b11101000;
        __delay_ms(1000);

        PORTC = 0b11011000;
        __delay_ms(1000);
        
        iter++;
    }
    
    PORTC = 0b00000000;
}


void prg_four() 
{
    // hypnotic from the middle
    
    int iter = 0;
    
    PORTC = 0b00000000;
    
    while(iter < 100)
    {
        PORTC = 0b00001000;
        __delay_ms(200);

        PORTC = 0b01010000;
        __delay_ms(200);

        PORTC = 0b10100000;
        __delay_ms(200);

        iter++;
    }
    
    PORTC = 0b00000000;
}


void prg_five() 
{
    // back n forth round round round...
    
    int iter = 0;
    
    PORTC = 0b00000000;

    while (iter < 60) 
    {
        PORTC = 0b00100000;
        __delay_ms(100);
        
        PORTC = 0b00010000;
        __delay_ms(100);
        
        PORTC = 0b00001000;
        __delay_ms(100);
        
        PORTC = 0b01000000;
        __delay_ms(100);
    
        PORTC = 0b10000000;
        __delay_ms(100);
        
        PORTC = 0b10000000;
        __delay_ms(100);
        
        PORTC = 0b01000000;
        __delay_ms(100);
        
        PORTC = 0b00001000;
        __delay_ms(100);
        
        PORTC = 0b00010000;
        __delay_ms(100);
        
        PORTC = 0b00100000;
        __delay_ms(100);

        iter++;
     }
    
    PORTC = 0b00000000;

}


/**************************************************************
* interrupt service routine
***************************************************************/

void __interrupt() interrupt_service_routine(void)
{
    /* This function will handle both the external and internal interrupts,
     * External interrupts are handled differently depending on if RA5 is high
     * or low. JUST CHANGE FLAG VARIABLES INSIDE ISR TO SPEND AS LITTLE TIME IN
     ISR FUNCTION AS POSSSIBLE. */
    
    if (INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1) 
    {
        
        if (PORTAbits.RA5) // if pin 5 is high = select mode
        {
            if (prg == 5) // prg reach maximum value, reset it
            {
                prg = 1;
            }
            else         // else increment prg
            {
                prg++;
            }
            
            btn_pushed = 1;
            INTCONbits.IOCIF = 0; // reset flag bit
            IOCAF2 = 0;
        }
        else // pin 5 is low = execute mode  
        {
            if (ok_to_run) // to avoid start a prg from interrupt at start up
            {
                btn_pushed = 1;
                run_prg = 1;
            }
            
            INTCONbits.IOCIF = 0; // reset flag bit
            IOCAF2 = 0;
        }   
    }
}


/**************************************************************
* initializer, sets up everything in the beginning  
***************************************************************/

void initialize() {
    
    /* Initialization function that will configure the chip on start up.
     * Button interrupt: https://microchipdeveloper.com/mcu1101:project-9 */
    
    // set internal clock source to 16 MHz (data sheet p.68)
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1;
    OSCCONbits.IRCF3 = 1;
    
    ANSELA = 0b00000000;  // explicitly say that all A pins are digital (p.123)
    // they are analog by default on start up (?).
   
    WPUA = 0b00100100;    // Enable weak pull-up on pin RA2 and RA5 (p. 124)
    
    TRISA = 0b00100100;   // set pin RA2 and RA5 as input pins (p. 122).
    
    TRISB = 0b00000000;   // set portb as ouput (p.133)
    
    TRISC = 0b00000000;   // set portc as ouput (p.133)

    OPTION_REGbits.nWPUEN = 0x0;
    
    IOCAN2 = 1;   // enable interrupt-on-change negative on RA2 (p. 138).
    
    // enable interrupt-on-change globally (p.87)    
    INTCONbits.IOCIE = 1; 
    INTCONbits.GIE = 1;
    
    // Flash the LEDs when the system is turned ON
    start_flash();
    
    /* Following lines will give input to base of a transistor which collector
     * and emitter are put in parallel with the push button on RA2. So these
     * will also ground and generate interrupt on RA2 (hence reset of prg),
     * this is to charge the capacitor in my debounce circuit */
    
    PORTB = 0b00010000;
    __delay_ms(1);
    
    PORTB = 0b00000000;
    __delay_ms(1);
    
    PORTB = 0b00010000;
    __delay_ms(1);
    
    PORTB = 0b00000000;
    __delay_ms(1);
    
    PORTB = 0b00010000;
    __delay_ms(1);
    
    PORTB = 0b00000000;
    __delay_ms(1);
    
    prg = 1;
    
    // no it is OK to start a program
    
    ok_to_run = 1; 
}



void main(void) {
    
    initialize();    // configure chip 
    
    while(1) 
    {
        /* In main while loop continously check if btn_pushed or run_prg 
         * have been changed by the ISR.*/
        
        if (btn_pushed == 1 && run_prg == 0)
        {
            /* Program selection mode evaluate prg and turn on corresponding
             * LED to indicate program to be run */
            
            switch (prg) 
            {
                
            case 1:
                PORTC = 0;
                PORTCbits.RC5 = 1;
                btn_pushed = 0;
                break;
                
            case 2:
                PORTC = 0;
                PORTCbits.RC4 = 1;
                btn_pushed = 0;
                break;
                
            case 3:
                PORTC = 0;
                PORTCbits.RC3 = 1;
                btn_pushed = 0;
                break;
            
            case 4:
                PORTC = 0;
                PORTCbits.RC6 = 1;
                btn_pushed = 0;
                break;
                
            case 5:
                PORTC = 0;
                PORTCbits.RC7 = 1;
                btn_pushed = 0;
                break;
            }
        
        }
        
        else if (btn_pushed == 1 && run_prg == 1)
        {
            /* Program execute mode, call function to execute blink program */
            
            switch (prg) 
            {
                
            case 1:
                prg_one();
                btn_pushed = 0;
                run_prg = 0;
                PORTCbits.RC5 = 1;
                break;
                
            case 2:
                prg_two();
                btn_pushed = 0;
                run_prg = 0;
                PORTCbits.RC4 = 1;
                break;
                
            case 3:
                prg_three();
                btn_pushed = 0;
                run_prg = 0;
                PORTCbits.RC3 = 1;
                break;
            
            case 4:
                prg_four();
                btn_pushed = 0;
                run_prg = 0;
                PORTCbits.RC6 = 1;
                break;
                
            case 5:
                prg_five();
                btn_pushed = 0;
                run_prg = 0;
                PORTCbits.RC7 = 1;
                break;
            }
        }
    } 
}