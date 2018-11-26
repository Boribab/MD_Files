import wmi
import ctypes

if ctypes.windll.shell32.IsUserAnAdmin(): 
    print('관리자권한으로 실행된 프로세스입니다.')
else:
    print('일반권한으로 실행된 프로세스입니다. 관리자 권한으로 실행하세요')
    exit()


c = wmi.WMI().Win32_NetworkAdapterConfiguration(IPEnabled=True)
nic = c[2]
ip = u"10.156.146.136"
subnetmask = u"255.255.255.0"
gateway = u"10.156.146.1"
dns = u'210.111.226.7'
dns2 = u'210.111.226.8'

nic.EnableStatic(IPAddress=[ip], SubnetMask=[subnetmask])
nic.SetGateways(DefaultIPGateway=[gateway])
nic.SetDNSServerSearchOrder([dns,dns2])

print(nic)