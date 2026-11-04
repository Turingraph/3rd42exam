CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
SRCS_libft = $(wildcard libft/*.c)
SRCS_scanf = $(wildcard scanf/*.c)
SRCS_subset = $(wildcard subset/*.c)
SRCS_get_next_line = $(wildcard get_next_line/*.c)
SRCS_permutation = $(wildcard permutation/*.c)
OBJS_libft = $(patsubst %.c, obj/%.o, $(SRCS_libft))
OBJS_scanf = $(patsubst %.c, obj/%.o, $(SRCS_scanf)) $(OBJS_libft)
OUTS_libft = $(patsubst %.c, out/%.out, $(SRCS_libft))
OUTS_scanf = $(patsubst %.c, out/%.out, $(SRCS_scanf))
OUTS_subset = $(patsubst %.c, out/%.out, $(SRCS_subset))
OUTS_get_next_line = $(patsubst %.c, out/%.out, $(SRCS_get_next_line))
OUTS_permutation = $(patsubst %.c, out/%.out, $(SRCS_permutation))
OUTS = $(OUTS_libft) $(OUTS_scanf) $(OUTS_get_next_line) $(OUTS_permutation) $(OUTS_subset)

all: $(OUTS)

$(OUTS): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(notdir $(call remove_slash, $(dir $@))).a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r -f out/
	rm -r -f obj/

re: all clean

.PHONY: all clean re
