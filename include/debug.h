#include "console.h"
#include "vargs.h"
#include "elf.h"

// kernel print function
void printk(const char *format, ...);

// kernel print function with color
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);


