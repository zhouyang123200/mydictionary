#include "Request.hpp" 

Request::Request(string hostaddr, string port) : 
    hostaddr{hostaddr},
    port{port}
{
    auto const result = resolver.resolve(hostaddr, port);
    stream.connect(result);
}

Request::~Request() {
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);
}

string Request::get(string target) {
    http::request<http::string_body> req{http::verb::get, target, 11};
    req.set(http::field::host, hostaddr);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(stream, req);

    beast::flat_buffer buffer;
    http::response<http::string_body> res;
    http::read(stream, buffer, res);

    return res.body();
}