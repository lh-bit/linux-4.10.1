#ifndef _UAPI__LINUX_KVM_PARA_H
#define _UAPI__LINUX_KVM_PARA_H

/*
 * This header file provides a method for making a hypercall to the host
 * Architectures should define:
 * - kvm_hypercall0, kvm_hypercall1...
 * - kvm_arch_para_features
 * - kvm_para_available
 */

/* Return values for hypercalls */
#define KVM_ENOSYS		1000
#define KVM_EFAULT		EFAULT
#define KVM_E2BIG		E2BIG
#define KVM_EPERM		EPERM

#define KVM_HC_VAPIC_POLL_IRQ		1
#define KVM_HC_MMU_OP			2
#define KVM_HC_FEATURES			3
#define KVM_HC_PPC_MAP_MAGIC_PAGE	4
#define KVM_HC_KICK_CPU			5
#define KVM_HC_MIPS_GET_CLOCK_FREQ	6
#define KVM_HC_MIPS_EXIT_VM		7
#define KVM_HC_MIPS_CONSOLE_OUTPUT	8

/*
 * hypercalls use architecture specific
 */
#include <asm/kvm_para.h>

/* OSNET-DTID */
#include <asm/osnet.h>

#if OSNET_SETUP_DID
#define KVM_HC_SETUP_DTID        100
#define KVM_HC_RESTORE_DTID      101
#endif

#if OSNET_DTID_HYPERCALL_MAP_PID
#define KVM_HC_MAP_PID          200
#define KVM_HC_UNMAP_PID        201
#define KVM_HC_PAGE_WALK        202
#endif

#if OSNET_SET_X2APIC_ID
#define KVM_HC_SET_X2APIC_ID                    300
#define KVM_HC_RESTORE_X2APIC_ID                301
#define KVM_HC_DISABLE_INTERCEPT_WRMSR_ICR      302
#define KVM_HC_ENABLE_INTERCEPT_WRMSR_ICR       303
#endif
/* OSNET-END */

#endif /* _UAPI__LINUX_KVM_PARA_H */
