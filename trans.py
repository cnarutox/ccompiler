import re
lines = []
tricode = []
with open("./4yuan.txt") as f:
    line = f.readline()
    while line:
        print(line)
        s = []
        line = line.replace(" (", "")
        line = line.replace(")", "")
        a = line.split(',')
        b = a[0].split(':')
        s.append(b[0].strip())
        s.append(b[1].strip())
        s.append(a[1].strip())
        s.append(a[2].strip())
        s.append(a[3].strip().split('\n')[0])
        # print(s)
        lines.append(s)
        line = f.readline()


def trans(lists):
    tri = []
    if lists[1] == 'fun':
        tri.append('FUNCTION')
        tri.append(lists[4])
        tri.append(':')
    elif lists[1] == 'call':
        tri.append('CALL')
        tri.append(lists[4])
    elif lists[1] == 'ARG':
        tri.append('ARG')
        tri.append(lists[4])
    elif lists[1] == '=#':
        tri.append(lists[4])
        tri.append(':= #')
        tri.append(lists[2])
    elif lists[1] == 'param':
        tri.append('PARAM')
        tri.append(lists[4])
    elif lists[1] == '=':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[3])
    elif lists[1] == '+':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[2])
        tri.append('+')
        tri.append(lists[3])
    elif lists[1] == '-':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[2])
        tri.append('-')
        tri.append(lists[3])
    elif lists[1] == '/':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[2])
        tri.append('/')
        tri.append(lists[3])
    elif lists[1] == '*':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[2])
        tri.append('*')
        tri.append(lists[3])
    elif lists[1] == '%':
        tri.append(lists[4])
        tri.append(':=')
        tri.append(lists[2])
        tri.append('%')
        tri.append(lists[3])
    elif lists[1] == 'j=':
        tri.append('IF')
        tri.append(lists[2])
        tri.append('==')
        tri.append(lists[3])
        tri.append('GOTO')
        tri.append('label' + lists[4])
    elif lists[1] == 'j<':
        tri.append('IF')
        tri.append(lists[2])
        tri.append('<')
        tri.append(lists[3])
        tri.append('GOTO')
        tri.append('label' + lists[4])
    elif lists[1] == 'j>':
        tri.append('IF')
        tri.append(lists[2])
        tri.append('>')
        tri.append(lists[3])
        tri.append('GOTO')
        tri.append('label' + lists[4])
    elif lists[1] == 'j':
        tri.append('GOTO')
        tri.append('label' + lists[4])
    elif lists[1] == 'DEC':
        tri.append('DEC')
        tri.append(lists[4])
        tri.append(lists[2])
    else:
        print('没考虑到：')
        print(lists)
    return tri


for i in range(0, len(lines)):
    if len(trans(lines[i])) > 0:
        tricode.append(trans(lines[i]))
print(tricode)

m = open('./compare.txt', 'w')
for i in range(0, len(tricode)):
    st = ''
    for a in range(0, len(tricode[i])):
        tricode[i][a] += ' '
        st += tricode[i][a]
    m.write('\n' + st)
m.close()
