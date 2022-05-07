/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (26)
#endif
/* ISR prototypes */
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void gpt_counter_overflow_isr(void);
void sci_uart_eri_isr(void);
void sci_uart_tei_isr(void);
void spi_rxi_isr(void);
void spi_txi_isr(void);
void spi_eri_isr(void);
void sci_spi_rxi_isr(void);
void sci_spi_txi_isr(void);
void sci_spi_tei_isr(void);
void sci_spi_eri_isr(void);
void adc_scan_end_isr(void);
void rtc_alarm_periodic_isr(void);
void spi_tei_isr(void);
void rtc_carry_isr(void);
void iic_master_txi_isr(void);
void iic_master_eri_isr(void);
void iic_master_rxi_isr(void);
void iic_master_tei_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI1_RXI ((IRQn_Type) 0) /* SCI1 RXI (Received data full) */
#define SCI1_RXI_IRQn          ((IRQn_Type) 0) /* SCI1 RXI (Received data full) */
#define VECTOR_NUMBER_SCI1_TXI ((IRQn_Type) 1) /* SCI1 TXI (Transmit data empty) */
#define SCI1_TXI_IRQn          ((IRQn_Type) 1) /* SCI1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_GPT5_COUNTER_OVERFLOW ((IRQn_Type) 2) /* GPT5 COUNTER OVERFLOW (Overflow) */
#define GPT5_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 2) /* GPT5 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_SCI1_ERI ((IRQn_Type) 3) /* SCI1 ERI (Receive error) */
#define SCI1_ERI_IRQn          ((IRQn_Type) 3) /* SCI1 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
#define SCI9_RXI_IRQn          ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define SCI9_TXI_IRQn          ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define SCI9_TEI_IRQn          ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define SCI9_ERI_IRQn          ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 8) /* SPI0 RXI (Receive buffer full) */
#define SPI0_RXI_IRQn          ((IRQn_Type) 8) /* SPI0 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 9) /* SPI0 TXI (Transmit buffer empty) */
#define SPI0_TXI_IRQn          ((IRQn_Type) 9) /* SPI0 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SCI1_TEI ((IRQn_Type) 10) /* SCI1 TEI (Transmit end) */
#define SCI1_TEI_IRQn          ((IRQn_Type) 10) /* SCI1 TEI (Transmit end) */
#define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 11) /* SPI0 ERI (Error) */
#define SPI0_ERI_IRQn          ((IRQn_Type) 11) /* SPI0 ERI (Error) */
#define VECTOR_NUMBER_SCI2_RXI ((IRQn_Type) 12) /* SCI2 RXI (Receive data full) */
#define SCI2_RXI_IRQn          ((IRQn_Type) 12) /* SCI2 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI2_TXI ((IRQn_Type) 13) /* SCI2 TXI (Transmit data empty) */
#define SCI2_TXI_IRQn          ((IRQn_Type) 13) /* SCI2 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI2_TEI ((IRQn_Type) 14) /* SCI2 TEI (Transmit end) */
#define SCI2_TEI_IRQn          ((IRQn_Type) 14) /* SCI2 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI2_ERI ((IRQn_Type) 15) /* SCI2 ERI (Receive error) */
#define SCI2_ERI_IRQn          ((IRQn_Type) 15) /* SCI2 ERI (Receive error) */
#define VECTOR_NUMBER_ADC0_SCAN_END ((IRQn_Type) 16) /* ADC0 SCAN END (A/D scan end interrupt) */
#define ADC0_SCAN_END_IRQn          ((IRQn_Type) 16) /* ADC0 SCAN END (A/D scan end interrupt) */
#define VECTOR_NUMBER_RTC_ALARM ((IRQn_Type) 17) /* RTC ALARM (Alarm interrupt) */
#define RTC_ALARM_IRQn          ((IRQn_Type) 17) /* RTC ALARM (Alarm interrupt) */
#define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 18) /* SPI0 TEI (Transmission complete event) */
#define SPI0_TEI_IRQn          ((IRQn_Type) 18) /* SPI0 TEI (Transmission complete event) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type) 19) /* RTC CARRY (Carry interrupt) */
#define RTC_CARRY_IRQn          ((IRQn_Type) 19) /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 20) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define GPT0_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 20) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_IIC0_TXI ((IRQn_Type) 21) /* IIC0 TXI (Transmit data empty) */
#define IIC0_TXI_IRQn          ((IRQn_Type) 21) /* IIC0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type) 22) /* RTC PERIOD (Periodic interrupt) */
#define RTC_PERIOD_IRQn          ((IRQn_Type) 22) /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_IIC0_ERI ((IRQn_Type) 23) /* IIC0 ERI (Transfer error) */
#define IIC0_ERI_IRQn          ((IRQn_Type) 23) /* IIC0 ERI (Transfer error) */
#define VECTOR_NUMBER_IIC0_RXI ((IRQn_Type) 24) /* IIC0 RXI (Receive data full) */
#define IIC0_RXI_IRQn          ((IRQn_Type) 24) /* IIC0 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC0_TEI ((IRQn_Type) 26) /* IIC0 TEI (Transmit end) */
#define IIC0_TEI_IRQn          ((IRQn_Type) 26) /* IIC0 TEI (Transmit end) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
