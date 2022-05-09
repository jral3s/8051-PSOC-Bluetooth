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
    
    // Set Enable High - AT Command Mode
    Control_Reg_1_Write(1);
    CyDelay(100);
    
    // UART_PutString("AT+ROLE=1\r\n"); // Set as Master
    // UART_PutString("AT+ROLE=0\r\n"); // Set as Slave
    
    // UART_PutString("AT+ROLE?\r\n"); // Set as Slave
    
    
    // UART_PutString("AT+UART?\r\n"); // Query Serial Settings
    // HC-05 #1 - 9600 BAUD (AT in 9600)
    // HC-05 #2 - 9600 BAUD (AT in 38400)
    
    // UART_PutString("AT+ADDR?\r\n"); // Query Address
    // HC-05 #1 - 00 18 e4 34 ce 8b
    // HC-05 #2 - 00 18 e4 34 c7 93
    
    // UART_PutString("AT+BIND=0018,e4,34c793\r\n");     // Set Bind Address for HC-05 #1    
    // UART_PutString("AT+BIND=0018,e4,34ce8b\r\n");     // Set Bind Address for HC-05 #2
    
    // UART_PutString("AT+BIND?\r\n");     // Query Bind Address
    
    // UART_PutString("AT+RNAME?0018,e4,34ce8b\r\n"); // Check if #2 can see #1
    // UART_PutString("AT+RNAME?0018,e4,34c793\r\n"); // Check if #1 can see #2
    
    // UART_PutString("AT+CMODE=0\r\n"); // Set Connection Mode to pair to bind address
    // UART_PutString("AT+CMODE?\r\n"); // Check Connection Mode
    
    UART_PutString("AT+RESET\r\n");
    CyDelay(500);
    UART_PutString("AT+INIT\r\n");
    CyDelay(500);
    UART_PutString("AT+FSAD=0018,e4,34ce8b\r\n");
    CyDelay(500);
    UART_PutString("AT+LINK=0018,e4,34ce8b\r\n");
    CyDelay(500);
        
    
    // Set Enable Low - Communications Mode
    // Control_Reg_1_Write(0);
    
    uint8 i = 0;
    
    for(;;)
    {
        /* Place your application code here. */
        if (UART_GetRxBufferSize() > 0) {
            i += 1;
            uint8 c = UART_GetChar();
            if (c == 0x0D || c == 0x0A)
                LCD_PutChar(32);
            else {
                if (i > 0) // change number to be the length of the AT Command to ignore those characters
                LCD_PutChar(c);  
            }
        }
    }
}

/* [] END OF FILE */
