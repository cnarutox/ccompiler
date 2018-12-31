import re
lines = []
tricode = []
with open("./intermediate.txt") as f:
    line = f.readline()
    while line:
        print(line)
        s = []
        a = line.split(',')
        b = a[0].split(':')
        s.append(b[0])
        s.append(b[1])
        s.append(a[1])
        s.append(a[2])
        s.append(a[3].split('\n')[0])
        print(s)
        lines.append(s)
        line = f.readline()


def trans(lists):
    tri = []
    if lists[0] == 'fun':
        tri.append('FUNCTION')
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
    # elif lists[1]=='DEC':
    #     print('这是声明语句，不考虑')
    else:
        print('没考虑到：')
        print(lists)
    return tri


for i in range(0, len(lines)):
    if len(trans(lines[i])) > 0:
        tricode.append(trans(lines[i]))
print(tricode)

m = open('test.asm', 'a')
for i in range(0, len(tricode)):
    st = ''
    for a in range(0, len(tricode[i])):
        tricode[i][a] += ' '
        st += tricode[i][a]
    m.write('\n' + st)
m.close()
