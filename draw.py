'''
this is a python script which takes the input 
from testOutput.csv and plots the graph of the data.
'''

import matplotlib.pyplot as plt

csvFile = open('testOutput.csv', 'r')
data = csvFile.readlines()
csvFile.close()

x = []
y = []
i = 0
for line in data:
    x.append(i)
    y.append(float(line))
    i += 1
    
plt.plot(x, y)
plt.show()
