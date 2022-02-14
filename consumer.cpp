#include <iostream>
#include <cppkafka/cppkafka.h>

using namespace std;
using namespace cppkafka;

int main(int argc, char** argv) {
    Configuration config = {
        { "metadata.broker.list", "127.0.0.1:9092" },
        { "group.id", "1" },
        { "enable.auto.commit", false}
    };


    Consumer consumer(config);

    consumer.set_assignment_callback([](const TopicPartitionList& partitions) {
        std::cout << "Got assigned: " << partitions << "\n";
    });

    consumer.set_revocation_callback([](const TopicPartitionList& partitions) {
        std::cout << "Got revoked: " << partitions << "\n";
    });

    consumer.subscribe({argv[1]});

    while (true) {
        Message msg = consumer.poll();
        if (msg) {
            if (msg.get_error()) {
                std::cout << "Message got error!\n";
                continue;
            }

            if (msg.get_key()) {
                std::cout << msg.get_key() << " -> ";
            }

            std::cout << msg.get_payload() << "\n";
            consumer.commit(msg);
        }
    }
}
