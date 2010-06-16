#include "temperature.h"

temperature::temperature()
{


}

temperature::~temperature()
{
    release_device();
}

int temperature::write_read_spi_data(unsigned char *data, int data_len, int write_read)
{
    int ret_val = 0;

    //if (data_len > SPI_DATA_LENGTH)
    //    data_len = SPI_DATA_LENGTH;

    ret_val = get_spi_cmd_data(data, data_len, write_read);

    return ret_val;
}

int temperature::init()
{
    return init_device();
}

int temperature::get_status()
{
    return get_spi_status();
}
