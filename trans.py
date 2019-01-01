# import re
# lines = []
# tricode = []
# with open("./4yuan.txt") as f:
#     line = f.readline()
#     while line:
#         print(line)
#         s = []
#         line = line.replace(" (", "")
#         line = line.replace(")", "")
#         a = line.split(',')
#         b = a[0].split(':')
#         s.append(b[0].strip())
#         s.append(b[1].strip())
#         s.append(a[1].strip())
#         s.append(a[2].strip())
#         s.append(a[3].strip().split('\n')[0])
#         # print(s)
#         lines.append(s)
#         line = f.readline()

# var_dic = {}
# N = 0
# M = 0
# param_list = []

# # def trans(lines):
# #     for i in range(0, len(lines)):
# #         lists = line[i]
# #         tri = []
# #         if lists[0] == 'fun':
# #             tri.extend(['FUNCTION', lists[4]])
# #             tricode.append(tri)
# #             for i in range(0, len(param_list)):
# #                 tricode.append(param_list[i])
# #             param_list = []
# #         elif lists[1] == '=#':
# #             var_dic[lists[4]] = 'temp' + str(M)
# #             M += 1
# #             tri.extend([var_dic[lists[4]], ':= #', lists[2]])
# #             tricode.append(tri)
# #         elif lists[1] == 'param':
# #             tri.extend(['PARAM', var_dic[lists[4]]])
# #             param_list.append(tri)
# #         elif lists[1] == '=':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[3])
# #         elif lists[1] == '+':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[2])
# #             tri.append('+')
# #             tri.append(lists[3])
# #         elif lists[1] == '-':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[2])
# #             tri.append('-')
# #             tri.append(lists[3])
# #         elif lists[1] == '/':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[2])
# #             tri.append('/')
# #             tri.append(lists[3])
# #         elif lists[1] == '*':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[2])
# #             tri.append('*')
# #             tri.append(lists[3])
# #         elif lists[1] == '%':
# #             tri.append(lists[4])
# #             tri.append(':=')
# #             tri.append(lists[2])
# #             tri.append('%')
# #             tri.append(lists[3])
# #         elif lists[1] == 'j=':
# #             tri.append('IF')
# #             tri.append(lists[2])
# #             tri.append('==')
# #             tri.append(lists[3])
# #             tri.append('GOTO')
# #             tri.append('label' + lists[4])
# #         elif lists[1] == 'j<':
# #             tri.append('IF')
# #             tri.append(lists[2])
# #             tri.append('<')
# #             tri.append(lists[3])
# #             tri.append('GOTO')
# #             tri.append('label' + lists[4])
# #         elif lists[1] == 'j>':
# #             tri.append('IF')
# #             tri.append(lists[2])
# #             tri.append('>')
# #             tri.append(lists[3])
# #             tri.append('GOTO')
# #             tri.append('label' + lists[4])
# #         elif lists[1] == 'j':
# #             tri.append('GOTO')
# #             tri.append('label' + lists[4])
# #         # elif lists[1]=='DEC':
# #         #     var_dic[lists[4]]='var'+str(N)
# #         #     N+=1
# #         else:
# #             print('没考虑到：')
# #             print(lists)

# # def trans(lists):
# #     tri = []
# #     if lists[1] == 'fun':
# #         tri.append('FUNCTION')
# #         tri.append(lists[4])
# #         tri.append(':')
# #     elif lists[1] == 'call':
# #         tri.append('CALL')
# #         tri.append(lists[4])
# #     elif lists[1] == 'RETURN':
# #         tri.append('RETURN')
# #         tri.append(lists[4])
# #     elif lists[1] == 'ARG':
# #         tri.append('ARG')
# #         tri.append(lists[4])
# #     elif lists[1] == '=#':
# #         tri.append(lists[4])
# #         tri.append(':= #')
# #         tri.append(lists[2])
# #     elif lists[1] == 'param':
# #         tri.append('PARAM')
# #         tri.append(lists[4])
# #     elif lists[1] == '=':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[3])
# #     elif lists[1] == '+':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[2])
# #         tri.append('+')
# #         tri.append(lists[3])
# #     elif lists[1] == '-':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[2])
# #         tri.append('-')
# #         tri.append(lists[3])
# #     elif lists[1] == '/':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[2])
# #         tri.append('/')
# #         tri.append(lists[3])
# #     elif lists[1] == '*':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[2])
# #         tri.append('*')
# #         tri.append(lists[3])
# #     elif lists[1] == '%':
# #         tri.append(lists[4])
# #         tri.append(':=')
# #         tri.append(lists[2])
# #         tri.append('%')
# #         tri.append(lists[3])
# #     elif lists[1] == 'j=':
# #         tri.append('IF')
# #         tri.append(lists[2])
# #         tri.append('==')
# #         tri.append(lists[3])
# #         tri.append('GOTO')
# #         tri.append('label' + lists[4])

# #     elif lists[1] == 'j<':
# #         tri.append('IF')
# #         tri.append(lists[2])
# #         tri.append('<')
# #         tri.append(lists[3])
# #         tri.append('GOTO')
# #         tri.append('label' + lists[4])

# #     elif lists[1] == 'j>':
# #         tri.append('IF')
# #         tri.append(lists[2])
# #         tri.append('>')
# #         tri.append(lists[3])
# #         tri.append('GOTO')
# #         tri.append('label' + lists[4])

# #     elif lists[1] == 'j':
# #         tri.append('GOTO')
# #         tri.append('label' + lists[4])

# #     elif lists[1] == 'DEC':
# #         tri.append('DEC')
# #         tri.append(lists[4])
# #         tri.append(lists[2])
# #     else:
# #         print('没考虑到：')
# #         print(lists)
# #     return tri

# for i in range(0, len(lines)):
#     if len(trans(lines[i])) > 0:
#         tricode.append(trans(lines[i]))
# print(tricode)

# m = open('./compare.txt', 'w')
# for i in range(0, len(tricode)):
#     st = ''
#     for a in range(0, len(tricode[i])):
#         if tricode[i][a] != ':= #':
#             tricode[i][a] += ' '
#         st += tricode[i][a]
#     m.write(st.strip() + '\n')
# m.close()

import re
lines = []
tricode = []
with open("./4yuan.txt") as f:
    line = f.readline()
    while line:
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
        lines.append(s)
        line = f.readline()

var_dic = {}
param_list = []
label_dic = {}  # 将label编号和0123对应起来
N = 0
M = 0


def varname(lines):
    global var_dic, param_list, label_dic, tricode, N, M
    for i in range(0, len(lines)):
        lists = lines[i]
        # if lists[1] == 'DEC':
        #     var_dic[lists[4]] = 'var' + str(N)
        #     N += 1
        if lists[1] == 'j' or lists[1] == 'j=' or lists[1] == 'j>' or lists[1] == 'j<':
            if lists[4] not in label_dic.keys():
                a = 'label' + str(len(label_dic))
                label_dic[lists[4]] = a

    # for x in range(0, len(lines)):
    #     lists = lines[x]
    #     for j in range(2, 5):
    #         if lists[j] not in var_dic:
    #             var_dic[lists[j]] = 'temp' + str(M)
    #             M += 1


def trans(lines):
    global var_dic, param_list, label_dic, tricode, N, M
    # for i in range(0, len(lines)):
    i = 0
    while i < len(lines):
        if str(i) in label_dic.keys():
            tricode.append(['LABEL', label_dic[str(i)], ' :'])
        lists = lines[i]
        tri = []
        if lists[1] == 'fun':
            if lists[2] == 0:
                tri.extend(['FUNCTION', lists[4] + " :"])
                tricode.append(tri)
            # if lists[2]==1:
            #     if lists[4] not in var_dic:
            #     var_dic[lists[4]] = 'temp' + str(M)
            #     M += 1
            #     tri.extend([var_dic[lists[4]],':=','CALL',lists[4]])
            #     a
        #  关终端啦~你复制一下这个文件吧，我现在会push上去  不改了？                   
        # 辛苦啦~  
        #        
            for i in range(0, len(param_list)):
                tricode.append(param_list[i])
            param_list = []
        elif lists[1] == 'call':
            if lists[2] == '0':
                tri.extend(['CALL', lists[4]])
                tricode.append(tri)
            if lists[2] == '1':  # 有返回值
                tri.extend(['temp' + str(M), ':=', 'CALL', lists[4]])
                tricode.append(tri)
                var_dic[str(i)] = 'temp' + str(M)
                M += 1
                tri = [lines[i + 1][2], ':=', 'temp' + str(M - 1)]
                tricode.append(tri)
                i += 1
        elif lists[1] == 'ARG':
            tri.extend(['ARG', var_dic[lists[4]]])
            tricode.append(tri)
        elif lists[1] == 'DEC':
            tri.extend(['DEC',lists[4],lists[2]])
            tricode.append(tri)
        elif lists[1] == 'RETURN':
            tri.extend(['RETURN', var_dic[lists[4]]])
            tricode.append(tri)
        elif lists[1] == '=#':  #缺call fun
            tri.extend([var_dic[lists[4]], ':= #', lists[2]])
            tricode.append(tri)
        elif lists[1] == 'param':
            tri.extend(['PARAM', var_dic[lists[4]]])
            param_list.append(tri)
        elif lists[1] == '=':
            tri.extend([var_dic[lists[4]], ':=', var_dic[lists[3]]])
            tricode.append(tri)
        elif lists[1] == '+' or lists[1] == '-' or lists[1] == '*' or lists[1] == '/' or lists[1] == '%' or lists[1] == '^':
            tri.append(var_dic[lists[4]])
            tri.append(':=')
            tri.append(var_dic[lists[2]])
            tri.append(lists[1])
            tri.append(var_dic[lists[3]])
            tricode.append(tri)
        elif lists[1] == 'j=':
            tri.append('IF')
            tri.append(var_dic[lists[2]])
            tri.append('==')
            tri.append(var_dic[lists[3]])
            tri.append('GOTO')
            tri.append(label_dic[lists[4]])
            tricode.append(tri)
        elif lists[1] == 'j<':
            tri.append('IF')
            tri.append(var_dic[lists[2]])
            tri.append('<')
            tri.append(var_dic[lists[3]])
            tri.append('GOTO')
            tri.append(label_dic[lists[4]])
            tricode.append(tri)
        elif lists[1] == 'j>':
            tri.append('IF')
            tri.append(var_dic[lists[2]])
            tri.append('>')
            tri.append(var_dic[lists[3]])
            tri.append('GOTO')
            tri.append(label_dic[lists[4]])
            tricode.append(tri)
        elif lists[1] == 'j':
            tri.append('GOTO')
            tri.append(label_dic[lists[4]])
            tricode.append(tri)
        else:
            print('没考虑到：')
            print(lists)
        i += 1


varname(lines)
trans(lines)
print(label_dic)
m = open('.\\compare.txt', 'w')
for i in range(0, len(tricode)):
    st = ''
    for a in range(0, len(tricode[i])):
        if tricode[i][a] != ':= #':
            tricode[i][a] += ' '
        st += tricode[i][a]
    m.write(st.strip() + '\n')
m.close()