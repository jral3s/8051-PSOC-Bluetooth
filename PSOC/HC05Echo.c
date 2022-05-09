/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    UART_Init();
    UART_Start();
    
    LCD_Start();
    LCD_ClearDisplay();
    
    // Set Enable Low - Communications Mode
    Control_Reg_1_Write(0);
        
    for(;;)
    {
        /* Place your application code here. */
        if (UART_GetRxBufferSize() > 0) {
            uint8 c = UART_GetChar();
            UART_PutChar(c);
            LCD_PutChar(c);
        }
    }
}

/* [] END OF FILE */
