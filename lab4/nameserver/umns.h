#ifndef UMNS_H
#define UMNS_H

#include <vector>
#include "nameserverinterface.h"
#include <unordered_map>

using namespace std;

class UMNS : public NameServerInterface {
public:
  virtual void insert(const HostName&, const IPAddress&) override;
  virtual bool remove(const HostName&) override;
  virtual IPAddress lookup(const HostName&) const override;
private:
  unordered_map<HostName, IPAddress> database;
};

#endif
