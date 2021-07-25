#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t init_barrier;

void *i2c_init(void *data)
{
    printf("i2c started\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);
    printf("i2c completed\n");
}

void *uart_init(void *data)
{
    printf("uart started\n");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("uart completed\n");
}

void *eth_init(void *data)
{
    printf("ethernet started\n");
    sleep(6);
    pthread_barrier_wait(&init_barrier);
    printf("ethernet completed\n");
}

void *eeprom_init(void *data)
{
    printf("eeprom started\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);    
    printf("eeprom completed\n");
}

int main()
{
    pthread_t uart,i2c,eth,eeprom;
    pthread_barrier_init(&init_barrier,NULL,4);
    pthread_create(&i2c,NULL,i2c_init,NULL);
    pthread_create(&uart,NULL,uart_init,NULL);
    pthread_create(&eth,NULL,eth_init,NULL);
    pthread_create(&eeprom,NULL,eeprom_init,NULL);
    pthread_join(i2c,NULL);
    pthread_join(uart,NULL);
    pthread_join(eth,NULL);
    pthread_join(eeprom,NULL);
    return 0;
}