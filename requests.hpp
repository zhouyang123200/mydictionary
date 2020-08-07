#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

class Rqeust {
    public:
        Rqeust();
        ~Rqeust();
        

    private:
        net::io_context ioc;
        tcp::resolver resolver;
        beast::tcp_stream stream;
};
