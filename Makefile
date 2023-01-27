##
## EPITECH PROJECT, 2022
## radar
## File description:
## Makefile
##

CC	  = gcc
RM	  = rm -rf

LIB 	= lib/my_addchar.c\
		lib/my_addstr.c\
		lib/my_compstr.c\
		lib/my_convnbstr.c\
		lib/my_convstrnb.c\
		lib/my_countnb.c\
		lib/my_countstr.c\
		lib/my_dupstr.c\
		lib/my_isnb.c\
		lib/my_rand.c\
		lib/my_revstr.c\
		lib/my_showchar.c\
		lib/my_showstr.c\
		lib/my_convstrarray.c\
		lib/my_printf.c\
		lib/my_scanf.c\

## CHANGE THIS ##
SRC		= src/ms_chat.c\
		src/ms_usefull.c\

MAIN	= src/main.c\

SRCOBJ  = $(SRC:.c=.o)
LIBOBJ  = $(LIB:.c=.o)

## CHANGE THIS ##
BINNAME = name
LIBNAME = lib$(BINNAME).a

CFLAGS  = -W -Wall -Wextra

## CHANGE THIS ##
INCLUDE	=

## ---------- ##

all: build

build: $(LIBOBJ) $(SRCOBJ)
	ar rc $(LIBNAME) $(LIBOBJ) $(SRCOBJ)
	gcc $(CFLAGS) $(MAIN) -L. -l$(BINNAME) $(INCLUDE) -o $(BINNAME)

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)
	$(RM) $(LIBNAME)
	$(RM) *.c~

fclean: clean
	$(RM) $(SRCNAME)

re: fclean build
	make clean

.PHONY:
	clean fclean re build all
