#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 21 of your 30 day trial period.
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
# Date: 10/31/18
# Time: 10:50:01
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : sectence $end

    1  sectence : obj

    2  obj : object


##############################################################################
# States
##############################################################################

state 0
	$accept : . sectence $end

	object  shift 1

	sectence  goto 2
	obj  goto 3


state 1
	obj : object .  (2)

	.  reduce 2


state 2
	$accept : sectence . $end  (0)

	$end  accept


state 3
	sectence : obj .  (1)

	.  reduce 1


##############################################################################
# Summary
##############################################################################

3 token(s), 3 nonterminal(s)
3 grammar rule(s), 4 state(s)


##############################################################################
# End of File
##############################################################################
