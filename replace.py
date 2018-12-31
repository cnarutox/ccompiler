import re
import fileinput
i = 0
# for line in fileinput.input('mylexer.l', inplace=True):
for line in fileinput.input('myparser.y', inplace=True):
    # for line in [
    #         'ellipsis	{yylval.ntnode = new node("ELLIPSIS");	return ELLIPSIS;}'
    # ]:
    try:
        v = re.search(r'//printf("\d+ ")', '$$ = new node();')
        # v = re.search(r'\$\$ = new node\(\);', '$$ = new node();')
        # v = re.search('return (\w+);', line).group(1)
        # re.sub(r'reserve\(([A-Z]+)', 'reserve\(' + v, line)
        i += 1
        print(
            re.sub(r'//printf("\d+ ")',
                   '', line),
            end='')
        # print(
        #     re.sub(r'\$\$ = new node\(\);',
        #            f'$$ = new node();\n\t\tprintf("{i} ");', line),
        #     end='')
        # print(
        #     re.sub('return \w+;', 'printf("' + v + '");\treturn ' + v + ';',
        #            line),
        #     end='')
    except AttributeError:
        print(line, end='')
