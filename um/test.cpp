#include "softsec.h"
#include <stdio.h>
#include "../shared/shared.h"

int main()
{
    SS::UM::LoadDriver(TEXT("softsec_x64"), TEXT("C:\\Users\\Win10_64\\Desktop\\softsec_x64.sys"));

    Sleep(1000);
    HANDLE hDevice = CreateFile(TEXT("\\\\.\\softsec"),
                                GENERIC_READ | GENERIC_WRITE,
                                0,
                                NULL,
                                CREATE_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    printf("hDevice:[%p]\n", hDevice);

    SS::VirtualMemory vm = {};
    vm.Method = SS::VirtualMemory::METHOD::Allocate;
    vm.ProcessId = 4176;
    vm.Size = 0x1000;
    vm.AllocationType = MEM_COMMIT;
    vm.Protect = PAGE_READWRITE;

    ULONG bytesReturned = 0;
    BOOL bRc = DeviceIoControl(hDevice,
                               (DWORD)IOCTL_SS_VirtualMemory,
                               &vm,
                               sizeof(vm),
                               &vm,
                               sizeof(vm),
                               &bytesReturned,
                               NULL);

    printf("bRc:[%d] BaseAddress:[%p]\n", bRc, (VOID *)vm.BaseAddress);

    system("pause");

    SS::UM::UnloadDriver(TEXT("softsec_x64"));
    return 0;
}
