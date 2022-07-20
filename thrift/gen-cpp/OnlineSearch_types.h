/**
 * Autogenerated by Thrift Compiler (0.17.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef OnlineSearch_TYPES_H
#define OnlineSearch_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace OnlineSearch { namespace Interface {

struct SearchStatus {
  enum type {
    Searching = 0,
    Done = 1
  };
};

extern const std::map<int, const char*> _SearchStatus_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const SearchStatus::type& val);

std::string to_string(const SearchStatus::type& val);

typedef int32_t SearchId;

class SearchResult;

class ConnectionInfo;

typedef struct _SearchResult__isset {
  _SearchResult__isset() : _name(false) {}
  bool _name :1;
} _SearchResult__isset;

class SearchResult : public virtual ::apache::thrift::TBase {
 public:

  SearchResult(const SearchResult&);
  SearchResult& operator=(const SearchResult&);
  SearchResult() noexcept
               : _name() {
  }

  virtual ~SearchResult() noexcept;
  std::string _name;

  _SearchResult__isset __isset;

  void __set__name(const std::string& val);

  bool operator == (const SearchResult & rhs) const
  {
    if (!(_name == rhs._name))
      return false;
    return true;
  }
  bool operator != (const SearchResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SearchResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(SearchResult &a, SearchResult &b);

std::ostream& operator<<(std::ostream& out, const SearchResult& obj);

typedef struct _ConnectionInfo__isset {
  _ConnectionInfo__isset() : _address(false), _port(false), _client_id(false) {}
  bool _address :1;
  bool _port :1;
  bool _client_id :1;
} _ConnectionInfo__isset;

class ConnectionInfo : public virtual ::apache::thrift::TBase {
 public:

  ConnectionInfo(const ConnectionInfo&);
  ConnectionInfo& operator=(const ConnectionInfo&);
  ConnectionInfo() noexcept
                 : _address(),
                   _port(0),
                   _client_id() {
  }

  virtual ~ConnectionInfo() noexcept;
  std::string _address;
  int32_t _port;
  std::string _client_id;

  _ConnectionInfo__isset __isset;

  void __set__address(const std::string& val);

  void __set__port(const int32_t val);

  void __set__client_id(const std::string& val);

  bool operator == (const ConnectionInfo & rhs) const
  {
    if (!(_address == rhs._address))
      return false;
    if (!(_port == rhs._port))
      return false;
    if (!(_client_id == rhs._client_id))
      return false;
    return true;
  }
  bool operator != (const ConnectionInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ConnectionInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(ConnectionInfo &a, ConnectionInfo &b);

std::ostream& operator<<(std::ostream& out, const ConnectionInfo& obj);

}} // namespace

#endif
