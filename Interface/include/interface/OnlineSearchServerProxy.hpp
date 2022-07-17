#pragma once

namespace OnlineSearch::Interface
{
template <typename Derived>
class OnlineSearchServerProxy
{
public :
    auto initialize() -> bool 
    { 
        return static_cast<Proxy*>(this)->_initialize();
    }

    auto finalize() -> bool 
    {
        return static_cast<Proxy*>(this)->_finalize();
    }

private :
    class Proxy : public Derived
    {
        friend bool OnlineSearchServerProxy::initialize();
        friend bool OnlineSearchServerProxy::finalize();
    };
};
} // namespace OnlineSearch::Interface