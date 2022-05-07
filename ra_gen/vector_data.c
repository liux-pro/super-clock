/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [1] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [2] = gpt_counter_overflow_isr, /* GPT5 COUNTER OVERFLOW (Overflow) */
            [3] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
            [4] = sci_uart_rxi_isr, /* SCI9 RXI (Received data full) */
            [5] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [8] = spi_rxi_isr, /* SPI0 RXI (Receive buffer full) */
            [9] = spi_txi_isr, /* SPI0 TXI (Transmit buffer empty) */
            [10] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [11] = spi_eri_isr, /* SPI0 ERI (Error) */
            [12] = sci_spi_rxi_isr, /* SCI2 RXI (Receive data full) */
            [13] = sci_spi_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [14] = sci_spi_tei_isr, /* SCI2 TEI (Transmit end) */
            [15] = sci_spi_eri_isr, /* SCI2 ERI (Receive error) */
            [16] = adc_scan_end_isr, /* ADC0 SCAN END (A/D scan end interrupt) */
            [17] = rtc_alarm_periodic_isr, /* RTC ALARM (Alarm interrupt) */
            [18] = spi_tei_isr, /* SPI0 TEI (Transmission complete event) */
            [19] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [20] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
            [21] = iic_master_txi_isr, /* IIC0 TXI (Transmit data empty) */
            [22] = rtc_alarm_periodic_isr, /* RTC PERIOD (Periodic interrupt) */
            [23] = iic_master_eri_isr, /* IIC0 ERI (Transfer error) */
            [24] = iic_master_rxi_isr, /* IIC0 RXI (Receive data full) */
            [26] = iic_master_tei_isr, /* IIC0 TEI (Transmit end) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_GPT5_COUNTER_OVERFLOW), /* GPT5 COUNTER OVERFLOW (Overflow) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SPI0_RXI), /* SPI0 RXI (Receive buffer full) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TXI), /* SPI0 TXI (Transmit buffer empty) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SPI0_ERI), /* SPI0 ERI (Error) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI2_RXI), /* SCI2 RXI (Receive data full) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TXI), /* SCI2 TXI (Transmit data empty) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TEI), /* SCI2 TEI (Transmit end) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_SCI2_ERI), /* SCI2 ERI (Receive error) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_ADC0_SCAN_END), /* ADC0 SCAN END (A/D scan end interrupt) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_RTC_ALARM), /* RTC ALARM (Alarm interrupt) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TEI), /* SPI0 TEI (Transmission complete event) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_RTC_CARRY), /* RTC CARRY (Carry interrupt) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_GPT0_COUNTER_OVERFLOW), /* GPT0 COUNTER OVERFLOW (Overflow) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_IIC0_TXI), /* IIC0 TXI (Transmit data empty) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_RTC_PERIOD), /* RTC PERIOD (Periodic interrupt) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_IIC0_ERI), /* IIC0 ERI (Transfer error) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_IIC0_RXI), /* IIC0 RXI (Receive data full) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_IIC0_TEI), /* IIC0 TEI (Transmit end) */
        };
        #endif
