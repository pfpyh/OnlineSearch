#include "OnlineSearch.h"
#include "OnlineSearch_types.h"

#include <thrift/protocol/TProtocol.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransport.h>

#include <string>
#include <iostream>

using namespace OnlineSearch;
using namespace OnlineSearch::Interface;

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

void main()
{
    try
    {
        auto t = new TSocket("localhost", 9090);
        std::shared_ptr<TTransport> socket(t);
        std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
        OnlineSearchClient client(protocol);

        transport->open();
        client.search("temp");
    }
    catch (std::bad_alloc e)
    {
        auto what = e.what();
        std::cout << what << std::endl;
    }
}