
int main(void);
  void __attribute__ ((weak, naked)) reset_handler(void) {
      (*(volatile unsigned int *)(0x40021018)) |= (1 << 4);

      (*(volatile unsigned int *)(0x40011004)) |= (0x00 << (((13 - 8) * 4) + 2));
      (*(volatile unsigned int *)(0x40011004)) |= (0x02 << ((13 - 8) * 4));
      main();
  }

void blocking_handler(void) { while (1); }
void null_handler(void) {}
extern unsigned _stack;

__attribute__ ((section(".vectors")))
struct {
    unsigned int *initial_sp_value;
    void (*reset)(void);
    void (*nmi)(void);
    void (*hard_fault)(void);
    void (*memory_manage_fault)(void);
    void (*bus_fault)(void);
    void (*usage_fault)(void);
    void (*reserved_x001c[4])(void);
    void (*sv_call)(void);
    void (*debug_monitor)(void);
    void (*reserved_x0034)(void);
    void (*pend_sv)(void);
    void (*systick)(void);
    void (*irq[68])(void);
} vector_table = {
    .initial_sp_value = &_stack,
    .reset = reset_handler,
    .nmi = null_handler,
    .hard_fault = blocking_handler,

    .sv_call = null_handler,
    .pend_sv = null_handler,
    .systick = null_handler,
    .irq = {
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
        null_handler,
    }
};
