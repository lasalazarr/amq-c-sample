//
// Created on 11/29/16.
//


#include <stdio.h>
#include <string>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/core/ActiveMQConnection.h>
#include <activemq/transport/DefaultTransportListener.h>
#include <activemq/library/ActiveMQCPP.h>

using namespace activemq;
using namespace activemq::core;
using namespace activemq::transport;
using namespace cms;
using namespace std;

int main(int argc, char **argv) {
    string brokerURI = "tcp://127.0.0.1:61616";
    string dest = "cppQueue";

    activemq::library::ActiveMQCPP::initializeLibrary();
    ActiveMQConnectionFactory *connectionFactory = new ActiveMQConnectionFactory(brokerURI);

    Connection *connection = connectionFactory->createConnection();

    connection->start();

    Session *session = connection->createSession(Session::AUTO_ACKNOWLEDGE);
    Destination *destination = session->createQueue(dest);
    MessageProducer *producer = producer = session->createProducer(destination);
    producer->setDeliveryMode(DeliveryMode::NON_PERSISTENT);

    // Create a messages
    string text = (string) "Hello world! from activemqcpp";
    TextMessage *message = session->createTextMessage(text);

    cout << "Sending Message: " << message->getText() << endl;
    producer->send(message);

    delete message;
    delete destination;
    delete session;
    delete connection;
    delete connectionFactory;

    return 0;
}