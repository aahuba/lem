NAME=lem-in
FLAGS= -g -Wall -Wextra -Werror
OBJECTS = srcs/main.o srcs/algo.o srcs/correct_room.o srcs/num_ant.o srcs/lem.o srcs/help.o srcs/check_room_info.o

all: $(NAME)

$(OBJECTS) : %.o: %.c
	$(CC) -c $(FLAGS) -I ft_printf/ftprintf/ -I ft_printf/libft/ $< -o $@


$(NAME): $(OBJECTS)
	$(MAKE) -C ft_printf/
	gcc -o $(NAME) $(OBJECTS) ft_printf/libftprintf.a

clean:
	$(MAKE) -C ft_printf/ clean
	-rm $(OBJECTS)
fclean : clean
	$(MAKE) -C ft_printf/ fclean
	-rm -v $(NAME)
re: fclean all

