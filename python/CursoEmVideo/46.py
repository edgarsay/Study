from time import sleep

for i in range(10,-1,-1):
    print('{:=^30}'.format(i))
    sleep(1)
print('{:*^30}'.format('*FOGOS*'))