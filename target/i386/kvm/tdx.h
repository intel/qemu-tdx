#ifndef QEMU_I386_TDX_H
#define QEMU_I386_TDX_H

#include "qom/object.h"
#include "qapi/error.h"
#include "exec/confidential-guest-support.h"

#define TYPE_TDX_GUEST "tdx-guest"
#define TDX_GUEST(obj)     \
    OBJECT_CHECK(TdxGuest, (obj), TYPE_TDX_GUEST)

typedef struct TdxGuestClass {
    ConfidentialGuestSupportClass parent_class;
} TdxGuestClass;

typedef struct TdxGuest {
    ConfidentialGuestSupport parent_obj;

    QemuMutex lock;

    bool initialized;
    bool debug;
} TdxGuest;

int tdx_kvm_init(ConfidentialGuestSupport *cgs, Error **errp);
void tdx_get_supported_cpuid(KVMState *s, uint32_t function,
                             uint32_t index, int reg, uint32_t *ret);

#endif