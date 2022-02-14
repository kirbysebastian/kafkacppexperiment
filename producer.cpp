#include <iostream>
#include <cppkafka/cppkafka.h>

using namespace std;
using namespace cppkafka;

int main(int argc, char** argv) {
    // Create the config
    Configuration config = {
        { "metadata.broker.list", "127.0.0.1:9092" }
    };

    // Create the producer
    Producer producer(config);

    // Produce a message!
    string message = argv[2];

    //for (int i=0; i<=100000; ++i) {
        producer.produce(MessageBuilder(argv[1]).partition(0).payload(message));
    //}
    producer.flush();
}
