NAME = libasm.a
TESTNAME = test

SRCDIR = src
OBJDIR = build

SRCS = $(SRCDIR)/ft_strlen.s \
	   $(SRCDIR)/ft_strcmp.s \
	   # $(SRCDIR)/ft_strcpy.s \
	   # $(SRCDIR)/ft_write.s \
	   # $(SRCDIR)/ft_read.s \
	   # $(SRCDIR)/ft_strdup.s

OBJS = $(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))

AS = nasm
ASFLAGS = -felf64 -g

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
CSRCS = test.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(CSRCS) $(NAME) -o $(TESTNAME)

.PHONY: all re clean fclean test
