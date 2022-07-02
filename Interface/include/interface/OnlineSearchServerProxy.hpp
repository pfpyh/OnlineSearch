//#pragma once
//
//namespace OnlineSearch::Interface::Server
//{
//template <typename Derived>
//class OnlineSearchServerProxy
//{
//public :
//    auto initialize() -> bool { 
//        return reinterpret_cast<Derived*>(this)->_initialize(); 
//    }
//
//    auto finalize() -> bool {
//        return reinterpret_cast<Derived*>(this)->_finalize();
//    }
//
//    auto requestSearch(std::string keyword) -> bool {
//        return reinterpret_cast<Derived*>(this)->_requestSearch(std::move(keyword));
//    }
//
//    auto notifyResult() -> void {
//        
//    }
//};
//} // namespace OnlineSearch::Interface::Server