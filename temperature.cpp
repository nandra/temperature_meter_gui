#include "temperature.h"

temperature::temperature()
{
    this->device = new iqrf_dev();

}

temperature::~temperature()
{
    delete(this->device);
}

int temperature::write_read_spi_data(unsigned char *data, int data_len, int write_read)
{
    int ret_val = 0;

    if (data_len > SPI_DATA_LENGTH)
        data_len = SPI_DATA_LENGTH;

    ret_val = this->device->get_spi_cmd_data(data, data_len, write_read);

    return ret_val;
}

int temperature::init()
{
    return this->device->init_device();
}

int temperature::get_status()
{
    return this->device->get_spi_status();
}
