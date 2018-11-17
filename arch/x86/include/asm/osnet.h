/* OSNET uses these control flags to change the behavior of
 * the host kernel and KVM.
 */
#ifndef _ASM_X86_OSNET_H
#define _ASM_X86_OSNET_H

#define OSNET_ALL_VMEXIT_REASON 999999
#define OSNET_VMCS_READ64 1
#define OSNET_VMCS_WRITE64 1
#define OSNET_HLT 1
#define OSNET_DTID_SET_PIR_ON 1
#define OSNET_DTID_LAPIC_TIMER_INTERRUPT_HANDLER 1
#define OSNET_DTID_LAPIC_TIMER_INTERRUPT_HANDLER_EMULATE_TIMER 0
#define OSNET_DTID_HRTIMER_EMULATE_TIMER 1
#define OSNET_DTID_WRMSR_EMULATE_TIMER 0
#define OSNET_DTID_WRMSR_UPDATE_APIC_TIMER 0
#define OSNET_DTID_INTERCEPT_MSR_X2APIC 0
#define OSNET_DTID_HYPERCALL 0
#define OSNET_DTID_SYNC_PIR_VIRR 0

#define OSNET_TRACE_PRINTK 0
#define OSNET_TRACE_CLOCKEVENT 0
#define OSNET_TRACE_HOST_POSTED_INTERRUPT_HANDLER 0
#define OSNET_TRACE_DTID_TARGET_EXPIRATION 0
#define OSNET_TRACE_DTID_SET_PIR_ON 0
#define OSNET_TRACE_DTID_WRMSR_EMULATE_TIMER 0
#define OSNET_TRACE_DTID_HYPERCALL 0
#define OSNET_TRACE_VMEXIT 0
#define OSNET_TRACE_VMEXIT_OVERALL 0
#define OSNET_TRACE_VMEXIT_SECTION 0
#define OSNET_TRACE_TIMER_EVENT_HANDLER 0
#define OSNET_TRACE_DTID_CREATE_VCPU_TIMER 0
#define OSNET_TRACE_DTID_START_TIMER 1
#define OSNET_TRACE_DTID_RESTART_TIMER 0

#if OSNET_DTID_LAPIC_TIMER_INTERRUPT_HANDLER
#define MS_TO_NS(x) (x * 1E6L)
#define OSNET_KVM_MAX_VCPUS 288

/* Each vCPU's timer is emulated by the host hrtimer. */
struct osnet_vcpu_hrtimer
{
  struct kvm_vcpu *vcpu;
  struct hrtimer *timer;
};

struct osnet_kvm
{
  struct kvm *kvm;
  struct osnet_vcpu_hrtimer *vcpu_timers[OSNET_KVM_MAX_VCPUS];
  int created_timers;
  int started_timers;
};
#endif

#endif
