/**
 * OSNET uses these control flags to change the behavior of
 * KVM.
 */
#ifndef _ASM_X86_OSNET_H
#define _ASM_X86_OSNET_H

#define OSNET_VMCS 1
#define OSNET_HLT 1
#define OSNET_TRACE_PRINTK 0
#define OSNET_DTID 1
#define OSNET_DTID_LAPIC 0
#define OSNET_DTID_WRMSR 0
#define OSNET_DTID_INTERCEPT_MSR 1
#define OSNET_DTID_HYPERCALL 1
#define OSNET_DTID_SYNC_PIR_VIRR 1


#endif
