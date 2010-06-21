#include "temperature.h"

temperature::temperature()
{


}

temperature::~temperature()
{
    iqrf_release_device();
}

int temperature::write_read_spi_data(unsigned char *data, int data_len, int write_read)
{
    int ret_val = 0;

    if (data_len > 0x35)
        data_len = 0x35;

    ret_val = iqrf_read_write_spi_cmd_data(data, data_len, write_read);

    return ret_val;
}

int temperature::init()
{
    return iqrf_init_device();
}

int temperature::get_status()
{
    return iqrf_get_spi_status();
}
