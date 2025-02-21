EXEC = bubble quick

.PHONY: all
all: $(EXEC)

bubble: bubble.c
	gcc -O3 -o $@ $<

quick: quick.c
	gcc -O3 -o $@ $<

.PHONY: clean
clean:
	rm -f $(EXEC)
