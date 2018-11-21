#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 43 of your 30 day trial period.
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
# Date: 11/21/18
# Time: 21:05:31
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : stmt $end

    1  stmt : expr ';' expr

    2  expr : NUMBER '+' NUMBER
    3       | expr '+' NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . stmt $end

	NUMBER  shift 1

	stmt  goto 2
	expr  goto 3


state 1
	expr : NUMBER . '+' NUMBER

	'+'  shift 4


state 2
	$accept : stmt . $end  (0)

	$end  accept


state 3
	stmt : expr . ';' expr
	expr : expr . '+' NUMBER

	'+'  shift 5
	';'  shift 6


state 4
	expr : NUMBER '+' . NUMBER

	NUMBER  shift 7


state 5
	expr : expr '+' . NUMBER

	NUMBER  shift 8


state 6
	stmt : expr ';' . expr

	NUMBER  shift 1

	expr  goto 9


state 7
	expr : NUMBER '+' NUMBER .  (2)

	.  reduce 2


state 8
	expr : expr '+' NUMBER .  (3)

	.  reduce 3


state 9
	stmt : expr ';' expr .  (1)
	expr : expr . '+' NUMBER

	'+'  shift 5
	.  reduce 1


##############################################################################
# Summary
##############################################################################

5 token(s), 3 nonterminal(s)
4 grammar rule(s), 10 state(s)


##############################################################################
# End of File
##############################################################################
