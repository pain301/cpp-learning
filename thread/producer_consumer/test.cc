#include "buffer.hh"
#include "thread.hh"

int main(){
	Buffer buffer(5);
	Thread *producer = new ProducerThread(buffer);
	Thread *consumer = new ConsumerThread(buffer);

	producer->start();
	consumer->start();

	producer->join();
	consumer->join();

	return 0;
}
