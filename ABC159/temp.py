import numpy as np

a = np.zeros(10)
print(a)
class Calc():

    def add(self, a):
        a[2] += 2
    
calc = Calc()

calc.add(a)

print(a)