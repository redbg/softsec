/**
 * @file shared.h
 * @author redbg (redbg@softsec.org)
 * @brief
 * @version 0.1
 * @date 2021-11-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "amd64.h"

#define NT_DEVICE_NAME L"\\Device\\softsec"
#define DOS_DEVICE_NAME L"\\DosDevices\\softsec"

#define IOCTL_SS_VirtualMemory CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

namespace SS::BASE
{
    struct VirtualMemory
    {
        enum class METHOD : DWORD64
        {
            Allocate,
            Free,
            Copy
        } Method;
        DWORD64 TargetProcessId;
        DWORD64 TargetAddress;
        DWORD64 SourceProcessId;
        DWORD64 SourceAddress;
        DWORD64 Size;
        ULONG AllocationType;
        ULONG Protection;
        NTSTATUS ntStatus;
    };
}
