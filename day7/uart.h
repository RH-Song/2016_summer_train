/*
 * uart.h
 *
 *  Created on: 2016��5��6��
 *      Author: Laowang
 */

#ifndef UART_H_
#define UART_H_

void Uart_init(long);
void Uart_send_byte(long, unsigned char);
unsigned char Uart_receive_byte(long);

#endif /* UART_H_ */
