#ifndef HEADER
#define HEADER
int _printf(const char *format, ...);

int _strlen(const char *s);

void print_number(int n, int *counter);

int power(int ten, int to_the_power);
void write_and_count(const char*, int, int*, int);
int binary_numbers(int d);

int octal_numbers(int d);
void hexqdecimal_numbers(int d, int *counter, int capital);

void print_with_S(char *toprint, int *counter);
void print_address(void *toprint, int *counter);


#endif
