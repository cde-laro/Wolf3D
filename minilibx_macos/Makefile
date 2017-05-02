NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -g
COLOR = \0033[1;35m

all: $(NOM)
	@echo "$(COLOR)$(NOM)\t\t\0033[1;30m[All OK]\0033[0;37m"
$(NOM):	$(OBJ)
	@ar rc $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(OBJ) *~
	@echo "$(COLOR)Objects of $(NOM)\t\0033[0;31m[Deleted]\0033[0;37m"

fclean:
	@rm -f $(NOM) *~
	@rm -f mlx_app
	@echo "$(COLOR)$(NOM)\t\t\0033[0;31m[Deleted]\0033[0;37m"

re: clean all
