#ifndef __I2C_H__
#define __I2C_H__ 1


extern void i2c_start (void);
extern void i2c_stop (void);
extern  bit i2c_bit_rw (bit b);


extern unsigned char i2c_byte_read  (bit b);
extern           bit i2c_byte_write (unsigned char c);


extern bit  i2c_dev_test (void);
extern void i2c_dev_wait_offline (void);
extern void i2c_dev_wait_online (void);


extern int i2c_mem_write_page (const unsigned char* buf, unsigned int buf_size, unsigned int addr);
extern bit i2c_mem_write      (const unsigned char* buf, unsigned int buf_size, unsigned int addr);
extern int i2c_mem_read_page  (      unsigned char* buf, unsigned int buf_size, unsigned int addr);
extern bit i2c_mem_read       (      unsigned char* buf, unsigned int buf_size, unsigned int addr);
extern bit i2c_mem_verify     (const unsigned char* buf, unsigned int buf_size, unsigned int addr);
extern void i2c_mem_show      (                          unsigned int buf_size, unsigned int addr);


#endif
