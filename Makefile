CC = gcc
CFlags = -W -Wall
TARGET = market
DTARGET = market_debug
OBJECT = market.c product.o manager.o 


$(TARGET): $(OBJECT) 
	$(CC) $(CFlags) -o $@ $^ 
$(DTARGET): $(OBJECT)
	$(CC) $(CFlags) -DDEBUG -o $@ $^ 

clean : 
	rm *.o $(TARGET) $(DTARGET)

