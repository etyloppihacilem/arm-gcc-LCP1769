#include "LPC17xx.h"          // Définitions registres périphériques
#include <stdint.h>

#define LED_PORT   LPC_GPIO0  // Port 0
#define LED_PIN    22         // Broche 22  (carte LPCXpresso : LED rouge)

static void delay_ms(uint32_t ms)
{
    /* Petit délai bloquant : ~1 ms par incrément lorsque l’horloge cœur = 100 MHz.
       Ajuste le facteur si tu changes SystemCoreClock.                    */
    volatile uint32_t cycles = ms * (SystemCoreClock / 4000U);
    while (cycles--) __NOP();
}

int main(void)
{
    /* 1) Met à jour SystemCoreClock (défini dans system_LPC17xx.c) */
    SystemCoreClockUpdate();          // <- optionnel si PLL déjà fixée

    /* 2) Configure P0.22 en sortie push-pull */
    LED_PORT->FIODIR |= (1U << LED_PIN);

    /* 3) Boucle de clignotement */
    while (1)
    {
        LED_PORT->FIOSET = (1U << LED_PIN);   // allume
        delay_ms(500);                        // ~100 ms

        LED_PORT->FIOCLR = (1U << LED_PIN);   // éteint
        delay_ms(500);
    }
}

