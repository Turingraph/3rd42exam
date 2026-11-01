CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
SRCS_libft = $(wildcard libft/*.c)
SRCS_scanf = $(wildcard scanf/*.c)
OBJS_libft = $(patsubst %.c, obj/%.o, $(SRCS_libft))
OBJS_scanf = $(patsubst %.c, obj/%.o, $(SRCS_scanf)) $(OBJS_libft)
OUTS_libft = $(patsubst %.c, out/%.out, $(SRCS_libft))
OUTS_scanf = $(patsubst %.c, out/%.out, $(SRCS_scanf))
OUTS = $(OUTS_libft) $(OUTS_scanf)

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
