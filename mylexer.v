#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 53 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/01/18
# Time: 18:00:06
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t]+

    2  "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"

    3  \/\/[^\n]*

    4  \"(\\.|[^"\\])*\"

    5  \n

    6  void

    7  main

    8  ":"

    9  "("

   10  ")"

   11  "{"

   12  "}"

   13  "["

   14  "]"

   15  int

   16  float

   17  char

   18  double

   19  short

   20  ;

   21  for

   22  "="

   23  [0-9]+(\.[0-9]+)?([Ee][+-]?[0-9]+)?+[A-Za-z_]([A-Za-z_]|[0-9])*

   24  [0-9]+(\.[0-9]+)?([Ee][+-]?[0-9]+)?

   25  "<"">""<="">=""!=""+"

   26  "-"

   27  "/"

   28  "*"

   29  if

   30  break

   31  case

   32  const

   33  continue

   34  default

   35  do

   36  else

   37  enum

   38  extern

   39  goto

   40  return

   41  register

   42  signed

   43  unsigned

   44  sizeof

   45  static

   46  struct

   47  switch

   48  typedef

   49  union

   50  volatile

   51  while

   52  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 3
	0x22               goto 6
	0x23 - 0x27 (5)    goto 3
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b - 0x2c (2)    goto 3
	0x2d               goto 10
	0x2e               goto 3
	0x2f               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3a               goto 13
	0x3b               goto 14
	0x3c               goto 15
	0x3d               goto 16
	0x3e - 0x5a (29)   goto 3
	0x5b               goto 17
	0x5c               goto 3
	0x5d               goto 18
	0x5e - 0x61 (4)    goto 3
	0x62               goto 19
	0x63               goto 20
	0x64               goto 21
	0x65               goto 22
	0x66               goto 23
	0x67               goto 24
	0x68               goto 3
	0x69               goto 25
	0x6a - 0x6c (3)    goto 3
	0x6d               goto 26
	0x6e - 0x71 (4)    goto 3
	0x72               goto 27
	0x73               goto 28
	0x74               goto 29
	0x75               goto 30
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 3
	0x7b               goto 33
	0x7c               goto 3
	0x7d               goto 34
	0x7e - 0xff (130)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 3
	0x22               goto 6
	0x23 - 0x27 (5)    goto 3
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b - 0x2c (2)    goto 3
	0x2d               goto 10
	0x2e               goto 3
	0x2f               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3a               goto 13
	0x3b               goto 14
	0x3c               goto 15
	0x3d               goto 16
	0x3e - 0x5a (29)   goto 3
	0x5b               goto 17
	0x5c               goto 3
	0x5d               goto 18
	0x5e - 0x61 (4)    goto 3
	0x62               goto 19
	0x63               goto 20
	0x64               goto 21
	0x65               goto 22
	0x66               goto 23
	0x67               goto 24
	0x68               goto 3
	0x69               goto 25
	0x6a - 0x6c (3)    goto 3
	0x6d               goto 26
	0x6e - 0x71 (4)    goto 3
	0x72               goto 27
	0x73               goto 28
	0x74               goto 29
	0x75               goto 30
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 3
	0x7b               goto 33
	0x7c               goto 3
	0x7d               goto 34
	0x7e - 0xff (130)  goto 3


state 3
	match 52


state 4
	0x09               goto 4
	0x20               goto 4

	match 1


state 5
	match 5


state 6
	0x00 - 0x21 (34)   goto 35
	0x22               goto 36
	0x23 - 0x5b (57)   goto 35
	0x5c               goto 37
	0x5d - 0xff (163)  goto 35

	match 52


state 7
	match 9


state 8
	match 10


state 9
	match 28


state 10
	match 26


state 11
	0x2a               goto 38
	0x2f               goto 39

	match 27


state 12
	0x2e               goto 40
	0x30 - 0x39 (10)   goto 12
	0x41 - 0x44 (4)    goto 41
	0x45               goto 42
	0x46 - 0x5a (21)   goto 41
	0x5f               goto 41
	0x61 - 0x64 (4)    goto 41
	0x65               goto 42
	0x66 - 0x7a (21)   goto 41

	match 24


state 13
	match 8


state 14
	match 20


state 15
	0x3e               goto 43

	match 52


state 16
	match 22


state 17
	match 13


state 18
	match 14


state 19
	0x72               goto 44

	match 52


state 20
	0x61               goto 45
	0x68               goto 46
	0x6f               goto 47

	match 52


state 21
	0x65               goto 48
	0x6f               goto 49

	match 52


state 22
	0x6c               goto 50
	0x6e               goto 51
	0x78               goto 52

	match 52


state 23
	0x6c               goto 53
	0x6f               goto 54

	match 52


state 24
	0x6f               goto 55

	match 52


state 25
	0x66               goto 56
	0x6e               goto 57

	match 52


state 26
	0x61               goto 58

	match 52


state 27
	0x65               goto 59

	match 52


state 28
	0x68               goto 60
	0x69               goto 61
	0x74               goto 62
	0x77               goto 63

	match 52


state 29
	0x79               goto 64

	match 52


state 30
	0x6e               goto 65

	match 52


state 31
	0x6f               goto 66

	match 52


state 32
	0x68               goto 67

	match 52


state 33
	match 11


state 34
	match 12


state 35
	0x00 - 0x21 (34)   goto 35
	0x22               goto 36
	0x23 - 0x5b (57)   goto 35
	0x5c               goto 37
	0x5d - 0xff (163)  goto 35


state 36
	match 4


state 37
	0x00 - 0x09 (10)   goto 35
	0x0b - 0xff (245)  goto 35


state 38
	0x00 - 0x29 (42)   goto 38
	0x2a               goto 68
	0x2b - 0x2e (4)    goto 38
	0x2f               goto 38
	0x30 - 0xff (208)  goto 38


state 39
	0x00 - 0x09 (10)   goto 39
	0x0b - 0xff (245)  goto 39

	match 3


state 40
	0x30 - 0x39 (10)   goto 69


state 41
	0x30 - 0x39 (10)   goto 41
	0x41 - 0x5a (26)   goto 41
	0x5f               goto 41
	0x61 - 0x7a (26)   goto 41

	match 23


state 42
	0x2b               goto 70
	0x2d               goto 70
	0x30 - 0x39 (10)   goto 71
	0x41 - 0x5a (26)   goto 41
	0x5f               goto 41
	0x61 - 0x7a (26)   goto 41

	match 23


state 43
	0x3c               goto 72


state 44
	0x65               goto 73


state 45
	0x73               goto 74


state 46
	0x61               goto 75


state 47
	0x6e               goto 76


state 48
	0x66               goto 77


state 49
	0x75               goto 78

	match 35


state 50
	0x73               goto 79


state 51
	0x75               goto 80


state 52
	0x74               goto 81


state 53
	0x6f               goto 82


state 54
	0x72               goto 83


state 55
	0x74               goto 84


state 56
	match 29


state 57
	0x74               goto 85


state 58
	0x69               goto 86


state 59
	0x67               goto 87
	0x74               goto 88


state 60
	0x6f               goto 89


state 61
	0x67               goto 90
	0x7a               goto 91


state 62
	0x61               goto 92
	0x72               goto 93


state 63
	0x69               goto 94


state 64
	0x70               goto 95


state 65
	0x69               goto 96
	0x73               goto 97


state 66
	0x69               goto 98
	0x6c               goto 99


state 67
	0x69               goto 100


state 68
	0x00 - 0x29 (42)   goto 38
	0x2a               goto 68
	0x2b - 0x2e (4)    goto 38
	0x2f               goto 101
	0x30 - 0xff (208)  goto 38


state 69
	0x30 - 0x39 (10)   goto 69
	0x41 - 0x44 (4)    goto 41
	0x45               goto 42
	0x46 - 0x5a (21)   goto 41
	0x5f               goto 41
	0x61 - 0x64 (4)    goto 41
	0x65               goto 42
	0x66 - 0x7a (21)   goto 41

	match 24


state 70
	0x30 - 0x39 (10)   goto 102


state 71
	0x30 - 0x39 (10)   goto 71
	0x41 - 0x44 (4)    goto 41
	0x45               goto 103
	0x46 - 0x5a (21)   goto 41
	0x5f               goto 41
	0x61 - 0x64 (4)    goto 41
	0x65               goto 103
	0x66 - 0x7a (21)   goto 41

	match 23


state 72
	0x3d               goto 104


state 73
	0x61               goto 105


state 74
	0x65               goto 106


state 75
	0x72               goto 107


state 76
	0x73               goto 108
	0x74               goto 109


state 77
	0x61               goto 110


state 78
	0x62               goto 111


state 79
	0x65               goto 112


state 80
	0x6d               goto 113


state 81
	0x65               goto 114


state 82
	0x61               goto 115


state 83
	match 21


state 84
	0x6f               goto 116


state 85
	match 15


state 86
	0x6e               goto 117


state 87
	0x69               goto 118


state 88
	0x75               goto 119


state 89
	0x72               goto 120


state 90
	0x6e               goto 121


state 91
	0x65               goto 122


state 92
	0x74               goto 123


state 93
	0x75               goto 124


state 94
	0x74               goto 125


state 95
	0x65               goto 126


state 96
	0x6f               goto 127


state 97
	0x69               goto 128


state 98
	0x64               goto 129


state 99
	0x61               goto 130


state 100
	0x6c               goto 131


state 101
	match 2


state 102
	0x30 - 0x39 (10)   goto 102
	0x41 - 0x44 (4)    goto 41
	0x45               goto 103
	0x46 - 0x5a (21)   goto 41
	0x5f               goto 41
	0x61 - 0x64 (4)    goto 41
	0x65               goto 103
	0x66 - 0x7a (21)   goto 41

	match 24


state 103
	0x2b               goto 132
	0x2d               goto 132
	0x30 - 0x39 (10)   goto 71
	0x41 - 0x5a (26)   goto 41
	0x5f               goto 41
	0x61 - 0x7a (26)   goto 41

	match 23


state 104
	0x3e               goto 133


state 105
	0x6b               goto 134


state 106
	match 31


state 107
	match 17


state 108
	0x74               goto 135


state 109
	0x69               goto 136


state 110
	0x75               goto 137


state 111
	0x6c               goto 138


state 112
	match 36


state 113
	match 37


state 114
	0x72               goto 139


state 115
	0x74               goto 140


state 116
	match 39


state 117
	match 7


state 118
	0x73               goto 141


state 119
	0x72               goto 142


state 120
	0x74               goto 143


state 121
	0x65               goto 144


state 122
	0x6f               goto 145


state 123
	0x69               goto 146


state 124
	0x63               goto 147


state 125
	0x63               goto 148


state 126
	0x64               goto 149


state 127
	0x6e               goto 150


state 128
	0x67               goto 151


state 129
	match 6


state 130
	0x74               goto 152


state 131
	0x65               goto 153


state 132
	0x30 - 0x39 (10)   goto 154


state 133
	0x3d               goto 155


state 134
	match 30


state 135
	match 32


state 136
	0x6e               goto 156


state 137
	0x6c               goto 157


state 138
	0x65               goto 158


state 139
	0x6e               goto 159


state 140
	match 16


state 141
	0x74               goto 160


state 142
	0x6e               goto 161


state 143
	match 19


state 144
	0x64               goto 162


state 145
	0x66               goto 163


state 146
	0x63               goto 164


state 147
	0x74               goto 165


state 148
	0x68               goto 166


state 149
	0x65               goto 167


state 150
	match 49


state 151
	0x6e               goto 168


state 152
	0x69               goto 169


state 153
	match 51


state 154
	0x30 - 0x39 (10)   goto 154
	0x41 - 0x44 (4)    goto 41
	0x45               goto 103
	0x46 - 0x5a (21)   goto 41
	0x5f               goto 41
	0x61 - 0x64 (4)    goto 41
	0x65               goto 103
	0x66 - 0x7a (21)   goto 41


state 155
	0x21               goto 170


state 156
	0x75               goto 171


state 157
	0x74               goto 172


state 158
	match 18


state 159
	match 38


state 160
	0x65               goto 173


state 161
	match 40


state 162
	match 42


state 163
	match 44


state 164
	match 45


state 165
	match 46


state 166
	match 47


state 167
	0x66               goto 174


state 168
	0x65               goto 175


state 169
	0x6c               goto 176


state 170
	0x3d               goto 177


state 171
	0x65               goto 178


state 172
	match 34


state 173
	0x72               goto 179


state 174
	match 48


state 175
	0x64               goto 180


state 176
	0x65               goto 181


state 177
	0x2b               goto 182


state 178
	match 33


state 179
	match 41


state 180
	match 43


state 181
	match 50


state 182
	match 25


#############################################################################
# Summary
#############################################################################

1 start state(s)
52 expression(s), 182 state(s)


#############################################################################
# End of File
#############################################################################
