pub=redis_publisher.o publisher.o TimeStamp.o
sub=redis_subscriber.o subscriber.o TimeStamp.o
GCC=g++ -std=c++11 -g
CXXFLAGS=-std=c++11 -g
target=server client
LIBS=-lpthread -levent -lhiredis
all:$(target)
server:$(pub)
	$(GCC) -o $@ $^ $(LIBS)
client:$(sub)
	$(GCC) -o $@ $^ $(LIBS)
clean:
	rm -rf $(target) $(pub) $(sub)

