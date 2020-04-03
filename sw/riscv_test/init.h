#ifndef INIT_H
#define INIT_H

#include "platform_config.h"

#define SBI_CONSOLE_PUTCHAR 1
#define SBI_CONSOLE_GETCHAR 2
#define SBI_SHUTDOWN 8

#ifndef __ASSEMBLER__

#include <stdint.h>

// memory configuration
typedef struct plf_mem_region_info {
    uintptr_t base;
    uintptr_t size;
    unsigned attr;
    const char *name;
} plf_mem_region_info;

typedef struct hart_storage {
    unsigned long xreg[32];
#ifndef __riscv_hard_float
    double freg[32];
#endif // __riscv_hard_float
} hart_storage;

extern __thread hart_storage hart_local_storage;

#ifdef PLF_MEM_MAP
extern const plf_mem_region_info mem_regions[];
#endif // PLF_MEM_MAP

#endif // !__ASSEMBLER__

#endif // INIT_H