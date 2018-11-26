import wmi

a = int(input("number : "))
c = wmi.WMI().Win32_NetworkAdapterConfiguration(IPEnabled=1)
print(c[a])