import wmi
import ctypes

if ctypes.windll.shell32.IsUserAnAdmin(): 
    print('관리자권한으로 실행된 프로세스입니다.')
else:
    print('일반권한으로 실행된 프로세스입니다. 관리자 권한으로 실행하세요')
    exit()

c = wmi.WMI().Win32_NetworkAdapterConfiguration(IPEnabled=True)

nic = c[2]

nic.EnableDHCP()
nic.SetDNSServerSearchOrder()

print(nic)