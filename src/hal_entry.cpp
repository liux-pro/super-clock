#include <ws2812/ws2812.h>
#include <ws2812/logo.h>
#include "hal_data.h"
#include "debug/debug.h"
#include "timer/timer0.h"
#include "gxht30/gxht30.h"
#include "rtc/rtc.h"
#include "utils.h"
#include "adc/adc.h"

#define SAMPLING_FREQUENCY 1000

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER
volatile bool scan_complete_flag = false;
fsp_err_t err;



void hal_entry(void) {
	debug("legend-tech\n");
	debug("hello world\n");

    logo_init();
    logo_black();
    logo_send_sync();
//	R_BSP_SoftwareDelay(2000, BSP_DELAY_UNITS_MILLISECONDS);
//    logo_blue();
//    logo_send_sync();
//    stop();
//	gxht30_init();
//	gxht30_result result;
//	gxht30_read(&result);
//  stop();



    /* Initializes the module. */
    err = R_GPT_Open(&gpt4_speaker_ctrl, &gpt4_speaker_cfg);
    /* Handle any errors. This function should be defined by the user. */
    assert(FSP_SUCCESS == err);
    /* Start the timer. */
    (void) R_GPT_Start(&gpt4_speaker_ctrl);
	uint32_t pclkd_freq_hz = BSP_STARTUP_PCLKD_HZ >> gpt4_speaker_cfg.source_div;
	uint32_t period_counts =
		(uint32_t) (((uint64_t) pclkd_freq_hz) / 262);
	debug("%ld\n",period_counts);
    err = R_GPT_PeriodSet(&gpt4_speaker_ctrl, period_counts);
    err = R_GPT_DutyCycleSet(&gpt4_speaker_ctrl, period_counts/2, GPT_IO_PIN_GTIOCB);
    R_GPT_Reset(&gpt4_speaker_ctrl);
    stop();


    adc_init();



	while (1){
		debug("%d\n",adc_get_brightness());
		R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
	    adc_async_scan();
	}

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}




/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event) {
	if (BSP_WARM_START_RESET == event) {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

		/* Enable reading from data flash. */
		R_FACI_LP->DFLCTL = 1U;

		/* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
		 * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
	}

	if (BSP_WARM_START_POST_C == event) {
		/* C runtime environment and system clocks are setup. */

		/* Configure pins. */
		R_IOPORT_Open(&g_ioport_ctrl, g_ioport.p_cfg);
	}
}

#if BSP_TZ_SECURE_BUILD

BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
#endif
