BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
COLOUR_RESET = \033[0m
REPLACE = \033[1A\033[K\033[A

CC = c++
CFLAGS = -Wall -Wextra -std=c++98
SRCSDIR = ./
CLASSES = classes/
ODIR = ./
FILES =	$(SRCSDIR)main.cpp \
		$(CLASSES)converter.cpp \


OFILES = $(SRCSDIR)main.o \
		$(CLASSES)converter.o \

NAME = convert

all: $(NAME)

$(ODIR)%.o: $(SRCSDIR)%.cpp
	@echo "$(YELLOW)$(BOLD)💾 Compiling $<...$(COLOUR_RESET)"
	@$(CC) $(CFLAGS) -I./classes -c $< -o $@

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "$(GREEN)$(BOLD)🎊 Compilation complete! 🎊$(COLOUR_RESET)"
	@echo "$(CYAN)$(BOLD)Executable: $@$(COLOUR_RESET)"

clean:
	@echo "$(RED)$(BOLD)🧹 Removing object files...$(COLOUR_RESET)"
	@rm -f $(OFILES)
	@echo "$(GREEN)$(BOLD)✔️ Object files removed!$(COLOUR_RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)🗑️  Removing executable $(NAME)...$(COLOUR_RESET)"
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(GREEN)$(BOLD)✨ All clean! ✨$(COLOUR_RESET)"

party:
	@echo "$(BOLD)Let's party!"
	@echo "$(RED)$(BOLD)  (^-^) $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(CYAN)$(BOLD) \\(^-^\\) $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(YELLOW)$(BOLD)  (^-^)  $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(BLUE)$(BOLD) (/^-^)/ $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(MAGENTA)$(BOLD)  (^-^)  $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(GREEN)$(BOLD) \\(^-^)/ $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(REPLACE)\033[A"
	@echo "$(BOLD)Party time is over! Back to work! \n  (^-^)7$(COLOUR_RESET)"

re: fclean all

.PHONY: all clean fclean re party
