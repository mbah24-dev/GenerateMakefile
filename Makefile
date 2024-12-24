NAME      ?= exec
CC         = cc
DIR        = src
INC        = inc
CFLAGS     = -Wall -Werror -Wextra -I ./
HEADER     = $(INC)/utils.h $(INC)/GenMakefile.h 
SRC        = $(DIR)/init/makefile_constants.c $(DIR)/core/scan_files.c $(DIR)/GenMakefile.c \
			 $(DIR)/utils/utils.c $(DIR)/errors/errors.c $(DIR)/parsing/parse_src_files_buffer.c 

OBJS       = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
