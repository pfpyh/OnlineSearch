/**
 * Autogenerated by Thrift Compiler (0.17.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "OnlineSearchProxy.h"

namespace OnlineSearch { namespace Interface {


OnlineSearchProxy_onSearchStatusChanged_args::~OnlineSearchProxy_onSearchStatusChanged_args() noexcept {
}


uint32_t OnlineSearchProxy_onSearchStatusChanged_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->search_id);
          this->__isset.search_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast4;
          xfer += iprot->readI32(ecast4);
          this->search_status = static_cast<SearchStatus::type>(ecast4);
          this->__isset.search_status = true;
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

uint32_t OnlineSearchProxy_onSearchStatusChanged_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchStatusChanged_args");

  xfer += oprot->writeFieldBegin("search_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->search_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("search_status", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(static_cast<int32_t>(this->search_status));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchStatusChanged_pargs::~OnlineSearchProxy_onSearchStatusChanged_pargs() noexcept {
}


uint32_t OnlineSearchProxy_onSearchStatusChanged_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchStatusChanged_pargs");

  xfer += oprot->writeFieldBegin("search_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->search_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("search_status", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(static_cast<int32_t>((*(this->search_status))));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchStatusChanged_result::~OnlineSearchProxy_onSearchStatusChanged_result() noexcept {
}


uint32_t OnlineSearchProxy_onSearchStatusChanged_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t OnlineSearchProxy_onSearchStatusChanged_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchStatusChanged_result");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchStatusChanged_presult::~OnlineSearchProxy_onSearchStatusChanged_presult() noexcept {
}


uint32_t OnlineSearchProxy_onSearchStatusChanged_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}


OnlineSearchProxy_onSearchResultChanged_args::~OnlineSearchProxy_onSearchResultChanged_args() noexcept {
}


uint32_t OnlineSearchProxy_onSearchResultChanged_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->search_id);
          this->__isset.search_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->results.clear();
            uint32_t _size5;
            ::apache::thrift::protocol::TType _etype8;
            xfer += iprot->readListBegin(_etype8, _size5);
            this->results.resize(_size5);
            uint32_t _i9;
            for (_i9 = 0; _i9 < _size5; ++_i9)
            {
              xfer += this->results[_i9].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.results = true;
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

uint32_t OnlineSearchProxy_onSearchResultChanged_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchResultChanged_args");

  xfer += oprot->writeFieldBegin("search_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->search_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("results", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->results.size()));
    std::vector<SearchResult> ::const_iterator _iter10;
    for (_iter10 = this->results.begin(); _iter10 != this->results.end(); ++_iter10)
    {
      xfer += (*_iter10).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchResultChanged_pargs::~OnlineSearchProxy_onSearchResultChanged_pargs() noexcept {
}


uint32_t OnlineSearchProxy_onSearchResultChanged_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchResultChanged_pargs");

  xfer += oprot->writeFieldBegin("search_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->search_id)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("results", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->results)).size()));
    std::vector<SearchResult> ::const_iterator _iter11;
    for (_iter11 = (*(this->results)).begin(); _iter11 != (*(this->results)).end(); ++_iter11)
    {
      xfer += (*_iter11).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchResultChanged_result::~OnlineSearchProxy_onSearchResultChanged_result() noexcept {
}


uint32_t OnlineSearchProxy_onSearchResultChanged_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t OnlineSearchProxy_onSearchResultChanged_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("OnlineSearchProxy_onSearchResultChanged_result");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


OnlineSearchProxy_onSearchResultChanged_presult::~OnlineSearchProxy_onSearchResultChanged_presult() noexcept {
}


uint32_t OnlineSearchProxy_onSearchResultChanged_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

void OnlineSearchProxyClient::onSearchStatusChanged(const SearchId search_id, const SearchStatus::type search_status)
{
  send_onSearchStatusChanged(search_id, search_status);
  recv_onSearchStatusChanged();
}

void OnlineSearchProxyClient::send_onSearchStatusChanged(const SearchId search_id, const SearchStatus::type search_status)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onSearchStatusChanged", ::apache::thrift::protocol::T_CALL, cseqid);

  OnlineSearchProxy_onSearchStatusChanged_pargs args;
  args.search_id = &search_id;
  args.search_status = &search_status;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void OnlineSearchProxyClient::recv_onSearchStatusChanged()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("onSearchStatusChanged") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  OnlineSearchProxy_onSearchStatusChanged_presult result;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  return;
}

void OnlineSearchProxyClient::onSearchResultChanged(const SearchId search_id, const std::vector<SearchResult> & results)
{
  send_onSearchResultChanged(search_id, results);
  recv_onSearchResultChanged();
}

void OnlineSearchProxyClient::send_onSearchResultChanged(const SearchId search_id, const std::vector<SearchResult> & results)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onSearchResultChanged", ::apache::thrift::protocol::T_CALL, cseqid);

  OnlineSearchProxy_onSearchResultChanged_pargs args;
  args.search_id = &search_id;
  args.results = &results;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void OnlineSearchProxyClient::recv_onSearchResultChanged()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("onSearchResultChanged") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  OnlineSearchProxy_onSearchResultChanged_presult result;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  return;
}

bool OnlineSearchProxyProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void OnlineSearchProxyProcessor::process_onSearchStatusChanged(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = nullptr;
  if (this->eventHandler_.get() != nullptr) {
    ctx = this->eventHandler_->getContext("OnlineSearchProxy.onSearchStatusChanged", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "OnlineSearchProxy.onSearchStatusChanged");

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preRead(ctx, "OnlineSearchProxy.onSearchStatusChanged");
  }

  OnlineSearchProxy_onSearchStatusChanged_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postRead(ctx, "OnlineSearchProxy.onSearchStatusChanged", bytes);
  }

  OnlineSearchProxy_onSearchStatusChanged_result result;
  try {
    iface_->onSearchStatusChanged(args.search_id, args.search_status);
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != nullptr) {
      this->eventHandler_->handlerError(ctx, "OnlineSearchProxy.onSearchStatusChanged");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("onSearchStatusChanged", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preWrite(ctx, "OnlineSearchProxy.onSearchStatusChanged");
  }

  oprot->writeMessageBegin("onSearchStatusChanged", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postWrite(ctx, "OnlineSearchProxy.onSearchStatusChanged", bytes);
  }
}

void OnlineSearchProxyProcessor::process_onSearchResultChanged(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = nullptr;
  if (this->eventHandler_.get() != nullptr) {
    ctx = this->eventHandler_->getContext("OnlineSearchProxy.onSearchResultChanged", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "OnlineSearchProxy.onSearchResultChanged");

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preRead(ctx, "OnlineSearchProxy.onSearchResultChanged");
  }

  OnlineSearchProxy_onSearchResultChanged_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postRead(ctx, "OnlineSearchProxy.onSearchResultChanged", bytes);
  }

  OnlineSearchProxy_onSearchResultChanged_result result;
  try {
    iface_->onSearchResultChanged(args.search_id, args.results);
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != nullptr) {
      this->eventHandler_->handlerError(ctx, "OnlineSearchProxy.onSearchResultChanged");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("onSearchResultChanged", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->preWrite(ctx, "OnlineSearchProxy.onSearchResultChanged");
  }

  oprot->writeMessageBegin("onSearchResultChanged", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != nullptr) {
    this->eventHandler_->postWrite(ctx, "OnlineSearchProxy.onSearchResultChanged", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > OnlineSearchProxyProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< OnlineSearchProxyIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< OnlineSearchProxyIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new OnlineSearchProxyProcessor(handler));
  return processor;
}

void OnlineSearchProxyConcurrentClient::onSearchStatusChanged(const SearchId search_id, const SearchStatus::type search_status)
{
  int32_t seqid = send_onSearchStatusChanged(search_id, search_status);
  recv_onSearchStatusChanged(seqid);
}

int32_t OnlineSearchProxyConcurrentClient::send_onSearchStatusChanged(const SearchId search_id, const SearchStatus::type search_status)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onSearchStatusChanged", ::apache::thrift::protocol::T_CALL, cseqid);

  OnlineSearchProxy_onSearchStatusChanged_pargs args;
  args.search_id = &search_id;
  args.search_status = &search_status;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void OnlineSearchProxyConcurrentClient::recv_onSearchStatusChanged(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("onSearchStatusChanged") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      OnlineSearchProxy_onSearchStatusChanged_presult result;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      sentry.commit();
      return;
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void OnlineSearchProxyConcurrentClient::onSearchResultChanged(const SearchId search_id, const std::vector<SearchResult> & results)
{
  int32_t seqid = send_onSearchResultChanged(search_id, results);
  recv_onSearchResultChanged(seqid);
}

int32_t OnlineSearchProxyConcurrentClient::send_onSearchResultChanged(const SearchId search_id, const std::vector<SearchResult> & results)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onSearchResultChanged", ::apache::thrift::protocol::T_CALL, cseqid);

  OnlineSearchProxy_onSearchResultChanged_pargs args;
  args.search_id = &search_id;
  args.results = &results;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void OnlineSearchProxyConcurrentClient::recv_onSearchResultChanged(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("onSearchResultChanged") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      OnlineSearchProxy_onSearchResultChanged_presult result;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      sentry.commit();
      return;
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

}} // namespace

