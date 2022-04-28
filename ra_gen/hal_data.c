/* generated HAL source file - do not edit */
#include "hal_data.h"

/* Macros to tie dynamic ELC links to ADC_TRIGGER_SYNC_ELC option in adc_trigger_t. */
#define ADC_TRIGGER_ADC0        ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC0_B      ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC1        ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC1_B      ADC_TRIGGER_SYNC_ELC
dtc_instance_ctrl_t g_transfer3_ctrl;

transfer_info_t g_transfer3_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.repeat_area =
		TRANSFER_REPEAT_AREA_DESTINATION, .transfer_settings_word_b.irq =
		TRANSFER_IRQ_END, .transfer_settings_word_b.chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_FIXED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_1_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_NORMAL, .p_dest = (void*) NULL, .p_src =
		(void const*) NULL, .num_blocks = 0, .length = 0, };

const dtc_extended_cfg_t g_transfer3_cfg_extend = { .activation_source =
		VECTOR_NUMBER_IIC0_RXI, };
const transfer_cfg_t g_transfer3_cfg = { .p_info = &g_transfer3_info,
		.p_extend = &g_transfer3_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer3 = { .p_ctrl = &g_transfer3_ctrl, .p_cfg =
		&g_transfer3_cfg, .p_api = &g_transfer_on_dtc };
dtc_instance_ctrl_t g_transfer2_ctrl;

transfer_info_t g_transfer2_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_FIXED, .transfer_settings_word_b.repeat_area =
		TRANSFER_REPEAT_AREA_SOURCE, .transfer_settings_word_b.irq =
		TRANSFER_IRQ_END, .transfer_settings_word_b.chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_1_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_NORMAL, .p_dest = (void*) NULL, .p_src =
		(void const*) NULL, .num_blocks = 0, .length = 0, };

const dtc_extended_cfg_t g_transfer2_cfg_extend = { .activation_source =
		VECTOR_NUMBER_IIC0_TXI, };
const transfer_cfg_t g_transfer2_cfg = { .p_info = &g_transfer2_info,
		.p_extend = &g_transfer2_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer2 = { .p_ctrl = &g_transfer2_ctrl, .p_cfg =
		&g_transfer2_cfg, .p_api = &g_transfer_on_dtc };
iic_master_instance_ctrl_t g_i2c_master0_ctrl;
const iic_master_extended_cfg_t g_i2c_master0_extend =
		{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT, .timeout_scl_low =
				IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
				/* Actual calculated bitrate: 99272. Actual calculated duty cycle: 49%. */.clock_settings.brl_value =
						27, .clock_settings.brh_value = 26,
				.clock_settings.cks_value = 2, };
const i2c_master_cfg_t g_i2c_master0_cfg = { .channel = 0, .rate =
		I2C_MASTER_RATE_STANDARD, .slave = 0x44, .addr_mode =
		I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == g_transfer2)
                .p_transfer_tx       = NULL,
#else
		.p_transfer_tx = &g_transfer2,
#endif
#if (RA_NOT_DEFINED == g_transfer3)
                .p_transfer_rx       = NULL,
#else
		.p_transfer_rx = &g_transfer3,
#endif
#undef RA_NOT_DEFINED
		.p_callback = i2c0_callback, .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC0_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC0_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC0_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC0_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC0_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif
		.ipl = (2), .p_extend = &g_i2c_master0_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master0 = { .p_ctrl = &g_i2c_master0_ctrl,
		.p_cfg = &g_i2c_master0_cfg, .p_api = &g_i2c_master_on_iic };
rtc_instance_ctrl_t g_rtc0_ctrl;
const rtc_error_adjustment_cfg_t g_rtc0_err_cfg = { .adjustment_mode =
		RTC_ERROR_ADJUSTMENT_MODE_AUTOMATIC, .adjustment_period =
		RTC_ERROR_ADJUSTMENT_PERIOD_10_SECOND, .adjustment_type =
		RTC_ERROR_ADJUSTMENT_NONE, .adjustment_value = 0, };
const rtc_cfg_t g_rtc0_cfg = { .clock_source = RTC_CLOCK_SOURCE_LOCO,
		.freq_compare_value_loco = 255, .p_err_cfg = &g_rtc0_err_cfg,
		.p_callback = NULL, .p_context = NULL, .alarm_ipl = (BSP_IRQ_DISABLED),
		.periodic_ipl = (BSP_IRQ_DISABLED), .carry_ipl = (2),
#if defined(VECTOR_NUMBER_RTC_ALARM)
    .alarm_irq               = VECTOR_NUMBER_RTC_ALARM,
#else
		.alarm_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_PERIOD)
    .periodic_irq            = VECTOR_NUMBER_RTC_PERIOD,
#else
		.periodic_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_CARRY)
    .carry_irq               = VECTOR_NUMBER_RTC_CARRY,
#else
		.carry_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const rtc_instance_t g_rtc0 = { .p_ctrl = &g_rtc0_ctrl, .p_cfg = &g_rtc0_cfg,
		.p_api = &g_rtc_on_rtc };
gpt_instance_ctrl_t g_timer0_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer0_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer0_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb =
						{ .output_enabled = false, .stop_level =
								GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer0_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer0_cfg = { .mode = TIMER_MODE_PERIODIC,
/* Actual period: 1 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0x2dc6c00, .duty_cycle_counts = 0x16e3600, .source_div =
		(timer_source_div_t) 0, .channel = 0, .p_callback = timer0_callback,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer0_extend, .cycle_end_ipl = (2),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer0 = { .p_ctrl = &g_timer0_ctrl, .p_cfg =
		&g_timer0_cfg, .p_api = &g_timer_on_gpt };
adc_instance_ctrl_t g_adc0_ctrl;
const adc_extended_cfg_t g_adc0_cfg_extend = { .add_average_count = ADC_ADD_OFF,
		.clearing = ADC_CLEAR_AFTER_READ_ON, .trigger_group_b =
				ADC_TRIGGER_SYNC_ELC, .double_trigger_mode =
				ADC_DOUBLE_TRIGGER_DISABLED, .adc_vref_control =
				ADC_VREF_CONTROL_AVCC0_AVSS0, .enable_adbuf = 0,
#if defined(VECTOR_NUMBER_ADC0_WINDOW_A)
    .window_a_irq        = VECTOR_NUMBER_ADC0_WINDOW_A,
#else
		.window_a_irq = FSP_INVALID_VECTOR,
#endif
		.window_a_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_ADC0_WINDOW_B)
    .window_b_irq      = VECTOR_NUMBER_ADC0_WINDOW_B,
#else
		.window_b_irq = FSP_INVALID_VECTOR,
#endif
		.window_b_ipl = (BSP_IRQ_DISABLED), };
const adc_cfg_t g_adc0_cfg = { .unit = 0, .mode = ADC_MODE_CONTINUOUS_SCAN,
		.resolution = ADC_RESOLUTION_12_BIT, .alignment =
				(adc_alignment_t) ADC_ALIGNMENT_RIGHT, .trigger =
				ADC_TRIGGER_SOFTWARE, .p_callback = adc_callback,
		/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_adc0_cfg_extend,
#if defined(VECTOR_NUMBER_ADC0_SCAN_END)
    .scan_end_irq        = VECTOR_NUMBER_ADC0_SCAN_END,
#else
		.scan_end_irq = FSP_INVALID_VECTOR,
#endif
		.scan_end_ipl = (2),
#if defined(VECTOR_NUMBER_ADC0_SCAN_END_B)
    .scan_end_b_irq      = VECTOR_NUMBER_ADC0_SCAN_END_B,
#else
		.scan_end_b_irq = FSP_INVALID_VECTOR,
#endif
		.scan_end_b_ipl = (BSP_IRQ_DISABLED), };
#if ((0) | (0))
const adc_window_cfg_t g_adc0_window_cfg =
{
    .compare_mask        =  0,
    .compare_mode_mask   =  0,
    .compare_cfg         = (0) | (0) | (0) | (ADC_COMPARE_CFG_EVENT_OUTPUT_OR),
    .compare_ref_low     = 0,
    .compare_ref_high    = 0,
    .compare_b_channel   = (ADC_WINDOW_B_CHANNEL_0),
    .compare_b_mode      = (ADC_WINDOW_B_MODE_LESS_THAN_OR_OUTSIDE),
    .compare_b_ref_low   = 0,
    .compare_b_ref_high  = 0,
};
#endif
const adc_channel_cfg_t g_adc0_channel_cfg = { .scan_mask = ADC_MASK_CHANNEL_19
		| 0, .scan_mask_group_b = 0, .priority_group_a =
		ADC_GROUP_A_PRIORITY_OFF, .add_mask = 0, .sample_hold_mask = 0,
		.sample_hold_states = 24,
#if ((0) | (0))
    .p_window_cfg        = (adc_window_cfg_t *) &g_adc0_window_cfg,
#else
		.p_window_cfg = NULL,
#endif
		};
/* Instance structure to use this module. */
const adc_instance_t g_adc0 = { .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg,
		.p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
sci_uart_instance_ctrl_t g_uart0_ctrl;

baud_setting_t g_uart0_baud_setting = {
/* Baud rate calculated with 0.160% error. */.semr_baudrate_bits_b.abcse = 0,
		.semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1,
		.cks = 0, .brr = 12, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
				false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart0_cfg_extend = {
		.clock = SCI_UART_CLOCK_INT, .rx_edge_start =
				SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
				SCI_UART_NOISE_CANCELLATION_DISABLE, .rx_fifo_trigger =
				SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting =
				&g_uart0_baud_setting,
		.flow_control = SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
		.flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
		.rs485_setting = { .enable = SCI_UART_RS485_DISABLE, .polarity =
				SCI_UART_RS485_DE_POLARITY_HIGH,
#if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
				.de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
				}, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg = { .channel = 9, .data_bits = UART_DATA_BITS_8,
		.parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
				user_uart_callback, .p_context = NULL, .p_extend =
				&g_uart0_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
		.rxi_ipl = (2), .txi_ipl = (0), .tei_ipl = (0), .eri_ipl = (2),
#if defined(VECTOR_NUMBER_SCI9_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI9_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI9_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI9_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI9_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif
		};

/* Instance structure to use this module. */
const uart_instance_t g_uart0 = { .p_ctrl = &g_uart0_ctrl,
		.p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci };
dtc_instance_ctrl_t g_transfer1_ctrl;

transfer_info_t g_transfer1_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.repeat_area =
		TRANSFER_REPEAT_AREA_DESTINATION, .transfer_settings_word_b.irq =
		TRANSFER_IRQ_END, .transfer_settings_word_b.chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_FIXED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_2_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_NORMAL, .p_dest = (void*) NULL, .p_src =
		(void const*) NULL, .num_blocks = 0, .length = 0, };

const dtc_extended_cfg_t g_transfer1_cfg_extend = { .activation_source =
		VECTOR_NUMBER_SPI0_RXI, };
const transfer_cfg_t g_transfer1_cfg = { .p_info = &g_transfer1_info,
		.p_extend = &g_transfer1_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 = { .p_ctrl = &g_transfer1_ctrl, .p_cfg =
		&g_transfer1_cfg, .p_api = &g_transfer_on_dtc };
dtc_instance_ctrl_t g_transfer0_ctrl;

transfer_info_t g_transfer0_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_FIXED, .transfer_settings_word_b.repeat_area =
		TRANSFER_REPEAT_AREA_SOURCE, .transfer_settings_word_b.irq =
		TRANSFER_IRQ_END, .transfer_settings_word_b.chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_2_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_NORMAL, .p_dest = (void*) NULL, .p_src =
		(void const*) NULL, .num_blocks = 0, .length = 0, };

const dtc_extended_cfg_t g_transfer0_cfg_extend = { .activation_source =
		VECTOR_NUMBER_SPI0_TXI, };
const transfer_cfg_t g_transfer0_cfg = { .p_info = &g_transfer0_info,
		.p_extend = &g_transfer0_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 = { .p_ctrl = &g_transfer0_ctrl, .p_cfg =
		&g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
spi_instance_ctrl_t g_spi0_ctrl;

/** SPI extended configuration for SPI HAL driver */
const spi_extended_cfg_t g_spi0_ext_cfg = { .spi_clksyn = SPI_SSL_MODE_CLK_SYN,
		.spi_comm = SPI_COMMUNICATION_FULL_DUPLEX, .ssl_polarity = SPI_SSLP_LOW,
		.ssl_select = SPI_SSL_SELECT_SSL0, .mosi_idle =
				SPI_MOSI_IDLE_VALUE_FIXING_DISABLE, .parity =
				SPI_PARITY_MODE_DISABLE, .byte_swap = SPI_BYTE_SWAP_DISABLE,
		.spck_div = {
		/* Actual calculated bitrate: 6000000. */.spbr = 1, .brdv = 0 },
		.spck_delay = SPI_DELAY_COUNT_1,
		.ssl_negation_delay = SPI_DELAY_COUNT_1, .next_access_delay =
				SPI_DELAY_COUNT_1 };

/** SPI configuration for SPI HAL driver */
const spi_cfg_t g_spi0_cfg = { .channel = 0,

#if defined(VECTOR_NUMBER_SPI0_RXI)
    .rxi_irq             = VECTOR_NUMBER_SPI0_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPI0_TXI)
    .txi_irq             = VECTOR_NUMBER_SPI0_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPI0_TEI)
    .tei_irq             = VECTOR_NUMBER_SPI0_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPI0_ERI)
    .eri_irq             = VECTOR_NUMBER_SPI0_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif

		.rxi_ipl = (2), .txi_ipl = (2), .tei_ipl = (2), .eri_ipl = (2),

		.operating_mode = SPI_MODE_MASTER,

		.clk_phase = SPI_CLK_PHASE_EDGE_ODD, .clk_polarity =
				SPI_CLK_POLARITY_LOW,

		.mode_fault = SPI_MODE_FAULT_ERROR_DISABLE, .bit_order =
				SPI_BIT_ORDER_MSB_FIRST, .p_transfer_tx = g_spi0_P_TRANSFER_TX,
		.p_transfer_rx = g_spi0_P_TRANSFER_RX, .p_callback = spi_callback,

		.p_context = NULL, .p_extend = (void*) &g_spi0_ext_cfg, };

/* Instance structure to use this module. */
const spi_instance_t g_spi0 = { .p_ctrl = &g_spi0_ctrl, .p_cfg = &g_spi0_cfg,
		.p_api = &g_spi_on_spi };
void g_hal_init(void) {
	g_common_init();
}
