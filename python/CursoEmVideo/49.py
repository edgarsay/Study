n = int(input('digite o numero :'))

print('{:=^40}'.format(''))

for i in range(1,11):
    print('{:2} * {:2} = {:2}'.format(n,i,(n*i)))

print('{:=^40}'.format(''))
