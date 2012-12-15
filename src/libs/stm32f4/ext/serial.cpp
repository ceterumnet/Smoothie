#include "serial.h"

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


static Serial * Serial::g_Serial = 0;

Serial::Serial(int tx, int rx){
   Serial::g_Serial = this;
};

void Serial::baud(int b) {

};

bool Serial::getc(char *c) {
    return VCP_get_char(c);
};

void Serial::puts(char *buf) {
    VCP_send_str((uint8_t *)buf);
};


bool Serial::readable() {
    return true;
};


extern "C" {
    void EVAL_COM_IRQHandler() {

    };

    void g_Serial_callback() {
        if(Serial::g_Serial)
            Serial::g_Serial->callbackFptr->call(0);
    }
}
