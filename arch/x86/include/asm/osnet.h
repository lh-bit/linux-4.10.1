/**
 * DTID uses the timer interrupt handler to set the PIR and
 * ON. We can enable either of the implementation by setting
 * the control flag to 1.
 */
#ifndef _ASM_X86_OSNET_H
#define _ASM_X86_OSNET_H

#define OSNET_DTID_LAPIC 0
#define OSNET_DTID_DEVELOP 1
#define OSNET_DTID 1
#define OSNET_VMCS 1
#define OSNET_HLT 1
#define OSNET_TRACE_PRINTK 0

#endif
