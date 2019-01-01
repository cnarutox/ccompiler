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

var_dic={}
N=0
M=0
param_list=[]
def trans(lines):
    for i in range(0, len(lines)):
        lists=line[i]
        tri = []
        if lists[0] == 'fun':
            tri.extend(['FUNCTION',lists[4]])
            tricode.append(tri)
            for i in range(0,len(param_list)):
                tricode.append(param_list[i])
            param_list=[]
        elif lists[1] == '=#':
            var_dic[lists[4]]='temp'+str(M)
            M+=1
            tri.extend([var_dic[lists[4]],':= #',lists[2]])
            tricode.append(tri)
        elif lists[1] == 'param':
            tri.extend(['PARAM',var_dic[lists[4]]])
            param_list.append(tri)
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
        #     var_dic[lists[4]]='var'+str(N)
        #     N+=1
        else:
            print('没考虑到：')
            print(lists)

<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes

# for i in range(0, len(lines)):
#     if len(trans(lines[i])) > 0:
#         tricode.append(trans(lines[i]))
# print(tricode)

m = open('./compare.txt', 'w')
for i in range(0, len(tricode)):
    st = ''
    for a in range(0, len(tricode[i])):
        tricode[i][a] += ' '
        st += tricode[i][a]
    m.write('\n' + st)
m.close()
