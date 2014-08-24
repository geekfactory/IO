#include <xc.h>
#include <stdio.h>
#include "../IO.h"
#include "../delay/Delay.h"

// Fusibles de configuración MCLR (reset) Activo, Protección de lectura desactivada
// Bronw-out reset desactivado, perro guardian desactivado, Power-up timer desactivado
// Oscilador Interno Activo
// CONFIG1
#pragma config FOSC = XT	// Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

void main()
{
	int i;
	//OSCCON = 0x6C; // Para usar el oscilador interno PIC16F88 4 Mhz
	//OSCCON = 0x7C; // Para usar el oscilador interno PIC16F88 8 Mhz
	ANSEL = 0x00; // Configuracion de canales analogicos en PIC16F88

	io_mode(8, OUTPUT);
	io_mode(9, OUTPUT);
	io_mode(10, OUTPUT);
	io_mode(11, OUTPUT);
	io_mode(12, OUTPUT);
	io_mode(13, OUTPUT);
	io_mode(14, OUTPUT);
	io_mode(15, OUTPUT);

	for (;;) {
		for (i = 8; i < 16; i++) {
			io_write(i, HIGH);
			delay_ms(100);
			io_write(i, LOW);
		}

	}

}
