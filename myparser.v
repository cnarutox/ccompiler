#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 50 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 11/28/18
# Time: 16:08:57
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : stmt $end

    1  stmt : expr ';' expr
    2       | stmt ';' expr

    3  expr : NUMBER '+' NUMBER
    4       | expr '+' NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . stmt $end

	NUMBER  shift 1

	expr  goto 2
	stmt  goto 3


state 1
	expr : NUMBER . '+' NUMBER

	'+'  shift 4


state 2
	stmt : expr . ';' expr
	expr : expr . '+' NUMBER

	'+'  shift 5
	';'  shift 6


state 3
	$accept : stmt . $end  (0)
	stmt : stmt . ';' expr

	$end  accept
	';'  shift 7


state 4
	expr : NUMBER '+' . NUMBER

	NUMBER  shift 8


state 5
	expr : expr '+' . NUMBER

	NUMBER  shift 9


state 6
	stmt : expr ';' . expr

	NUMBER  shift 1

	expr  goto 10


state 7
	stmt : stmt ';' . expr

	NUMBER  shift 1

	expr  goto 11


state 8
	expr : NUMBER '+' NUMBER .  (3)

	.  reduce 3


state 9
	expr : expr '+' NUMBER .  (4)

	.  reduce 4


state 10
	stmt : expr ';' expr .  (1)
	expr : expr . '+' NUMBER

	'+'  shift 5
	.  reduce 1


state 11
	stmt : stmt ';' expr .  (2)
	expr : expr . '+' NUMBER

	'+'  shift 5
	.  reduce 2


##############################################################################
# Summary
##############################################################################

5 token(s), 3 nonterminal(s)
5 grammar rule(s), 12 state(s)


##############################################################################
# End of File
##############################################################################
