/**
 * Autogenerated by Thrift Compiler (0.17.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "OnlineSearch_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace OnlineSearch { namespace Interface {

int _kSearchStatusValues[] = {
  SearchStatus::Searching,
  SearchStatus::Done
};
const char* _kSearchStatusNames[] = {
  "Searching",
  "Done"
};
const std::map<int, const char*> _SearchStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kSearchStatusValues, _kSearchStatusNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const SearchStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _SearchStatus_VALUES_TO_NAMES.find(val);
  if (it != _SearchStatus_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const SearchStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _SearchStatus_VALUES_TO_NAMES.find(val);
  if (it != _SearchStatus_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


SearchResult::~SearchResult() noexcept {
}


void SearchResult::__set__name(const std::string& val) {
  this->_name = val;
}
std::ostream& operator<<(std::ostream& out, const SearchResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t SearchResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->_name);
          this->__isset._name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SearchResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SearchResult");

  xfer += oprot->writeFieldBegin("_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SearchResult &a, SearchResult &b) {
  using ::std::swap;
  swap(a._name, b._name);
  swap(a.__isset, b.__isset);
}

SearchResult::SearchResult(const SearchResult& other0) {
  _name = other0._name;
  __isset = other0.__isset;
}
SearchResult& SearchResult::operator=(const SearchResult& other1) {
  _name = other1._name;
  __isset = other1.__isset;
  return *this;
}
void SearchResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SearchResult(";
  out << "_name=" << to_string(_name);
  out << ")";
}


ConnectionInfo::~ConnectionInfo() noexcept {
}


void ConnectionInfo::__set__address(const std::string& val) {
  this->_address = val;
}

void ConnectionInfo::__set__port(const int32_t val) {
  this->_port = val;
}

void ConnectionInfo::__set__client_id(const std::string& val) {
  this->_client_id = val;
}
std::ostream& operator<<(std::ostream& out, const ConnectionInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ConnectionInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->_address);
          this->__isset._address = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->_port);
          this->__isset._port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->_client_id);
          this->__isset._client_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ConnectionInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ConnectionInfo");

  xfer += oprot->writeFieldBegin("_address", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->_address);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("_port", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->_port);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("_client_id", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->_client_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ConnectionInfo &a, ConnectionInfo &b) {
  using ::std::swap;
  swap(a._address, b._address);
  swap(a._port, b._port);
  swap(a._client_id, b._client_id);
  swap(a.__isset, b.__isset);
}

ConnectionInfo::ConnectionInfo(const ConnectionInfo& other2) {
  _address = other2._address;
  _port = other2._port;
  _client_id = other2._client_id;
  __isset = other2.__isset;
}
ConnectionInfo& ConnectionInfo::operator=(const ConnectionInfo& other3) {
  _address = other3._address;
  _port = other3._port;
  _client_id = other3._client_id;
  __isset = other3.__isset;
  return *this;
}
void ConnectionInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ConnectionInfo(";
  out << "_address=" << to_string(_address);
  out << ", " << "_port=" << to_string(_port);
  out << ", " << "_client_id=" << to_string(_client_id);
  out << ")";
}

}} // namespace
