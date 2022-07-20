#include "OnlineSearchServer.hpp"

int main(int argc, char** argv) {
    int port = 9090;
    ::std::shared_ptr<OnlineSearchHandler> handler(new OnlineSearchHandler());
    ::std::shared_ptr<TProcessor> processor(new OnlineSearchProcessor(handler));
    ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
}