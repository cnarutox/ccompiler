import re
import fileinput

f = open('compare.txt')
text = f.read()
f.close()

with open('compare.txt', 'w') as f:
    p = re.compile(r'^(temp\d+) := (#\d+)', re.M | re.I)
    r = re.findall(p, text)
    for i in r:
        text = text.replace(i[0], i[1])
    f.write(text)
p = re.compile(r'^(#\d+) := (#\d+)')
for line in fileinput.input('compare.txt', inplace=True):
    r = re.match(p, line)
    if r:
        print('', end='')
    else:
        print(line, end='')
