BINS=
MBINS=example61 example62 example63

all: $(BINS) $(MBINS)

$(BINS): % : %.o
	$(CC)  -o $@ $<

$(MBINS): % : %.o 
	$(CC)  -o $@ $<

clean:
	-rm -f *.o $(BINS) $(MBINS)
