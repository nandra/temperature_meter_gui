#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iqrf.h>

class temperature {
public:
    temperature();
    ~temperature();
    int write_read_spi_data(unsigned char *data, int data_len, int write_read);
    int init();
    int get_status();
private:
    //iqrf_dev *device;


};
#endif // TEMPERATURE_H
